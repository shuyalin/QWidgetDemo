#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    view = new CustomListView(this);
    view->setGeometry(0,0,width(),height());
    view->show();
}

Widget::~Widget()
{
    delete ui;
}
