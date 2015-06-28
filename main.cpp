#include "start.h"
#include <QApplication>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    start w;
    w.show();

    return a.exec();
}
