#include "radiobuttonstyle.h"
#include "ui_radiobuttonstyle.h"

radioButtonStyle::radioButtonStyle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::radioButtonStyle)
{
    ui->setupUi(this);
}

radioButtonStyle::~radioButtonStyle()
{
    delete ui;
}
