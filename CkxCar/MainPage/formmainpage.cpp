#include "formmainpage.h"
#include "ui_formmainpage.h"
#include "formhomepage.h"
#include "formradio.h"
#include "formblue.h"
#include "formusbpage.h"
#include "formhomepageone.h"
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
    FormHomePageOne *homePageOne = new FormHomePageOne;
    //FormHomePage *homePage = new FormHomePage;
    ui->stackedWidget->addWidget(radio);
    ui->stackedWidget->addWidget(blue);
    ui->stackedWidget->addWidget(usb);
    ui->stackedWidget->addWidget(homePageOne);
    ui->stackedWidget->setCurrentWidget(homePageOne);

    connect(AppEvent::instance(),SIGNAL(pageChange(AppEvent::PageType)),this,SLOT(changePage(AppEvent::PageType)));
}
void FormMainPage::changePage(AppEvent::PageType pageType)
{
    if(AppEvent::Radio == pageType){
        ui->stackedWidget->setCurrentIndex(0);
    }else if(AppEvent::Bluetooth == pageType){
        ui->stackedWidget->setCurrentIndex(1);
    }else if(AppEvent::Usb == pageType){
        ui->stackedWidget->setCurrentIndex(2);
        qDebug()<<"UUUUUUUUUUUUUUUUUUSB";
    }else if(AppEvent::Home == pageType){
        ui->stackedWidget->setCurrentIndex(3);
    }
}


void FormMainPage::on_btnBack_clicked()
{
    emit AppEvent::instance()->pageChange(AppEvent::Home);
}
