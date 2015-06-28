#include "start.h"
#include "mainwindow.h"
#include <QApplication>
#include "time.h"
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.GameStart();
    return a.exec();
}
