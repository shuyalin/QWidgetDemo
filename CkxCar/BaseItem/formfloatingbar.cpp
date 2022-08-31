#include "formfloatingbar.h"
#include "ui_formfloatingbar.h"
#include "appevent.h"
#include <uihelper.h>
#include <QDebug>
FormFloatingBar::FormFloatingBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFloatingBar)
{
    ui->setupUi(this);
    timer = new  QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    connect(AppEvent::instance(),SIGNAL(putVal(QString)),this,SLOT(putVal(QString)));
    UiHelper::instance()->setLabelText(ui->labTempTitle,"temperal : ");
    UiHelper::instance()->setItemFont(ui->labTempTitle,24);
    UiHelper::instance()->setLabelText(ui->labTempValue,"23");
    UiHelper::instance()->setItemFont(ui->labTempValue,24);
    UiHelper::instance()->setBtnIcon(ui->btnQuit,":/res/images/StatusBarWidgetBackButtonPress.png");
    timer->start(1000);
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
void FormFloatingBar::showTime()
{
    UiHelper::instance()->setItemFont(ui->labTime,24);
    ui->labTime->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
}
