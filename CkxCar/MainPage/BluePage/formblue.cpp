#include "formblue.h"
#include "ui_formblue.h"

FormBlue::FormBlue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBlue)
{
    ui->setupUi(this);
}

FormBlue::~FormBlue()
{
    delete ui;
}
