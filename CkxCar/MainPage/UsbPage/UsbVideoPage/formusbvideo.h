#ifndef FORMUSBVIDEO_H
#define FORMUSBVIDEO_H

#include <QWidget>

namespace Ui {
class FormUsbVideo;
}

class FormUsbVideo : public QWidget
{
    Q_OBJECT

public:
    explicit FormUsbVideo(QWidget *parent = 0);
    ~FormUsbVideo();

private:
    Ui::FormUsbVideo *ui;
};

#endif // FORMUSBVIDEO_H
