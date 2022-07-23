#include "formusbpage.h"
#include "ui_formusbpage.h"

FormUsbPage::FormUsbPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUsbPage)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);
}

FormUsbPage::~FormUsbPage()
{
    delete ui;
}
