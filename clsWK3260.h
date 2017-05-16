#ifndef CLSWK3260_H
#define CLSWK3260_H

#include "ui_clsWK3260.h"
#include "WKEMeasStetup.h"

class clsWK3260 : public WKEMeasStetup, private Ui::clsWK3260
{
    Q_OBJECT

public:
    explicit clsWK3260(QWidget *parent = 0);

    void initWK3260MeasSetup();
    void writeSettings();
    void readSettings();

    void setItem1(QString item);
    void setItem2(QString item);
    void setEqucct(QString equcct);
    void setSpeed(QString speed);
    void setRange(QString range);
    void setBiasType(QString biasType);
    void setBiasSwitch(QString biasSwicth);
    void setBias(double bias);
    void setFreqency(double freq);
    void setLevel(double level);

    QString getItem1();
    QString getItem2();
    QString getBiasStatus();
    QString getBiasSwitch();
    QString getRange();
    QString getSpeed();
    QString getEqucct();
    QString getBiasType();
    double getFrequency();
    double getLevel();
    double getBias();
private slots:
    void on_cmbItem1_currentIndexChanged(int index);
    void on_cmbItem2_currentIndexChanged(int index);
    void on_cmbStatus_currentIndexChanged(int index);
    void on_btnBias_clicked();
    void on_btnSwitch_clicked();
    void on_btnLevel_clicked();
    void on_btnFreq_clicked();
    void on_btnSpeed_clicked();
    void on_btnRange_clicked();
    void on_btnEqucct_clicked();

    void on_btnOK_clicked();

    void on_btnCancel_clicked();

private:
    QString item1,item2;
    QString speed,range,equcct;
    double frequency,level,bias;
    QString biasStatus,biasSwitch,biasType;
};

#endif // CLSWK3260_H
