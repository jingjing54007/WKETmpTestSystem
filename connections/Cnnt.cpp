#include "Cnnt.h"
#include <QtCore/QCoreApplication>
#include <QDebug>
Cnnt *Cnnt::mGlobal=0;


Cnnt *Cnnt::Instance()
{
    static QMutex mutex;
    if (!mGlobal)
    {
        QMutexLocker locker(&mutex);
        if (!mGlobal)
            mGlobal = new Cnnt();
    }

    return mGlobal;
}
/*��������������*/
void Cnnt::setConnectionType(QString connectionType)
{
    this->connectionType=connectionType;
}
/*�����������ӵĵ�ַ*/
void Cnnt::setConnectionAddress(QString strAddress)
{
    this->strAddress=strAddress;
}

/*��������������*/
bool Cnnt::setUpConnection()
{

    cnt= connectionFactory::getConnection(this->connectionType);
    cnt->setAddress(this->strAddress);
    isConnectionInit=cnt->init();
    return isConnectionInit;
}

/*����PC������������*/
bool Cnnt::setUpConnection(QString connectionType, QString strAddress)
{
    this->connectionType=connectionType;
    this->strAddress=strAddress;
    return setUpConnection();
}

/*����GPIBָ���ȡ����ֵ*/
QString Cnnt::sendCommand(QString command, bool hasReturn, int delay)
{
    if(isConnectionInit)
        return cnt->sendCommand(command,hasReturn,delay);
    else
    {
        qDebug()<<"The connection does't setup correctly!";
        return "";
    }
}

void Cnnt::disConnectInstrument()
{
    if(isConnectionInit)
        cnt->disConnect();
}

Cnnt::Cnnt()
{
    isConnectionInit=false;
}
