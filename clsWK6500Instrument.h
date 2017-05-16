#ifndef CLSWK6500INSTRUMENT_H
#define CLSWK6500INSTRUMENT_H

#include "WKEInstrument.h"

class clsWK6500Instrument : public WKEInstrument
{
public:
    clsWK6500Instrument();

    void trig();
    void updateGPIBCommand();

    void setItem1(QString item);
    void setItem2(QString item);
    void setFrequency(double freq);
    void setBias(double bias);
    void setBiasSwitch(QString biasSwitch);
    void setBiasType(QString biasType);
    void setEqucct(QString equcct);
    void setSpeed(QString speed);
    void setRange(QString range);
    void setLevel(double level);

    QString getItem1();
    QString getItem2();
    double getFrequency();
    double getBias();
    QString getBiasType();
    QString getBiasSwitch();
    QString getEquuct();
    QString getRange();
    QString getSpeed();
    double getLevel();

private:
    QString item1,item2;
    QString range,speed,equcct;
    QString biasType,biasSwicth;
    double frequency;
    double bias;
    double level;

};

#endif // CLSWK6500INSTRUMENT_H
