#include "widget.h"
#include <QApplication>
#include "myhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<"ssssssssssss";
    myHelper::setStyle(":/images/images/css/black.css");
    Widget w;
    w.show();

    return a.exec();
}
