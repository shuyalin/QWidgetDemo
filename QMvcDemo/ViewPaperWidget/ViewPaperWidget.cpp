#include "ViewPaperWidget.h"
#include "AutoConnect/AutoConnect.h"
#include "ViewPaperTipWidget/ViewPaperTipWidget.h"
#include "uihelper.h"
#include <QEvent>
#include <QPalette>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QScrollBar>
#include <QStandardItemModel>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>

namespace SourceString {
static const QString Radio(QObject::tr("Radio"));
static const QString Bluetooth(QObject::tr("Bluetooth"));
static const QString SD(QObject::tr("SD"));
static const QString USB(QObject::tr("USB"));
static const QString Carlife(QObject::tr("Carlife"));
static const QString Carplay(QObject::tr("Carplay"));
static const QString CarInfo(QObject::tr("CarInfo"));
static const QString Link(QObject::tr("Link"));
static const QString ECLink(QObject::tr("ECLinkPHone"));
static const QString HiCar(QObject::tr("HiCar"));
static const QString AUX(QObject::tr("AUX"));
static const QString Camera(QObject::tr("Camera"));
static const QString Steering(QObject::tr("Steering"));
static const QString Setting(QObject::tr("Setting"));
static const QString airconditioner(QObject::tr("conditioner"));
static const QString Assist(QObject::tr("Touch"));
static const QString CarDotor(QObject::tr("CarDotor"));
static const QString Navi(QObject::tr("Navi"));
}

namespace SourceStringS {
static const QString Monitor(QObject::tr("Monitor"));
static const QString Area360(QObject::tr("360Area"));
}

class ViewPaperVariant
{
public:
    enum ButtonStatus {
        B_Normal = 0,
        B_Press = 1,
    };
    ViewPaperVariant();
    ~ViewPaperVariant();
    QList<QRect> m_IconRectList;
    QList<QRect> m_TextRectList;
    QList<QPixmap*> m_NormalList;
    QList<QPixmap*> m_PressList;
    QList<QString> m_TextList;
    QList<ViewPaperVariant::ButtonStatus> m_StatusList;
};
Q_DECLARE_METATYPE(ViewPaperVariant)

struct ItemData {
    UiHelper::Type m_Type;
    QString m_Title;
    QString m_Normal;
    QString m_Press;
};

class ViewPaperItemDelegate;
class ViewPaperWidgetPrivate
{
    Q_DISABLE_COPY(ViewPaperWidgetPrivate)
public:
    explicit ViewPaperWidgetPrivate(ViewPaperWidget* parent);
    ~ViewPaperWidgetPrivate();
    void initializeParent();
    void initializeBasic();
    void reload();
    void initializeBasicWidget();
    void initializePropertyAnimation();
    void initializeFirstView();
    void initializeSecondView();
    void initializeThirdView();
    void firstViewPaperHandler(const unsigned int index);
    void secondViewPaperHandler(const unsigned int index);
    void thirdViewPaperHandler(const unsigned int index);
private:
    Q_DECLARE_PUBLIC(ViewPaperWidget)
    ViewPaperWidget* const q_ptr;
    ViewPaperTipWidget* m_ViewPaperTipWidget;
    ViewPaperItemDelegate* m_ViewPaperItemDelegate;
    QStandardItemModel* m_StandardItemModel;
    bool m_Finish;
    bool m_Filter;
    QPoint m_StartMovePoint;
    unsigned short m_Threshold;
    ViewPaperVariant m_FirstViewPaperVariant;
    ViewPaperVariant m_SecondViewPaperVariant;
    ViewPaperVariant m_ThirdViewPaperVariant;
    QPropertyAnimation m_PropertyAnimation;
    unsigned short m_CurrentViewPapger;
    QMap<unsigned int, struct ItemData> m_MapType;
    bool m_Reload;
    bool m_Move;
};

ViewPaperWidget::ViewPaperWidget(QWidget *parent)
    : QListView(parent)
    , d_ptr(new ViewPaperWidgetPrivate(this))
{
}

ViewPaperWidget::~ViewPaperWidget()
{
    if (NULL != d_ptr) {
        delete d_ptr;
    }
}

void ViewPaperWidget::styleChange()
{
    Q_D(ViewPaperWidget);
    d->m_Reload = true;
}

void ViewPaperWidget::resizeEvent(QResizeEvent *event)
{
    UiHelper::instance()->geometryFit(0, 302, 800, 178, this);
}

void ViewPaperWidget::mousePressEvent(QMouseEvent *event)
{
    Q_D(ViewPaperWidget);
    d->initializePropertyAnimation();
    d->initializeSecondView();
    d->initializeThirdView();
    if (d->m_Finish) {
        if (rect().contains(event->pos())) {
            d->m_StartMovePoint = event->pos();
            d->m_Filter = false;
            QModelIndex modelIndex = indexAt(event->pos());
            if (modelIndex.isValid()) {
                update(modelIndex);
            }
        }
        QListView::mousePressEvent(event);
    }
}

