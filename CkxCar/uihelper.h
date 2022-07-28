#ifndef UIHELPER_H
#define UIHELPER_H

#include <QObject>
#include  <QScopedPointer>
#include <QWidget>
class UiHelper:public QObject
{
    Q_OBJECT
public:
    UiHelper(QObject *parent = 0);
    static UiHelper *instance();

    void movePos(int xPos,int yPos,QWidget *item);
private:
    static QScopedPointer<UiHelper> self;
};

#endif // UIHELPER_H
