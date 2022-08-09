#ifndef FORMPAGETWO_H
#define FORMPAGETWO_H

#include <QWidget>

namespace Ui {
class FormPageTwo;
}

class FormPageTwo : public QWidget
{
    Q_OBJECT

public:
    explicit FormPageTwo(QWidget *parent = 0);
    ~FormPageTwo();
    void retransLator();
protected:
    void languageChange();
private:
    Ui::FormPageTwo *ui;
};

#endif // FORMPAGETWO_H
