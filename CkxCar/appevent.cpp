#include "appevent.h"
#include <QMutexLocker>
#include <QDebug>
#include <QMetaType>
QScopedPointer<AppEvent> AppEvent::self;

AppEvent *AppEvent::instance()
{
    if (self.isNull()) {
            static QMutex mutex;
            QMutexLocker locker(&mutex);
            if (self.isNull()) {
                self.reset(new AppEvent);
            }
        }

        return self.data();
}

AppEvent::AppEvent(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<AppEvent::PageType>("AppEvent::PageType");
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(pushData()));
    timer->start(1000);
}

void AppEvent::pushData()
{
    emit putVal(QString::number(qrand()%10));
}
