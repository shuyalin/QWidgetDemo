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
void UiHelper::setToolBtnStyle(QToolButton *toolBtn,const QString &text,int textSize,const QString iconName)
{
    //设置显示的文本
    toolBtn->setText(text);
    if (textSize == E_BIG)
    {
        toolBtn->setFont(QFont("文泉驿雅黑",16,QFont::Bold));
    }else if (textSize == E_NORMAL)
        toolBtn->setFont(QFont("文泉驿雅黑",12,QFont::Bold));

    toolBtn->setAutoRaise(true);
    //设置按钮图标
    toolBtn->setIcon(QPixmap(QString("%1").arg(iconName)));
    toolBtn->setIconSize(QPixmap(QString("%1").arg(iconName)).size());
    //设置文本在图标下边
    toolBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}
void UiHelper::setBtnIcon(QPushButton *btn,const QString iconName)
{
    btn->setIcon(QPixmap(QString("%1").arg(iconName)));
    btn->setIconSize(QPixmap(QString("%1").arg(iconName)).size());
}

void UiHelper::setLabelIcon(QLabel *label,const QString iconName)
{
    label->setPixmap(QPixmap(iconName));
}
void UiHelper::setItemFont(QLabel *label,int fontSize)
{
    font.setPixelSize(fontSize);
    label->setFont(font);
}
void UiHelper::setLabelText(QLabel *label,const QString text)
{
    label->setText(text);
}

void UiHelper::setLabelPic(QLabel *label,const QString url)
{
    label->setPixmap(QPixmap(url));
}

void UiHelper::movePos(int xPos,int yPos,QWidget *item)
{
    item->move(xPos,yPos);
}
