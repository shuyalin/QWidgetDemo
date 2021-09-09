#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    customPlot = new QCustomPlot(this);
    customPlot->setGeometry(10,10,800,480);
    customPlot->xAxis->setRange(0,100);
    customPlot->yAxis->setRange(10,20);

    customPlot->xAxis->setPadding(10);
    customPlot->yAxis->setPadding(10);

    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    customPlot->legend->setVisible(true);
    //customPlot->legend->setFont(QFont("Helvetica",9));

#if 0
    QPen pen;                 //画笔
    QStringList lineNames;    //图例中曲线名字链表
    lineNames << "lsNone" << "lsLine" << "lsStepLeft" << "lsStepRight" << "lsStepCenter" << "lsImpulse";
    // add graphs with different line styles:（增加曲线，并设置相应的样式）
    for (int i=QCPGraph::lsNone; i<=QCPGraph::lsImpulse; ++i)
    {
      customPlot->addGraph();        //增加曲线
      pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));                                //给pen设置新颜色
      customPlot->graph()->setPen(pen);      //给曲线增加pen
      customPlot->graph()->setName(lineNames[i]);                    //图例名字
      customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);     //曲线样式
      customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));    //曲线上点的样式

      // generate data:(生成曲线)
      QVector<double> x(100), y(100);
      for (int j=0; j<100; ++j)
      {
        x[j] = j/15.0 * 5*3.14 + 0.01;
        y[j] = 7*qSin(x[j])/x[j] - (i-QCPGraph::lsNone)*5 + (QCPGraph::lsImpulse)*5 + 2;
      }
      customPlot->graph()->setData(x, y);
      customPlot->graph()->rescaleAxes(true);
    }
    // zoom out a bit:
    customPlot->yAxis->scaleRange(1.1, customPlot->yAxis->range().center());
    customPlot->xAxis->scaleRange(1.1, customPlot->xAxis->range().center());
    // set blank axis lines:
    customPlot->xAxis->setTicks(false);
    customPlot->yAxis->setTicks(true);
    customPlot->xAxis->setTickLabels(false);
    customPlot->yAxis->setTickLabels(true);
    // make top right axes clones of bottom left axes:
    customPlot->axisRect()->setupFullAxesBox();
#endif

#if 1
    QVector<double> x(101), y(101);
    for (int i = 0; i < 101; ++i) {
        x[i] = i / 50.0 - 1; // -1 到 1
        y[i] = x[i] * x[i];
    }

    customPlot->addGraph();                       // 添加一个曲线图QGraph
    customPlot->graph(0)->setData(x, y);          // 为曲线图添加数据
    customPlot->graph(0)->setName("first example");   // 设置曲线图的名字
    customPlot->xAxis->setLabel("x");             // 设置x轴的标签
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(-1, 1);           // 设置x轴的范围为(-1,1)
    customPlot->yAxis->setRange(0, 1);
    //customPlot->legend->setVisible(true);         // 显示图例

#endif

#if 0
    //整个显示区域背景色
    QLinearGradient plotGradient;
    plotGradient.setStart(0,0);
    plotGradient.setFinalStop(400, 0);
    plotGradient.setColorAt(0, QColor(11, 11, 234));
    plotGradient.setColorAt(1, QColor(234, 12, 12));
    customPlot->setBackground(plotGradient);      // 设置背景颜色
#endif



#if 1
    //坐标轴区域背景色
    QLinearGradient plotGradient;
    plotGradient.setStart(0,0);
    plotGradient.setFinalStop(800, 0);
    plotGradient.setColorAt(0, QColor(11, 11, 234));
    plotGradient.setColorAt(1, QColor(234, 12, 12));
    customPlot->axisRect()->setBackground(plotGradient);      // 设置背景颜色
#endif

}

Widget::~Widget()
{
    delete ui;
}
