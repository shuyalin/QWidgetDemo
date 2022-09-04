#ifndef CUSTOMLISTWIDGETITEM_H
#define CUSTOMLISTWIDGETITEM_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class CustomListWidgetItem;
}

class CustomListWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit CustomListWidgetItem(QWidget *parent = 0);
    ~CustomListWidgetItem();
    QString getExpandStatu();

private slots:
    void on_pushButton_clicked();
signals:
    void click();
    void sendVerticalPos(int verVal);
private:
    Ui::CustomListWidgetItem *ui;
    QString expandStatu;
};

#endif // CUSTOMLISTWIDGETITEM_H
