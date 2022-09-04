#include "widget.h"
#include "ui_widget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    window = new WidgetWindow(this);

}

MyWidget::~MyWidget()
{
    delete ui;
}
