#ifndef FORMUSBMUSIC_H
#define FORMUSBMUSIC_H

#include <QWidget>
#include "appevent.h"

namespace Ui {
class FormUsbMusic;
}

class FormUsbMusic : public QWidget
{
    Q_OBJECT

public:
    explicit FormUsbMusic(QWidget *parent = 0);
    ~FormUsbMusic();

signals:
    void quitPage();

private:
    Ui::FormUsbMusic *ui;
};

#endif // FORMUSBMUSIC_H
