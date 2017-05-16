#include "clsMeasSetup.h"
#include "clsWK6500Items.h"
#include "clsSpeed.h"
#include "clsRange.h"
#include "NumberInput.h"
#include "clsFormat.h"
#include "dlgLevelInputBox.h"
#include "clsSettings.h"

#include <QDebug>

clsMeasSetup::clsMeasSetup(QWidget *parent) :
    WKEMeasStetup(parent)
{
    setupUi(this);
    readSettings();
    initWK6500MeasSetup();
}

void clsMeasSetup::initWK6500MeasSetup()
{
    clsFormat *f=new clsFormat();
    this->btnItem1->setText(item1);
    this->btnItem2->setText(item2);
    if(equcct=="SER")
        this->btnEqucct->setText("串联");
    else
        this->btnEqucct->setText("并联");
    this->btnBias->setText(f->format(bias,2)+"A");
    if(biasType=="A")
        this->btnBiasType->setText("电流");
    else
        this->btnBiasType->setText("电压");
    this->btnFreq->setText(f->format(frequency,2)+"Hz");
    this->btnLevel->setText(f->format(level,2)+"V");
    this->btnRange->setText(range);
    this->btnSpeed->setText(speed);
    if(biasSwitch=="OFF")
        this->btnSwitch->setText("关");
    else
        this->btnSwitch->setText("开");
}

void clsMeasSetup::writeSettings()
{
    clsSettings settings;
    QString strNode="WK6500MeasSetup/";
    settings.writeSetting(strNode+"Item1",this->item1);
    settings.writeSetting(strNode+"Item2",this->item2);
    settings.writeSetting(strNode+"Equcct",this->equcct);
    settings.writeSetting(strNode+"Speed",this->speed);
    settings.writeSetting(strNode+"Range",this->range);
    settings.writeSetting(strNode+"BiasType",this->biasType);
    //settings.writeSetting(strNode+"BiasStatus",this->biasStatus);
    settings.writeSetting(strNode+"BiasSwitch",this->biasSwitch);
    settings.writeSetting(strNode+"Bias",this->bias);
    settings.writeSetting(strNode+"Level",this->level);
    settings.writeSetting(strNode+"Frequency",this->frequency);
}

void clsMeasSetup::readSettings()
{

    clsSettings settings;
    QString strNode="WK6500MeasSetup/";

    settings.readSetting(strNode+"Item1",this->item1);
    settings.readSetting(strNode+"Item2",this->item2);
    settings.readSetting(strNode+"Equcct",this->equcct);
    settings.readSetting(strNode+"Speed",this->speed);
    settings.readSetting(strNode+"Range",this->range);
    settings.readSetting(strNode+"BiasType",this->biasType);
    //settings.readSetting(strNode+"BiasStatus",this->biasStatus);
    settings.readSetting(strNode+"BiasSwitch",this->biasSwitch);
    settings.readSetting(strNode+"Bias",this->bias);
    settings.readSetting(strNode+"Level",this->level);
    settings.readSetting(strNode+"Frequency",this->frequency);
}

void clsMeasSetup::on_btnItem1_clicked()
{
    clsWK6500Items *wk6500=new clsWK6500Items();
    wk6500->setWindowTitle(tr("设置测试项目"));
    if(wk6500->exec()==QDialog::Accepted)
    {
        this->item1=wk6500->getItem();
    }
    this->btnItem1->setText(item1);
}

void clsMeasSetup::on_btnItem2_clicked()
{
    clsWK6500Items *wk6500=new clsWK6500Items();
    wk6500->setWindowTitle(tr("设置测试项目"));
    if(wk6500->exec()==QDialog::Accepted)
    {
        this->item2=wk6500->getItem();
    }
    this->btnItem2->setText(item2);
}

void clsMeasSetup::on_btnFreq_clicked()
{
    NumberInput *num=new NumberInput;
    num->setWindowTitle(tr("设置测试频率"));
    doubleType dt;
    dt.setData(frequency,"");
    QString tmpUnit;
    double tmpValue;
    dt.getDataAndUnit(tmpValue,tmpUnit);
    num->setValueAndSuffix(tmpValue,tmpUnit);
    if(num->exec()==QDialog::Accepted)
    {
        this->frequency=num->getNumber();
        dt.setData(frequency,"");
    }
//    clsFormat *f=new clsFormat();
//    QString str=f->format(frequency,2);
//    this->btnFreq->setText(str+"Hz");
    btnFreq->setText(dt.formateToString(6)+"Hz");
}

