#ifndef FORMHOMEPAGEONE_H
#define FORMHOMEPAGEONE_H

#include <QWidget>

namespace Ui {
class FormHomePageOne;
}

class FormHomePageOne : public QWidget
{
    Q_OBJECT

public:
    explicit FormHomePageOne(QWidget *parent = 0);
    ~FormHomePageOne();

private:
    Ui::FormHomePageOne *ui;
};

#endif // FORMHOMEPAGEONE_H
