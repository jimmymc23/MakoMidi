#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <RtMidi.h>  // Include the RtMidi library

// Save load includes:
#include <QComboBox>
#include <QDial>
#include <QPushButton>
#include <QTextEdit>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
// End Save load includes

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  // Make sure this is here

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void connect_midi();
    void on_openMidiPortButton_clicked();
    void on_midiChannelChanged(int channel);

    // Save load
    void on_saveButton_clicked();
    void on_loadButton_clicked();
    // end Save Load

    //ProgramcomboBox
    void on_ProgramChanged(int index);

    // Division DivsioncomboBox
    void on_DivisionChanged(int index);

    void on_presetToggleButton_clicked();
    // PresetDial
    void on_presetDialChanged(int value);
    //void on_presetUpButtonChanged();
    void on_presetDownButton_clicked();
    void on_presetUpButton_clicked();


    void on_decayDialChanged(int value);
    void on_swellDialChanged(int value);
    void on_mixDialChanged(int value);
    void on_rateDialChanged(int value);
    void on_depthDialChanged(int value);
    void on_preDelayDialChanged(int value);
    void on_loDialChanged(int value);
    void on_highDialChanged(int value);
    void on_xDialChanged(int value);


private:
    Ui::MainWindow *ui;
    RtMidiOut *midiOut;
    int midiChannel;
    int midiBank;

    // Save load
    QTextEdit descriptionText;
    QString fileNameLabel;
    // end Save Load

    bool bypassToggleState;
};

#endif // MAINWINDOW_H
