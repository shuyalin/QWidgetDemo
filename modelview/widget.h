#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QFileSystemModel>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QPlainTextEdit m_edit;
    QFileSystemModel m_fsm;
protected slots:
    void onDirectoryLoaded(const QString& path);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
