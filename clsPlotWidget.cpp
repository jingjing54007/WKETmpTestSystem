#include "clsPlotWidget.h"
#include <Qwt/qwt_plot_canvas.h>
#include <Qwt/qwt_plot_grid.h>
#include <Qwt/qwt_plot_layout.h>
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_plot_zoomer.h>
#include "UserfulFunctions.h"
#include "doubleType.h"

#include <QDebug>


clsPlotWidget::clsPlotWidget(QWidget *parent) :
    QwtPlot(parent)
{
    penList<<QPen(QColor(255,0,0))<<QPen(QColor(0,255,0))<<QPen(QColor(0,0,255))
             <<QPen(QColor(127,0,127))<<QPen(QColor(0,255,255));
    initPlot();
}

void clsPlotWidget::initPlot()
{
    setFrameStyle(QFrame::NoFrame);
    setLineWidth(1);
    plotLayout()->setAlignCanvasToScales(true);

    //x轴增加网格
    xGrid=new QwtPlotGrid;
    xGrid->setAxes(QwtPlot::xBottom,QwtPlot::yLeft);
    xGrid->setMajorPen(QPen(QColor(0,128,128),0,Qt::DotLine));
    xGrid->setMinorPen(QPen(QColor(0,64,64),0,Qt::DotLine));
    xGrid->attach(this);
    //Y轴左边坐标网格
    yLeftGrid=new QwtPlotGrid;
    yLeftGrid->setAxes(QwtPlot::xBottom,QwtPlot::yLeft);
    yLeftGrid->setMajorPen(QPen(QColor(0,128,128),0,Qt::DotLine));;
    yLeftGrid->setMinorPen(QPen(QColor(0,64,64),0,Qt::DotLine));
    yLeftGrid->attach(this);
//    //Y轴右边坐标网格
//    yRightGrid=new QwtPlotGrid;
//    yRightGrid->setAxes(QwtPlot::xBottom,QwtPlot::yRight);
//    yRightGrid->setMajorPen(QPen(QColor(96,96,0),0,Qt::DotLine));
//    yRightGrid->setMinorPen(QPen(QColor(96,96,0),0,Qt::DotLine));
//    yRightGrid->attach(this);

    //添加左边Y轴坐标，参数为true添加，否则不能添加
    this->enableAxis(QwtPlot::yLeft,true);
    //设置坐标轴的名称
    this->setAxisTitle(QwtPlot::yLeft,"Temperature(℃)->");

    this->setAxisTitle(QwtPlot::xBottom,"Time(s)->");
    //添加右边的Y轴坐标,参数为true时才能添加，为false不能添加
//    this->enableAxis(QwtPlot::yRight,true);
//    this->setAxisTitle(QwtPlot::yRight,"<-Temp(℃)");


    QwtPlotCanvas *canvas=new QwtPlotCanvas();
    canvas->setBorderRadius(5);
    //设置画布背景
    setCanvasBackground(QColor(255,255,255));

    //设置X、Y坐标轴范围
    setAxisScale(QwtPlot::xBottom,10,100);
    setAxisScale(QwtPlot::yLeft,1,1000);
   // setAxisScale(QwtPlot::yRight,1,1000);

    //新建一个曲线对象
//    curve1=new QwtPlotCurve("Curve1");
//    curve2=new QwtPlotCurve("Curve2");

//    //设置曲线颜色
    //curve1->setSamples(xData,yData);
//    curve1->attach(this);
//    QPen pen(QColor(255,0,0));
//    curve1->setPen(pen);
    //设置曲线curve1以左边Y轴为坐标轴
//    curve1->setYAxis(QwtPlot::yLeft);

//    curve2->attach(this);
//    QPen p(QColor(0,255,0));
//    curve2->setPen(p);

//    curve2->setYAxis(QwtPlot::yRight);

//    //抗锯齿
//    curve1->setRenderHint(QwtPlotItem::RenderAntialiased,true);
//    curve2->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    mark=new QwtPlotMarker;
    mark->setValue(1000,0.0);
    mark->setLineStyle(QwtPlotMarker::VLine);
    mark->setLabelAlignment(Qt::AlignLeft | Qt::AlignBottom);
    mark->setLinePen(QPen(Qt::red,0,Qt::SolidLine));
    mark->attach(this);
    setAutoReplot(true);
}

void clsPlotWidget::setXData(QVector<double> xData)
{
    this->xData=xData;
}

void clsPlotWidget::setYData(QVector<double> yData)
{
    this->yData=yData;
}

