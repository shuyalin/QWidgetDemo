#ifndef FORMMAINPAGE_H
#define FORMMAINPAGE_H

#include <QWidget>
#include "appevent.h"
namespace Ui {
class FormMainPage;
}

class FormMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit FormMainPage(QWidget *parent = 0);
    ~FormMainPage();
    void initForm();

public slots:
    void changePage(AppEvent::PageType pageType);

private slots:
    void on_btnBack_clicked();

private:
    Ui::FormMainPage *ui;
};

#endif // FORMMAINPAGE_H
