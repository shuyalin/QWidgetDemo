#include "formfloatingbar.h"
#include "ui_formfloatingbar.h"
#include "appevent.h"
#include <QDebug>
FormFloatingBar::FormFloatingBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFloatingBar)
{
    ui->setupUi(this);
    connect(AppEvent::instance(),SIGNAL(putVal(QString)),this,SLOT(putVal(QString)));
}

FormFloatingBar::~FormFloatingBar()
{
    delete ui;
}

void FormFloatingBar::on_btnQuit_clicked()
{
    emit quitPage();
}
void FormFloatingBar::putVal(QString str)
{
    qDebug()<<"cccccccccccccccccc "<<str ;
    ui->labTime->setText(str);
}
