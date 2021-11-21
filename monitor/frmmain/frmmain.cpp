#include "frmmain.h"
#include "ui_frmmain.h"

frmmain::frmmain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmmain)
{
    ui->setupUi(this);
}

frmmain::~frmmain()
{
    delete ui;
}
