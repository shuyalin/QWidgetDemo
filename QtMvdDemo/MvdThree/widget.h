#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "customlistview.h"
#include "widgetwindow.h"
namespace Ui {
class Widget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private:
    Ui::Widget *ui;
    CustomListView *view;
    WidgetWindow *window;
};

#endif // WIDGET_H
