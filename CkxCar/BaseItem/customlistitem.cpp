#include "customlistitem.h"
#include "ui_customlistitem.h"
#include <QDebug>
customListItem::customListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customListItem)
{
    ui->setupUi(this);
    btns << ui->btn1 << ui->btn2 << ui->btn3 << ui->btn4 << ui->btn5;
    foreach (auto item, btns) {
        connect(item,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    }
}

customListItem::~customListItem()
{
    delete ui;
}

void customListItem::setBtnName(int index,const QString name)
{
    btns.at(index)->setObjectName(name);
}

void customListItem::setBtnText(int index,const QString text)
{
    btns.at(index)->setText(text);
}
void customListItem::onClick()
{

    QToolButton *btn = static_cast<QToolButton*>(sender());
    qDebug()<<"wwwwwwwwwwww "<<btn->objectName();
    emit click(btn->objectName());
}
