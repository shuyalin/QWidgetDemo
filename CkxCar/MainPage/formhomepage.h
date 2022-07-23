#ifndef FORMHOMEPAGE_H
#define FORMHOMEPAGE_H

#include <QWidget>
#include <QToolButton>
#include <QList>
#include <QEvent>
namespace Ui {
class FormHomePage;
}
class ToolButton;
class FormHomePage : public QWidget
{
    Q_OBJECT

public:
    explicit FormHomePage(QWidget *parent = 0);
    ~FormHomePage();
    void initPage();

public slots:
    void btnClick();

private:
    Ui::FormHomePage *ui;
    QList<QToolButton*> btns;
};

#endif // FORMHOMEPAGE_H
