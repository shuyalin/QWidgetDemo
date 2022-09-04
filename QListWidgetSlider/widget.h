#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QListWidget>
#include <QScrollBar>
#include <QStandardItemModel>
#include "mylistview.h"
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
    void contentSlider();
private:
    Ui::Widget *ui;
    QTimer *timer;
    QStandardItemModel *model;
    BluetoothContactDelegate *delegate;
    int delta;
};

#endif // WIDGET_H
