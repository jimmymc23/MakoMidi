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
    QDial *decayDial;
    QDial *swellDial;
    QDial *mixDial;
    QDial *preDelayDial;
    QDial *depthDial;
    QDial *rateDial;
    QDial *highDial;
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
    QDial *loDial;
    QLabel *label_11;
    QLabel *label_12;
    QDial *xDial;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 576);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openMidiPortButton = new QPushButton(centralwidget);
        openMidiPortButton->setObjectName(QString::fromUtf8("openMidiPortButton"));
        openMidiPortButton->setGeometry(QRect(680, 90, 80, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(570, 90, 97, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        midiChannelSpinBox = new QSpinBox(layoutWidget);
        midiChannelSpinBox->setObjectName(QString::fromUtf8("midiChannelSpinBox"));
        midiChannelSpinBox->setMaximum(15);
        midiChannelSpinBox->setValue(3);

        horizontalLayout->addWidget(midiChannelSpinBox);

        descriptionText = new QPlainTextEdit(centralwidget);
        descriptionText->setObjectName(QString::fromUtf8("descriptionText"));
        descriptionText->setGeometry(QRect(20, 40, 481, 31));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 80, 760, 3));
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
        line_2->setGeometry(QRect(20, 120, 760, 3));
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
        ProgramcomboBox->setGeometry(QRect(131, 416, 101, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 420, 71, 16));
        presetToggleButton = new QPushButton(centralwidget);
        presetToggleButton->setObjectName(QString::fromUtf8("presetToggleButton"));
        presetToggleButton->setGeometry(QRect(40, 80, 221, 40));
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
        presetlcd->setGeometry(QRect(100, 330, 101, 51));
        decayDial = new QDial(centralwidget);
        decayDial->setObjectName(QString::fromUtf8("decayDial"));
        decayDial->setGeometry(QRect(320, 150, 121, 101));
        decayDial->setLayoutDirection(Qt::LeftToRight);
        decayDial->setMaximum(127);
        decayDial->setValue(64);
        decayDial->setInvertedAppearance(true);
        decayDial->setInvertedControls(true);
        swellDial = new QDial(centralwidget);
        swellDial->setObjectName(QString::fromUtf8("swellDial"));
        swellDial->setGeometry(QRect(480, 150, 121, 101));
        swellDial->setMaximum(127);
        swellDial->setValue(64);
        mixDial = new QDial(centralwidget);
        mixDial->setObjectName(QString::fromUtf8("mixDial"));
        mixDial->setGeometry(QRect(640, 150, 121, 101));
        mixDial->setMinimum(0);
        mixDial->setMaximum(127);
        mixDial->setValue(64);
        preDelayDial = new QDial(centralwidget);
        preDelayDial->setObjectName(QString::fromUtf8("preDelayDial"));
        preDelayDial->setGeometry(QRect(640, 280, 121, 101));
        preDelayDial->setMaximum(127);
        preDelayDial->setValue(64);
        depthDial = new QDial(centralwidget);
        depthDial->setObjectName(QString::fromUtf8("depthDial"));
        depthDial->setGeometry(QRect(480, 280, 121, 101));
        depthDial->setMaximum(127);
        depthDial->setValue(64);
        rateDial = new QDial(centralwidget);
        rateDial->setObjectName(QString::fromUtf8("rateDial"));
        rateDial->setGeometry(QRect(320, 280, 121, 101));
        rateDial->setMaximum(127);
        rateDial->setValue(64);
        highDial = new QDial(centralwidget);
        highDial->setObjectName(QString::fromUtf8("highDial"));
        highDial->setGeometry(QRect(480, 410, 121, 101));
        highDial->setMaximum(127);
        highDial->setValue(64);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 240, 81, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 240, 81, 20));
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
        label_7->setGeometry(QRect(500, 370, 81, 20));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(660, 370, 81, 20));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(500, 500, 81, 20));
        label_9->setAlignment(Qt::AlignCenter);
        midiDevicecomboBox = new QComboBox(centralwidget);
        midiDevicecomboBox->setObjectName(QString::fromUtf8("midiDevicecomboBox"));
        midiDevicecomboBox->setGeometry(QRect(328, 90, 221, 23));
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
        loDial = new QDial(centralwidget);
        loDial->setObjectName(QString::fromUtf8("loDial"));
        loDial->setGeometry(QRect(320, 410, 121, 101));
        loDial->setMaximum(127);
        loDial->setValue(64);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(340, 500, 81, 20));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(660, 500, 81, 20));
        label_12->setAlignment(Qt::AlignCenter);
        xDial = new QDial(centralwidget);
        xDial->setObjectName(QString::fromUtf8("xDial"));
        xDial->setGeometry(QRect(640, 410, 121, 101));
        xDial->setMaximum(127);
        xDial->setValue(64);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mako R1 - MidiControl", nullptr));
        openMidiPortButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "channel", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        fileNameLabel->setText(QCoreApplication::translate("MainWindow", "Filename", nullptr));
        ProgramcomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Spring", nullptr));
        ProgramcomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Hall", nullptr));
        ProgramcomboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Plate", nullptr));
        ProgramcomboBox->setItemText(3, QCoreApplication::translate("MainWindow", "BFR", nullptr));
        ProgramcomboBox->setItemText(4, QCoreApplication::translate("MainWindow", "RFRCT", nullptr));
        ProgramcomboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Air", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Program", nullptr));
        presetToggleButton->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Decay", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Swell", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mix", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Rate", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Depth", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Pre Delay", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "High", nullptr));
        presetUpButton->setText(QString());
        presetDownButton->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Lo", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
