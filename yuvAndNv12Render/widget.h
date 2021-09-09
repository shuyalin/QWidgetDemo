#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "core_opengl/yuvopenglwidget.h"
#include "core_opengl/nv12openglwidget.h"
#include <stdio.h>
namespace Ui {
class Widget;
}
class VideoFrame{
public:
    int width;
    int height;
    unsigned char *data0;
    unsigned char *data1;
    unsigned char *data2;
    int line0;
    int line1;
    int line2;
};
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initFrameYuv420p(char *url, int w, int h,int num);
    void initFrameNV12(char *url, int w, int h,int num);


    YUVOpenGLWidget *yuvWidget;     //显示yuv数据的控件
    NV12OpenGLWidget *nv12Widget;   //显示nv12数据的控件

    QTimer *timerYuv420pFlush;
    QTimer *timerYuvNV12Flush;
    VideoFrame videoFrame;
public slots:
    void flushYuv420pData();
    void flushYuvNV12Data();

private slots:
    void on_yuv420Btn_clicked();

    void on_nv12Btn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
