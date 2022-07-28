#include "formusbpage.h"
#include "ui_formusbpage.h"

#include <QDebug>

FormUsbPage::FormUsbPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUsbPage)
{
    ui->setupUi(this);
    initPage();
    initSlot();
}

FormUsbPage::~FormUsbPage()
{
    delete ui;
}

void FormUsbPage::initPage()
{
    music = new FormUsbMusic(this);
    ui->stackedWidget->addWidget(music);
    ui->stackedWidget_2->setCurrentIndex(1);
    connect(music,SIGNAL(quitPage()),this,SLOT(backUsbPage()));

    btns<<ui->btnUsbMusic << ui->btnUsbPic << ui->btnUsbVideo;
    foreach (auto item, btns) {
        connect(item,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    }
}
void FormUsbPage::initSlot()
{
    connect(ui->floatingBar,SIGNAL(quitPage()),this,SIGNAL(quitPage()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(playMusicPage(QListWidgetItem*)));
}
void FormUsbPage::playMusicPage(QListWidgetItem* item)
{
    if("music" == ui->listWidget->property("type")){

    }else if("pic" == ui->listWidget->property("type")){

    }else if("video" == ui->listWidget->property("type")){

    }
    ui->stackedWidget->setCurrentIndex(1);
}
void FormUsbPage::backUsbPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void FormUsbPage::onClick()
{
    QPushButton *btn = static_cast<QPushButton*>(sender());
    if(btn == ui->btnUsbMusic){
        ui->listWidget->setProperty("type","music");
    }else if(btn == ui->btnUsbPic){
        ui->listWidget->setProperty("type","pic");
    }else if(btn == ui->btnUsbVideo){
        ui->listWidget->setProperty("type","video");
    }
}
