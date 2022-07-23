#ifndef FORMUSBPHOTO_H
#define FORMUSBPHOTO_H

#include <QWidget>

namespace Ui {
class FormUsbPhoto;
}

class FormUsbPhoto : public QWidget
{
    Q_OBJECT

public:
    explicit FormUsbPhoto(QWidget *parent = 0);
    ~FormUsbPhoto();

private:
    Ui::FormUsbPhoto *ui;
};

#endif // FORMUSBPHOTO_H
