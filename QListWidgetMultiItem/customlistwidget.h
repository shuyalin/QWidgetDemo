#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>
class CustomListWidget:public QListWidget
{
    Q_OBJECT
public:
    CustomListWidget(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    int lastY;
};

#endif // CUSTOMLISTWIDGET_H
