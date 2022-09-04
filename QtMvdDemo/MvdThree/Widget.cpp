#include "Widget.h"
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QResource>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <fcntl.h>
#include <unistd.h>
#include <QFont>
#include <QTimer>
#include <QTime>

class WidgetPrivate
{
    Q_DISABLE_COPY(WidgetPrivate)
public:
    explicit WidgetPrivate(Widget* parent);
    ~WidgetPrivate();
    void initialize();
    void initHolderTypTimer();
#define HolderNum 5
    void clearListPreemptiveType();
    int sizeListPreemptiveType();
    Widget::Type getListPreemptiveType(const int index);
    void addListPreemptiveType(const Widget::Type type);
    //void sortListPreemptiveType();//将列表按acc 倒车 电话 power排列
    void removeListPreemptiveType(const Widget::Type type);
    bool replaceListPreemptiveType(const Widget::Type source,const Widget::Type in);
    int inIndexofListPreemptiveType(const Widget::Type type);
    QString qDebugListPreemptiveType();

    Widget::Type m_ListPreemptiveType[HolderNum];
    int test[HolderNum];
    int m_bacquireRun;
    //Widget::Type m_PreemptiveType;
    Widget::Type m_HolderType;
    Widget::Type m_CurrentType;
    QString m_Rcc;
    float m_WidthScalabilityFactor;
    float m_HeightScalabilityFactor;

private:
    Widget* m_Parent;
};

bool Widget::setThemeRccPath(const QString &path) const
{
    bool ret(false);
    if (path != m_Private->m_Rcc) {
        QResource::unregisterResource(m_Private->m_Rcc);
        m_Private->m_Rcc = path;
        ret = QResource::registerResource(m_Private->m_Rcc);
    }
    return ret;
}

void Widget::reset()
{
}

QRect Widget::geometryFit(const int x, const int y, const int w, const int h, QWidget *widget)
{
    initializePrivate();
    int ax = x * m_Private->m_WidthScalabilityFactor;
    int ay = y * m_Private->m_HeightScalabilityFactor;
    int aw = w * m_Private->m_WidthScalabilityFactor;
    int ah = h * m_Private->m_HeightScalabilityFactor;
    if (NULL != widget) {
        widget->move(ax, ay);
        widget->setFixedSize(QSize(aw, ah));
    }
    QRect rect(ax, ay, aw, ah);
    return rect;
}

QRect Widget::geometrySource(const int x, const int y, const int w, const int h, QWidget *widget)
{
    int ax = x / m_Private->m_WidthScalabilityFactor;
    int ay = y / m_Private->m_HeightScalabilityFactor;
    int aw = w / m_Private->m_WidthScalabilityFactor;
    int ah = h / m_Private->m_HeightScalabilityFactor;
    QRect rect(ax, ay, aw, ah);
    return rect;
}

float Widget::widthScalabilityFactor()
{
    initializePrivate();
    return m_Private->m_WidthScalabilityFactor;
}

float Widget::heightScalabilityFactor()
{
    initializePrivate();
    return m_Private->m_HeightScalabilityFactor;
}

void Widget::acquireWidgetType(const Widget::Type type)
{
    initializePrivate();
qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
    if (Widget::T_SettingGeneral == type
      ||Widget::T_Camera == type
      ||Widget::T_BluetoothDial == type
      ||Widget::T_BluetoothSetting == type
      ||Widget::T_Power == type
      ||Widget::T_Acc == type)
    {
        qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<"currentWidgetType()"<<currentWidgetType()<<"type"<<type;
        if (currentWidgetType()!=type)
        {
            qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<"size"<<m_Private->sizeListPreemptiveType();
            if(0==m_Private->sizeListPreemptiveType())
            {
                m_Private->m_HolderType = currentWidgetType();
                qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<m_Private->m_HolderType;
            }
            qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<"type"<<type;
            m_Private->addListPreemptiveType(type);
            if(type == Widget::T_Camera || type == Widget::T_Acc)
            {
               qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
            }
            else
            {
               qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
               onWidgetTypeChange(type, m_Private->m_CurrentType, WidgetStatus::RequestShow);
            }
        }
    }
}

void Widget::releaseWidgetType(const Widget::Type type)
{
    initializePrivate();
qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<"type"<<type<<"m_PreemptiveType"
<<m_Private->qDebugListPreemptiveType()<<"currentWidgetType()"<<currentWidgetType()
<<"m_Private->m_HolderType"<<m_Private->m_HolderType;
    if (Widget::T_SettingGeneral == type
      ||Widget::T_Camera == type
      ||Widget::T_BluetoothDial == type
      ||Widget::T_Power == type
      ||Widget::T_Acc == type)
    {
        qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
        if (m_Private->inIndexofListPreemptiveType(type)!=-1)
        {
            qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
            if(m_Private->sizeListPreemptiveType()==1)
            {
                Widget::Type bk=m_Private->getListPreemptiveType(0);
                m_Private->removeListPreemptiveType(type);
                qDebug()<<__PRETTY_FUNCTION__<<__LINE__;
                onWidgetTypeChange(m_Private->m_HolderType, bk,  WidgetStatus::RequestShow);
            }
            else if(m_Private->sizeListPreemptiveType()>1)
            {
                qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<m_Private->qDebugListPreemptiveType();
                m_Private->removeListPreemptiveType(type);
                qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<m_Private->qDebugListPreemptiveType();
                if(m_Private->getListPreemptiveType(0)==Widget::T_BluetoothDial
                 ||m_Private->getListPreemptiveType(0)==Widget::T_Power)
                {

                    onWidgetTypeChange(m_Private->getListPreemptiveType(0), m_Private->getListPreemptiveType(0),  WidgetStatus::RequestShow);
                }
            }
        }
    }
}


