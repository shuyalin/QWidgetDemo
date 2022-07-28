#include "formusbmusic.h"
#include "ui_formusbmusic.h"
FormUsbMusic::FormUsbMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUsbMusic)
{
    ui->setupUi(this);
    connect(ui->floatingBar,SIGNAL(quitPage()),this,SIGNAL(quitPage()));
}

FormUsbMusic::~FormUsbMusic()
{
    delete ui;
}