void ViewPaperWidget::mouseMoveEvent(QMouseEvent *event)
{
    Q_D(ViewPaperWidget);
    if (d->m_Move) {
        if (d->m_Finish) {
            if (rect().contains(event->pos())) {
                QPoint relativePos = d->m_StartMovePoint - event->pos();
                int deltaEnd = event->pos().x() - d->m_StartMovePoint.x();
                if (d->m_Filter) {
                    d->m_StartMovePoint = event->pos();
                    horizontalScrollBar()->setValue(horizontalOffset() + relativePos.x());
                } else if ((qAbs(deltaEnd) > d->m_Threshold)) {
                    d->m_Filter = true;
                    d->m_StartMovePoint = event->pos();
                    if (relativePos.x() > 0) {
                        horizontalScrollBar()->setValue(horizontalOffset() + relativePos.x() - d->m_Threshold);
                    } else {
                        horizontalScrollBar()->setValue(horizontalOffset() + relativePos.x() + d->m_Threshold);
                    }
                }
            }
            QListView::mouseReleaseEvent(event);
        }
    }
}

void ViewPaperWidget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "ViewPaperWidget::mouseReleaseEvent";

    Q_D(ViewPaperWidget);
    qDebug() <<"d->m_Finish:" << d->m_Finish;

    if (d->m_Finish) {
        int width = 800 * SCALED_FACTOR_X;
        int distance = 160 *  SCALED_FACTOR_X;
        int offset = horizontalOffset() % width;
        int third = horizontalOffset() / width;
        if(third == 0){
            if (0 != offset) {
                if (offset < distance) {
                    d->m_PropertyAnimation.setStartValue(horizontalOffset());
                    d->m_PropertyAnimation.setEndValue(0);
                    d->m_CurrentViewPapger = 0;
                    d->m_Finish = false;
                    d->m_PropertyAnimation.start();
                } else if ((offset >= distance) && (offset <= (width - distance))) {
                    d->m_PropertyAnimation.setStartValue(horizontalOffset());
                    if (0 == d->m_CurrentViewPapger) {
                        d->m_PropertyAnimation.setEndValue(width);
                        d->m_CurrentViewPapger = 1;
                    } else if (1 == d->m_CurrentViewPapger) {
                        d->m_PropertyAnimation.setEndValue(0);
                        d->m_CurrentViewPapger = 0;
                    }
                    d->m_Finish = false;
                    d->m_PropertyAnimation.start();
                } else if (offset > (width - distance)) {
                    d->m_PropertyAnimation.setStartValue(horizontalOffset());
                    d->m_PropertyAnimation.setEndValue(width);
                    d->m_CurrentViewPapger = 1;
                    d->m_Finish = false;
                    d->m_PropertyAnimation.start();
                }
            }
        }else if(third == 1){
            if (0 != offset) {
                if (offset < distance) {
                    d->m_PropertyAnimation.setStartValue(horizontalOffset());
                    d->m_PropertyAnimation.setEndValue(width);
                    d->m_CurrentViewPapger = 1;
                    d->m_Finish = false;
                    d->m_PropertyAnimation.start();
                } else if ((offset >= distance) && (offset <= (width - distance))) {
                    d->m_PropertyAnimation.setStartValue(horizontalOffset());
                    if (0 == d->m_CurrentViewPapger) {
                        d->m_PropertyAnimation.setEndValue(width+width);
                        d->m_CurrentViewPapger = 2;
                    } else if (1 == d->m_CurrentViewPapger) {
                        d->m_PropertyAnimation.setEndValue(width+width);
                        d->m_CurrentViewPapger = 2;
                    }else{
                        d->m_PropertyAnimation.setEndValue(width);
                        d->m_CurrentViewPapger = 1;
                        d->m_Finish = false;
                        d->m_PropertyAnimation.start();
                    }
                    d->m_Finish = false;
                    d->m_PropertyAnimation.start();
                } else if (offset > (width - distance)) {
                    d->m_PropertyAnimation.setStartValue(horizontalOffset());
                    d->m_PropertyAnimation.setEndValue(width);
                    d->m_CurrentViewPapger = 1;
                    d->m_Finish = false;
                    d->m_PropertyAnimation.start();
                }
            }
        }
        d->m_Filter = false;
        QListView::mouseReleaseEvent(event);
    }
}

void ViewPaperWidget::setHorizontalOffset(int value)
{
    QScrollBar* scrollBar = horizontalScrollBar();
    if (NULL != scrollBar) {
        if (value % width() == 0) {
            Q_D(ViewPaperWidget);
            d->m_Finish = true;
        }
        scrollBar->setValue(value);
    }
}



