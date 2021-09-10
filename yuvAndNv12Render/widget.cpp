#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


#define YUV420P_URL "720p50_mobcal_ter.y4m"
#define YUVNV12_URL "syl720p_nv12.yuv"
//#define URL "1.yuv"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    render = new VideoRender(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_yuv420Btn_clicked()
{
    render->initFrameYuv420p("/home/brian/work_dir/qt/pc_qt/yuvAndNv12Render/"YUV420P_URL,1280,720,1);
}

void Widget::on_nv12Btn_clicked()
{
    render->initFrameNV12("/home/brian/work_dir/qt/pc_qt/yuvAndNv12Render/"YUVNV12_URL,1280,720,1);
}
