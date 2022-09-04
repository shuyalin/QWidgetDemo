#include "mylistview.h"
#include <QDebug>
#include <QPainter>
MyListView::MyListView(QWidget *parent):QListView(parent)
{

}
void MyListView::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"mmmmmmmmmmmmmmmmmmmm";
    QListView::mouseMoveEvent(event);
}

BluetoothContactDelegate::BluetoothContactDelegate(QObject *parent)
    : QItemDelegate(parent)
{

}

BluetoothContactDelegate::~BluetoothContactDelegate()
{
}

void BluetoothContactDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QRect textRect1 = QRect(option.rect);
    painter->setBrush(QBrush(Qt::green));
    painter->drawRect(textRect1);
}

void BluetoothContactDelegate::onPressIndexChanged(const QModelIndex &index)
{
    m_PressIndex = index;
}
