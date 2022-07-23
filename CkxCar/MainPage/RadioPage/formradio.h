#ifndef FORMRADIO_H
#define FORMRADIO_H

#include <QWidget>

namespace Ui {
class FormRadio;
}

class FormRadio : public QWidget
{
    Q_OBJECT

public:
    explicit FormRadio(QWidget *parent = 0);
    ~FormRadio();

private:
    Ui::FormRadio *ui;
};

#endif // FORMRADIO_H
