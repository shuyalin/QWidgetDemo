#include "formpagetwo.h"
#include "ui_formpagetwo.h"

FormPageTwo::FormPageTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPageTwo)
{
    ui->setupUi(this);
}

FormPageTwo::~FormPageTwo()
{
    delete ui;
}
void FormPageTwo::retransLator()
{
    ui->retranslateUi(this);
}
void FormPageTwo::languageChange()
{
    ui->retranslateUi(this);
}
