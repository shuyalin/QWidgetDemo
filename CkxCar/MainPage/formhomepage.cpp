#include "formhomepage.h"
#include "ui_formhomepage.h"
#include "appevent.h"
#include "toolbutton.h"
#include <QDebug>
FormHomePage::FormHomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHomePage)
{
    ui->setupUi(this);
    initPage();
}

FormHomePage::~FormHomePage()
{
    delete ui;
}
void FormHomePage::initPage()
{
    btns << ui->btnRadio << ui->btnBlue << ui->btnUsb;
    foreach (auto item, btns) {
        connect(item,SIGNAL(clicked(bool)),this,SLOT(btnClick()));
    }
}

void FormHomePage::btnClick()
{
    QToolButton *btn = static_cast<QToolButton*>(sender());
    if(btn == ui->btnRadio){
    }else if(btn == ui->btnBlue){
    }else if(btn == ui->btnUsb){
    }
}
