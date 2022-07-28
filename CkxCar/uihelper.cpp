#include "uihelper.h"
#include <QMutexLocker>
QScopedPointer<UiHelper> UiHelper::self;

UiHelper *UiHelper::instance()
{
    if (self.isNull()) {
            static QMutex mutex;
            QMutexLocker locker(&mutex);
            if (self.isNull()) {
                self.reset(new UiHelper);
            }
        }

        return self.data();
}

UiHelper::UiHelper(QObject *parent) : QObject(parent)
{
}
void UiHelper::movePos(int xPos,int yPos,QWidget *item)
{
    item->move(xPos,yPos);
}
