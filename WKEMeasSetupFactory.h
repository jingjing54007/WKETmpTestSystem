#ifndef WKEMEASSETUPFACTORY_H
#define WKEMEASSETUPFACTORY_H

#include "WKEMeasStetup.h"
#include "clsWK3260.h"
#include "clsMeasSetup.h"

class WKEMeasSetupFactory
{
public:
   // WKEMeasSetupFactory() {}
    static WKEMeasStetup * getMeasSetup(QString instruMode)
    {
        if("3260"==instruMode)
            return new clsWK3260();
        else if("6500"==instruMode)
            return new clsMeasSetup();
        else
            return (WKEMeasStetup *)0;
    }

};

#endif // WKEMEASSETUPFACTORY_H
