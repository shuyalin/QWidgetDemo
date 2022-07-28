#include "formblue.h"
#include "ui_formblue.h"

FormBlue::FormBlue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBlue)
{
    ui->setupUi(this);
    connect(ui->floatingBar,SIGNAL(quitPage()),this,SIGNAL(quitPage()));
}

FormBlue::~FormBlue()
{
    delete ui;
}

