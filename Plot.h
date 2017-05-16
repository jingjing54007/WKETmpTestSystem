#ifndef PLOT_H
#define PLOT_H

#include <Qwt/qwt_plot.h>
#include <QWidget>
//#include <QwtInclude/qwt_plot.h>

#include <clsRefTraceProperty.h>
class QwtPlotCurve;
class QwtPlotMarker;
class QwtPlotCurve;
class QwtPlotGrid;

struct PlotCurves{
    QwtPlotCurve *cur1;
    QwtPlotCurve *cur2;
};

class Plot: public QwtPlot
{
    Q_OBJECT
public:

    enum Choice{
        yLeft, yRight,Both
    };

    Plot(QWidget *parent=0);

    void showData(const int dex, const QVector<double> &x,
                  const QVector<double>& curvel,
                  const QVector<double> & curve2);
    void autoScale(Choice choice);
    void setGraphTitle(const QString &);
    void addNewCurve(const int index,
                     const QString curTitle1,
                     const bool OnOrOff, const bool xON, const bool yON);

    void setTraceA(const QString & value);
    void setTraceB(const QString & value);
    void setXTrace(const QString & value);

    QString getTraceA(){return strTraceA;}
    QString getTraceB(){return strTraceB;}
    QString getXTrace(){return strXTrace;}

    void setTraces(const QString &traceA="Z",
                   const QString &traceB="θ",
                   const QString &xTrace=tr("频率[Hz]"));

    void setXScale(double min, double max, bool logx);
    void setYLeftScal(double min, double max, bool logx);
    void setYRightScal(double min, double max);

    void setScale(double xmin=100,double xmax=100000,bool blLogX=true,
                  double yLeftMin=100,double yLeftMax=100000,bool blLogYLeft=true,
                  double yRightMin=-100, double yRightMax=100);
  void getScale(double &xmin,  double &xmax, bool &blLogX,
                 double &yLeftMin, double &yLeftMax, bool &blLogYLeft,
                 double &yRightMin, double &yRightMax);
    void turnOffCurves(Choice choice, bool status=true, bool blStatus=true, int i=0);
    QList<PlotCurves> getCurves(){return this->curves.values();}
    void turnOffCurves(int index, bool status,bool xStatus,bool yStatus);
    void turnOffCurves( QList<curveProperty> cp, Plot::Choice choice, bool status);

    double getXmax() const;
    double getXmin() const;
    double getYLeftMax() const;
    double getYLeftMin() const;
    double getYRightMax() const;
    double getYRightMin() const;
    bool getBlLogX() const;
    void setBlLogX(bool value);
    bool getBlLogYLeft() const;
    void setBlLogYLeft(bool value);
    bool getYLeftIsEnable();
    bool getYRightIsEnable();

    void clearData(const int dex);
    void setToTop(curveProperty property, bool isOnTop);
    void turnOffRefTrace();

    void findPeak(Choice x, bool peakType, int index);
    void findNextLeftHigh(Choice x, int index);
    void findNextLeftLow(Choice x, int index);
    void findNextRightHigh(Choice x, int index);
    void findNextRightLow(Choice x, int index);
    QMap<double, double> fff(QMap<double,double> list, double tmpRet);
    double getCurrentMarkValue();
    QMap<double, double> getChoiceData(Choice x);

    int getCurvesCount()
    {
        return curves.count();
    }

public slots:
    QString setMarker(const double& freq, const int intSelected);
    void addNewCurve(curveProperty property, bool isSetCurrent=false);
protected:
    void mouseMoveEvent(QMouseEvent *e);

private:

    QString strTraceA , strTraceB, strXTrace;

    //为了可以显示多条曲线
    QMap <int,PlotCurves> curves;
    QList<QColor> curves1Color;
    QList<QColor> curves2Color;
    QMap <int,QString> strMap;
    QwtPlotMarker *d_marker1;
    QwtPlotGrid *gridX;
    QwtPlotGrid *gridYLeft;
    QwtPlotGrid *gridYRight;



    bool blLogX;
    bool blLogYLeft;
    double dblMarkValue;

    double xmax;
    double xmin;
    double yLeftMax;
    double yLeftMin;
    double yRightMax;
    double yRightMin;

};

#endif // PLOT_H
