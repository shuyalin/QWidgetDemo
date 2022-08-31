#include "formlistwidget.h"
#include "ui_formlistwidget.h"

FormListWidget::FormListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormListWidget)
{
    ui->setupUi(this);
}

FormListWidget::~FormListWidget()
{
    delete ui;
}
