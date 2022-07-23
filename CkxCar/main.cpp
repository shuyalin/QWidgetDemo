#include <QApplication>
#include "formmainpage.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormMainPage w;
    w.show();

    return a.exec();
}
