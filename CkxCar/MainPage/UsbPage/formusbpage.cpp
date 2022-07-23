#include "formusbpage.h"
#include "ui_formusbpage.h"
#include "formusbmusic.h"
#include "formusbphoto.h"
#include "formusbvideo.h"
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
    FormUsbMusic *usbMusic = new FormUsbMusic;
    FormUsbPhoto *usbPhoto = new FormUsbPhoto;
    FormUsbVideo *usbVideo = new FormUsbVideo;

    ui->stackedWidget->addWidget(usbMusic);
    ui->stackedWidget->addWidget(usbPhoto);
    ui->stackedWidget->addWidget(usbVideo);

    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(0);
}
void FormUsbPage::initSlot()
{
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(playMusicPage(QListWidgetItem*)));
}
void FormUsbPage::playMusicPage(QListWidgetItem* item)
{
    ui->stackedWidget->setCurrentIndex(2);
    qDebug()<<"ttttttttt ";
}
