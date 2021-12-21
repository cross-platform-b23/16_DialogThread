#include "dialogthread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogThread w;
    w.show();
    return a.exec();
}
