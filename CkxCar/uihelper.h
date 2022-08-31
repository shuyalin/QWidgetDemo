#ifndef UIHELPER_H
#define UIHELPER_H

#include <QObject>
#include  <QScopedPointer>
#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QPushButton>

enum E_TEXTSIZE{
    E_NORMAL = 0,
    E_BIG = !E_NORMAL
};
class UiHelper:public QObject
{
    Q_OBJECT
public:
    UiHelper(QObject *parent = 0);
    static UiHelper *instance();
    void setToolBtnStyle(QToolButton *toolBtn,const QString &text,int textSize,const QString iconName);
    void setBtnIcon(QPushButton *btn,const QString iconName);
    void setLabelIcon(QLabel *label,const QString iconName);
    void setItemFont(QLabel *label,int fontSize);
    void setLabelText(QLabel *label,const QString text);
    void setLabelPic(QLabel *label,const QString url);
    void movePos(int xPos,int yPos,QWidget *item);
private:
    static QScopedPointer<UiHelper> self;
    QFont font;
};

#endif // UIHELPER_H
