#include "videorender.h"

VideoRender::VideoRender(QWidget *parent):QObject(parent),
    yuvWidget(NULL),nv12Widget(NULL)
{
    yuvWidget = new YUVOpenGLWidget(parent);
    nv12Widget = new NV12OpenGLWidget(parent);
    yuvWidget->hide();
    nv12Widget->hide();
    yuvWidget->setGeometry(0,0,1280,720);
    nv12Widget->setGeometry(0,0,1280,720);
    timerYuv420pFlush = new QTimer(this);
    timerYuvNV12Flush = new QTimer(this);
    connect(timerYuv420pFlush,SIGNAL(timeout()),this,SLOT(flushYuv420pData()));
    connect(timerYuvNV12Flush,SIGNAL(timeout()),this,SLOT(flushYuvNV12Data()));
}
void VideoRender::initFrameYuv420p(char *url, int w, int h,int num)
{
    if(fp){
        fclose(fp);
    }
    if(pic){
        free(pic);
    }
    if(timerYuv420pFlush->isActive()){
        timerYuv420pFlush->stop();
    }
    if(timerYuvNV12Flush->isActive()){
        timerYuvNV12Flush->stop();
    }

    fp=fopen(url,"rb+");

    videoFrame.width = w;
    videoFrame.height = h;
    videoFrame.data0 = (unsigned char *)malloc(w*h);
    videoFrame.data1 = (unsigned char *)malloc(w*h/4);
    videoFrame.data2 = (unsigned char *)malloc(w*h/4);

    videoFrame.line0 = w;
    videoFrame.line1 = w/2;
    videoFrame.line2 = w/2;

    pic = (unsigned char *)malloc(w*h*3/2);

    timerYuv420pFlush->start(50);
}
void VideoRender::flushYuv420pData()
{
    if(0 == fread(pic,1,videoFrame.width*videoFrame.height*3/2,fp)){
        fseek(fp,0,SEEK_SET);
    }
    //Y
    memcpy(videoFrame.data0,pic,videoFrame.width*videoFrame.height);
    //U
    memcpy(videoFrame.data1,pic+videoFrame.width*videoFrame.height,videoFrame.width*videoFrame.height/4);
    //V
    memcpy(videoFrame.data2,pic+videoFrame.width*videoFrame.height*5/4,videoFrame.width*videoFrame.height/4);
    qDebug()<<"rrrrrrrrrrrrrrrrrr "<<videoFrame.width<<" "<<videoFrame.height;
    yuvWidget->setFrameSize(videoFrame.width, videoFrame.height);
    yuvWidget->updateTextures(videoFrame.data0, videoFrame.data1, videoFrame.data2, videoFrame.line0, videoFrame.line1, videoFrame.line2);
    yuvWidget->show();
}
