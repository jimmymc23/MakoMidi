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
    QDial *timeDial;
    QDial *repeatsDial;
    QDial *mixDial;
    QDial *ageDial;
    QDial *toneDial;
    QDial *modDial;
    QDial *attackDial;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *DivsioncomboBox;
    QLabel *label_10;
    QComboBox *midiDevicecomboBox;
    QPushButton *presetUpButton;
    QPushButton *presetDownButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 565);
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
        midiChannelSpinBox->setValue(4);

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
        timeDial = new QDial(centralwidget);
        timeDial->setObjectName(QString::fromUtf8("timeDial"));
        timeDial->setGeometry(QRect(320, 150, 121, 101));
        timeDial->setLayoutDirection(Qt::LeftToRight);
        timeDial->setMaximum(127);
        timeDial->setValue(64);
        timeDial->setInvertedAppearance(true);
        timeDial->setInvertedControls(true);
        repeatsDial = new QDial(centralwidget);
        repeatsDial->setObjectName(QString::fromUtf8("repeatsDial"));
        repeatsDial->setGeometry(QRect(480, 150, 121, 101));
        repeatsDial->setMaximum(127);
        repeatsDial->setValue(64);
        mixDial = new QDial(centralwidget);
        mixDial->setObjectName(QString::fromUtf8("mixDial"));
        mixDial->setGeometry(QRect(640, 150, 121, 101));
        mixDial->setMinimum(0);
        mixDial->setMaximum(127);
        mixDial->setValue(64);
        ageDial = new QDial(centralwidget);
        ageDial->setObjectName(QString::fromUtf8("ageDial"));
        ageDial->setGeometry(QRect(640, 280, 121, 101));
        ageDial->setMaximum(127);
        ageDial->setValue(64);
        toneDial = new QDial(centralwidget);
        toneDial->setObjectName(QString::fromUtf8("toneDial"));
        toneDial->setGeometry(QRect(480, 280, 121, 101));
        toneDial->setMaximum(127);
        toneDial->setValue(64);
        modDial = new QDial(centralwidget);
        modDial->setObjectName(QString::fromUtf8("modDial"));
        modDial->setGeometry(QRect(320, 280, 121, 101));
        modDial->setMaximum(127);
        modDial->setValue(64);
        attackDial = new QDial(centralwidget);
        attackDial->setObjectName(QString::fromUtf8("attackDial"));
        attackDial->setGeometry(QRect(480, 410, 121, 101));
        attackDial->setMaximum(127);
        attackDial->setValue(64);
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
        DivsioncomboBox = new QComboBox(centralwidget);
        DivsioncomboBox->addItem(QString());
        DivsioncomboBox->addItem(QString());
        DivsioncomboBox->addItem(QString());
        DivsioncomboBox->setObjectName(QString::fromUtf8("DivsioncomboBox"));
        DivsioncomboBox->setGeometry(QRect(131, 446, 101, 23));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 450, 71, 16));
        midiDevicecomboBox = new QComboBox(centralwidget);
        midiDevicecomboBox->setObjectName(QString::fromUtf8("midiDevicecomboBox"));
        midiDevicecomboBox->setGeometry(QRect(328, 90, 221, 23));
        presetUpButton = new QPushButton(centralwidget);
        presetUpButton->setObjectName(QString::fromUtf8("presetUpButton"));
        presetUpButton->setGeometry(QRect(230, 190, 31, 51));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("go-up")));
        presetUpButton->setIcon(icon);
        presetDownButton = new QPushButton(centralwidget);
        presetDownButton->setObjectName(QString::fromUtf8("presetDownButton"));
        presetDownButton->setGeometry(QRect(230, 260, 31, 51));
        presetDownButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("go-down")));
        presetDownButton->setIcon(icon1);
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mako D1 - MidiControl", nullptr));
        openMidiPortButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "channel", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        fileNameLabel->setText(QCoreApplication::translate("MainWindow", "Filename", nullptr));
        ProgramcomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Digital", nullptr));
        ProgramcomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Mod", nullptr));
        ProgramcomboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Vintage", nullptr));
        ProgramcomboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Dual", nullptr));
        ProgramcomboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Reverse", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Delay Type", nullptr));
        presetToggleButton->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Repeats", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Mix", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Mod", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Tone", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Attack", nullptr));
        DivsioncomboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Quarter", nullptr));
        DivsioncomboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Eighth", nullptr));
        DivsioncomboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Dotted Eighth", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "Division", nullptr));
        presetUpButton->setText(QString());
        presetDownButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
