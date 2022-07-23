#ifndef FORMUSBPAGE_H
#define FORMUSBPAGE_H

#include <QWidget>

namespace Ui {
class FormUsbPage;
}

class FormUsbPage : public QWidget
{
    Q_OBJECT

public:
    explicit FormUsbPage(QWidget *parent = 0);
    ~FormUsbPage();

private:
    Ui::FormUsbPage *ui;
};

#endif // FORMUSBPAGE_H
