#ifndef CLSMEASSETUP_H
#define CLSMEASSETUP_H

#include "ui_clsMeasSetup.h"
#include "WKEMeasStetup.h"

class clsMeasSetup : public WKEMeasStetup, private Ui::clsMeasSetup
{
    Q_OBJECT

public:
    explicit clsMeasSetup(QWidget *parent = 0);

    void initWK6500MeasSetup();

    void writeSettings();
    void readSettings();

    QString getItem1() ;
    void setItem1(/*const */QString value);

    QString getItem2() /*const*/;
    void setItem2(/*const*/ QString value);

    QString getEqucct() /*const*/;
    void setEqucct(/*const*/ QString value);

    QString getSpeed()/* const*/;
    void setSpeed(const QString value);

    QString getRange() /*const*/;
    void setRange(const QString value);

    QString getBiasType() /*const*/;
    void setBiasType(const QString value);

    QString getBiasSwitch() /*const*/;
    void setBiasSwitch(const QString value);

    double getFrequency() /*const*/;
    void setFreqency(double value);

    double getLevel() /*const*/;
    void setLevel(double value);

    double getBias() /*const*/;
    void setBias(double value);

private slots:
    void on_btnItem1_clicked();
    void on_btnItem2_clicked();
    void on_btnFreq_clicked();
    void on_btnLevel_clicked();
    void on_btnEqucct_clicked();
    void on_btnSpeed_clicked();
    void on_btnRange_clicked();
    void on_btnBias_clicked();
    void on_btnBiasType_clicked();
    void on_btnSwitch_clicked();
    void on_btnCancel_clicked();
    void on_btnOK_clicked();

private:
    QString item1;
    QString item2;
    QString equcct,speed,range;
    QString biasType,biasSwitch;
    double frequency,level,bias;
};

#endif // CLSMEASSETUP_H
