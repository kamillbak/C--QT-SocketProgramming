#include "chartclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChartClass w;
    w.show();
    return a.exec();
}
