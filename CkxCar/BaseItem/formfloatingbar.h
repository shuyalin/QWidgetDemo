#ifndef FORMFLOATINGBAR_H
#define FORMFLOATINGBAR_H

#include <QWidget>

namespace Ui {
class FormFloatingBar;
}

class FormFloatingBar : public QWidget
{
    Q_OBJECT

public:
    explicit FormFloatingBar(QWidget *parent = 0);
    ~FormFloatingBar();

signals:
    void quitPage();

private slots:
    void on_btnQuit_clicked();
    void putVal(QString str);

private:
    Ui::FormFloatingBar *ui;
};

#endif // FORMFLOATINGBAR_H
