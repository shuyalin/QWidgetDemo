#ifndef FRMNAVI_H
#define FRMNAVI_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class frmNavi;
}

class frmNavi : public QWidget
{
    Q_OBJECT

public:
    explicit frmNavi(QWidget *parent = 0);
    ~frmNavi();
    void setLabelOnePic(const QString &url);
    void setLabelTwoText(const QString &text);
    void showExpand();
    void hideExpand();

signals:
    void click();
private slots:
    void on_pushButton_clicked();

private:
    Ui::frmNavi *ui;
};

#endif // FRMNAVI_H
