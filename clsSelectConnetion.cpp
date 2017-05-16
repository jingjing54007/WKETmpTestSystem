#include "clsSelectConnetion.h"
#include "clsSettings.h"
#include "clsRuningSettings.h"
#include "clsMainDialog.h"
#include "clsGetTemp.h"


#include <QDebug>

clsSelectConnetion::clsSelectConnetion(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    readSettings();
}

void clsSelectConnetion::readSettings()
{
    clsSettings settings;
    QString strNode="Connection/";
    settings.readSetting(strNode+"Type",this->intSelect);
    switch (intSelect) {
    case 0:
        rBtnGPIB->setChecked(true);
        this->txtAddress->setVisible(true);
        settings.readSetting(strNode+"GPIBAddress",strAddress);
        this->txtAddress->setText(strAddress);
        cmbModel->setVisible(false);
        break;
    case 1:
        rBtnLAN->setChecked(true);
        this->txtAddress->setVisible(true);
        settings.readSetting(strNode+"LANAddress",strAddress);
        this->txtAddress->setText(strAddress);
        cmbModel->setVisible(true);
    default:
        break;
    }
}

void clsSelectConnetion::writeSettings()
{
    clsSettings settings;
    QString strNode="Connection/";
    settings.writeSetting(strNode+"Type",this->intSelect);
    switch (intSelect) {
    case 0:
        settings.writeSetting(strNode+"GPIBAddress",this->txtAddress->text());
        break;
    case 1:
        settings.writeSetting(strNode+"LANAddress",this->txtAddress->text());
        break;
    default:
        break;
    }
}

void clsSelectConnetion::on_btnConnct_clicked()
{
    switch (intSelect) {
    case 0:
        clsRS::getInst().setConnectType("GPIB");
        break;
    case 1:
        clsRS::getInst().setConnectType("LAN");
        break;
    case 2:
        clsRS::getInst().setConnectType("USB");
        break;
    default:
        break;
    }

    QString newAddress;
    if(intSelect==1)
    {
        //newAddress=QString("%1,%2").arg(txtAddress->text().arg(cmbModel->currentText()));
        newAddress=txtAddress->text()+","+cmbModel->currentText();
    }
    else
    {
        newAddress=txtAddress->text();
    }

    clsRS::getInst().setAddress(newAddress);
    bool isInit=clsRS::getInst().initConnection();
    if(!isInit)
    {
        qDebug()<<"初始化连接失败";
        return;
    }
    QString strRes=clsRS::getInst().sendCommand("*IDN?",true);
    qDebug()<<"仪器序列号："<<strRes;

    QStringList resList=strRes.split(",");
    if(resList.length()>=2)
    {
        if(!resList.at(0).contains("WAYNE") || resList.at(0).contains("KUWAKI") )
            return;
        qDebug()<<"Instrument ID: "<<resList.at(1);
        if(!resList.at(1).trimmed().isEmpty())
        {
            clsRS::getInst().instrumentModel=resList.at(1).trimmed();

            QRegExp rx("[PMIA]*([0-9]+)([BPA]?Q{0,})");
            if(rx.exactMatch(clsRS::getInst().instrumentModel))
            {
                QRegExp rx4100 ("^4[13][0-9]*");
                if(rx4100.exactMatch(clsRS::getInst().instrumentModel))
                {
                    clsRS::getInst().meterSeries="4300";
                    goto ToHere;
                }

                QRegExp rx6500 ("^65[0-9]*[BPA]");
                if(rx6500.exactMatch(clsRS::getInst().instrumentModel))
                {
                    clsRS::getInst().meterSeries="6500";
                    goto ToHere;
                }

                QRegExp rx3260 ("^PMA3260[BA]");
                if(rx3260.exactMatch(clsRS::getInst().instrumentModel))
                {
                    clsRS::getInst().meterSeries="3260";
                    goto ToHere;
                }

                QRegExp rx3255 ("^IA3255[BA]Q{0,}");
                if(rx3255.exactMatch(clsRS::getInst().instrumentModel))
                {
                    clsRS::getInst().meterSeries="3255";
                    goto ToHere;
                }

                QRegExp rx6440 ("^64[43]0");
                if(rx6440.exactMatch(clsRS::getInst().instrumentModel))
                {
                    clsRS::getInst().meterSeries="6440";
                    goto ToHere;
                }

            }
        }
        else
            clsRS::getInst().instrumentModel="No Instrument!";

        qDebug()<< "Instrument mode: "<<clsRS::getInst().meterSeries;
    }

ToHere:
    qDebug()<< "clsRS::getInst().instrumentModel:\t"<<clsRS::getInst().instrumentModel;
    qDebug()<< "clsRS::getInst().meterMode:\t\t"<<clsRS::getInst().meterSeries;
//    buttonOp(isInit);
    writeSettings();

//    clsMainDialog mainDlg;

//    mainDlg.exec();
    this->accept();
}

void clsSelectConnetion::on_rBtnGPIB_clicked()
{
    intSelect=0;

    clsSettings settings;
    QString strNode="Connection/";
    settings.readSetting(strNode+"GPIBAddress",this->strAddress);
    this->txtAddress->setText(strAddress);
    this->txtAddress->setVisible(true);
    this->cmbModel->setVisible(false);
    this->label->setVisible(true);
}

void clsSelectConnetion::on_rBtnLAN_clicked()
{
    intSelect=1;

    clsSettings settings;
    QString strNode="Connetion/";
    settings.readSetting(strNode+"LANAddress",this->strAddress);
    this->txtAddress->setText(strAddress);
    this->txtAddress->setVisible(true);
    this->cmbModel->setVisible(true);
    this->label->setVisible(true);
}

void clsSelectConnetion::on_rBtnUSB_clicked()
{
    intSelect=2;

    clsSettings settings;
    QString strNode="Connetion/";
    settings.readSetting(strNode+"USBAddress",this->strAddress);
    this->txtAddress->setText(strAddress);
    this->txtAddress->setVisible(false);
    this->cmbModel->setVisible(false);
    this->label->setVisible(false);
}
