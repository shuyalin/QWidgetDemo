#ifndef FORMMAINPAGE_H
#define FORMMAINPAGE_H

#include <QWidget>
#include <QEvent>
#include "appevent.h"

namespace Ui {
class FormMainPage;
}
class FormRadio;
class FormBlue;
class FormUsbPage;
class FormHomePageOne;
class FormMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit FormMainPage(QWidget *parent = 0);
    ~FormMainPage();
    void initForm();

public slots:
    void pageTypeChange(AppEvent::PageType destPage);
    void backHomePage();
private:
    Ui::FormMainPage *ui;
};

#endif // FORMMAINPAGE_H
