#include "mywidget.h"
#include <QVBoxLayout>
#include "frmnavi1.h"
#include "frmnavi.h"
#include  <QApplication>
#include  <QDebug>
MyWidget::MyWidget(QWidget *parent):QWidget(parent)
{
    //initComponent_3();
    initComponent_4();
}
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    lsatY = event->pos().y();
}

void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    int delta = event->pos().y() - lsatY;
    qDebug()<<"111111111111111111 "<<delta;
    QWheelEvent wheelEvent(QPoint(0, 0), -delta, Qt::LeftButton, Qt::NoModifier);
    QApplication::sendEvent(widget, &wheelEvent);
}
void MyWidget::initComponent_3()
{
    spaceItem = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Expanding);
    customArea = new QScrollArea(this);
    customArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    customArea->setWidgetResizable(true);
    customArea->setGeometry(0,0,974,711);
    widget = new QWidget(customArea);
    widget->setGeometry(0,0,customArea->width(),customArea->height());
    widget->setStyleSheet("background:green;");
    QVBoxLayout *m_pSCVLayout = new QVBoxLayout(widget);
    m_pSCVLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);
    customArea->setWidget(widget);
    int i = 0;
    QString str("liuyifei %1");
    frmNavi *navi1;
    for (i=0; i<10; ++i)
    {
        navi1 = new frmNavi(widget);
        navi1->setLabelTwoText(str.arg(i+1));
        m_pSCVLayout->addWidget(navi1);
    }
    m_pSCVLayout->addSpacerItem(spaceItem);
}

void MyWidget::initComponent_4()
{
    spaceItem = new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Expanding);
    customArea = new QScrollArea(this);
    customArea->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    customArea->setWidgetResizable(true);
    customArea->setGeometry(0,0,974,711);
    widget = new QWidget(customArea);
    widget->setGeometry(0,0,customArea->width(),customArea->height());
    widget->setStyleSheet("background:green;");
    QVBoxLayout *m_pSCVLayout = new QVBoxLayout(widget);
    m_pSCVLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);
    customArea->setWidget(widget);
    int i = 0;
    QString str("liuyifei %1");
    FrmNavi1 *navi1;
    for (i=0; i<10; ++i)
    {
        navi1 = new FrmNavi1(widget);
        navi1->setLabelTwoText(str.arg(i+1));
        m_pSCVLayout->addWidget(navi1);
    }
    m_pSCVLayout->addSpacerItem(spaceItem);
}
