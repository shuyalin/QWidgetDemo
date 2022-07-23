#include "formusbvideo.h"
#include "ui_formusbvideo.h"

FormUsbVideo::FormUsbVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUsbVideo)
{
    ui->setupUi(this);
}

FormUsbVideo::~FormUsbVideo()
{
    delete ui;
}
