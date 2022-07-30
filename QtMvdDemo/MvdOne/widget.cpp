#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    view = new MultimediaListView(this);
    view->setGeometry(10,10,width()-20,height()-20);
    QStringList list;
    list<<"zhangsan"<<"lisi"<<"wangwu"<<"mazi";
    for(int i = 0;i<list.size();i++){
        view->appendListView(list.at(i));
    }
}

Widget::~Widget()
{
    delete ui;
}
