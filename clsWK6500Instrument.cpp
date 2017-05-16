#include "clsWK6500Instrument.h"
#include "clsRuningSettings.h"
#include <QDebug>

clsWK6500Instrument::clsWK6500Instrument()
{
}

void clsWK6500Instrument::trig()
{
    clsRS::getInst().sendCommand(":METER:TRIG");
}

void clsWK6500Instrument::updateGPIBCommand()
{

    clsRS::getInst().sendCommand(":METER:FUNC:1 "+item1+";""2 "+item2);

    clsRS::getInst().sendCommand(":METER:FREQ "+QString::number(frequency));

    clsRS::getInst().sendCommand(":METER:LEVEL "+QString::number(level)+"V");

    clsRS::getInst().sendCommand(":METER:RANGE "+range);
    clsRS::getInst().sendCommand("METER:SPEED "+speed);
    clsRS::getInst().sendCommand(":METER:BIAS "+QString::number(bias)+biasType);
    clsRS::getInst().sendCommand(":METER:BIAS "+biasSwicth);
    clsRS::getInst().sendCommand(":METER:EQUCCT "+this->equcct);

//qDebug()<<"Item1   ="<<item1<<item2;
//    clsRS::getInst().sendCommand(":METER:FREQ "+QString::number(150000));

//    clsRS::getInst().sendCommand(":METER:LEVEL "+QString::number(0.5)+"V");

//    clsRS::getInst().sendCommand(":METER:RANGE 7");
//    clsRS::getInst().sendCommand("METER:SPEED FAST");
//    clsRS::getInst().sendCommand(":METER:BIAS "+QString::number(0.1)+"A");
//    clsRS::getInst().sendCommand(":METER:BIAS OFF");
//    clsRS::getInst().sendCommand(":METER:EQUCCT SER");
}

void clsWK6500Instrument::setItem1(QString item)
{
    this->item1=item;
}

void clsWK6500Instrument::setItem2(QString item)
{
    this->item2=item;
}

void clsWK6500Instrument::setFrequency(double freq)
{
    this->frequency=freq;
}

void clsWK6500Instrument::setBias(double bias)
{
    this->bias=bias;
}

void clsWK6500Instrument::setBiasSwitch(QString biasSwitch)
{
    this->biasSwicth=biasSwitch;
}

void clsWK6500Instrument::setBiasType(QString biasType)
{
    this->biasType=biasType;
}

void clsWK6500Instrument::setEqucct(QString equcct)
{
    this->equcct=equcct;
}

void clsWK6500Instrument::setSpeed(QString speed)
{
    this->speed=speed;
}

void clsWK6500Instrument::setRange(QString range)
{
    this->range=range;
}

void clsWK6500Instrument::setLevel(double level)
{
    this->level=level;
}

QString clsWK6500Instrument::getItem1()
{
    return item1;
}

QString clsWK6500Instrument::getItem2()
{
    return this->item2;
}

double clsWK6500Instrument::getFrequency()
{
    return this->frequency;
}

double clsWK6500Instrument::getBias()
{
    return this->bias;
}

QString clsWK6500Instrument::getBiasType()
{
    return this->biasType;
}

QString clsWK6500Instrument::getBiasSwitch()
{
    return this->biasSwicth;
}

QString clsWK6500Instrument::getEquuct()
{
    return this->equcct;
}

QString clsWK6500Instrument::getRange()
{
    return this->range;
}

QString clsWK6500Instrument::getSpeed()
{
    return this->speed;
}

double clsWK6500Instrument::getLevel()
{
    return this->level;
}
