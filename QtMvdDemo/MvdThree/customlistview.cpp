#include "customlistview.h"
#include <QStandardItemModel>
#include <QDebug>

CustomListView::CustomListView(QWidget *parent):QListView(parent)
{
#if 1
    picUrlLists << ":/images/BluetoothDialOneNormal.png"\
                << ":/images/BluetoothDialTwoNormal.png"\
                << ":/images/BluetoothDialThreeNormal.png"\
                << ":/images/BluetoothDialFourNormal.png"\
                << ":/images/BluetoothDialFiveNormal.png"\
                << ":/images/BluetoothDialSixNormal.png"\
                << ":/images/BluetoothDialSevenNormal.png"\
                << ":/images/BluetoothDialEightNormal.png"\
                << ":/images/BluetoothDialNineNormal.png";

    titleTextLists << "one" << "two" << "three" << "four" << "five" << "six"\
                   << "seven" << "eight" << "nine";

    detailTextLists << "11111111111111111111" << "2222222222222222222222"\
                    << "33333333333333333333" << "4444444444444444444444"\
                    << "55555555555555555555" << "6666666666666666666666"\
                    << "77777777777777777777" << "8888888888888888888888"\
                    << "99999999999999999999";
#endif
    for(int i = 0;i < picUrlLists.size();i++){
        MyData data;
        data.picUrl = picUrlLists.at(i);
        data.titleText = titleTextLists.at(i);
        data.detailText = detailTextLists.at(i);
        dataLists << data;
    }



    model = new QStandardItemModel(this);
    delegate = new MyModelDelegate(this);
    setModel(model);
    setItemDelegate(delegate);

    initItem_1();

}
void CustomListView::initItem_1()
{
    for(int i = 0;i < dataLists.size();i++){
        QStandardItem *item = new QStandardItem;
        item->setData(QVariant::fromValue(dataLists.at(i)),Qt::UserRole+1);
        model->setItem(i,0,item);
    }
}
#if 0
void CustomListView::initItem_2()
{
    for(int i = 0;i < dataLists.size();i++){
        QStandardItem *item = new QStandardItem;
        item->setData(QVariant::fromValue(dataLists.at(i)),Qt::UserRole + 1);
        model->setItem(i,0,item);
    }
}

void CustomListView::initItem_3()
{
    QStandardItem *root = model->invisibleRootItem();
    for(int i = 0;i < dataLists.size();i++){
        QStandardItem *item = new QStandardItem;
        item->setData(QVariant::fromValue(dataLists.at(i)),Qt::UserRole + 1);
        root->setChild(root->rowCount(),0,item);
    }
}
#endif

#if 1
MyModelDelegate::MyModelDelegate(QObject *parent)
    : CustomItemDelegate(parent)
{

}

MyModelDelegate::~MyModelDelegate()
{
}
void MyModelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->setFont(QFont(QString(), 22));

    QVariant variant = index.data(Qt::UserRole + 1);
    MyData data = variant.value<MyData>();

    painter->drawPixmap(20,option.rect.y()+10,QPixmap(data.picUrl));
    painter->drawText(200,option.rect.y()+60,data.titleText);
    painter->drawText(300,option.rect.y()+60,data.detailText);
    //painter->drawText(option.rect, Qt::AlignCenter, QObject::tr(variant.m_Text.toLocal8Bit().constData()));
}
void MyModelDelegate::onCurrentIndexChange(const QModelIndex &index)
{
    currentIndex = index;
}
QSize MyModelDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    return QSize(option.rect.width(), 120);
}
#endif