void ViewPaperWidget::onButtonRelease(const unsigned int index)
{
    qDebug()<<"DDDDDDDDDDDDDDDDDDDDDD "<<index;
    Q_D(ViewPaperWidget);
    if (isVisible()) {
        switch (d->m_CurrentViewPapger) {
        case 0: {
            d->firstViewPaperHandler(index);
            break;
        }
        case 1: {
            d->secondViewPaperHandler(index);
            break;
        }
        case 2: {
            d->thirdViewPaperHandler(index);
            break;
        }
        default: {
            break;
        }
        }
    }
}

ViewPaperWidgetPrivate::ViewPaperWidgetPrivate(ViewPaperWidget *parent)
    : q_ptr(parent)
{
    m_ViewPaperTipWidget = NULL;
    m_ViewPaperItemDelegate = NULL;
    m_StandardItemModel = NULL;
    m_Finish = true;
    m_Filter = false;
    m_StartMovePoint = QPoint(0, 0);
    m_Threshold = 10;
    m_FirstViewPaperVariant;
    m_SecondViewPaperVariant;
    m_ThirdViewPaperVariant;
    m_PropertyAnimation;
    m_CurrentViewPapger = -1;
    m_Reload = false;
    m_Move = true;
    initializeBasic();
    initializeBasicWidget();
    initializeParent();
}

ViewPaperWidgetPrivate::~ViewPaperWidgetPrivate()
{
    for (QList<QPixmap*>::Iterator iter = m_FirstViewPaperVariant.m_NormalList.begin();
         iter != m_FirstViewPaperVariant.m_NormalList.end(); ++iter) {
        delete *iter;
    }
    for (QList<QPixmap*>::Iterator iter = m_FirstViewPaperVariant.m_PressList.begin();
         iter != m_FirstViewPaperVariant.m_PressList.end(); ++iter) {
        delete *iter;
    }
}

void ViewPaperWidgetPrivate::initializeParent()
{
    Q_Q(ViewPaperWidget);
    QPalette palette = q->palette();
    palette.setBrush(QPalette::Base, Qt::NoBrush);
    q->setPalette(palette);
    q->setFlow(QListView::LeftToRight);
    q->setFrameShape(QListView::NoFrame);
    q->setHorizontalScrollMode(QListView::ScrollPerPixel);
    q->setEditTriggers(QListView::NoEditTriggers);
    q->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    q->setItemDelegate(m_ViewPaperItemDelegate);
    Qt::ConnectionType type = static_cast<Qt::ConnectionType>(Qt::UniqueConnection | Qt::AutoConnection);
    QObject::connect(m_ViewPaperItemDelegate, ARKSENDER(buttonRelease(const unsigned int)),
                     q,                       ARKRECEIVER(onButtonRelease(const unsigned int)),
                     type);
    q->setModel(m_StandardItemModel);
    q->setVisible(false);
}

