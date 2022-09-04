#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
namespace Ui {
class Widget;
}
class CustomListView;
class QStandardItemModel;
class BluetoothContactDelegate;
class CustomScrollBar;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initItem();
private:
    Ui::Widget *ui;
    CustomListView* m_CustomListView;
    QStandardItemModel* m_StandardItemModel;
    BluetoothContactDelegate* m_ContactDelegate;
    CustomScrollBar* m_CustomScrollBar;
    QList<QString> list;
};

#endif // WIDGET_H