int Widget::inIndexofListPreemptiveType(const Widget::Type type)
{
    m_Private->inIndexofListPreemptiveType(type);
}

QString Widget::qDebugListPreemptiveType()
{
    return m_Private->qDebugListPreemptiveType();
}

void Widget::setWidgetType(const Widget::Type destinationType, const Widget::Type requestType, const QString &status)
{
    initializePrivate();
    //qDebug()<<"lllllllllllllllllllllllllllllsetWidgetType"<<m_Private->m_CurrentType<<destinationType<<requestType<<status;
    if (WidgetStatus::Show == status) {
        m_Private->m_CurrentType = destinationType;
    }
    onWidgetTypeChange(destinationType, requestType,  status);
}

const Widget::Type Widget::currentWidgetType() const
{
    return m_Private->m_CurrentType;
}

const Widget::Type Widget::HolderTypeWidgetType() const
{
    return m_Private->m_HolderType;
}

void Widget::beep()
{
}


Widget::Widget(QObject *parent)
    : QObject(parent)
    , m_Private(new WidgetPrivate(this))
{
}

Widget::~Widget()
{
}

void Widget::initializePrivate()
{
    if (NULL == m_Private) {
        m_Private.reset(new WidgetPrivate(this));
    }
}

WidgetPrivate::WidgetPrivate(Widget* parent)
    : m_Parent(parent)
{
    m_HolderType = Widget::T_Undefine;
    clearListPreemptiveType();
    m_WidthScalabilityFactor = 1.000000f;
    m_HeightScalabilityFactor = 1.000000f;
    m_CurrentType = Widget::T_Radio;
    m_bacquireRun = 0;
    initialize();
    initHolderTypTimer();
}

WidgetPrivate::~WidgetPrivate()
{
    QResource::unregisterResource(m_Rcc);
}


void WidgetPrivate::initialize()
{
    QDesktopWidget* desktop = qApp->desktop();
    int pixelSize(20);
//#if defined(XGHD169)
//    if (600 != desktop->height()) {
//#else
    if (600 == desktop->height()) {
//#endif
        m_WidthScalabilityFactor = 1.28f;
        m_HeightScalabilityFactor = 1.25f;
        pixelSize = 25;
    }
    QFont font(QString("DejaVu Sans"));
    font.setPixelSize(pixelSize);

}

void WidgetPrivate::initHolderTypTimer()
{

}


void WidgetPrivate::clearListPreemptiveType()
{
    for (int i=0;i<HolderNum;i++) {
            m_ListPreemptiveType[i] = Widget::T_Undefine;
    }
}

int WidgetPrivate::sizeListPreemptiveType()
{
    int ret = 0;
    for (int i=0;i<HolderNum;i++) {
        if(Widget::T_Undefine == m_ListPreemptiveType[i])
            ret++;
    }
    return HolderNum-ret;
}

Widget::Type WidgetPrivate::getListPreemptiveType(const int index)
{
    return m_ListPreemptiveType[index];
}

void WidgetPrivate::addListPreemptiveType(const Widget::Type type)
{
    int i;
    for (i=0;i<HolderNum;i++) {
        if(m_ListPreemptiveType[i]==type)
        {
            qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<"type already exists";
            return;
        }
    }
    if(m_ListPreemptiveType[0]!=type)
    {
        int i;
        for (i=HolderNum-1;i>=0;i--) {
            m_ListPreemptiveType[i+1] = m_ListPreemptiveType[i];
        }
        m_ListPreemptiveType[0] = type;
    }
    qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<qDebugListPreemptiveType();
}

void WidgetPrivate::removeListPreemptiveType(const Widget::Type type)
{
    int i,index=0;
    for (i=0;i<HolderNum;) {
        if(m_ListPreemptiveType[i] == type)
        {
            index=i;
            break;
        }
        if(i==HolderNum-1)
        {
            qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<type<<"can not remove";
            return;
        }
        i++;
    }

    for (i=index;i<HolderNum-1;i++) {
        m_ListPreemptiveType[i] = m_ListPreemptiveType[i+1];
    }
    m_ListPreemptiveType[HolderNum-1] = Widget::T_Undefine;
}

bool WidgetPrivate::replaceListPreemptiveType(const Widget::Type source, const Widget::Type in)
{
    int i,ret(true);
    for (i=0;i<HolderNum;) {
        if(m_ListPreemptiveType[i]==source)
        {
            m_ListPreemptiveType[i] = in;
            break;
        }
        if(i==HolderNum-1)
        {
            ret = false;
        }
        i++;
    }
    return ret;
}

int WidgetPrivate::inIndexofListPreemptiveType(const Widget::Type type)
{
    int i,ret=-1;
    for (i=0;i<HolderNum;i++) {
        //qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<i<<m_ListPreemptiveType[i]<<type;
        if(m_ListPreemptiveType[i] == type)
        {
            qDebug()<<__PRETTY_FUNCTION__<<__LINE__<<"i"<<i<<"type"<<type;
            ret = i;
            break;
        }
    }
    return ret;
}

QString WidgetPrivate::qDebugListPreemptiveType()
{
    int i;
    QString str1,str2;
    for (i=0;i<HolderNum;i++) {
        str1+=QString("%1 ").arg(m_ListPreemptiveType[i]);
    }
    return str1;
}

