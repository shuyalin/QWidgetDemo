#include "widget.h"
#include "ui_widget.h"
#include "savelog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    SaveLog::getInstance()->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    static int cnt = 0;
    cnt++;
    QString msg = "liuyifei";
    //QByteArray buffer = msg.toUtf8();
    //const char *data = buffer.constData();
    //msg << cnt;
    qDebug()<<msg<<" : "<<cnt;
}
