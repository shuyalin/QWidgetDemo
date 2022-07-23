#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent):QListWidget(parent)
{

}
void ListWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        int qt4Delta = (event->x() - m_LastX) * 0.5;

        QWheelEvent e = QWheelEvent(event->pos(), event->globalPos(), QPoint(0, 0), QPoint(0, 0),
                                    qt4Delta, Qt::Horizontal, Qt::NoButton, Qt::NoModifier);
        wheelEvent(&e);
        m_LastX = event->x();
    }
    QWidget::mouseMoveEvent(event);
}
void ListWidget::mousePressEvent(QMouseEvent* event)
{
    m_LastX = event->x();
    QListWidget::mousePressEvent(event);
}
