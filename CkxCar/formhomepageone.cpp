#include "formhomepageone.h"
#include "ui_formhomepageone.h"

FormHomePageOne::FormHomePageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHomePageOne)
{
    ui->setupUi(this);
}

FormHomePageOne::~FormHomePageOne()
{
    delete ui;
}