void ViewPaperWidgetPrivate::initializeBasic()
{
    Q_Q(ViewPaperWidget);
    if (NULL == m_StandardItemModel) {
        m_StandardItemModel = new QStandardItemModel(q);
    }
#if defined(XGHD169)
    struct ItemData data;
    data.m_Type = Widget::T_Radio;
    data.m_Title = QString("Radio");
    data.m_Normal = QString(":/Images/ViewPaperWidgetRadioNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetRadioPress.png");
    m_MapType.insert(m_MapType.size(), data);

    data.m_Type = Widget::T_Bluetooth;
    data.m_Title = QString("Bluetooth");
    data.m_Normal = QString(":/Images/ViewPaperWidgetBluetoothNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetBluetoothPress.png");
    m_MapType.insert(m_MapType.size(), data);

    data.m_Type = Widget::T_USBDisk;
    data.m_Title = QString("USB");
    data.m_Normal = QString(":/Images/ViewPaperWidgetUSBNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetUSBPress.png");
    m_MapType.insert(m_MapType.size(), data);

#ifdef ENABLE_CARINFO
    data.m_Type = Widget::T_CarInfoWindget;
    data.m_Title = QString("CarInfo");
    data.m_Normal = QString(":/Images/ViewPaperWidgetCarInfoNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetCarInfoPress.png");
    m_MapType.insert(m_MapType.size(), data);
#endif

#ifdef ENABLE_LINK
    if (CLT_ECLink != SettingPersistent::getCarLinkType()) {
        data.m_Type = Widget::T_Link;
        data.m_Title = QString("Link");
        data.m_Normal = QString(":/Images/ViewPaperWidgetLinkNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetLinkPress.png");
        m_MapType.insert(m_MapType.size(), data);
    } else {
        data.m_Type = Widget::T_Link;
        data.m_Title = SourceString::ECLink;
        data.m_Normal = QString(":/Images/ViewPaperWidgetECLinkNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetECLinkPress.png");
        m_MapType.insert(m_MapType.size(), data);
    }
#endif

#ifdef ENABLE_CARLIFE
#ifdef ENABLE_AUTO
        if (CLT_CarlifeCarplay == SettingPersistent::getCarLinkType()) {
#endif
            data.m_Type = Widget::T_Carlife;
            data.m_Title = QString("Carlife");
            data.m_Normal = QString(":/Images/ViewPaperWidgetCarlifeNormal.png");
            data.m_Press = QString(":/Images/ViewPaperWidgetCarlifePress.png");
            m_MapType.insert(m_MapType.size(), data);
#ifdef ENABLE_AUTO
        } else {
            data.m_Type = Widget::T_CarAuto;
            data.m_Title = QString("Auto");
            data.m_Normal = QString(":/Images/ViewPaperWidgetAutoNormal.png");
            data.m_Press = QString(":/Images/ViewPaperWidgetAutoPress.png");
            m_MapType.insert(m_MapType.size(), data);
        }
#endif
#endif

#ifdef ENABLE_CARPLAY
        data.m_Type = Widget::T_Carplay;
        data.m_Title = QString("Carplay");
        data.m_Normal = QString(":/Images/ViewPaperWidgetCarplayNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetCarplayPress.png");
        m_MapType.insert(m_MapType.size(), data);
#endif

#ifdef ENABLE_STEERING
        data.m_Type = Widget::T_Steering;
        data.m_Title = QString("Steering");
        data.m_Normal = QString(":/Images/ViewPaperWidgetPanelNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetPanelPress.png");
        m_MapType.insert(m_MapType.size(), data);
#endif
#if 0
        data.m_Type = Widget::T_Setting;
        data.m_Title = QString("Setting");
        data.m_Normal = QString(":/Images/ViewPaperWidgetSettingNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetSettingPress.png");
        m_MapType.insert(m_MapType.size(), data);
#endif
#else
    struct ItemData data;
    data.m_Type = UiHelper::T_Radio;
    data.m_Title = QString("Radio");
    data.m_Normal = QString(":/Images/ViewPaperWidgetRadioNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetRadioPress.png");
    m_MapType.insert(m_MapType.size(), data);

//#ifdef ENABLE_BT
    data.m_Type = UiHelper::T_Bluetooth;
    data.m_Title = QString("Bluetooth");
    data.m_Normal = QString(":/Images/ViewPaperWidgetBluetoothNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetBluetoothPress.png");
    m_MapType.insert(m_MapType.size(), data);
//#endif

#ifdef ENABLE_SD
    data.m_Type = Widget::T_SDDisk;
    data.m_Title = QString("SD");
    data.m_Normal = QString(":/Images/ViewPaperWidgetSDNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetSDPress.png");
    m_MapType.insert(m_MapType.size(), data);
#endif

//#ifdef ENABLE_USB
    data.m_Type = UiHelper::T_USBDisk;
    data.m_Title = QString("USB");
    data.m_Normal = QString(":/Images/ViewPaperWidgetUSBNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetUSBPress.png");
    m_MapType.insert(m_MapType.size(), data);
//#endif

    data.m_Type = UiHelper::T_Link;
    data.m_Title = SourceString::ECLink;
    data.m_Normal = QString(":/Images/ViewPaperWidgetECLinkNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetECLinkPress.png");
    m_MapType.insert(m_MapType.size(), data);

#ifdef ENABLE_LINK
    qDebug() << __PRETTY_FUNCTION__ <<"line:"<< __LINE__<<"getCarLinkType :"<<SettingPersistent::getCarLinkType();
    if (CLT_ECLink == SettingPersistent::getCarLinkType()) {
        data.m_Type = Widget::T_Link;
        data.m_Title = SourceString::ECLink;
        data.m_Normal = QString(":/Images/ViewPaperWidgetECLinkNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetECLinkPress.png");
        m_MapType.insert(m_MapType.size(), data);
    }
#ifdef ENABLE_HICAR
    else if(CLT_HICAR == SettingPersistent::getCarLinkType()){
        data.m_Type = Widget::T_Link;
        data.m_Title = SourceString::HiCar;
        data.m_Normal = QString(":/Images/ViewPaperWidgetHiCarNormal.png");//add by wandz for huawei hicar
        data.m_Press = QString(":/Images/ViewPaperWidgetHiCarPress.png");
        m_MapType.insert(m_MapType.size(), data);
    }
#endif
    else {
        data.m_Type = Widget::T_Link;
        data.m_Title = QString("Link");
        data.m_Normal = QString(":/Images/ViewPaperWidgetLinkNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetLinkPress.png");
        m_MapType.insert(m_MapType.size(), data);
    }
#endif

#ifdef ENABLE_PHOTO
    data.m_Type = Widget::T_PhotoBrowerWidget;
    data.m_Title = QString("Photo");
    data.m_Normal = QString(":/images/PhotoIconNormal.png");
    data.m_Press = QString(":/images/PhotoIconPress.png");
    m_MapType.insert(m_MapType.size(), data);
#endif

//#ifdef ENABLE_CAMERA
    data.m_Type = UiHelper::T_Camera;
    #if defined(ENABLE_HC_WL)
        data.m_Title = QString("360Area");//360°全景
        data.m_Normal = QString(":/images/CarBack360degreeNormal.png");
        data.m_Press = QString(":/images/CarBack360degreePress.png");
    #else
        data.m_Title = QString("Camera");
        data.m_Normal = QString(":/Images/ViewPaperWidgetCameraNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetCameraPress.png");
    #endif
    m_MapType.insert(m_MapType.size(), data);
//#endif

//#ifdef ENABLE_AUX
    data.m_Type = UiHelper::T_AUX;
    #if defined(ENABLE_HC_WL)
        data.m_Title = QString("Monitor");//视频监控
        data.m_Normal = QString(":/Images/ViewPaperWidgetCameraNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetCameraPress.png");
    #else
        data.m_Title = QString("AUX");
        data.m_Normal = QString(":/Images/ViewPaperWidgetAUXNormal.png");
        data.m_Press = QString(":/Images/ViewPaperWidgetAUXPress.png");
    #endif
    m_MapType.insert(m_MapType.size(), data);
//#endif

#ifdef ENABLE_STEERING
    data.m_Type = Widget::T_Steering;
    data.m_Title = QString("Steering");
    data.m_Normal = QString(":/Images/ViewPaperWidgetPanelNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetPanelPress.png");
    m_MapType.insert(m_MapType.size(), data);
#endif

#ifdef ENABLE_NAVI
    data.m_Type = Widget::T_Navi;
    data.m_Title = QString("Navi");
    data.m_Normal = QString(":/Images/ViewPaperWidgetPanelNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetPanelPress.png");
    m_MapType.insert(m_MapType.size(), data);
#endif

    data.m_Type = UiHelper::T_airconditioner;
    data.m_Title = SourceString::airconditioner;
    data.m_Normal = QString(":/Images/ViewPaperWidgetConditionerNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetConditionerPress.png");
    m_MapType.insert(m_MapType.size(), data);

    data.m_Type = UiHelper::T_CarDotor;
    data.m_Title = SourceString::CarDotor;
    data.m_Normal = QString(":/Images/ViewPaperWidgetCarDotorNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetCarDotorPress.png");
    m_MapType.insert(m_MapType.size(), data);


    data.m_Type = UiHelper::T_Assist;
    data.m_Title = SourceString::Assist;
    data.m_Normal = QString(":/Images/ViewPaperWidgetAssistNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetAssistPress.png");
    m_MapType.insert(m_MapType.size(), data);

    data.m_Type = UiHelper::T_Setting;
    data.m_Title = QString("Setting");
    data.m_Normal = QString(":/Images/ViewPaperWidgetSettingNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetSettingPress.png");
    m_MapType.insert(m_MapType.size(), data);

    data.m_Type = UiHelper::T_VoiceAssistant;
    data.m_Title = QString("Navi");
    data.m_Normal = QString(":/Images/ViewPaperWidgetSettingNormal.png");
    data.m_Press = QString(":/Images/ViewPaperWidgetSettingPress.png");
    m_MapType.insert(m_MapType.size(), data);
#endif
    initializeFirstView();
}

