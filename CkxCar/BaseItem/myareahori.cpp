#include "myareahori.h"

#include <QDebug>
MyAreaHori::MyAreaHori(QWidget *widget):QScrollArea(widget)
{
    //setAttribute(Qt::WA_TransparentForMouseEvents, true);
}
void MyAreaHori::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
        {
            int qt4Delta = (event->x() - m_LastX);
            qDebug()<<"yyyyyyyyyyyy "<<qt4Delta;
            QWheelEvent e = QWheelEvent(event->pos(),qt4Delta,Qt::NoButton, Qt::NoModifier,Qt::Horizontal);
            wheelEvent(&e);
            m_LastX = event->x();
        }
        QWidget::mouseMoveEvent(event);
}
void MyAreaHori::mousePressEvent(QMouseEvent *event)
{
    m_LastX = event->x();
    qDebug()<<"eeeeeeeeeeeee "<<m_LastX;
    QWidget::mousePressEvent(event);
}

