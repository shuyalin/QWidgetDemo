#ifndef FORMRADIO_H
#define FORMRADIO_H

#include <QWidget>
#include "appevent.h"
namespace Ui {
class FormRadio;
}

class FormRadio : public QWidget
{
    Q_OBJECT

public:
    explicit FormRadio(QWidget *parent = 0);
    ~FormRadio();

signals:
    void quitPage();

private:
    Ui::FormRadio *ui;
};

#endif // FORMRADIO_H
