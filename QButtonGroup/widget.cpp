#include "widget.h"
#include "ui_widget.h"
#include "iconfont.h"
#include <QButtonGroup>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btn1->setCheckable(true);
    ui->btn2->setCheckable(true);
    ui->btn3->setCheckable(true);
    ui->btn4->setCheckable(true);
    ui->btn5->setCheckable(true);
    ui->btn6->setCheckable(true);
    ui->btn7->setCheckable(true);
    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->btn1);
    group->addButton(ui->btn2);
    group->addButton(ui->btn3);
    group->addButton(ui->btn4);
    group->addButton(ui->btn5);
    group->addButton(ui->btn6);
    group->addButton(ui->btn7);

    int iconSize = 40;
    IconFont::Instance()->setIcon(ui->btn1, 0xe718, iconSize);
    IconFont::Instance()->setIcon(ui->btn2, 0xe717, iconSize);
    IconFont::Instance()->setIcon(ui->btn3, 0xe71a, iconSize);
    IconFont::Instance()->setIcon(ui->btn4, 0xe6fe, iconSize + 4);
    IconFont::Instance()->setIcon(ui->btn5, 0xe719, iconSize);
    IconFont::Instance()->setIcon(ui->btn6, 0xe71b, iconSize);
    IconFont::Instance()->setIcon(ui->btn7, 0xe63d, iconSize);
}

Widget::~Widget()
{
    delete ui;
}
