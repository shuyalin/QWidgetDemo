#include "customlistwidget.h"
#include <QDebug>
CustomListWidget::CustomListWidget(QWidget *parent):QListWidget(parent)
{
    lastY = 0;
}
void CustomListWidget::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event);
}

void CustomListWidget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"wwwwwwwwwwwwwwwww";
    if (event->buttons() == Qt::LeftButton)
    {
        int delta = (event->y() - lastY) * 0.5;
        qDebug()<<"sssssssssssssssssssssss";
        QWheelEvent e = QWheelEvent(event->pos(), event->globalPos(), QPoint(0, 0), QPoint(0, 0),
                                    delta, Qt::Vertical, Qt::NoButton, Qt::NoModifier);
        wheelEvent(&e);
        lastY = event->y();
    }
    QListWidget::mouseMoveEvent(event);
}

void CustomListWidget::mouseReleaseEvent(QMouseEvent *event)
{

    QListWidget::mouseReleaseEvent(event);
}
