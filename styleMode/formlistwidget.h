#ifndef FORMLISTWIDGET_H
#define FORMLISTWIDGET_H

#include <QWidget>

namespace Ui {
class FormListWidget;
}

class FormListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FormListWidget(QWidget *parent = 0);
    ~FormListWidget();

private:
    Ui::FormListWidget *ui;
};

#endif // FORMLISTWIDGET_H