void ViewPaperWidgetPrivate::reload()
{
    for (int iter = 0;
         iter < m_FirstViewPaperVariant.m_NormalList.count();
         ++iter) {
        delete m_FirstViewPaperVariant.m_NormalList.at(iter);
        m_FirstViewPaperVariant.m_NormalList.replace(iter, new QPixmap(m_MapType[iter].m_Normal));
    }

    for (int iter = 0;
         iter < m_FirstViewPaperVariant.m_PressList.count();
         ++iter) {
        delete m_FirstViewPaperVariant.m_PressList.at(iter);
        m_FirstViewPaperVariant.m_PressList.replace(iter, new QPixmap(m_MapType[iter].m_Press));
    }
    QStandardItem* firstItem = new QStandardItem();
    firstItem->setSizeHint(QSize(800 * SCALED_FACTOR_X, 178 * SCALED_FACTOR_Y));
    firstItem->setData(qVariantFromValue(m_FirstViewPaperVariant), Qt::UserRole);
    m_StandardItemModel->setItem(0, 0, firstItem);

    for (int iter = 0;
         iter < m_SecondViewPaperVariant.m_NormalList.count();
         ++iter) {
        delete m_SecondViewPaperVariant.m_NormalList.at(iter);
        m_SecondViewPaperVariant.m_NormalList.replace(iter, new QPixmap(m_MapType[0 + iter].m_Normal));
    }

    for (int iter = 0;
         iter < m_SecondViewPaperVariant.m_PressList.count();
         ++iter) {
        delete m_SecondViewPaperVariant.m_PressList.at(iter);
        m_SecondViewPaperVariant.m_PressList.replace(iter, new QPixmap(m_MapType[0 + iter].m_Press));
    }
    QStandardItem* secondItem = new QStandardItem();
    secondItem->setSizeHint(QSize(800 * SCALED_FACTOR_X, 178 * SCALED_FACTOR_Y));
    secondItem->setData(qVariantFromValue(m_SecondViewPaperVariant), Qt::UserRole);
    m_StandardItemModel->setItem(1, 0, secondItem);

    for (int iter = 0;
         iter < m_ThirdViewPaperVariant.m_NormalList.count();
         ++iter) {
        delete m_ThirdViewPaperVariant.m_NormalList.at(iter);
        m_ThirdViewPaperVariant.m_NormalList.replace(iter, new QPixmap(m_MapType[0 + iter].m_Normal));
    }

    for (int iter = 0;
         iter < m_ThirdViewPaperVariant.m_PressList.count();
         ++iter) {
        delete m_ThirdViewPaperVariant.m_PressList.at(iter);
        m_ThirdViewPaperVariant.m_PressList.replace(iter, new QPixmap(m_MapType[0 + iter].m_Press));
    }
    QStandardItem* thirdItem = new QStandardItem();
    thirdItem->setSizeHint(QSize(800 * SCALED_FACTOR_X, 178 * SCALED_FACTOR_Y));
    thirdItem->setData(qVariantFromValue(m_ThirdViewPaperVariant), Qt::UserRole);
    m_StandardItemModel->setItem(2, 0, thirdItem);
}

