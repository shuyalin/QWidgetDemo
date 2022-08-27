#ifndef FRMNAVI1_H
#define FRMNAVI1_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
class FrmNavi1:public QWidget
{
    Q_OBJECT
public:
    FrmNavi1(QWidget *parent = 0);
    ~FrmNavi1();
    void setLabelTwoText(const QString &text);

public slots:
    void expandArea();
//protected:
    //void resizeEvent(QResizeEvent *event);
private:
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout1;
    QLabel *labOne;
    QLabel *labTwo;
    QLabel *labThree;
    QPushButton *btnOne;
    QWidget *widgetOne;
    QWidget *widgetTwo;
};

#endif // FRMNAVI1_H
