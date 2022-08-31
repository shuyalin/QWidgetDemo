#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QScrollArea>
#include "frmnavi.h"
#include "customscrollarea.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initComponent();
    void initComponent_1();
    void initComponent_2();
    void initComponent_3();
private:
    Ui::Widget *ui;
    frmNavi *navi;
    QScrollArea *area;
    CustomScrollArea *customArea;
    QWidget *scrollAreaWidgetContents;
};

#endif // WIDGET_H
