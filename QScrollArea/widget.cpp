#include "widget.h"
#include "ui_widget.h"
#include <QScrollArea>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initComponent();
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


    int i = 0;
    QString str("pushButton %1");
//    QPushButton* pushButton;
//    for (i=0; i<10; ++i)
//    {
//        pushButton = new QPushButton(str.arg(i+1), ui->scrollAreaWidgetContents);
//        pushButton->setMinimumSize(pushButton->size());
//        m_pSCVLayout->addWidget(pushButton);
//    }
    frmNavi *navi1;
    navi = new frmNavi(ui->scrollAreaWidgetContents);
    navi->setLabelTwoText(str.arg(i+1));
    m_pSCVLayout->addWidget(navi);
    for (i=0; i<20; ++i)
    {
        navi1 = new frmNavi(ui->scrollAreaWidgetContents);
        //navi->setMinimumSize(navi->size());
        navi1->setLabelTwoText(str.arg(i+1));
        m_pSCVLayout->addWidget(navi1);
    }
    //connect(navi,SIGNAL(click()),this,SLOT(expandSD()));
}
void Widget::expandSD()
{
    static int count = 0;
    if(count % 2 == 0)
        navi->showExpand();
    else
        navi->hideExpand();
    count++;
}
