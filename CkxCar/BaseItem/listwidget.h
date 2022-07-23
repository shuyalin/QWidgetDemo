#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include  <QListWidget>
#include <QMouseEvent>
class ListWidget:public QListWidget
{
public:
    ListWidget(QWidget *parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);
private:
    int m_LastX;
};

#endif // LISTWIDGET_H
