#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , midiOut(nullptr)
    , midiChannel(0)  // Initialize MIDI channel to 0 (channel 1 for users)
    , midiBank(0)     // Initialize to Bank 0
{
    std::cout << "MainWindow constructor called." << std::endl;  // Debug message

    ui->setupUi(this);

    try {
        midiOut = new RtMidiOut();  // Create an RtMidiOut object

        // Open a virtual port with a specific name
        midiOut->openVirtualPort("Mako R1 Output");

        std::cout << "Opened virtual MIDI port: MakoR1-MidiControl MIDI Output" << std::endl;
    } catch (RtMidiError &error) {
        error.printMessage();
        exit(EXIT_FAILURE);
    }
    connect_midi();

    // get the default midi channel
    midiChannel = ui->midiChannelSpinBox->value() - 1;  // Match the initial value of the spin box

// SAVE LOAD STUFF
    ui->fileNameLabel->setText("No File Selected");

// END SAVE LOAD

    connect(ui->ProgramcomboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_ProgramChanged);
    //connect(ui->DivsioncomboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_DivisionChanged);

    connect(ui->presetDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_presetDialChanged);

    connect(ui->decayDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_decayDialChanged);
    connect(ui->swellDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_swellDialChanged);
    connect(ui->mixDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_mixDialChanged);
    connect(ui->rateDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_rateDialChanged);
    connect(ui->depthDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_depthDialChanged);
    connect(ui->preDelayDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_preDelayDialChanged);
    connect(ui->loDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_loDialChanged);
    connect(ui->highDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_highDialChanged);
    connect(ui->xDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_xDialChanged);

}

MainWindow::~MainWindow()
{
    delete ui;

    // Clean up MIDI resources
    if (midiOut) {
        delete midiOut;
    }
}

void MainWindow::connect_midi()
{
    if (!midiOut) {
        std::cerr << "MIDI output object not available." << std::endl;
        return;
    }

    unsigned int portCount = midiOut->getPortCount();
    if (portCount == 0) {
        std::cerr << "No MIDI output ports available." << std::endl;
        return;
    }

    // List available MIDI ports
    std::cout << "Available MIDI Output Ports:" << std::endl;
    for (unsigned int i = 0; i < portCount; ++i) {
        std::string portName = midiOut->getPortName(i);
        ui->midiDevicecomboBox->addItem(QString::fromStdString(portName));
        std::cout << "Port " << i << ": " << portName << std::endl;
    }

    // Open the first available port (or allow user to choose if there are multiple)
    try {
        midiOut->openPort(0);  // Opens the first port (you can change this index)
        std::cout << "Opened MIDI port 0: " << midiOut->getPortName(0) << std::endl;

    } catch (RtMidiError &error) {
        error.printMessage();
    }
}

void MainWindow::on_midiChannelChanged(int channel)
{
    midiChannel = channel - 1;  // MIDI channels range from 0-15 internally (user inputs 1-16)
    std::cout << "MIDI Channel set to: " << midiChannel + 1 << std::endl;
    connect_midi();
    on_openMidiPortButton_clicked();
}

void MainWindow::on_openMidiPortButton_clicked(){

    try {
        // Get the selected device index from the combo box
        int selectedDevice = ui->midiDevicecomboBox->currentIndex();

        if (selectedDevice < 0 || selectedDevice >= midiOut->getPortCount()) {
            std::cerr << "Invalid device selected." << std::endl;
            return;
        }

        // Close any previously opened port
        if (midiOut->isPortOpen()) {
            midiOut->closePort();
        }

        // Open the selected MIDI device
        midiOut->openPort(selectedDevice);

        std::cout << "Connected to MIDI device: " << midiOut->getPortName(selectedDevice) << std::endl;

    } catch (RtMidiError &error) {
        error.printMessage();
    }
}


