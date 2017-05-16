#ifndef CLSPLOTWIDGET_H
#define CLSPLOTWIDGET_H

#include <Qwt/qwt_plot.h>
#include <QWidget>
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_plot_grid.h>
#include <Qwt/qwt_plot_marker.h>

class clsPlotWidget : public QwtPlot
{
    Q_OBJECT
public:
    clsPlotWidget(QWidget *parent = 0);
    void initPlot();
    void setXData(QVector<double> xData);
    void setYData(QVector<double> yData);
    void plotShowCurves(int index, QVector<double> x,/* QVector<double> yLeftData,*/ QVector<double> yRightData);
    void setXScale(double xMin,double xMax);
    void setYLeftScale(double yMin,double yMax);
    void setYRightScale(double yMin,double yMax);
    QString setMark(const double &time, const int index);
    void autoScale();
    void addNewCurve(int count);
    void clearCurves(int count);
    QMap<double, double> getPlotCurvesData(const QList<QwtPlotCurve*> curves, int index);
    void turnOffCurves();
signals:

public slots:

private:
    QwtPlotGrid *xGrid;
    QwtPlotGrid *yLeftGrid;
    QwtPlotGrid *yRightGrid;
    QwtPlotMarker *mark;

    QVector<double> xData;
    QVector<double> yData;
//    QwtPlotCurve *curve1;
//    QwtPlotCurve *curve2;
    QList<QwtPlotCurve*>curveList;
    QList<QPen> penList;

    double xMax;
    double xMin;
    double yLeftMin;
    double yLeftMax;
    double yRightMin;
    double yRightMax;
};

#endif // CLSPLOTWIDGET_H
