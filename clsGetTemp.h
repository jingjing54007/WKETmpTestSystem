#ifndef CLSGETTEMP_H
#define CLSGETTEMP_H

#include <QObject>
#include <QThread>

#include "NIDAQmx.h"
#include <QTimer>




class clsGetTemp : public QObject
{
    Q_OBJECT
    Q_ENUMS(TermocoupleType)
public:

    clsGetTemp();



    enum TermocoupleType
    {
        J_Type_TC = 10072, // J
        K_Type_TC = 10073, // K
        N_Type_TC = 10077, // N
        TC = 10082, // R
        S_Type_TC = 10085, // S
        T_Type_TC = 10086, // T
        B_Type_TC = 10047, // B
        E_Type_TC =  10055 // E
    };

    void run();

    void setThermocoupleTyple( TermocoupleType t);
    void stop();

    void setMinTemp(double value);

    void setMaxTmp(double value);
    bool setupTh();
    bool setupTh(double minTemp, double maxTemp, TermocoupleType t);
    void setDelayTime(double t);
     double trig(double t, bool stop);
signals:
    void getTemp(double);

private slots:





private:
    TaskHandle taskHandle;
    TermocoupleType t;
    double minTemp;
    double maxTmp;

    QTimer * timer;
    double delayTime;
};

#endif // CLSGETTEMP_H
