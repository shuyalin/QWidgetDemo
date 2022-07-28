#ifndef FORMBLUE_H
#define FORMBLUE_H

#include <QWidget>
#include "appevent.h"
namespace Ui {
class FormBlue;
}

class FormBlue : public QWidget
{
    Q_OBJECT

public:
    explicit FormBlue(QWidget *parent = 0);
    ~FormBlue();

signals:
    void quitPage();


private:
    Ui::FormBlue *ui;
};

#endif // FORMBLUE_H
