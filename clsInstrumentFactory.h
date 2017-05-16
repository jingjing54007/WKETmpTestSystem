#ifndef CLSINSTRUMENTFACTORY_H
#define CLSINSTRUMENTFACTORY_H

#include "WKEInstrument.h"
#include "clsWK6500Instrument.h"
#include "clsWK3260Instrument.h"


class clsInstrumentFactory
{
public:
   // clsInstrumentFactory() {}
    static WKEInstrument * getWKEInstrument(QString strType)
    {
        if("6500"==strType)
            return new clsWK6500Instrument();
        if("3260"==strType)
            return new clsWK3260Instrument();
        else
            return (WKEInstrument*)0;
    }
};

#endif // CLSINSTRUMENTFACTORY_H
