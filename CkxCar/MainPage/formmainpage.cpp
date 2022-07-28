#include "formmainpage.h"
#include "ui_formmainpage.h"
#include "formhomepage.h"
#include "formradio.h"
#include "formblue.h"
#include "formusbpage.h"
#include "formhomepageone.h"
#include "uihelper.h"
#include <QDebug>

FormMainPage::FormMainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMainPage)
{
    ui->setupUi(this);
    initForm();
}

FormMainPage::~FormMainPage()
{
    delete ui;
}

void FormMainPage::initForm()
{
    FormRadio *radio = new FormRadio;
    FormBlue *blue = new FormBlue;
    FormUsbPage *usb = new FormUsbPage;
    FormHomePageOne *pageOne = new FormHomePageOne;
    ui->stackedWidget->addWidget(radio);
    ui->stackedWidget->addWidget(blue);
    ui->stackedWidget->addWidget(usb);
    ui->stackedWidget->addWidget(pageOne);

    ui->stackedWidget->setCurrentIndex(3);
    connect(radio,SIGNAL(quitPage()),this,SLOT(backHomePage()));
    connect(blue,SIGNAL(quitPage()),this,SLOT(backHomePage()));
    connect(usb,SIGNAL(quitPage()),this,SLOT(backHomePage()));
    connect(AppEvent::instance(),SIGNAL(pageChange(AppEvent::PageType)),this,SLOT(pageTypeChange(AppEvent::PageType)));
}
void FormMainPage::backHomePage()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void FormMainPage::pageTypeChange(AppEvent::PageType destPage)
{
    if(AppEvent::Radio == destPage){
        ui->stackedWidget->setCurrentIndex(0);
    }else if(AppEvent::Bluetooth == destPage){
        ui->stackedWidget->setCurrentIndex(1);
    }else if(AppEvent::Usb == destPage){
        qDebug()<<"VVVVVVVVVVVVVVVVVVVVV";
        ui->stackedWidget->setCurrentIndex(2);
    }else if(AppEvent::Home == destPage){
        ui->stackedWidget->setCurrentIndex(3);
    }
}