void ViewPaperWidgetPrivate::initializeBasicWidget()
{
    Q_Q(ViewPaperWidget);
#ifndef LUYUAN169
    if (m_MapType.size() > 5) {
        if (NULL == m_ViewPaperTipWidget) {
            m_ViewPaperTipWidget = new ViewPaperTipWidget(q);
        }
    }
#endif
    if (NULL == m_ViewPaperItemDelegate) {
        m_ViewPaperItemDelegate = new ViewPaperItemDelegate(q);
    }
}

void ViewPaperWidgetPrivate::initializePropertyAnimation()
{
    static bool flag(true);
    if (flag) {
        flag = false;
        Q_Q(ViewPaperWidget);
        m_PropertyAnimation.setTargetObject(q);
        m_PropertyAnimation.setDuration(500);
        m_PropertyAnimation.setPropertyName(QByteArray("horizontalOffset"));
        Qt::ConnectionType type = static_cast<Qt::ConnectionType>(Qt::UniqueConnection | Qt::AutoConnection);
        QObject::connect(&m_PropertyAnimation, ARKSENDER(finished()),
                         q,                    ARKRECEIVER(onFinished()),
                         type);
    }
}

void ViewPaperWidgetPrivate::initializeFirstView()
{
    static bool flag(true);
    if (flag) {
        flag = false;
        Q_Q(ViewPaperWidget);
        m_CurrentViewPapger = 0;
        m_FirstViewPaperVariant.m_StatusList.clear();
        m_FirstViewPaperVariant.m_IconRectList.clear();
        m_FirstViewPaperVariant.m_TextRectList.clear();
        m_FirstViewPaperVariant.m_TextList.clear();
        m_FirstViewPaperVariant.m_NormalList.clear();
        m_FirstViewPaperVariant.m_PressList.clear();
#ifdef LUYUAN169
        int count = 4;
        m_Move = false;
#else
        int count = 5;
#endif
        int step = (800 - 106 * count) / (count + 1);
        for (int i = 0; i < count; ++i) {
            m_FirstViewPaperVariant.m_StatusList.append(ViewPaperVariant::B_Normal);
            m_FirstViewPaperVariant.m_IconRectList.append(UiHelper::instance()->geometryFit(step + (step + 106) * i, 37, 106, 106));
            m_FirstViewPaperVariant.m_TextRectList.append(UiHelper::instance()->geometryFit(step + (step + 106) * i, 178 - 40, 106, 40));
            m_FirstViewPaperVariant.m_TextList.append(m_MapType[i].m_Title);
            m_FirstViewPaperVariant.m_NormalList.append(new QPixmap(m_MapType[i].m_Normal));
            m_FirstViewPaperVariant.m_PressList.append(new QPixmap(m_MapType[i].m_Press));
        }
        QStandardItem* firstItem = new QStandardItem();
        firstItem->setSizeHint(QSize(800 * SCALED_FACTOR_X, 178 * SCALED_FACTOR_Y));
        firstItem->setData(qVariantFromValue(m_FirstViewPaperVariant), Qt::UserRole);
        m_StandardItemModel->setItem(0, 0, firstItem);
    }
}

