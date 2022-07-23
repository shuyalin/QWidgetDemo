#ifndef MYAREAHORI_H
#define MYAREAHORI_H

#include <QScrollArea>
#include <QMouseEvent>
class MyAreaHori:public QScrollArea
{
public:
    MyAreaHori(QWidget *widget = 0);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int m_LastX;
};

#endif // MYAREAHORI_H

