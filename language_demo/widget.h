#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTranslator>
#include "form.h"
#include "formpagetwo.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    enum LanguageType{
        english,
        chinese,
    };
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    LanguageType lanType;

public slots:
    void changePage();
    void closeNewPage();

private slots:
    void on_chinese_clicked();

    void on_english_clicked();

    void on_back_clicked();

    void on_pushButton_5_clicked();

    void on_btnSetting_clicked();

    void on_btnHome_clicked();

    void on_btnPageTwp_clicked();

private:
    Ui::Widget *ui;
    Form *form;
    QTranslator *myTranslator;
    FormPageTwo *pageTwo;
};

#endif // WIDGET_H
