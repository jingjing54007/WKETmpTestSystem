#ifndef WKEINSTRUMENT_H
#define WKEINSTRUMENT_H

#include <QDialog>

class WKEInstrument : public QDialog
{
    Q_OBJECT
public:
    explicit WKEInstrument(QWidget *parent = 0);

    virtual void trig()=0;
    virtual void updateGPIBCommand()=0;

    virtual void setItem1(QString item1)=0;
    virtual void setItem2(QString item)=0;
    virtual void setFrequency(double f)=0;
    virtual void setEqucct(QString equcct)=0;
    virtual void setSpeed(QString speed)=0;
    virtual void setRange(QString range)=0;
    virtual void setBiasType(QString type)=0;
    virtual void setBiasSwitch(QString biasSwitch)=0;
    virtual void setBias(double bias)=0;
    virtual void setLevel(double level)=0;

    virtual QString getItem1()=0;
    virtual QString getItem2()=0;
    virtual double getFrequency()=0;
    virtual QString getEquuct()=0;
    virtual QString getSpeed()=0;
    virtual QString getRange()=0;
    virtual QString getBiasType()=0;
    virtual QString getBiasSwitch()=0;
    virtual double getBias()=0;
    virtual double getLevel()=0;

signals:

public slots:

};

#endif // WKEINSTRUMENT_H
