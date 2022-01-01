#include "widget.h"
#include "ui_widget.h"

#include "itemStyle/radiobuttonstyle.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    radioButtonStyle *radio = new radioButtonStyle;
    ui->stackedWidget->addWidget(radio);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnRadio_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
