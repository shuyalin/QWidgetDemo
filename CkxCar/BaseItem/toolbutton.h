#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QWidget>
#include <QMouseEvent>
class ToolButton:public QWidget
{
    Q_OBJECT
public:
    ToolButton(QWidget *parent = 0);

signals:
    void click(QString objectName);

private:
    bool isMove;
};

#endif // TOOLBUTTON_H
