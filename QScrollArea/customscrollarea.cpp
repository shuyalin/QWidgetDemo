#include "customscrollarea.h"
#include <QListView>
#include <QDebug>
CustomScrollArea::CustomScrollArea(QWidget *widget):QScrollArea(widget)
{
    //setAttribute(Qt::WA_TransparentForMouseEvents, true);
}
void CustomScrollArea::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
        {
            int qt4Delta = (event->y() - lastY);
            qDebug()<<"yyyyyyyyyyyy "<<qt4Delta;
            QWheelEvent e = QWheelEvent(event->pos(),qt4Delta,Qt::NoButton, Qt::NoModifier,Qt::Vertical);
            wheelEvent(&e);
            lastY = event->y();
        }
        //QScrollArea::mouseMoveEvent(event);
    QListView::mouseMoveEvent(event);
}
void CustomScrollArea::mousePressEvent(QMouseEvent *event)
{
    lastY = event->y();
    qDebug()<<"eeeeeeeeeeeee "<<lastY;
    QScrollArea::mousePressEvent(event);
}

