#include "widget.h"
#include "ui_widget.h"
#include <QTranslator>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    lanType = english;
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(changePage()));
    myTranslator = new QTranslator(qApp);

    pageTwo = new FormPageTwo;
    ui->stackedWidget->addWidget(pageTwo);

    ui->btnPageTwp->setText(QObject::tr("test Page"));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changePage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_chinese_clicked()
{
    lanType = chinese;

    myTranslator->load("chinese.qm");
    qApp->installTranslator(myTranslator);
    ui->retranslateUi(this);
    pageTwo->retransLator();
}

void Widget::on_english_clicked()
{
    lanType = english;
    myTranslator->load("english.qm");
    qApp->installTranslator(myTranslator);
    ui->retranslateUi(this);
    pageTwo->retransLator();
}

void Widget::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_pushButton_5_clicked()
{
    form = new Form;
    connect(form,SIGNAL(quitPage()),this,SLOT(closeNewPage()));
    form->show();
}
void Widget::closeNewPage()
{
    if(form){
        form->deleteLater();
        form = NULL;
    }
}

void Widget::on_btnSetting_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_btnHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_btnPageTwp_clicked()
{
    pageTwo->retransLator();
    ui->btnPageTwp->setText(QObject::tr("test Page"));
    ui->stackedWidget->setCurrentIndex(2);
}
