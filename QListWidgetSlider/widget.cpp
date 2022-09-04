#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QStandardItem>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    delta = 0;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(contentSlider()));
    timer->start(1000);
    delegate = new BluetoothContactDelegate();
    model = new QStandardItemModel;
    for(int i = 0;i<20;i++){
        QStandardItem *item =  new QStandardItem();
        item->setSizeHint(QSize(360,60));
        model->setItem(i,0,item);
    }
    ui->listView->setModel(model);
    ui->listView->setItemDelegate(delegate);
    setStyleSheet("QListView::item{background:green;}");
}

Widget::~Widget()
{
    delete ui;
}
void Widget::contentSlider()
{
    delta += 1;
    qDebug()<<"rrrrrrrrrrrrrr "<<delta;
    ui->listWidget->verticalScrollBar()->setValue(delta);
}
