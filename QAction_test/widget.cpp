#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*QAction类提供了抽象的用户界面action，这些action可以被放置在窗口部件中。*/
    QAction *actionOne = new QAction("grade",this);
    connect(actionOne,SIGNAL(triggered(bool)),this,SLOT(print()));
    this->addAction(actionOne);
    QAction *actionTwo = new QAction("name",this);
    connect(actionTwo,SIGNAL(triggered(bool)),this,SLOT(print()));
    this->addAction(actionTwo);
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::print()
{
    qDebug()<<"11111111111111111111";
}
