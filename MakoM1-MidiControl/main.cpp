#include "mainwindow.h"

// Save / Load
//#include "mainwindow.moc"
// END Save / Load

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
