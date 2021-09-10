#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile file(":/css/mystyle.qss");
    file.open(QFile::ReadOnly);
    QString css = QLatin1String( file.readAll());
    qApp->setStyleSheet(css);

    Widget w;
    w.show();

    return a.exec();
}
