#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_ViewPaperWidget = new ViewPaperWidget;
    ui->stackedWidget->addWidget(m_ViewPaperWidget);
    ui->stackedWidget->setCurrentIndex(0);
    connect(m_ViewPaperWidget,SIGNAL(pushStr(const QString&)),this,SLOT(showText(const QString &)));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::showText(const QString &text)
{
    ui->label->setText(text);
}
