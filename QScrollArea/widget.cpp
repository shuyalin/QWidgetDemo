#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include "frmnavi1.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //initComponent();
    //initComponent_1();
    //initComponent_2();
    initComponent_3();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initComponent()
{
    ui->scrollArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    ui->scrollArea->setWidgetResizable(true);

    QVBoxLayout *m_pSCVLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    m_pSCVLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);

    qDebug()<<"aaaaaaaaaaaaaaaaaaaa";
    int i = 0;
    QString str("pushButton %1");
    frmNavi *navi1;
    //m_pSCVLayout->addWidget(navi);
    for (i=0; i<20; ++i)
    {
        navi1 = new frmNavi(ui->scrollAreaWidgetContents);
        navi1->setLabelTwoText(str.arg(i+1));
        m_pSCVLayout->addWidget(navi1);
    }
}
void Widget::initComponent_1()
{
    ui->scrollArea->setVisible(false);
    area = new QScrollArea(this);
    area->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    area->setWidgetResizable(true);
    area->setGeometry(0,0,width(),height());
    QWidget *widget = new QWidget(area);
    widget->setGeometry(0,0,area->width(),area->height());
    widget->show();
    QVBoxLayout *m_pSCVLayout = new QVBoxLayout(widget);
    m_pSCVLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);


    int i = 0;
    QString str("shuyalin %1");
    frmNavi *navi1;
    for (i=0; i<20; ++i)
    {
        navi1 = new frmNavi(widget);
        navi1->setLabelTwoText(str.arg(i+1));
        m_pSCVLayout->addWidget(navi1);
    }
}

void Widget::initComponent_2()
{
    ui->scrollArea->setVisible(false);
    area = new QScrollArea(this);
    area->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    area->setWidgetResizable(true);
    area->setGeometry(0,0,width(),height());
    QWidget *widget = new QWidget(area);
    widget->setGeometry(0,0,area->width(),area->height());
    widget->show();
    QVBoxLayout *m_pSCVLayout = new QVBoxLayout(widget);
    m_pSCVLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);


    int i = 0;
    QString str("zhangsan %1");
    FrmNavi1 *navi1;
    for (i=0; i<20; ++i)
    {
        navi1 = new FrmNavi1(widget);
        navi1->setLabelTwoText(str.arg(i+1));
        m_pSCVLayout->addWidget(navi1);
    }
}

void Widget::initComponent_3()
{
    ui->scrollArea->setVisible(false);
    ui->scrollArea_2->setVisible(false);
    customArea = new CustomScrollArea(this);
    customArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    customArea->setWidgetResizable(true);
    customArea->setGeometry(0,0,width(),height());
    scrollAreaWidgetContents = new QWidget(customArea);
    scrollAreaWidgetContents->setEnabled(true);
    scrollAreaWidgetContents->setGeometry(0,0,customArea->width(),customArea->height());
    scrollAreaWidgetContents->setStyleSheet("background:green;");
    QVBoxLayout *m_pSCVLayout = new QVBoxLayout(scrollAreaWidgetContents);
    m_pSCVLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);

    //customArea->widget()->setMouseTracking(true);
    int i = 0;
    QString str("liuyifei %1");
    frmNavi *navi1;
    for (i=0; i<20; ++i)
    {
        navi1 = new frmNavi(scrollAreaWidgetContents);
        navi1->setLabelTwoText(str.arg(i+1));
        m_pSCVLayout->addWidget(navi1);
    }
}
