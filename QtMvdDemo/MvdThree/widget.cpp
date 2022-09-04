#include "widget.h"
#include "ui_widget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    view = new CustomListView(this);
//    view->setGeometry(0,0,width()/2 -10,height());
//    view->show();

    window = new WidgetWindow(this);
    //window->setGeometry(10,0,width()/2 -10,height());
    //window->show();
}

MyWidget::~MyWidget()
{
    delete ui;
}