// SAVE LOAD
void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Preset", "", "JSON Files (*.json)");
    if (!fileName.endsWith(".json", Qt::CaseInsensitive)) {
        fileName += ".json";
    }
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Save Error", "Unable to save file");
        return;
    }


    QJsonObject json;
    json["description"] = ui->descriptionText->toPlainText();
    json["program"] = ui->ProgramcomboBox->currentIndex();
    //json["division"] = ui->DivsioncomboBox->currentIndex();
    json["decayDial"] = ui->decayDial->value();
    json["swellDial"] = ui->swellDial->value();
    json["mixDial"] = ui->mixDial->value();
    json["rateDial"] = ui->rateDial->value();
    json["depthDial"] = ui->depthDial->value();
    json["preDelayDial"] = ui->preDelayDial->value();
    json["loDial"] = ui->loDial->value();
    json["highDial"] = ui->highDial->value();
    json["xDial"] = ui->xDial->value();

    QJsonDocument jsonDoc(json);
    file.write(jsonDoc.toJson());
    file.close();

    ui->fileNameLabel->setText("Saved to: " + fileName);
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Load Preset", "", "JSON Files (*.json)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Load Error", "Unable to open file");
        return;
    }

    QByteArray saveData = file.readAll();
    QJsonDocument jsonDoc(QJsonDocument::fromJson(saveData));
    QJsonObject json = jsonDoc.object();

    if (json.contains("description") && json["description"].isString()) {
        ui->descriptionText->setPlainText(json["description"].toString());    
    }
    if (json.contains("program") && json["program"].isDouble()) {
        ui->ProgramcomboBox->setCurrentIndex(json["program"].toInt());
    }

    /*if (json.contains("division") && json["division"].isDouble()) {
        ui->DivsioncomboBox->setCurrentIndex(json["division"].toInt());
    }*/

    if (json.contains("decayDial") && json["decayDial"].isDouble()) {
        ui->decayDial->setValue(json["decayDial"].toInt());
    }

    if (json.contains("swellDial") && json["swellDial"].isDouble()) {
        ui->swellDial->setValue(json["swellDial"].toInt());
    }

    if (json.contains("mixDial") && json["mixDial"].isDouble()) {
        ui->mixDial->setValue(json["mixDial"].toInt());
    }

    if (json.contains("rateDial") && json["rateDial"].isDouble()) {
        ui->rateDial->setValue(json["rateDial"].toInt());
    }

    if (json.contains("depthDial") && json["depthDial"].isDouble()) {
        ui->depthDial->setValue(json["depthDial"].toInt());
    }

    if (json.contains("preDelayDial") && json["preDelayDial"].isDouble()) {
        ui->preDelayDial->setValue(json["preDelayDial"].toInt());
    }

    if (json.contains("loDial") && json["loDial"].isDouble()) {
        ui->loDial->setValue(json["loDial"].toInt());
    }

    if (json.contains("highDial") && json["highDial"].isDouble()) {
        ui->highDial->setValue(json["highDial"].toInt());
    }

    if (json.contains("xDial") && json["xDial"].isDouble()) {
        ui->xDial->setValue(json["xDial"].toInt());
    }

    file.close();

    ui->fileNameLabel->setText("Loaded from: " + fileName);
}
// END SAVE LOAD

void MainWindow::on_ProgramChanged(int index)
{

    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(22);                  //
    message.push_back(index +1);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Program changed to: " << index + 1 << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_DivisionChanged(int index)
{
    int value;

    if(index == 0){value = 20;}
    else if (index == 1){value = 50;}
    else if (index == 2){value = 100;}

    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(25);                  //
    message.push_back(value);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Division changed to: " << index << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}


void MainWindow::on_presetToggleButton_clicked()
{
    // Toggle the state using the checked property of the button
    bypassToggleState = ui->presetToggleButton->isChecked();

    // Update button text to indicate current state
    if (bypassToggleState) {
        ui->presetToggleButton->setText("On");
    } else {
        ui->presetToggleButton->setText("Bypassed");
    }

    // Prepare the MIDI message for CC#12
    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(30);                  // Control Change #12 (Preset Toggle)
    message.push_back(bypassToggleState ? 127 : 0); // Value = 127 (On) or 0 (Off)

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Bypass: " << (bypassToggleState ? "On" : "Off") << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}


void MainWindow::on_presetDialChanged(int value)
{
    // Update the preset bank
    value = ui->presetDial->value();
    std::cout << "Selecing Preset: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xC0 + midiChannel);  // Program Change message, channel
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Selected Preset: " << value << std::endl;
        ui->presetlcd->display(value);
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_presetUpButton_clicked()
{
    int value = ui->presetDial->value();


    if(value < ui->presetDial->maximum())
    {
        value = value +1;
        std::cout << "Up button clicked " << value << std::endl;
        ui->presetDial->setValue(value);
        on_presetDialChanged(value);
    }
}


void MainWindow::on_presetDownButton_clicked()
{
    int value = ui->presetDial->value();

    if(value > 0)
    {
        value = value -1;
        std::cout << "Down button clicked " << value << std::endl;
        ui->presetDial->setValue(value);
        on_presetDialChanged(value);
    }
}

void MainWindow::on_decayDialChanged(int value)
{

    // Update the preset bank
    value = ui->decayDial->value();
    std::cout << "Decay set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
     message.push_back(3);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Decay set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_swellDialChanged(int value)
{

    // Update the preset bank
    value = ui->swellDial->value();
    std::cout << "Swell set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(14);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Swell set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_mixDialChanged(int value)
{

    // Update the preset bank
    value = ui->mixDial->value();
    std::cout << "Mix set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(15);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Mix set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_rateDialChanged(int value)
{

    // Update the preset bank
    value = ui->rateDial->value();
    std::cout << "Rate set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(20);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Rate set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_depthDialChanged(int value)
{
    // Update the preset bank
    value = ui->depthDial->value();
    std::cout << "Depth set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(21);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Depth set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_preDelayDialChanged(int value)
{
    // Update the preset bank
    value = ui->preDelayDial->value();
    std::cout << "Pre Delay set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(22);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Pre Delay set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_loDialChanged(int value)
{
    // Update the preset bank
    value = ui->loDial->value();
    std::cout << "Lo set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(24);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Lo set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_highDialChanged(int value)
{
    // Update the preset bank
    value = ui->highDial->value();
    std::cout << "High set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(25);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "High set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_xDialChanged(int value)
{
    // Update the preset bank
    value = ui->highDial->value();
    std::cout << "X set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(26);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "X set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

