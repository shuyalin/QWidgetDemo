﻿#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QRect>
#include <QScopedPointer>
#include <QApplication>
namespace WidgetStatus {
static const QString RequestShow("RequestShow");
static const QString RequestHide("RequestHide");
static const QString Show("Show");
}

class WidgetPrivate;
class Widget : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Widget)
#ifdef g_Widget
#undef g_Widget
#endif
#define g_Widget (Widget::instance())
public:
    enum Type {
        T_Undefine = -1,
        T_Back = 0,
        T_Home = 1,
        T_ViewPaper0 = 2,
        T_ViewPaper1 = 3,
        T_Radio = 4,
        T_Bluetooth = 5,
        T_BluetoothDial = 6,//拨号盘
        T_BluetoothContact = 7,//联系人/电话簿
        T_BluetoothRecord = 8,//通话记录
        T_BluetoothMusic = 9,
        T_BluetoothSetting = 10,
        T_SDDisk = 11,
        T_SDDiskMusic = 12,
        T_SDDiskImage = 13,
        T_SDDiskVideo = 14,
        T_SDMusic = 15,
        T_SDImage = 16,
        T_SDImageFullScreen = 17,
        T_SDVideo = 18,
        T_SDVideoFullScreen = 19,
        T_USBDisk = 20,
        T_USBDiskMusic = 21,
        T_USBDiskImage = 22,
        T_USBDiskVideo = 23,
        T_USBMusic = 24,
        T_USBImage = 25,
        T_USBImageFullScreen = 26,
        T_USBVideo = 27,
        T_USBVideoFullScreen = 28,
        T_Link = 29,
        T_Carlife = 30,
        T_CarAuto = 31,
        T_Carplay = 32,
        T_AUX = 33,
        T_AUXFullScreen = 34,
        T_Camera = 35,
        T_CameraFullScreen = 36,
        T_Steering = 37,
        T_Setting = 38,
        T_SettingGeneral = 39,
        T_SettingStyle = 40,
        T_SettingSound = 41,
        T_SettingFactory = 42,
        T_CarInfoWindget = 43,
        T_Navi = 44,
        T_ECLink = 45,
        T_PhotoBrowerWidget = 46,
        T_Camera360DegreeWidget = 47,
        T_NaviFullScreen = 48,
        T_HiCarWidget = 49,
        T_CarPlayLinkModeOptionWidget = 50,
        T_CarlifeLinkModeOptionWidget = 51,
        T_CarAutoLinkModeOptionWidget = 52,
        T_airconditioner = 53,
        T_CarDotor = 54,
        T_CarDotorQuery = 55,
        T_CarDotorWaring = 56,
        T_CarDotorList = 57,
        T_TirePressure = 58,
        T_Assist = 59,
      //  T_OTA = 60,
        T_CarDotorWaringGuide = 60,
        T_RadioSignal = 61,

        T_Acc = 62,
        T_Power = 63,
        T_VoiceAssistant = 65,
        T_AssistantNavi = 66,
    };
    bool setThemeRccPath(const QString& path) const;
    void reset();
    QRect geometryFit(const int x, const int y, const int w, const int h, QWidget* widget = NULL);
    QRect geometrySource(const int x, const int y, const int w, const int h, QWidget* widget = NULL);
    float widthScalabilityFactor();
    float heightScalabilityFactor();
    void acquireWidgetType(const Widget::Type type);
    void releaseWidgetType(const Widget::Type type);
    int inIndexofListPreemptiveType(const Widget::Type type);
    QString qDebugListPreemptiveType();
    void setWidgetType(const Widget::Type destinationType, const Widget::Type requestType, const QString &status);
    const Widget::Type currentWidgetType() const;
    const Widget::Type HolderTypeWidgetType() const;
    inline static Widget* instance() {
        static Widget* widget(new Widget(qApp));
        return widget;
    }
    void beep();
signals:
    void onWidgetTypeChange(const Widget::Type destinationType, const Widget::Type requestType, const QString &status);
private:
    explicit Widget(QObject* parent = NULL);
    ~Widget();
    void initializePrivate();
    friend class WidgetPrivate;
    QScopedPointer<WidgetPrivate> m_Private;
};

#endif // WIDGET_H