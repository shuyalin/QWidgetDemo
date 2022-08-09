#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ViewPaperWidget/ViewPaperWidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    ViewPaperWidget* m_ViewPaperWidget;
};

#endif // WIDGET_H