void clsMeasSetup::on_btnLevel_clicked()
{
    NumberInput *num=new NumberInput();
    num->setWindowTitle(tr("设置测试电平"));
    if(num->exec()==QDialog::Accepted)
    {
        this->level=num->getNumber();
    }
    clsFormat *f=new clsFormat();
    QString str=f->format(level,2);
    this->btnLevel->setText(str+"V");
}

void clsMeasSetup::on_btnEqucct_clicked()
{
    if(btnEqucct->text()=="串联")
    {
        this->btnEqucct->setText("并联");
        this->equcct="PAR";
    }
    else
    {
        btnEqucct->setText("串联");
        this->equcct="SER";
    }
}

void clsMeasSetup::on_btnBiasType_clicked()
{
    if(this->btnBiasType->text()=="电流")
    {
        this->btnBiasType->setText("电压");
        this->biasType="V";
    }
    else
    {
        this->btnBiasType->setText("电流");
        this->biasType="A";
    }
}

void clsMeasSetup::on_btnSpeed_clicked()
{
    clsSpeed *dlg=new clsSpeed();
    dlg->setWindowTitle(tr("设置测试速度"));
    if(dlg->exec()==QDialog::Accepted)
    {
        this->speed=dlg->getSpeed();
    }
    btnSpeed->setText(speed);
}

void clsMeasSetup::on_btnRange_clicked()
{
    clsRange *dlg=new clsRange();
    dlg->setWindowTitle(tr("设置测试档位"));
    if(dlg->exec()==QDialog::Accepted)
    {
        this->range=dlg->getRange();
    }
    this->btnRange->setText(range);
}

void clsMeasSetup::on_btnBias_clicked()
{
    dlgLevelInputBox *levelInput=new dlgLevelInputBox();
    levelInput->setWindowTitle(tr("设置偏压"));
    if(levelInput->exec()==QDialog::Accepted)
    {
        bias=levelInput->getValue();
    }
    clsFormat *f=new clsFormat();
    btnBias->setText(f->format(bias,2));
}

void clsMeasSetup::on_btnSwitch_clicked()
{
    if(this->btnSwitch->text()=="开")
    {
        this->btnSwitch->setText("关");
        this->biasSwitch="OFF";
    }
    else
    {
        this->btnSwitch->setText("开");
        this->biasSwitch="ON";
    }
}

void clsMeasSetup::on_btnCancel_clicked()
{
    this->reject();
}

void clsMeasSetup::on_btnOK_clicked()
{
    writeSettings();
    this->accept();
}
double clsMeasSetup::getLevel()
{
    return level;
}

void clsMeasSetup::setLevel(double value)
{
    level = value;
}

double clsMeasSetup::getBias()
{
    return bias;
}

void clsMeasSetup::setBias(double value)
{
    bias=value;
}

double clsMeasSetup::getFrequency()
{
    return frequency;
}

void clsMeasSetup::setFreqency(double value)
{
    frequency = value;
}

QString clsMeasSetup::getBiasSwitch()
{
    return biasSwitch;
}

void clsMeasSetup::setBiasSwitch(const QString value)
{
    biasSwitch = value;
}

QString clsMeasSetup::getBiasType()
{
    return biasType;
}

void clsMeasSetup::setBiasType(const QString value)
{
    biasType = value;
}

QString clsMeasSetup::getRange()
{
    return range;
}

void clsMeasSetup::setRange(const QString value)
{
    range = value;
}

QString clsMeasSetup::getSpeed()
{
    return speed;
}

void clsMeasSetup::setSpeed(const QString value)
{
    speed = value;
}

QString clsMeasSetup::getEqucct()
{
    return equcct;
}

void clsMeasSetup::setEqucct(QString value)
{
    equcct = value;
}

QString clsMeasSetup::getItem2()
{
    return item2;
}

void clsMeasSetup::setItem2(QString value)
{
    item2 = value;
}

QString clsMeasSetup::getItem1() /*const*/
{
    return item1;
}

void clsMeasSetup::setItem1(QString value)
{
    item1 = value;
}

