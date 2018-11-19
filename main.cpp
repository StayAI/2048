#include "widget.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    static int i=0;
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("2048");
    w.setFixedSize(330,430);

    w.show();

    return a.exec();
}
