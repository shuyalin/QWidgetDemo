#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <unistd.h>

Test::Test()
{

}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    test = new Test;
    connect(test,SIGNAL(signalOne(const QString&)),this,SLOT(showString(const QString&)));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::showString(const QString &str)
{
    qDebug()<<"eeeeeeeee "<<str;
    ui->label->setText(str);
    usleep(3000*1000);
}

void Widget::on_pushButton_clicked()
{
    QMetaObject::invokeMethod(test,"signalOne",Qt::QueuedConnection,Q_ARG(const QString &,QString("shuyalin")));
    qDebug()<<"2222222222222222222";
}

void Widget::on_pushButton_2_clicked()
{
    QMetaObject::invokeMethod(test,"signalOne",Qt::DirectConnection,Q_ARG(const QString &,QString("shuyalin")));
    qDebug()<<"2222222222222222222";
}
