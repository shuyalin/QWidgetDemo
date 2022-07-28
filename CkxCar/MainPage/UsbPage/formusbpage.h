#ifndef FORMUSBPAGE_H
#define FORMUSBPAGE_H

#include <QWidget>
#include <QListWidgetItem>
#include <QList>
#include <QPushButton>
#include "appevent.h"
#include "formusbmusic.h"
#include "formusbphoto.h"
#include "formusbvideo.h"
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
signals:
    void quitPage();
public slots:
    void playMusicPage(QListWidgetItem* item);
    void backUsbPage();
    void onClick();
private:
    Ui::FormUsbPage *ui;
    FormUsbMusic *music;
    QList<QPushButton*> btns;
};

#endif // FORMUSBPAGE_H
