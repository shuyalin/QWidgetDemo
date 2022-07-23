#include "formhomepageone.h"
#include "ui_formhomepageone.h"
#include "customlistitem.h"
#include <QListWidgetItem>
#include "appevent.h"
FormHomePageOne::FormHomePageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHomePageOne)
{
    ui->setupUi(this);
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget,0);
    item->setSizeHint(QSize(1024,150));
    QListWidgetItem *item1 = new QListWidgetItem(ui->listWidget,0);
    item1->setSizeHint(QSize(1024,150));
    customListItem *widget = new customListItem(ui->listWidget);
    customListItem *widget1 = new customListItem(ui->listWidget);
    widget->setBtnText(0,"000");
    widget->setBtnText(1,"111");
    widget->setBtnText(2,"222");
    widget->setBtnText(3,"333");
    widget->setBtnText(4,"444");
    widget1->setBtnText(0,"aaa");
    widget1->setBtnText(1,"bbb");
    widget1->setBtnText(2,"ccc");
    widget1->setBtnText(3,"ddd");
    widget1->setBtnText(4,"eee");

    widget->setBtnName(0,"radio");
    widget->setBtnName(1,"blue");
    ui->listWidget->setItemWidget(item,widget);
    ui->listWidget->setItemWidget(item1,widget1);


    ui->listWidget->setViewMode(QListView::ListMode);
    ui->listWidget->setFlow(QListView::LeftToRight);
    ui->listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    connect(widget,SIGNAL(click(QString)),this,SLOT(onClick(QString)));
    connect(widget1,SIGNAL(click(QString)),this,SLOT(onClick(QString)));
}

FormHomePageOne::~FormHomePageOne()
{
    delete ui;
}

void FormHomePageOne::onClick(QString name)
{
    if(name == "radio"){
        emit AppEvent::instance()->pageChange(AppEvent::Radio);
    }else if(name == "blue"){
        emit AppEvent::instance()->pageChange(AppEvent::Bluetooth);
    }
}
