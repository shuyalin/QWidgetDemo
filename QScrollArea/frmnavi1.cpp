#include "frmnavi1.h"
#include <QDebug>
FrmNavi1::FrmNavi1(QWidget *parent):QWidget(parent)
{
    vLayout = new QVBoxLayout(this);
    vLayout->setSpacing(0);
    vLayout->setMargin(0);
    vLayout->setContentsMargins(0,0,0,0);
    widgetOne = new QWidget(this);
    widgetTwo = new QWidget(this);
    widgetOne->setVisible(true);
    widgetTwo->setVisible(false);
    vLayout->addWidget(widgetOne);
    vLayout->addWidget(widgetTwo);

    hLayout = new QHBoxLayout(widgetOne);
    hLayout->setSpacing(0);
    hLayout->setMargin(0);
    //hLayout->setContentsMargins(0,0,0,0);
    labOne = new QLabel(widgetOne);
    labOne->setFixedSize(50,50);
    labOne->setPixmap(QPixmap(":/images/AC_P.png"));
    labTwo = new QLabel(widgetOne);
    labTwo->setAlignment(Qt::AlignHCenter);
    btnOne = new QPushButton(widgetOne);
    btnOne->setFixedSize(50,50);
    hLayout->addWidget(labOne);
    hLayout->addWidget(labTwo);
    hLayout->addWidget(btnOne);

    hLayout1 = new QHBoxLayout(widgetTwo);
    hLayout1->setSpacing(0);
    hLayout1->setMargin(0);
    labThree = new QLabel(widgetTwo);
    labThree->setAlignment(Qt::AlignHCenter);
    labThree->setFixedSize(50,50);
    labThree->setText("hello");
    labThree->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    labThree->setStyleSheet("font-size:22px;");
    hLayout1->addWidget(labThree);
    setProperty("expand","Off");
    connect(btnOne,SIGNAL(clicked(bool)),this,SLOT(expandArea()));
}
FrmNavi1::~FrmNavi1()
{

}
void FrmNavi1::setLabelTwoText(const QString &text)
{
    labTwo->setText(text);
}
void FrmNavi1::expandArea()
{
    qDebug()<<"ffffffffffffffffffffffff";
    if(property("expand") == "Off"){
        setProperty("expand","On");
        widgetTwo->setVisible(true);
    }else if(property("expand") == "On"){
        setProperty("expand","Off");
        widgetTwo->setVisible(false);
    }

}
//void FrmNavi1::resizeEvent(QResizeEvent *event)
//{
//    resize(777,102);
//}