void ViewPaperWidgetPrivate::initializeSecondView()
{
    static bool flag(true);
    if (flag) {
        flag = false;
        Q_Q(ViewPaperWidget);
        m_SecondViewPaperVariant.m_StatusList.clear();
        m_SecondViewPaperVariant.m_StatusList.clear();
        m_SecondViewPaperVariant.m_IconRectList.clear();
        m_SecondViewPaperVariant.m_TextRectList.clear();
        m_SecondViewPaperVariant.m_TextList.clear();
        m_SecondViewPaperVariant.m_NormalList.clear();
        m_SecondViewPaperVariant.m_PressList.clear();
        //int count = m_MapType.size() - 5;
        int count = 5;
        if (count > 0) {
            for (int i = 0; i < count; ++i) {
                m_SecondViewPaperVariant.m_StatusList.append(ViewPaperVariant::B_Normal);
                m_SecondViewPaperVariant.m_IconRectList.append(UiHelper::instance()->geometryFit(45 + (45 + 106) * i, 37, 106, 106));
                m_SecondViewPaperVariant.m_TextRectList.append(UiHelper::instance()->geometryFit(45 + (45 + 106) * i, 178 - 40, 106, 40));
                m_SecondViewPaperVariant.m_TextList.append(m_MapType[5 + i].m_Title);
                m_SecondViewPaperVariant.m_NormalList.append(new QPixmap(m_MapType[5 + i].m_Normal));
                m_SecondViewPaperVariant.m_PressList.append(new QPixmap(m_MapType[5 + i].m_Press));
            }
            QStandardItem* secondItem = new QStandardItem();
            secondItem->setSizeHint(QSize(800 * SCALED_FACTOR_X, 178 * SCALED_FACTOR_Y));
            secondItem->setData(qVariantFromValue(m_SecondViewPaperVariant), Qt::UserRole);
            m_StandardItemModel->setItem(1, 0, secondItem);
        }
    }
}

void ViewPaperWidgetPrivate::initializeThirdView()
{
    static bool flag(true);
    if (flag) {
        flag = false;
        Q_Q(ViewPaperWidget);
        m_ThirdViewPaperVariant.m_StatusList.clear();
        m_ThirdViewPaperVariant.m_StatusList.clear();
        m_ThirdViewPaperVariant.m_IconRectList.clear();
        m_ThirdViewPaperVariant.m_TextRectList.clear();
        m_ThirdViewPaperVariant.m_TextList.clear();
        m_ThirdViewPaperVariant.m_NormalList.clear();
        m_ThirdViewPaperVariant.m_PressList.clear();
        int count = m_MapType.size() - 10;
        if (count > 0) {
            for (int i = 0; i < count; ++i) {
                m_ThirdViewPaperVariant.m_StatusList.append(ViewPaperVariant::B_Normal);
                m_ThirdViewPaperVariant.m_IconRectList.append(UiHelper::instance()->geometryFit(45 + (45 + 106) * i, 37, 106, 106));
                m_ThirdViewPaperVariant.m_TextRectList.append(UiHelper::instance()->geometryFit(45 + (45 + 106) * i, 178 - 40, 106, 40));
                m_ThirdViewPaperVariant.m_TextList.append(m_MapType[10 + i].m_Title);
                m_ThirdViewPaperVariant.m_NormalList.append(new QPixmap(m_MapType[10 + i].m_Normal));
                m_ThirdViewPaperVariant.m_PressList.append(new QPixmap(m_MapType[10 + i].m_Press));
            }
            QStandardItem* thirdItem = new QStandardItem();
            thirdItem->setSizeHint(QSize(800 * SCALED_FACTOR_X, 178 * SCALED_FACTOR_Y));
            thirdItem->setData(qVariantFromValue(m_ThirdViewPaperVariant), Qt::UserRole);
            m_StandardItemModel->setItem(2, 0, thirdItem);
        }
    }
}

void ViewPaperWidgetPrivate::firstViewPaperHandler(const unsigned int index)
{
    emit q_ptr->pushStr(m_MapType.value(index % 5).m_Title);
}

void ViewPaperWidgetPrivate::secondViewPaperHandler(const unsigned int index)
{
    emit q_ptr->pushStr(m_MapType.value((index-5) % 5).m_Title);
}

