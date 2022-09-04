#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QListView>
#include <QMouseEvent>
#include <QItemDelegate>
class MyListView:public QListView
{
public:
    MyListView(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent *event);

};
class BluetoothContactDelegate : public QItemDelegate
{
    Q_DISABLE_COPY(BluetoothContactDelegate)
public:
    explicit BluetoothContactDelegate(QObject* parent = NULL);
    ~BluetoothContactDelegate();
protected:
    void paint(QPainter* painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
protected slots:
    void onPressIndexChanged(const QModelIndex &index);
private:
    QModelIndex m_PressIndex;
    QScopedPointer<QPixmap> m_Rules;
    QScopedPointer<QPixmap> m_Icon;
    QScopedPointer<QPixmap> m_Press;
};
#endif // MYLISTVIEW_H
