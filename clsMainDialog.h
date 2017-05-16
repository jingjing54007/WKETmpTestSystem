#ifndef CLSMAINDIALOG_H
#define CLSMAINDIALOG_H

#include "ui_clsMainDialog.h"
#include "clsPlotWidget.h"
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_plot_picker.h>
#include "clsGetTemp.h"
#include "WKEInstrument.h"
#include "WKEMeasStetup.h"

class clsMainDialog : public QDialog, private Ui::clsMainDialog
{
    Q_OBJECT

public:
    explicit clsMainDialog(QWidget *parent = 0);
    void testTemp();
    void writeSettings();
    void readSettings();
    void setCmbTcTypeText();
    void initInstrumet();
    void autoSaveResult();
    void setRbtnBiasText();
private slots:
    void on_btnTrig_clicked();
    void on_btnMeasStup_clicked();

    void on_btnAutoFit_clicked();

    void on_cmbTcType_currentIndexChanged(int index);

    void on_btnTraceSetup_clicked();

    void on_btnData_clicked();

    void on_btnSaveImg_clicked();
    void moveMark(const QPoint &pos);

    void on_rbtnBias1_clicked();

    void on_rbtnBias2_clicked();

    void on_rbtnBias3_clicked();

    void on_rbtnBias4_clicked();

    void on_rbtnBias5_clicked();

private:
    clsPlotWidget *plot;
    QwtPlotPicker *picker;
    QVector <double> xData;
    QVector <double> yLeftData;
    QMap<int,QVector<double> > yDataMap;
    QwtPlotCurve *curve1;
    clsGetTemp *temp;
    double delayTime;
    double biasStup;
    clsGetTemp::TermocoupleType tcType;
    int tcTypeIndex;

    QString item1;
    QString item2;
    QString equcct,speed,range;
    QString biasType,biasSwitch;
    double frequency,level,bias;

    WKEInstrument *Instrument;
    WKEMeasStetup *meas;
    bool inittcType;
    QList<double>biasList;
    double maxTemp;
    bool stop;
    bool waite;
    QString strFilePath;
    int rBtnIndex;
};

#endif // CLSMAINDIALOG_H