void clsPlotWidget::plotShowCurves(int index, QVector<double> x,/*QVector<double> yLeftData,*/ QVector<double> yRightData)
{
//    curve1->setSamples(x,yLeftData);
//    curve2->setSamples(x,yRightData);
    curveList.at(index)->setSamples(x,yRightData);
}
//设置X轴的坐标范围
void clsPlotWidget::setXScale(double xMin, double xMax)
{
    setAxisScale(QwtPlot::xBottom,xMin,xMax);
    this->xMin=xMin;
    this->xMax=xMax;
}
//设置左侧Y轴坐标的范围
void clsPlotWidget::setYLeftScale(double yMin, double yMax)
{
    setAxisScale(QwtPlot::yLeft,yMin,yMax);
    this->yLeftMin=yMin;
    this->yLeftMax=yMax;
}
//设置右侧Y坐标轴的范围
void clsPlotWidget::setYRightScale(double yMin, double yMax)
{
    setAxisScale(QwtPlot::yRight,yMin,yMax);
    this->yRightMin=yMin;
    this->yRightMax=yMax;
}

QMap<double,double> clsPlotWidget::getPlotCurvesData(const QList<QwtPlotCurve *> curves, int index)
{
    QMap<double,double> myData;

    if(curves.length()<=index)
    {
        myData.clear();
        myData.insert(0,0.0);
        return myData;
    }
    //pointValueList.clear();
    myData.clear();
    for(int i=0;i<curves.at(index)->data()->size();i++)
    {
       QPointF pointValue =curves.at(index)->data()->sample(i);
       //pointValueList.insert(i,pointValue);
       myData.insert(pointValue.x(),pointValue.y());
    }
    return myData;
}

void clsPlotWidget::turnOffCurves()
{
    for(int i=0;i<curveList.length();i++)
    {
        curveList.at(i)->detach();

    }
    curveList.clear();
    replot();
}

QString clsPlotWidget::setMark(const double &time, const int index)
{
    QMap<double,double> myPoint;
    myPoint=getPlotCurvesData(curveList,index);
    QList<double> xTime;
    QList<double> yTemp;
    xTime.clear();
    yTemp.clear();
    xTime=myPoint.keys();
    double xValue,yValue;
    if(time>UserfulFunctions::Max(xTime))
        xValue=UserfulFunctions::Max(xTime);
    else if(time<UserfulFunctions::Min(xTime))
        xValue=UserfulFunctions::Min(xTime);
    else
        xValue=UserfulFunctions::getNearItem(xTime,time,false);

    yValue=myPoint.value(xValue);
    mark->setVisible(true);
    mark->setValue(xValue,0.0);

    doubleType dt;
    dt.setData(xValue,"");
    QString strX=dt.formateToString()+"s";
    dt.setData(yValue,"");
    QString strY=dt.formateToString()+"℃";

    QString info,label;
    info= QString("%1,%2")
            .arg(strX).arg(strY);

    label= QString("<p> <font size=\"3\" face=\"Helvetica\" color=\"#00c000\">%1<br>").arg(strX)+
            QString(" <font size=\"3\" face=\"Helvetica\" color=\"cyan\">%1</p>").arg(strY);

    QwtText text(label);
    text.setFont(QFont("Helvetica", 10, QFont::Bold));
    text.setColor(Qt::green);

    int myIndex=xTime.indexOf(xValue);

    if(myIndex <xTime.length()*3/6)
        mark->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
    else/*(index >keys.length()*3/6)*/
        mark->setLabelAlignment(Qt::AlignLeft |Qt::AlignBottom);

    mark->setLabel(text);
    mark->setTitle("1");

    return info;
}

void clsPlotWidget::autoScale()
{
    this->setAxisAutoScale(QwtPlot::yLeft,true);
    this->setAxisAutoScale(QwtPlot::yRight,true);
    this->setAxisAutoScale(QwtPlot::xBottom,true);
}

void clsPlotWidget::addNewCurve(int count)
{
    for(int i=0;i<count;i++)
    {
        QwtPlotCurve* curve=new QwtPlotCurve();
        curve->attach(this);
        curve->setPen(penList.at(i));
        curve->setYAxis(QwtPlot::yLeft);
        curve->setRenderHint(QwtPlotItem::RenderAntialiased,true);
        curveList<<curve;
    }
}

void clsPlotWidget::clearCurves(int count)
{

    for(int i=0;i<count;i++)
    {
        curveList.at(i)->detach();
    }
}
