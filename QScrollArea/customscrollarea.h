#ifndef MYAREAHORI_H
#define MYAREAHORI_H

#include <QScrollArea>
#include <QMouseEvent>
class CustomScrollArea:public QScrollArea
{
public:
    CustomScrollArea(QWidget *widget = 0);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int lastY;
};

#endif // MYAREAHORI_H

