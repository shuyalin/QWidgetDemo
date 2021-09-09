#ifndef VIDEORENDER_H
#define VIDEORENDER_H

#include <QObject>
#include <QTimer>
#include "core_opengl/yuvopenglwidget.h"
#include "core_opengl/nv12openglwidget.h"
#include <stdio.h>

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
class VideoRender:public QObject
{
    Q_OBJECT
public:
    VideoRender(QWidget *parent = 0);
    void initFrameYuv420p(char *url, int w, int h,int num);

public slots:
    void flushYuv420pData();
private:
    YUVOpenGLWidget *yuvWidget;     //显示yuv数据的控件
    NV12OpenGLWidget *nv12Widget;   //显示nv12数据的控件
    QTimer *timerYuv420pFlush;
    QTimer *timerYuvNV12Flush;
    VideoFrame videoFrame;
    FILE *fp;
    unsigned char *pic;
};

#endif // VIDEORENDER_H
