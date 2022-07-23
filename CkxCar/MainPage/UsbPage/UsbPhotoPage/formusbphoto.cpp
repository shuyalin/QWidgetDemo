#include "formusbphoto.h"
#include "ui_formusbphoto.h"

FormUsbPhoto::FormUsbPhoto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUsbPhoto)
{
    ui->setupUi(this);
}

FormUsbPhoto::~FormUsbPhoto()
{
    delete ui;
}
