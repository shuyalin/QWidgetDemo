#include "widget.h"
#include "ui_widget.h"
#include "form.h"
#include "testwidget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QListWidgetItem *item = new QListWidgetItem(ui->listWidget,0);
    item->setSizeHint(QSize(782,96));
    QListWidgetItem *item1 = new QListWidgetItem(ui->listWidget,0);
    item1->setSizeHint(QSize(782,96));
    QWidget *widget = new Form(ui->listWidget);
    QWidget *widget1 = new testWidget(ui->listWidget);
    ui->listWidget->setItemWidget(item,widget);
    ui->listWidget->setItemWidget(item1,widget1);
}

Widget::~Widget()
{
    delete ui;
}
