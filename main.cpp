#include "mainwindow.h"

#include <QApplication>
#include "semicl6.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    semicl6Initialize();
    semicl6();
    return a.exec();
}
