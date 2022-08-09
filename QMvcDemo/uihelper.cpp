#include "uihelper.h"
#include <QMutex>

QScopedPointer<UiHelper> UiHelper::self;

UiHelper::UiHelper(QObject *parent):QObject(parent)
{

}
QRect UiHelper::geometryFit(const int x, const int y, const int w, const int h, QWidget *widget)
{
    int ax = x * SCALED_FACTOR_X;
    int ay = y * SCALED_FACTOR_Y;
    int aw = w * SCALED_FACTOR_X;
    int ah = h * SCALED_FACTOR_Y;
    if (NULL != widget) {
        widget->move(ax, ay);
        widget->setFixedSize(QSize(aw, ah));
    }
    QRect rect(ax, ay, aw, ah);
    return rect;
}
QRect UiHelper::geometrySource(const int x, const int y, const int w, const int h, QWidget *widget)
{
    int ax = x / SCALED_FACTOR_X;
    int ay = y / SCALED_FACTOR_Y;
    int aw = w / SCALED_FACTOR_X;
    int ah = h / SCALED_FACTOR_Y;
    QRect rect(ax, ay, aw, ah);
    return rect;
}
UiHelper *UiHelper::instance()
{
    if(self.isNull()){
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self.isNull()){
            self.reset(new UiHelper);
        }
    }
    return self.data();
}
