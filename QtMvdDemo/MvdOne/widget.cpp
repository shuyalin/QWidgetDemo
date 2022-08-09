#include "widget.h"
#include "ui_widget.h"
#include "AutoConnect.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    view = new MultimediaListView(this);
    view->setGeometry(0,0,width(),height());
    QStringList list;
    list<<"zhangsan"<<"lisi"<<"wangwu"<<"mazi";
    for(int i = 0;i<list.size();i++){
        view->appendListView(list.at(i));
    }
    Qt::ConnectionType type = static_cast<Qt::ConnectionType>(Qt::UniqueConnection | Qt::AutoConnection);
    QObject::connect(view, ARKSENDER(listViewItemRelease(const int)),
                     this,   ARKRECEIVER(onListViewItemRelease(const int)),
                     type);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onListViewItemRelease(const int val)
{
    qDebug()<<"iiiiiiiiiiiiiiiiii "<<val;
    view->setCurrentIndex(view->model()->index(val,0,QModelIndex()));
}
