#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_ViewPaperWidget = new ViewPaperWidget(this);
    m_ViewPaperWidget->show();
}

Widget::~Widget()
{
    delete ui;
}
