#ifndef WKEMEASSTETUP_H
#define WKEMEASSTETUP_H

#include <QDialog>

class WKEMeasStetup : public QDialog
{
public:
    WKEMeasStetup(QWidget *parent=0);

    virtual void writeSettings()=0;
    virtual void readSettings()=0;

    virtual void setItem1(QString item)=0;
    virtual void setItem2(QString item2)=0;
    virtual void setEqucct(QString equcct)=0;
    virtual void setSpeed(QString speed)=0;
    virtual void setRange(QString range)=0;
    virtual void setBiasType(QString biasType)=0;
    virtual void setBiasSwitch(QString biasSwicth)=0;
    virtual void setBias(double bias)=0;
    virtual void setFreqency(double freq)=0;
    virtual void setLevel(double level)=0;

    virtual QString getItem1()=0;
    virtual QString getItem2()=0;
    virtual QString getSpeed()=0;
    virtual QString getRange()=0;
    virtual QString getEqucct()=0;
    virtual QString getBiasType()=0;
    virtual QString getBiasSwitch()=0;
    virtual double getBias()=0;
    virtual double getFrequency()=0;
    virtual double getLevel()=0;
};

#endif // WKEMEASSTETUP_H
