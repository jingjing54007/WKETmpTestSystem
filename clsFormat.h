#ifndef CLSFORMAT_H
#define CLSFORMAT_H

#include <QString>

class clsFormat
{
public:
    clsFormat();
    QString format(double value, int length);
private:
    QString strValue;
};

#endif // CLSFORMAT_H
