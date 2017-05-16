#ifndef CLSWK3260INSTRUMENT_H
#define CLSWK3260INSTRUMENT_H

#include "WKEInstrument.h"

class clsWK3260Instrument : public WKEInstrument
{
public:
    clsWK3260Instrument();
    void trig();
    void updateGPIBCommand();
    void setItem1(QString item);
    void setItem2(QString item);
    void setFrequency(double freq);
    void setLevel(double level);
    void setBias(double bias);
    void setBiasSwitch(QString biasSwitch);
    void setBiasType(QString biasType);
    void setEqucct(QString equcct);
    void setSpeed(QString speed);
    void setRange(QString range);

    QString getItem1();
    QString getItem2();
    double getFrequency();
    double getLevel();
    double getBias();
    QString getBiasSwitch();
    QString getBiasType();
    QString getEquuct();
    QString getSpeed();
    QString getRange();

private:
    double frequency;
    double level;
    double bias;
    QString item1,item2;
    QString range,speed;
    QString biasType,biasSwitch;
    QString equcct;
};

#endif // CLSWK3260INSTRUMENT_H
