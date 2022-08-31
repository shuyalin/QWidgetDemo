#include "customlistitem.h"
#include "ui_customlistitem.h"
#include "uihelper.h"
#include <QDebug>
customListItem::customListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customListItem)
{
    ui->setupUi(this);
    btns << ui->btn1 << ui->btn2 << ui->btn3 << ui->btn4 << ui->btn5;
    titleList << "Radio" <<"Bluetooth" <<"Usb" <<"PhoneLink" <<"Aux";
    iconList << ":/res/images/ViewPaperWidgetRadioNormal.png" \
             <<  ":/res/images/ViewPaperWidgetBluetoothNormal.png" \
             <<  ":/res/images/ViewPaperWidgetUSBNormal.png" \
             <<  ":/res/images/ViewPaperWidgetLinkNormal.png" \
             <<  ":/res/images/ViewPaperWidgetAUXNormal.png";
    foreach (auto item, btns) {
        connect(item,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    }
    for(int i=0;i<btns.size();i++){
        UiHelper::instance()->setToolBtnStyle(btns.at(i),titleList.at(i),E_BIG,iconList.at(i));
    }
}

customListItem::~customListItem()
{
    delete ui;
}

void customListItem::setBtnName(int index,const QString name)
{
    btns.at(index)->setObjectName(name);
}

void customListItem::setBtnText(int index,const QString text)
{
    btns.at(index)->setText(text);
}
void customListItem::onClick()
{

    QToolButton *btn = static_cast<QToolButton*>(sender());
    qDebug()<<"wwwwwwwwwwww "<<btn->objectName();
    emit click(btn->objectName());
}
