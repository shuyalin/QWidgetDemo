#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "frmnavi.h"
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

public slots:
    void expandSD();
private:
    Ui::Widget *ui;
    frmNavi *navi;
};

#endif // WIDGET_H
