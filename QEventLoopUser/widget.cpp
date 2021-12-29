#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

//实现目标：按下A按键十秒后打印AAAAAAA，且该十秒内不影响B按键的使用，
//B按键按下打印BBBBBBB，如果采用A按键槽函数里sleep10秒会导致B按键无法响应，
//而采用QEventLoop则不会。QEventLoop是一种局部的事件循环，不会卡主主界面。

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnA_clicked()
{
    QEventLoop loop;
    QTimer::singleShot(10*1000,&loop,SLOT(quit()));
    loop.exec();
    qDebug()<<"AAAAAAAAAAAAAAAAAAA";
}

void Widget::on_btnB_clicked()
{
    qDebug()<<"BBBBBBBBBBBBBBBBBBB";
}
