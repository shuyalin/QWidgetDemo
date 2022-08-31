#ifndef CUSTOMLISTVIEW_H
#define CUSTOMLISTVIEW_H

#include <QListView>
#include <QList>
#include <CustomItemDelegate.h>
#include <QPainter>
//#include <QMetaType>


typedef struct {
    QString picUrl;
    QString titleText;
    QString detailText;
}MyData;

Q_DECLARE_METATYPE(MyData)

class QStandardItemModel;
class MyModelDelegate;
class CustomListView:public QListView
{
    Q_OBJECT
public:
    CustomListView(QWidget *parent = 0);
    void initItem_1();
    //void initItem_2();
    //void initItem_3();
private:
    QStandardItemModel *model;
    MyModelDelegate *delegate;
    QList<MyData> dataLists;
    QList<QString> picUrlLists;
    QList<QString> titleTextLists;
    QList<QString> detailTextLists;
};
class MyModelDelegate:public CustomItemDelegate
{
    Q_OBJECT
public:
    explicit MyModelDelegate(QObject* parent = NULL);
    ~MyModelDelegate();
    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const override;
protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;


protected slots:
    void onCurrentIndexChange(const QModelIndex &index);

private:
    QModelIndex currentIndex;
};
#endif // CUSTOMLISTVIEW_H
