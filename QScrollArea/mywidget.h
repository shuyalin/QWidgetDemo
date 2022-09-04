#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QSpacerItem>
#include "customscrollarea.h"

class MyWidget:public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);
    void initComponent_3();
    void initComponent_4();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QScrollArea *customArea;
    QWidget *widget;
    QSpacerItem *spaceItem;
    int lsatY;
};

#endif // MYWIDGET_H
