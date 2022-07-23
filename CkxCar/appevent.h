#ifndef APPEVENT_H
#define APPEVENT_H

#include <QObject>
#include  <QScopedPointer>
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
        Bluetooth = 5
    };

    AppEvent(QObject *parent = 0);
    static AppEvent *instance();

signals:
    void pageChange(AppEvent::PageType pageType);

private:
    static QScopedPointer<AppEvent> self;
};

#endif // APPEVENT_H
