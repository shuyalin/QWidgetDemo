#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include "customlistwidgetitem.h"
#include <QList>
#include "mywidget.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void expandItem();
private:
    Ui::Widget *ui;
    QList<QListWidgetItem*> items;
    QList<CustomListWidgetItem*> widgets;
    MyWidget *widget;
};

#endif // WIDGET_H
