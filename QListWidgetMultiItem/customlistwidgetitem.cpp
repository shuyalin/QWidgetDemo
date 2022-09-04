#include "customlistwidgetitem.h"
#include "ui_customlistwidgetitem.h"

CustomListWidgetItem::CustomListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomListWidgetItem)
{
    ui->setupUi(this);
    setProperty("expand","on");
}

CustomListWidgetItem::~CustomListWidgetItem()
{
    delete ui;
}
QString CustomListWidgetItem::getExpandStatu()
{
    return expandStatu;
}


void CustomListWidgetItem::on_pushButton_clicked()
{
    if(property("expand") == "on"){
        ui->widget_3->setVisible(false);
        setProperty("expand","off");
        expandStatu = "off";
        emit click();
    }else if(property("expand") == "off"){
        ui->widget_3->setVisible(true);
        setProperty("expand","on");
        expandStatu = "on";
        emit click();
    }
}
