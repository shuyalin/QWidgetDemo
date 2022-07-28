#include "formradio.h"
#include "ui_formradio.h"
#include  "appevent.h"
FormRadio::FormRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRadio)
{
    ui->setupUi(this);
    connect(ui->floatingBar,SIGNAL(quitPage()),this,SIGNAL(quitPage()));
}

FormRadio::~FormRadio()
{
    delete ui;
}
