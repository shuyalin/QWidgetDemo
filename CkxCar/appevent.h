#ifndef APPEVENT_H
#define APPEVENT_H

#include <QObject>
#include  <QScopedPointer>
#include <QTimer>
class AppEvent:public QObject
{
    Q_OBJECT
public:
    enum PageType{
        Undefine = -1,
        Back = 0,
        Home = 1,
        ViewPaper0 = 2,
        ViewPaper1 = 3,
        Radio = 4,
        Bluetooth = 5,
        Usb = 6,
        UsbRes = 7,
        UsbMusic = 8
    };

    AppEvent(QObject *parent = 0);
    static AppEvent *instance();
signals:
    void putVal(QString val);
    void pageChange(AppEvent::PageType destPage);
public slots:
    void pushData();
private:
    static QScopedPointer<AppEvent> self;
    QTimer *timer;
};

#endif // APPEVENT_H
