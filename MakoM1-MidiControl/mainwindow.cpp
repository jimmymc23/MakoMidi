#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "build/Desktop-Release/MakoM1-MidiControl_autogen/include/ui_mainwindow.h"

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
        midiOut->openVirtualPort("Mako M1 Output");

        std::cout << "Opened virtual MIDI port: MakoM1-MidiControl MIDI Output" << std::endl;
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
    connect(ui->TypecomboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_TypeChanged);
    connect(ui->ShapecomboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_ShapeChanged);
    connect(ui->DivisioncomboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_DivisionChanged);
    connect(ui->RotarySpeedcomboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_RotarySpeedhanged);

    connect(ui->presetDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_presetDialChanged);

    connect(ui->rateDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_rateDialChanged);
    connect(ui->depthDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_depthDialChanged);
    connect(ui->lofiDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_lofiDialChanged);
    connect(ui->toneDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_toneDialChanged);
    connect(ui->symDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_symDialChanged);
    connect(ui->xDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_xDialChanged);
    connect(ui->envDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_envDialChanged);
    connect(ui->driveDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_driveDialChanged);
    connect(ui->spaceDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_spaceDialChanged);
    connect(ui->ageDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_ageDialChanged);
    connect(ui->noiseDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_noiseDialChanged);
    connect(ui->warbleDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_warbleDialChanged);


    connect(ui->volumeDial, QOverload<int>::of(&QDial::valueChanged), this, &MainWindow::on_volumeDialChanged);



    // Set defaults
    ui->TypecomboBox->addItem("Traditional Chorus");
    ui->TypecomboBox->addItem("Series Chorus");
    ui->TypecomboBox->addItem("Flanger");

    SkipEngageToggleState = false;  // Set to "Off" initially
    ui->TapSkippushButton->setCheckable(true);  // Ensure the button is checkable
    ui->TapSkippushButton->setChecked(SkipEngageToggleState);
    ui->TapSkippushButton->setText("Disenaged");  // Set initial label text

    ui->ShapecomboBox->hide();
    ui->RotarySpeedcomboBox->hide();
    ui->RotarySpeedLabel->hide();


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
    json["type"] = ui->TypecomboBox->currentIndex();

    json["Shape"] = ui->ShapecomboBox->currentIndex();
    json["Division"] = ui->DivisioncomboBox->currentIndex();
    json["RotarySpeed"] = ui->RotarySpeedcomboBox->currentIndex();

    json["rateDial"] = ui->rateDial->value();
    json["depthDial"] = ui->depthDial->value();
    json["lofiDial"] = ui->lofiDial->value();
    json["toneDial"] = ui->toneDial->value();
    json["symDial"] = ui->symDial->value();
    json["xDial"] = ui->xDial->value();
    json["envDial"] = ui->envDial->value();
    json["driveDial"] = ui->driveDial->value();
    json["spaceDial"] = ui->spaceDial->value();
    json["ageDial"] = ui->ageDial->value();
    json["noiseDial"] = ui->noiseDial->value();
    json["volumeDial"] = ui->volumeDial->value();
    json["warbleDial"] = ui->warbleDial->value();


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

    if (json.contains("Type") && json["Type"].isDouble()) {
        ui->TypecomboBox->setCurrentIndex(json["Type"].toInt());
    }

    if (json.contains("Division") && json["Division"].isDouble()) {
        ui->DivisioncomboBox->setCurrentIndex(json["Division"].toInt());
    }

    if (json.contains("RotarySpeed") && json["RotarySpeed"].isDouble()) {
        ui->RotarySpeedcomboBox->setCurrentIndex(json["RotarySpeed"].toInt());
    }


    if (json.contains("rateDial") && json["rateDial"].isDouble()) {
        ui->rateDial->setValue(json["rateDial"].toInt());
    }

    if (json.contains("depthDial") && json["depthDial"].isDouble()) {
        ui->depthDial->setValue(json["depthDial"].toInt());
    }

    if (json.contains("lofiDial") && json["lofiDial"].isDouble()) {
        ui->lofiDial->setValue(json["lofiDial"].toInt());
    }

    if (json.contains("toneDial") && json["toneDial"].isDouble()) {
        ui->toneDial->setValue(json["toneDial"].toInt());
    }

    if (json.contains("symDial") && json["symDial"].isDouble()) {
        ui->symDial->setValue(json["symDial"].toInt());
    }

    if (json.contains("xDial") && json["xDial"].isDouble()) {
        ui->xDial->setValue(json["xDial"].toInt());
    }

    if (json.contains("envDial") && json["envDial"].isDouble()) {
        ui->envDial->setValue(json["envDial"].toInt());
    }

    if (json.contains("driveDial") && json["driveDial"].isDouble()) {
        ui->driveDial->setValue(json["driveDial"].toInt());
    }

    if (json.contains("spaceDial") && json["spaceDial"].isDouble()) {
        ui->spaceDial->setValue(json["spaceDial"].toInt());
    }

    if (json.contains("ageDial") && json["ageDial"].isDouble()) {
        ui->ageDial->setValue(json["ageDial"].toInt());
    }

    if (json.contains("noiseDial") && json["noiseDial"].isDouble()) {
        ui->noiseDial->setValue(json["noiseDial"].toInt());
    }

    if (json.contains("volumeDial") && json["volumeDial"].isDouble()) {
        ui->volumeDial->setValue(json["volumeDial"].toInt());
    }

    if (json.contains("warbleDial") && json["warbleDial"].isDouble()) {
        ui->warbleDial->setValue(json["warbleDial"].toInt());
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

         ui->TypecomboBox->clear();
        if (index == 0){ // Chorus
            ui->TypecomboBox->addItem("Traditional Chorus");
            ui->TypecomboBox->addItem("Tri-Chorus");
            ui->TypecomboBox->addItem("Flanger");

            ui->ShapecomboBox->hide();
            ui->RotarySpeedcomboBox->hide();
            ui->RotarySpeedLabel->hide();
        }else if (index == 1) { // Phaser
            ui->TypecomboBox->addItem("2 Stage");
            ui->TypecomboBox->addItem("4 Stage");
            ui->TypecomboBox->addItem("Univibe Tuned");

            ui->ShapecomboBox->hide();
            ui->RotarySpeedcomboBox->hide();
            ui->RotarySpeedLabel->hide();

        }else if (index == 2) { // Tremolo
            ui->TypecomboBox->addItem("Traditional");
            ui->TypecomboBox->addItem("Harmonic");
            ui->TypecomboBox->addItem("Pattern");

            // Add Shape Options; Patterns 1 -3
            ui->ShapecomboBox->clear();
            ui->ShapecomboBox->addItem("Pattern 1");
            ui->ShapecomboBox->addItem("Pattern 2");
            ui->ShapecomboBox->addItem("Pattern 3");
            ui->ShapecomboBox->show();

            ui->RotarySpeedcomboBox->hide();
            ui->RotarySpeedLabel->hide();

        }else if (index == 3) { // Vibrato
            ui->TypecomboBox->addItem("Traditional");
            ui->TypecomboBox->addItem("Vinyl");
            ui->TypecomboBox->addItem("Tape");

            ui->ShapecomboBox->clear();
            ui->ShapecomboBox->addItem("Vinyl");
            ui->ShapecomboBox->addItem("Tape");
            ui->ShapecomboBox->show();

            ui->RotarySpeedcomboBox->hide();
            ui->RotarySpeedLabel->hide();

        }else if (index == 4) { // Rotary
            ui->TypecomboBox->addItem("Horn + Drum");
            ui->TypecomboBox->addItem("Horn Only");
            ui->TypecomboBox->addItem("Drum Only");

            ui->ShapecomboBox->hide();
            ui->RotarySpeedcomboBox->show();
            ui->RotarySpeedLabel->show();

        }else if (index == 5) { // Filter
            ui->TypecomboBox->addItem("Lowpass");
            ui->TypecomboBox->addItem("Highpass");
            ui->TypecomboBox->addItem("Bandpass");

            ui->ShapecomboBox->hide();
            ui->RotarySpeedcomboBox->hide();
            ui->RotarySpeedLabel->hide();
        }
        //on_TypeChanged(0);
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_TapSkippushButton_clicked(){

    // Toggle the state using the checked property of the button
    SkipEngageToggleState = ui->TapSkippushButton->isChecked();

    // Update button text to indicate current state
    if (SkipEngageToggleState) {
        ui->TapSkippushButton->setText("Engaged");
    } else {
        ui->TapSkippushButton->setText("Disenaged");
    }

    // Prepare the MIDI message for CC#9
    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(87);                   // Control Change #9 (Tuner Toggle)
    message.push_back(SkipEngageToggleState ? 127 : 0); // Value = 127 (On) or 0 (Off)

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Skip Engage / Rotary Break: " << (SkipEngageToggleState ? "On" : "Off") << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_TappushButton_clicked(){

    // Prepare the MIDI message for CC#9
    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(85);                   // Control Change #9 (Tuner Toggle)
    message.push_back(127); // Value = 127 (On) or 0 (Off)

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Tap Sent" << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}


void MainWindow::on_TypeChanged(int index)
{
    if (index == -1){index = 0;};

    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(17);                  //
    message.push_back(index);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Type changed to: " << index << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

    void MainWindow::on_RotarySpeedhanged(int index)
{
    int value;

    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(86);                  //
    message.push_back(index);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Rotary Speed changed to: " << index << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_ShapeChanged(int index)
{
    int value;

    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(15);                  //
    message.push_back(index);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Shape changed to: " << index << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_DivisionChanged(int index)
{
    int value;

    std::vector<unsigned char> message;
    message.push_back(0xB0 + midiChannel);  // Control Change message, channel
    message.push_back(16);                  //
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
    message.push_back(31);                  // Control Change #12 (Preset Toggle)
    message.push_back(bypassToggleState ? 127 : 0); // Value = 127 (On) or 0 (Off)

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "CC31 Bypass: " << (bypassToggleState ? "On" : "Off") << std::endl;
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

void MainWindow::on_rateDialChanged(int value)
{

    // Update the preset bank
    value = ui->rateDial->value();
    std::cout << "Rate set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
     message.push_back(3);
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
    message.push_back(9);
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

void MainWindow::on_lofiDialChanged(int value)
{

    // Update the preset bank
    value = ui->lofiDial->value();
    std::cout << "Lo-Fi set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(14);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Lo-Fi set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_toneDialChanged(int value)
{

    // Update the preset bank
    value = ui->toneDial->value();
    std::cout << "Tone set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(19);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Tone set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_symDialChanged(int value)
{

    // Update the preset bank
    value = ui->symDial->value();
    std::cout << "Sym set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(20);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Sym set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_xDialChanged(int value)
{
    // Update the preset bank
    value = ui->xDial->value();
    std::cout << "X set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(21);
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


void MainWindow::on_envDialChanged(int value)
{
    // Update the preset bank
    value = ui->envDial->value();
    std::cout << "Env set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(22);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Env set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}


void MainWindow::on_driveDialChanged(int value)
{
    // Update the preset bank
    value = ui->driveDial->value();
    std::cout << "Drive set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(23);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Drive set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_spaceDialChanged(int value)
{
    // Update the preset bank
    value = ui->spaceDial->value();
    std::cout << "Space set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(24);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Space set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_ageDialChanged(int value)
{
    // Update the preset bank
    value = ui->ageDial->value();
    std::cout << "Age set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(25);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Age set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_noiseDialChanged(int value)
{
    // Update the preset bank
    value = ui->noiseDial->value();
    std::cout << "Noise set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(26);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Noise set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_warbleDialChanged(int value)
{
    // Update the preset bank
    value = ui->warbleDial->value();
    std::cout << "Warble Dial set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(27);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Warble set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}

void MainWindow::on_volumeDialChanged(int value)
{
    // Update the preset bank
    value = ui->volumeDial->value();
    std::cout << "Output volume set to: " << value << std::endl;

    // Prepare the MIDI message
    std::vector<unsigned char> message;

    message.push_back(0xB0 + midiChannel);  // Program Change message, channel
    message.push_back(88);
    message.push_back(value);       // Program number (0-127)
    midiOut->sendMessage(&message);

    // Send the MIDI message
    if (midiOut && midiOut->isPortOpen()) {
        midiOut->sendMessage(&message);
        std::cout << "Output volume set to: " << value << std::endl;
    } else {
        std::cerr << "MIDI port is not open." << std::endl;
    }
}
