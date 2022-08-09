#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "MultimediaListView.h"
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
    void onListViewItemRelease(const int val);

private:
    Ui::Widget *ui;
    MultimediaListView *view;
};

#endif // WIDGET_H
