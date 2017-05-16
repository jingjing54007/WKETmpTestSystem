#include "clsWK3260Instrument.h"
#include "clsRuningSettings.h"

#include <QDebug>

clsWK3260Instrument::clsWK3260Instrument()
{
}

void clsWK3260Instrument::trig()
{
    clsRS::getInst().sendCommand(":IMP:TRIG");
}

void clsWK3260Instrument::updateGPIBCommand()
{

    clsRS::getInst().sendCommand(":IMP:FUNC:"+item1+";"+item2);//Example: :IMP:FUNC:C;D
    clsRS::getInst().sendCommand(":IMP:FREQ "+QString::number(frequency));//Example: :IMP:FREQ 1k
    clsRS::getInst().sendCommand(":IMP:LEV "+QString::number(level)+biasType);//Example: :IMP:LEV 1.2V
    clsRS::getInst().sendCommand(":IMP:BIAS EEXT");
    clsRS::getInst().sendCommand(":IMP:BIAS "+biasSwitch);
    clsRS::getInst().sendCommand(":IMP:BIAS "+QString::number(bias)+biasType);
    clsRS::getInst().sendCommand(":IMP:SPEED "+speed);//Example: :IMP:SPEED SLOW
    clsRS::getInst().sendCommand(":IMP:RANGE "+range);
    clsRS::getInst().sendCommand(":IMP:EQU-CCT "+equcct);//Example: :IMP:EQU-CCT SER
}

void clsWK3260Instrument::setItem1(QString item)
{
    this->item1=item;
}

void clsWK3260Instrument::setItem2(QString item)
{
    this->item2=item;
}

void clsWK3260Instrument::setFrequency(double freq)
{
    this->frequency=freq;
}

void clsWK3260Instrument::setLevel(double level)
{
    this->level=level;
}

void clsWK3260Instrument::setBias(double bias)
{
    this->bias=bias;
}

void clsWK3260Instrument::setBiasSwitch(QString biasSwitch)
{
    this->biasSwitch=biasSwitch;
}

void clsWK3260Instrument::setBiasType(QString biasType)
{
    this->biasType=biasType;
}

void clsWK3260Instrument::setEqucct(QString equcct)
{
    this->equcct=equcct;
}

void clsWK3260Instrument::setSpeed(QString speed)
{
    this->speed=speed;
}

void clsWK3260Instrument::setRange(QString range)
{
    this->range=range;
}

QString clsWK3260Instrument::getItem1()
{
    return item1;
}

QString clsWK3260Instrument::getItem2()
{
    return item2;
}

double clsWK3260Instrument::getFrequency()
{
    return frequency;
}

double clsWK3260Instrument::getLevel()
{
    return level;
}

double clsWK3260Instrument::getBias()
{
    return bias;
}

QString clsWK3260Instrument::getBiasSwitch()
{
    return biasSwitch;
}

QString clsWK3260Instrument::getBiasType()
{
    return biasType;
}

QString clsWK3260Instrument::getEquuct()
{
    return equcct;
}

QString clsWK3260Instrument::getSpeed()
{
    return speed;
}

QString clsWK3260Instrument::getRange()
{
    return range;
}
