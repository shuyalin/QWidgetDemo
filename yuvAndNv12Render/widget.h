#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QFile>
#include "core_opengl/yuvopenglwidget.h"
#include "core_opengl/nv12openglwidget.h"
#include <stdio.h>
#include "videorender.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_yuv420Btn_clicked();
    void on_nv12Btn_clicked();

private:
    Ui::Widget *ui;
    VideoRender *render;
};

#endif // WIDGET_H
