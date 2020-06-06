#include "airplane.h"
#include <QMainWindow>
#include <QPainter>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Airplane w;
    w.show();
    return a.exec();
}

