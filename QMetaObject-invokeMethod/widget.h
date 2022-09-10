#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}
class Test;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void showString(const QString &str);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    Test *test;
};

class Test:public QObject
{
    Q_OBJECT
public:
    Test();

signals:
    void signalOne(const QString &str);
};

#endif // WIDGET_H
