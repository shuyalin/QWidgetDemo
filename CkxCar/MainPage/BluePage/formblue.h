#ifndef FORMBLUE_H
#define FORMBLUE_H

#include <QWidget>

namespace Ui {
class FormBlue;
}

class FormBlue : public QWidget
{
    Q_OBJECT

public:
    explicit FormBlue(QWidget *parent = 0);
    ~FormBlue();

private:
    Ui::FormBlue *ui;
};

#endif // FORMBLUE_H
