#ifndef RADIOBUTTONSTYLE_H
#define RADIOBUTTONSTYLE_H

#include <QWidget>

namespace Ui {
class radioButtonStyle;
}

class radioButtonStyle : public QWidget
{
    Q_OBJECT

public:
    explicit radioButtonStyle(QWidget *parent = 0);
    ~radioButtonStyle();

private:
    Ui::radioButtonStyle *ui;
};

#endif // RADIOBUTTONSTYLE_H
