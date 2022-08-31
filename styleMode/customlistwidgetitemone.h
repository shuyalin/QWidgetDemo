#ifndef CUSTOMLISTWIDGETITEMONE_H
#define CUSTOMLISTWIDGETITEMONE_H

#include <QWidget>

namespace Ui {
class CustomListWidgetItemOne;
}

class CustomListWidgetItemOne : public QWidget
{
    Q_OBJECT

public:
    explicit CustomListWidgetItemOne(QWidget *parent = 0);
    ~CustomListWidgetItemOne();

private:
    Ui::CustomListWidgetItemOne *ui;
};

#endif // CUSTOMLISTWIDGETITEMONE_H
