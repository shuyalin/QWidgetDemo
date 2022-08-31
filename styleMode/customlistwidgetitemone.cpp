#include "customlistwidgetitemone.h"
#include "ui_customlistwidgetitemone.h"

CustomListWidgetItemOne::CustomListWidgetItemOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomListWidgetItemOne)
{
    ui->setupUi(this);
}

CustomListWidgetItemOne::~CustomListWidgetItemOne()
{
    delete ui;
}
