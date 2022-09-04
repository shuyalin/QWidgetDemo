#include "mywidget.h"
#include <QVBoxLayout>
#include  <QApplication>
#include <QWheelEvent>
#include  <QDebug>

MyWidget::MyWidget(QWidget *parent):QWidget(parent)
{

}
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    lsatY = event->pos().y();
}

void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    int delta = event->pos().y() - lsatY;
    qDebug()<<"111111111111111111 "<<delta;
    QWheelEvent wheelEvent(QPoint(0, 0), -delta, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent(listWidget, &wheelEvent);
}
