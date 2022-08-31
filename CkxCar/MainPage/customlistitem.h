#ifndef CUSTOMLISTITEM_H
#define CUSTOMLISTITEM_H

#include <QWidget>
#include <QList>
#include <QToolButton>
namespace Ui {
class customListItem;
}

class customListItem : public QWidget
{
    Q_OBJECT

public:
    explicit customListItem(QWidget *parent = 0);
    ~customListItem();
    void setBtnName(int index,const QString name);
    void setBtnText(int index,const QString text);

signals:
    void click(QString objectName);

public slots:
    void onClick();
private:
    Ui::customListItem *ui;
    QList<QToolButton*> btns;
    QList<QString> titleList;
    QList<QString> iconList;
};

#endif // CUSTOMLISTITEM_H
