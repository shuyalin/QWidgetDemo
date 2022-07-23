#ifndef FORMUSBPAGE_H
#define FORMUSBPAGE_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class FormUsbPage;
}

class FormUsbPage : public QWidget
{
    Q_OBJECT

public:
    explicit FormUsbPage(QWidget *parent = 0);
    ~FormUsbPage();

    void initPage();
    void initSlot();

public slots:
    void playMusicPage(QListWidgetItem* item);


private:
    Ui::FormUsbPage *ui;
};

#endif // FORMUSBPAGE_H
