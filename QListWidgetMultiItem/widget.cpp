#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
#if 0
    ui->listWidget->setStyleSheet("background:green;");
    ui->listWidget->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    //ui->listWidget->setSpacing(10);
    ui->listWidget->setFocusPolicy(Qt::NoFocus);
    for(int i = 0;i < 10;i++){
        CustomListWidgetItem *list = new CustomListWidgetItem(ui->listWidget);
        connect(list,SIGNAL(click()),this,SLOT(expandItem()));
        connect(list,SIGNAL(sendVerticalPos(int)),this,SLOT(sliderVal(int)));
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(QSize(360,200));
        list->setFocusPolicy(Qt::NoFocus);
        widgets.push_back(list);
        items.push_back(item);
        ui->listWidget->setItemWidget(item,list);
    }
#endif
    MyWidget *widget = new  MyWidget(this);
    widget->setGeometry(10,10,width(),height());
    widget->show();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::expandItem()
{
    CustomListWidgetItem *widget = static_cast<CustomListWidgetItem *>(sender());
    int i = 0;
    foreach (auto var, widgets) {
       if(var == widget){
           if(var->getExpandStatu() == "on"){
                items.at(i)->setSizeHint(QSize(360,200));
                qDebug()<<"111111111111";
           }else if(var->getExpandStatu() == "off"){
                items.at(i)->setSizeHint(QSize(360,60));
                qDebug()<<"22222222222222";
           }
           break;
       }
       i++;
    }
}

