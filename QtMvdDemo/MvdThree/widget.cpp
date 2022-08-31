#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    view = new CustomListView(this);
    view->setGeometry(0,0,width(),height());
    view->setStyleSheet("QScrollBar:vertical{"
    "width: " + QString::number(int(47 * 1.28)) + "px;"
    "background: transparent;"
    "margin: 0px, 0px, 0px, 0px;"
    "padding: 0px, 0px, 0px, 0px;"
    "}"
    "QScrollBar::handle:vertical{"
    "border-top-right-radius: " + QString::number(int(10 * 1.28)) + "px;"
    "border-bottom-right-radius: " + QString::number(int(10 * 1.28)) + "px;"
     "min-height: " + QString::number(int(47 * 1.28)) + "px;"
     "background: rgba(0, 162, 255, 191);"
    "}"
    "QScrollBar::add-line:vertical{"
    "height: 0px;"
    "width: 0px;"
    "}"
    "QScrollBar::sub-line:vertical{"
    "height: 0px;"
    "width: 0px;"
    "}"
    "QScrollBar::add-page:vertical{"
    "margin-left: " + QString::number(int(18 * 1.28)) + "px;"
    "margin-right: " + QString::number(int(18 * 1.28)) + "px;"
    "background: rgba(42, 42, 42, 191);"
    "}"
    "QScrollBar::sub-page:vertical{"
    "margin-left: " + QString::number(int(18 * 1.28)) + "px;"
    "margin-right: " + QString::number(int(18 * 1.28)) + "px;"
    "background: rgba(42, 42, 42, 191);"
    "}"
     );

    view->show();
}

Widget::~Widget()
{
    delete ui;
}
