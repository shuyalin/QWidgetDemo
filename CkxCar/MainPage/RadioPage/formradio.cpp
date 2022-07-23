#include "formradio.h"
#include "ui_formradio.h"

FormRadio::FormRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRadio)
{
    ui->setupUi(this);
}

FormRadio::~FormRadio()
{
    delete ui;
}
