#include "clsGetTemp.h"
#include <QTime>
#include <QDebug>
#include <QCoreApplication>
#include "UserfulFunctions.h"

clsGetTemp::clsGetTemp()
{
    this->t= J_Type_TC;
    this->minTemp =0.0;
    this->maxTmp =100.0;

    timer  = new QTimer();
    timer->setInterval(1);

   // connect(timer,SIGNAL(timeout()),this,SLOT(trig()));

}

void clsGetTemp::run()
{
    DAQmxStartTask(taskHandle);
    timer->start();

}


void clsGetTemp::setThermocoupleTyple(clsGetTemp::TermocoupleType t)
{
    this->t=t;
}

void clsGetTemp::stop()
{
    timer->stop();


    DAQmxStopTask(taskHandle);
}

bool clsGetTemp::setupTh()
{
    int value;
    value = DAQmxCreateTask("",&taskHandle);
    if(value !=0 )
    {
     qDebug()<< "Create thermocouple task error!"   ;
        return false;
    }
    value =DAQmxCreateAIThrmcplChan(taskHandle,"Dev1/ai0","",this->minTemp,this->maxTmp,DAQmx_Val_DegC,this->t,DAQmx_Val_BuiltIn,25.0,"");
    if(value !=0 )
    {
     qDebug()<< "Config thermocouple  error!"   ;
        return false;
    }


    value =DAQmxSetSampTimingType(taskHandle, DAQmx_Val_OnDemand);
    if(value !=0 )
    {
     qDebug()<< "set thermocouple sampling error!"   ;
        return false;
    }

    return true;

}

bool clsGetTemp::setupTh(double minTemp, double maxTemp, clsGetTemp::TermocoupleType t)
{
    this->maxTmp = maxTemp;
    this->minTemp = minTemp;
    this->t= t;

    return setupTh();
}

void clsGetTemp::setDelayTime(double t)
{
    delayTime=t;
}

void clsGetTemp::setMaxTmp(double value)
{
    maxTmp = value;
}

double clsGetTemp::trig(double t,bool stop)
{
    float64     data[1]={0};
    int32       read=0;
//    QTime t;
//    t.start();
//    QTime dieTime = QTime::currentTime().addMSecs(delayTime);
//    while( QTime::currentTime() < dieTime )
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    int value =DAQmxReadAnalogF64(taskHandle,-1,10.0,
                       DAQmx_Val_GroupByScanNumber,
                       data,1,&read,NULL);
    //UserfulFunctions::sleepMs(t);
    QTime dieTime = QTime::currentTime().addMSecs(t);
    while( QTime::currentTime() < dieTime && !stop )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    if(value !=0)
    {
        qDebug()<< "Read the temp time out";
    }


   // qDebug()<< QTime::currentTime().toString("hh:mm:ss.zzz") <<"\t" << data[0];
    return data[0];

    //emit getTemp(data[0]);
}

void clsGetTemp::setMinTemp(double value)
{
    minTemp = value;
}
