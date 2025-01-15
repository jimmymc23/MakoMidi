/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *openMidiPortButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *midiChannelSpinBox;
    QPlainTextEdit *descriptionText;
    QFrame *line;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QLabel *fileNameLabel;
    QFrame *line_2;
    QComboBox *ProgramcomboBox;
    QLabel *label_2;
    QPushButton *presetToggleButton;
    QDial *presetDial;
    QLCDNumber *presetlcd;
    QDial *rateDial;
    QDial *symDial;
    QDial *lofiDial;
    QDial *spaceDial;
    QDial *depthDial;
    QDial *toneDial;
    QDial *driveDial;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *midiDevicecomboBox;
    QPushButton *presetUpButton;
    QPushButton *presetDownButton;
    QDial *envDial;
    QLabel *label_11;
    QLabel *label_12;
    QDial *xDial;
    QLabel *label_10;
    QDial *ageDial;
    QDial *noiseDial;
    QLabel *label_13;
    QLabel *label_14;
    QDial *warbleDial;
    QComboBox *TypecomboBox;
    QLabel *label_15;
    QComboBox *ShapecomboBox;
    QLabel *label_16;
    QComboBox *DivisioncomboBox;
    QLabel *label_17;
    QPushButton *TapSkippushButton;
    QLabel *label_18;
    QPushButton *TappushButton;
    QComboBox *RotarySpeedcomboBox;
    QLabel *RotarySpeedLabel;
    QDial *volumeDial;
    QLabel *label_19;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(976, 704);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openMidiPortButton = new QPushButton(centralwidget);
        openMidiPortButton->setObjectName(QString::fromUtf8("openMidiPortButton"));
        openMidiPortButton->setGeometry(QRect(872, 90, 80, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(762, 90, 97, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        midiChannelSpinBox = new QSpinBox(layoutWidget);
        midiChannelSpinBox->setObjectName(QString::fromUtf8("midiChannelSpinBox"));
        midiChannelSpinBox->setMaximum(15);
        midiChannelSpinBox->setValue(6);

        horizontalLayout->addWidget(midiChannelSpinBox);

        descriptionText = new QPlainTextEdit(centralwidget);
        descriptionText->setObjectName(QString::fromUtf8("descriptionText"));
        descriptionText->setGeometry(QRect(20, 40, 481, 31));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 80, 940, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(20, 10, 80, 23));
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(110, 10, 80, 23));
        fileNameLabel = new QLabel(centralwidget);
        fileNameLabel->setObjectName(QString::fromUtf8("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(210, 12, 561, 16));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 120, 941, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        ProgramcomboBox = new QComboBox(centralwidget);
        ProgramcomboBox->addItem(QString());
        ProgramcomboBox->addItem(QString());
        ProgramcomboBox->addItem(QString());
        ProgramcomboBox->addItem(QString());
        ProgramcomboBox->addItem(QString());
        ProgramcomboBox->addItem(QString());
        ProgramcomboBox->setObjectName(QString::fromUtf8("ProgramcomboBox"));
        ProgramcomboBox->setGeometry(QRect(110, 420, 171, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 420, 71, 21));
        presetToggleButton = new QPushButton(centralwidget);
        presetToggleButton->setObjectName(QString::fromUtf8("presetToggleButton"));
        presetToggleButton->setGeometry(QRect(40, 80, 221, 50));
        QPalette palette;
        QBrush brush(QColor(224, 27, 36, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        QBrush brush1(QColor(239, 239, 239, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 0, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush2);
        QBrush brush3(QColor(153, 193, 241, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush2);
        presetToggleButton->setPalette(palette);
        presetToggleButton->setCheckable(true);
        presetDial = new QDial(centralwidget);
        presetDial->setObjectName(QString::fromUtf8("presetDial"));
        presetDial->setGeometry(QRect(-10, 140, 261, 201));
        presetDial->setMaximum(127);
        presetlcd = new QLCDNumber(centralwidget);
        presetlcd->setObjectName(QString::fromUtf8("presetlcd"));
        presetlcd->setGeometry(QRect(40, 330, 161, 51));
        presetlcd->setLayoutDirection(Qt::LeftToRight);
        rateDial = new QDial(centralwidget);
        rateDial->setObjectName(QString::fromUtf8("rateDial"));
        rateDial->setGeometry(QRect(320, 150, 121, 101));
        rateDial->setLayoutDirection(Qt::LeftToRight);
        rateDial->setMaximum(127);
        rateDial->setValue(64);
        rateDial->setInvertedAppearance(true);
        rateDial->setInvertedControls(true);
        symDial = new QDial(centralwidget);
        symDial->setObjectName(QString::fromUtf8("symDial"));
        symDial->setGeometry(QRect(480, 280, 121, 101));
        symDial->setMaximum(127);
        symDial->setValue(64);
        lofiDial = new QDial(centralwidget);
        lofiDial->setObjectName(QString::fromUtf8("lofiDial"));
        lofiDial->setGeometry(QRect(640, 150, 121, 101));
        lofiDial->setMinimum(0);
        lofiDial->setMaximum(127);
        lofiDial->setValue(64);
        spaceDial = new QDial(centralwidget);
        spaceDial->setObjectName(QString::fromUtf8("spaceDial"));
        spaceDial->setGeometry(QRect(320, 400, 121, 101));
        spaceDial->setMaximum(127);
        spaceDial->setValue(64);
        depthDial = new QDial(centralwidget);
        depthDial->setObjectName(QString::fromUtf8("depthDial"));
        depthDial->setGeometry(QRect(480, 150, 121, 101));
        depthDial->setMaximum(127);
        depthDial->setValue(64);
        toneDial = new QDial(centralwidget);
        toneDial->setObjectName(QString::fromUtf8("toneDial"));
        toneDial->setGeometry(QRect(320, 280, 121, 101));
        toneDial->setMaximum(127);
        toneDial->setValue(64);
        driveDial = new QDial(centralwidget);
        driveDial->setObjectName(QString::fromUtf8("driveDial"));
        driveDial->setGeometry(QRect(640, 400, 121, 101));
        driveDial->setMaximum(127);
        driveDial->setValue(64);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 240, 81, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 370, 81, 20));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(660, 240, 81, 20));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 370, 81, 20));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 240, 81, 20));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(340, 490, 81, 20));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(660, 490, 81, 20));
        label_9->setAlignment(Qt::AlignCenter);
        midiDevicecomboBox = new QComboBox(centralwidget);
        midiDevicecomboBox->setObjectName(QString::fromUtf8("midiDevicecomboBox"));
        midiDevicecomboBox->setGeometry(QRect(520, 90, 221, 23));
        presetUpButton = new QPushButton(centralwidget);
        presetUpButton->setObjectName(QString::fromUtf8("presetUpButton"));
        presetUpButton->setGeometry(QRect(230, 190, 31, 51));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("go-up");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        presetUpButton->setIcon(icon);
        presetDownButton = new QPushButton(centralwidget);
        presetDownButton->setObjectName(QString::fromUtf8("presetDownButton"));
        presetDownButton->setGeometry(QRect(230, 260, 31, 51));
        presetDownButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        iconThemeName = QString::fromUtf8("go-down");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        presetDownButton->setIcon(icon1);
        envDial = new QDial(centralwidget);
        envDial->setObjectName(QString::fromUtf8("envDial"));
        envDial->setGeometry(QRect(480, 400, 121, 101));
        envDial->setMaximum(127);
        envDial->setValue(64);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(500, 490, 81, 20));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(660, 370, 81, 20));
        label_12->setAlignment(Qt::AlignCenter);
        xDial = new QDial(centralwidget);
        xDial->setObjectName(QString::fromUtf8("xDial"));
        xDial->setGeometry(QRect(640, 280, 121, 101));
        xDial->setMaximum(127);
        xDial->setValue(64);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(340, 620, 81, 20));
        label_10->setAlignment(Qt::AlignCenter);
        ageDial = new QDial(centralwidget);
        ageDial->setObjectName(QString::fromUtf8("ageDial"));
        ageDial->setGeometry(QRect(320, 530, 121, 101));
        ageDial->setMaximum(4);
        ageDial->setValue(2);
        ageDial->setSliderPosition(2);
        ageDial->setNotchTarget(1.000000000000000);
        ageDial->setNotchesVisible(true);
        noiseDial = new QDial(centralwidget);
        noiseDial->setObjectName(QString::fromUtf8("noiseDial"));
        noiseDial->setGeometry(QRect(480, 530, 121, 101));
        noiseDial->setMaximum(127);
        noiseDial->setValue(64);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(500, 620, 81, 20));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(660, 620, 81, 20));
        label_14->setAlignment(Qt::AlignCenter);
        warbleDial = new QDial(centralwidget);
        warbleDial->setObjectName(QString::fromUtf8("warbleDial"));
        warbleDial->setGeometry(QRect(640, 530, 121, 101));
        warbleDial->setMaximum(127);
        warbleDial->setValue(64);
        TypecomboBox = new QComboBox(centralwidget);
        TypecomboBox->setObjectName(QString::fromUtf8("TypecomboBox"));
        TypecomboBox->setGeometry(QRect(110, 450, 171, 23));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 450, 71, 21));
        ShapecomboBox = new QComboBox(centralwidget);
        ShapecomboBox->addItem(QString());
        ShapecomboBox->addItem(QString());
        ShapecomboBox->setObjectName(QString::fromUtf8("ShapecomboBox"));
        ShapecomboBox->setGeometry(QRect(110, 480, 171, 23));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(40, 480, 71, 20));
        DivisioncomboBox = new QComboBox(centralwidget);
        DivisioncomboBox->addItem(QString());
        DivisioncomboBox->addItem(QString());
        DivisioncomboBox->addItem(QString());
        DivisioncomboBox->setObjectName(QString::fromUtf8("DivisioncomboBox"));
        DivisioncomboBox->setGeometry(QRect(110, 510, 171, 23));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(40, 510, 71, 20));
        label_17->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        TapSkippushButton = new QPushButton(centralwidget);
        TapSkippushButton->setObjectName(QString::fromUtf8("TapSkippushButton"));
        TapSkippushButton->setGeometry(QRect(770, 510, 171, 41));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(770, 490, 170, 21));
        label_18->setWordWrap(true);
        TappushButton = new QPushButton(centralwidget);
        TappushButton->setObjectName(QString::fromUtf8("TappushButton"));
        TappushButton->setGeometry(QRect(770, 580, 171, 51));
        RotarySpeedcomboBox = new QComboBox(centralwidget);
        RotarySpeedcomboBox->addItem(QString());
        RotarySpeedcomboBox->addItem(QString());
        RotarySpeedcomboBox->setObjectName(QString::fromUtf8("RotarySpeedcomboBox"));
        RotarySpeedcomboBox->setGeometry(QRect(110, 560, 171, 23));
        RotarySpeedLabel = new QLabel(centralwidget);
        RotarySpeedLabel->setObjectName(QString::fromUtf8("RotarySpeedLabel"));
        RotarySpeedLabel->setGeometry(QRect(27, 560, 81, 21));
        volumeDial = new QDial(centralwidget);
        volumeDial->setObjectName(QString::fromUtf8("volumeDial"));
        volumeDial->setGeometry(QRect(780, 260, 141, 141));
        volumeDial->setMaximum(127);
        volumeDial->setValue(64);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(820, 390, 61, 20));
        label_19->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 976, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mako M1 - MidiControl", nullptr));
        openMidiPortButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "channel", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        fileNameLabel->setText(QCoreApplication::translate("MainWindow", "Filename", nullptr));
        ProgramcomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Chorus", nullptr));
        ProgramcomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Phaser", nullptr));
        ProgramcomboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Temolo", nullptr));
        ProgramcomboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Vibrato", nullptr));
        ProgramcomboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Rotary", nullptr));
        ProgramcomboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Filter", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Program", nullptr));
        presetToggleButton->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Rate", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Sym", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Lo-Fi", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Tone", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Depth", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Space", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Drive", nullptr));
        presetUpButton->setText(QString());
        presetDownButton->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Env", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Noise", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Warble", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        ShapecomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Vinyl", nullptr));
        ShapecomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Tape", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "Shape", nullptr));
        DivisioncomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Quarter", nullptr));
        DivisioncomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Quarter Note Triplet", nullptr));
        DivisioncomboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Eighth", nullptr));

        label_17->setText(QCoreApplication::translate("MainWindow", "Division", nullptr));
        TapSkippushButton->setText(QCoreApplication::translate("MainWindow", "Skip Engage / Rotary Break", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Skip Engage / Rotary Break", nullptr));
        TappushButton->setText(QCoreApplication::translate("MainWindow", "Tap", nullptr));
        RotarySpeedcomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Slow", nullptr));
        RotarySpeedcomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Fast", nullptr));

        RotarySpeedLabel->setText(QCoreApplication::translate("MainWindow", "Rotary Speed", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Volume", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
