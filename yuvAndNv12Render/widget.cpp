#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
unsigned char *pic;
int num;
FILE *fp;
FILE *fp1;
FILE *fp2;
FILE *fp3;
#define YUV420P_URL "720p50_mobcal_ter.y4m"
#define YUVNV12_URL "syl720p_nv12.yuv"
//#define URL "1.yuv"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    yuvWidget = new YUVOpenGLWidget;
    nv12Widget = new NV12OpenGLWidget;
    yuvWidget->hide();
    nv12Widget->hide();
    yuvWidget->setGeometry(0,0,1280,720);
    nv12Widget->setGeometry(0,0,1280,720);
    timerYuv420pFlush = new QTimer(this);
    timerYuvNV12Flush = new QTimer(this);
    connect(timerYuv420pFlush,SIGNAL(timeout()),this,SLOT(flushYuv420pData()));
    connect(timerYuvNV12Flush,SIGNAL(timeout()),this,SLOT(flushYuvNV12Data()));



}

Widget::~Widget()
{
    delete ui;
}
void Widget::initFrameYuv420p(char *url, int w, int h,int num)
{
    fp=fopen(url,"rb+");
    fp1=fopen("output_420_y.y","wb+");
    fp2=fopen("output_420_u.y","wb+");
    fp3=fopen("output_420_v.y","wb+");


    videoFrame.width = w;
    videoFrame.height = h;
    videoFrame.data0 = (unsigned char *)malloc(w*h);
    videoFrame.data1 = (unsigned char *)malloc(w*h/4);
    videoFrame.data2 = (unsigned char *)malloc(w*h/4);

    videoFrame.line0 = w;
    videoFrame.line1 = w/2;
    videoFrame.line2 = w/2;

    pic = (unsigned char *)malloc(w*h*3/2);

//    free(pic);
//    fclose(fp);
//    fclose(fp1);
//    fclose(fp2);
//    fclose(fp3);
}
void Widget::initFrameNV12(char *url, int w, int h,int num)
{
    fp=fopen(url,"rb+");
    fp1=fopen("output_420_y.y","wb+");
    fp2=fopen("output_420_u.y","wb+");
    fp3=fopen("output_420_v.y","wb+");


    videoFrame.width = w;
    videoFrame.height = h;
    videoFrame.data0 = (unsigned char *)malloc(w*h);
    videoFrame.data1 = (unsigned char *)malloc(w*h/2);

    videoFrame.line0 = w;
    videoFrame.line1 = w;

    pic = (unsigned char *)malloc(w*h*3/2);
}
void Widget::flushYuv420pData()
{

    if(0 == fread(pic,1,videoFrame.width*videoFrame.height*3/2,fp)){
        fseek(fp,0,SEEK_SET);
    }
    //Y
    //fwrite(pic,1,videoFrame.width*videoFrame.height,fp1);
    memcpy(videoFrame.data0,pic,videoFrame.width*videoFrame.height);
    //U
    //fwrite(pic+videoFrame.width*videoFrame.height,1,videoFrame.width*videoFrame.height/4,fp2);
    memcpy(videoFrame.data1,pic+videoFrame.width*videoFrame.height,videoFrame.width*videoFrame.height/4);
    //V
    //fwrite(pic+videoFrame.width*videoFrame.height*5/4,1,videoFrame.width*videoFrame.height/4,fp3);
    memcpy(videoFrame.data2,pic+videoFrame.width*videoFrame.height*5/4,videoFrame.width*videoFrame.height/4);
    qDebug()<<"rrrrrrrrrrrrrrrrrr "<<videoFrame.width<<" "<<videoFrame.height;
    yuvWidget->setFrameSize(videoFrame.width, videoFrame.height);
    yuvWidget->updateTextures(videoFrame.data0, videoFrame.data1, videoFrame.data2, videoFrame.line0, videoFrame.line1, videoFrame.line2);
    //nv12Widget->setFrameSize(frame->width, frame->height);
    //nv12Widget->updateTextures(frame->data[0], frame->data[1], frame->linesize[0], frame->linesize[1]);
    yuvWidget->show();
}
void Widget::flushYuvNV12Data()
{
    if(0 == fread(pic,1,videoFrame.width*videoFrame.height*3/2,fp)){
        fseek(fp,0,SEEK_SET);
    }
    //Y
    //fwrite(pic,1,videoFrame.width*videoFrame.height,fp1);
    memcpy(videoFrame.data0,pic,videoFrame.width*videoFrame.height);
    //U
    //fwrite(pic+videoFrame.width*videoFrame.height,1,videoFrame.width*videoFrame.height/4,fp2);
    memcpy(videoFrame.data1,pic+videoFrame.width*videoFrame.height,videoFrame.width*videoFrame.height/2);
    //V
    //fwrite(pic+videoFrame.width*videoFrame.height*5/4,1,videoFrame.width*videoFrame.height/4,fp3);
    //memcpy(videoFrame.data2,pic+videoFrame.width*videoFrame.height*5/4,videoFrame.width*videoFrame.height/4);
    qDebug()<<"rrrrrrrrrrrrrrrrrr "<<videoFrame.width<<" "<<videoFrame.height;
    //nv12Widget->setFrameSize(videoFrame.width, videoFrame.height);
    //nv12Widget->updateTextures(videoFrame.data0, videoFrame.data1, videoFrame.data2, videoFrame.line0, videoFrame.line1, videoFrame.line2);
    nv12Widget->setFrameSize(videoFrame.width, videoFrame.height);
    nv12Widget->updateTextures(videoFrame.data0, videoFrame.data1, videoFrame.line0, videoFrame.line1);
    nv12Widget->show();
}
#if 0
/**
 * Split Y, U, V planes in YUV420P file.
 * @param url  Location of Input YUV file.
 * @param w    Width of Input YUV file.
 * @param h    Height of Input YUV file.
 * @param num  Number of frames to process.
 *
 */
int simplest_yuv420_split(char *url, int w, int h,int num){
    FILE *fp=fopen(url,"rb+");
    FILE *fp1=fopen("output_420_y.y","wb+");
    FILE *fp2=fopen("output_420_u.y","wb+");
    FILE *fp3=fopen("output_420_v.y","wb+");

    unsigned char *pic=(unsigned char *)malloc(w*h*3/2);

    for(int i=0;i<num;i++){

        fread(pic,1,w*h*3/2,fp);
        //Y
        fwrite(pic,1,w*h,fp1);
        //U
        fwrite(pic+w*h,1,w*h/4,fp2);
        //V
        fwrite(pic+w*h*5/4,1,w*h/4,fp3);
    }

    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}
#endif

void Widget::on_yuv420Btn_clicked()
{
    initFrameYuv420p("/home/brian/work_dir/qt/pc_qt/yuvAndNv12Render/"YUV420P_URL,1280,720,1);
    timerYuv420pFlush->start(50);
}

void Widget::on_nv12Btn_clicked()
{
    initFrameNV12("/home/brian/work_dir/qt/pc_qt/yuvAndNv12Render/"YUVNV12_URL,1280,720,1);
    timerYuvNV12Flush->start(50);
}
