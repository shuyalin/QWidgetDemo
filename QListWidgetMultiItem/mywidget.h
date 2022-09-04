#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QListWidget>
#include "customlistwidgetitem.h"
#include <QList>
class MyWidget:public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    int lsatY;
};

#endif // MYWIDGET_H