void ViewPaperWidgetPrivate::thirdViewPaperHandler(const unsigned int index)
{
    emit q_ptr->pushStr(m_MapType.value((index-10) % 5).m_Title);
}
ViewPaperItemDelegate::ViewPaperItemDelegate(QObject *parent)
    : CustomItemDelegate(parent)
{
    m_StartMovePoint = QPoint(0, 0);
    m_Filter = false;
}

ViewPaperItemDelegate::~ViewPaperItemDelegate()
{
}

void ViewPaperItemDelegate::mousePressEvent(QMouseEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    ViewPaperVariant variant = qvariant_cast<ViewPaperVariant>(index.data(Qt::UserRole));
    for (int i = 0; i < variant.m_IconRectList.size(); ++i) {
        QRect rect(variant.m_IconRectList.at(i).x() + option.rect.x(),
                   variant.m_IconRectList.at(i).y() + option.rect.y(),
                   variant.m_IconRectList.at(i).width(),
                   variant.m_IconRectList.at(i).height());
        if (variant.m_StatusList.size() > i) {
            if (rect.contains(event->pos())) {
                m_StartMovePoint = event->pos();
                m_Filter = false;
                variant.m_StatusList.replace(i, ViewPaperVariant::B_Press);
                model->setData(index, qVariantFromValue(variant), Qt::UserRole);
                break;
            }
        }
    }
}

void ViewPaperItemDelegate::mouseMoveEvent(QMouseEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (!m_Filter) {
        int deltaEnd = event->pos().x() - m_StartMovePoint.x();
        if (qAbs(deltaEnd) > 10) {
            m_Filter = true;
            m_StartMovePoint = QPoint(0, 0);
            ViewPaperVariant variant = qvariant_cast<ViewPaperVariant>(index.data(Qt::UserRole));
            for (int i = 0; i < variant.m_StatusList.size(); ++i) {
                if (variant.m_StatusList.size() > i) {
                    if (ViewPaperVariant::B_Normal != variant.m_StatusList.at(i)) {
                        variant.m_StatusList.replace(i, ViewPaperVariant::B_Normal);
                        model->setData(index, qVariantFromValue(variant), Qt::UserRole);
                        break;
                    }
                }
            }
        }
    }
}

void ViewPaperItemDelegate::mouseReleaseEvent(QMouseEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    ViewPaperVariant variant = qvariant_cast<ViewPaperVariant>(index.data(Qt::UserRole));
    for (int i = 0; i < variant.m_IconRectList.size(); ++i) {
        if (variant.m_StatusList.size() > i) {
            if (ViewPaperVariant::B_Press == variant.m_StatusList.at(i)) {
                buttonRelease(i);
            }
            variant.m_StatusList.replace(i, ViewPaperVariant::B_Normal);
            model->setData(index, qVariantFromValue(variant), Qt::UserRole);
        }
    }
}

void ViewPaperItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->setPen(Qt::white);
    painter->setFont(QFont(QString(),22));
    ViewPaperVariant variant = qvariant_cast<ViewPaperVariant>(index.data(Qt::UserRole));
    for (int i = 0; i < variant.m_StatusList.size(); ++i) {
        switch (variant.m_StatusList.at(i)) {
        case ViewPaperVariant::B_Normal: {
            if ((variant.m_NormalList.size() > i)
                    && (NULL != variant.m_NormalList.at(i))) {
                QRect normalRect(variant.m_IconRectList.at(i).x() + option.rect.x(),
                                 variant.m_IconRectList.at(i).y() + option.rect.y(),
                                 variant.m_IconRectList.at(i).width(),
                                 variant.m_IconRectList.at(i).height());
                painter->drawPixmap(normalRect.x(), normalRect.y(), *variant.m_NormalList.at(i));
            }
            break;
        }
        case ViewPaperVariant::B_Press: {
            if ((variant.m_PressList.size() > i)
                    && (NULL != variant.m_PressList.at(i))) {
                QRect pressRect(variant.m_IconRectList.at(i).x() + option.rect.x(),
                                variant.m_IconRectList.at(i).y() + option.rect.y(),
                                variant.m_IconRectList.at(i).width(),
                                variant.m_IconRectList.at(i).height());
                painter->drawPixmap(pressRect.x(), pressRect.y(), *variant.m_PressList.at(i));
            }
            break;
        }
        default: {
            break;
        }
        }
        if (variant.m_TextRectList.size() > i) {
            QRect textRect(variant.m_TextRectList.at(i).x() + option.rect.x(),
                           variant.m_TextRectList.at(i).y() + option.rect.y(),
                           variant.m_TextRectList.at(i).width(),
                           variant.m_TextRectList.at(i).height());
            painter->drawText(textRect, Qt::AlignCenter, QObject::tr(variant.m_TextList.at(i).toLocal8Bit().constData()));
        }
    }
}

ViewPaperVariant::ViewPaperVariant()
{
}

ViewPaperVariant::~ViewPaperVariant()
{
}
