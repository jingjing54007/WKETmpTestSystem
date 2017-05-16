#include "clsFormat.h"
#include <QLocale>
#include <QDebug>

clsFormat::clsFormat()
{
}

QString clsFormat::format(double value,int length)
{
    QLocale loc;
    if(value<1)
    {
        strValue=loc.toString(value*1000,'f',length)+"m";
    }
    else if(value<1000)
    {
        QString str=loc.toString(value,'f',length);
        //this->strValue=QString::number(value);
        strValue=str;
    }
    else if(value<1000000)
    {
        strValue=loc.toString(value/1000,'f',length)+"k";
        //this->strValue=QString::number(value/1000)+"k";
    }
    else if(value<=1.2e11)
    {
        strValue=loc.toString(value/1e6,'f',length)+"M";
        //this->strValue=QString::number(value/1e6)+"M";
    }
    return strValue;
}
