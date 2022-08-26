#include "frmnavi.h"
#include "ui_frmnavi.h"

frmNavi::frmNavi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmNavi)
{
    ui->setupUi(this);
    ui->widget_3->setVisible(false);
}

frmNavi::~frmNavi()
{
    delete ui;
}
void frmNavi::setLabelOnePic(const QString &url)
{
    ui->label->setPixmap(QPixmap(url));
}

void frmNavi::setLabelTwoText(const QString &text)
{
    ui->label_2->setText(text);
}

void frmNavi::on_pushButton_clicked()
{
    ui->widget_3->setVisible(true);//emit click();
}
void frmNavi::showExpand()
{
    ui->widget_3->setVisible(true);
}
void frmNavi::hideExpand()
{
    ui->widget_3->setVisible(false);
}

