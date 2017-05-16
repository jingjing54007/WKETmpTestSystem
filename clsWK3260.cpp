#include "clsWK3260.h"
#include "dlgLevelInputBox.h"
#include "clsFormat.h"
#include "clsSpeed.h"
#include "clsRange.h"
#include "NumberInput.h"
#include "clsSettings.h"

clsWK3260::clsWK3260(QWidget *parent) :
    WKEMeasStetup(parent)
{
    setupUi(this);
    readSettings();
    initWK3260MeasSetup();
}

void clsWK3260::initWK3260MeasSetup()
{
    clsFormat *f=new clsFormat();
    this->cmbItem1->setCurrentText(item1);
    this->cmbItem2->setCurrentText(item2);
    //this->cmbStatus->setCurrentText(biasStatus);
    this->btnFreq->setText(f->format(frequency,2)+"Hz");
    this->btnBias->setText(f->format(bias,2)+"A");
    this->btnLevel->setText(f->format(level,2)+"V");
    this->btnRange->setText(this->range);
    this->btnSpeed->setText(this->speed);
    if("ON"==biasSwitch)
        this->btnSwitch->setText("开");
    else
        this->btnSwitch->setText("关");
    if("SER"==equcct)
        this->btnEqucct->setText("串联");
    else
        this->btnEqucct->setText("并联");
}

void clsWK3260::writeSettings()
{
    clsSettings settings;
    QString strNode="WK3260MeasSetup/";
    settings.writeSetting(strNode+"Item1",this->item1);
    settings.writeSetting(strNode+"Item2",this->item2);
    settings.writeSetting(strNode+"Equcct",this->equcct);
    settings.writeSetting(strNode+"Speed",this->speed);
    settings.writeSetting(strNode+"Range",this->range);
    settings.writeSetting(strNode+"BiasType",this->biasType);
    settings.writeSetting(strNode+"BiasStatus",this->biasStatus);
    settings.writeSetting(strNode+"BiasSwitch",this->biasSwitch);
    settings.writeSetting(strNode+"Bias",this->bias);
    settings.writeSetting(strNode+"Level",this->level);
    settings.writeSetting(strNode+"Frequency",this->frequency);
}

void clsWK3260::readSettings()
{
    clsSettings settings;
    QString strNode="WK3260MeasSetup/";
    settings.readSetting(strNode+"Item1",this->item1);
    settings.readSetting(strNode+"Item2",this->item2);
    settings.readSetting(strNode+"Equcct",this->equcct);
    settings.readSetting(strNode+"Speed",this->speed);
    settings.readSetting(strNode+"Range",this->range);
    settings.readSetting(strNode+"BiasType",this->biasType);
    settings.readSetting(strNode+"BiasStatus",this->biasStatus);
    settings.readSetting(strNode+"BiasSwitch",this->biasSwitch);
    settings.readSetting(strNode+"Bias",this->bias);
    settings.readSetting(strNode+"Level",this->level);
    settings.readSetting(strNode+"Frequency",this->frequency);
}

void clsWK3260::setItem1(QString item)
{
    item1=item;
}

void clsWK3260::setItem2(QString item)
{
    item2=item;
}

void clsWK3260::setEqucct(QString equcct)
{
    this->equcct=equcct;
}

void clsWK3260::setSpeed(QString speed)
{
    this->speed=speed;
}

void clsWK3260::setRange(QString range)
{
    this->range=range;
}

void clsWK3260::setBiasType(QString biasType)
{
    this->biasType=biasType;
}

void clsWK3260::setBiasSwitch(QString biasSwicth)
{
    this->biasSwitch=biasSwicth;
}

void clsWK3260::setBias(double bias)
{
    this->bias=bias;
}

void clsWK3260::setFreqency(double freq)
{
    this->frequency=freq;
}

void clsWK3260::setLevel(double level)
{
    this->level=level;
}

QString clsWK3260::getItem1()
{
    return item1;
}

QString clsWK3260::getItem2()
{
    return item2;
}

QString clsWK3260::getBiasStatus()
{
    return biasStatus;
}

QString clsWK3260::getBiasSwitch()
{
    return biasSwitch;
}

QString clsWK3260::getRange()
{
    return range;
}

QString clsWK3260::getSpeed()
{
    return speed;
}

QString clsWK3260::getEqucct()
{
    return equcct;
}

QString clsWK3260::getBiasType()
{
    return biasType;
}

double clsWK3260::getFrequency()
{
    return frequency;
}

double clsWK3260::getLevel()
{
    return level;
}

double clsWK3260::getBias()
{
    return bias;
}

void clsWK3260::on_cmbItem1_currentIndexChanged(int index)
{
    this->item1=cmbItem1->currentText();
    if(item1=="Z")
    {
        cmbItem2->clear();
        cmbItem2->addItem("A");
        item2="A";
    }
    else
    {
        cmbItem2->clear();
        QStringList list;
        list<<"Q"<<"D"<<"R";
        cmbItem2->addItems(list);
    }
}

void clsWK3260::on_cmbItem2_currentIndexChanged(int index)
{
    item2=cmbItem2->currentText();
}

void clsWK3260::on_cmbStatus_currentIndexChanged(int index)
{
    this->biasStatus=cmbStatus->currentText();
}

void clsWK3260::on_btnBias_clicked()
{
    dlgLevelInputBox *input=new dlgLevelInputBox();
    if(QDialog::Accepted==input->exec())
    {
        this->bias=input->getValue();
    }
    clsFormat *format=new clsFormat();
    btnBias->setText(format->format(bias,2)+"A");
}

void clsWK3260::on_btnSwitch_clicked()
{
    if("开"== btnSwitch->text())
    {
        btnSwitch->setText("关");
        biasSwitch="OFF";
    }
    else if("关"==btnSwitch->text())
    {
        btnSwitch->setText("开");
        biasSwitch="ON";
    }
}

void clsWK3260::on_btnLevel_clicked()
{
    dlgLevelInputBox *input=new dlgLevelInputBox();
    if(input->exec()==QDialog::Accepted)
    {
        this->level=input->getValue();
    }
    clsFormat *format=new clsFormat();
    btnLevel->setText(format->format(level,2)+"V");
}

void clsWK3260::on_btnFreq_clicked()
{
    NumberInput *input =new NumberInput();
    if(input->exec()==QDialog::Accepted)
    {
        frequency=input->getNumber();
    }
    clsFormat *format=new clsFormat();
    btnFreq->setText(format->format(frequency,2)+"Hz");
}

void clsWK3260::on_btnSpeed_clicked()
{
    clsSpeed *dlg=new clsSpeed();
    if(dlg->exec()==QDialog::Accepted)
    {
        speed=dlg->getSpeed();
    }
    btnSpeed->setText(speed);
}

void clsWK3260::on_btnRange_clicked()
{
    clsRange *dlg=new clsRange();
    if(dlg->exec()==QDialog::Accepted)
    {
        range=dlg->getRange();
    }
    btnRange->setText(range);
}

void clsWK3260::on_btnEqucct_clicked()
{
    if(btnEqucct->text()=="串联")
    {
        btnEqucct->setText("并联");
        equcct="PAR";
    }
    else if(btnEqucct->text()=="并联")
    {
        btnEqucct->setText("串联");
        equcct="SER";
    }
}

void clsWK3260::on_btnOK_clicked()
{
    writeSettings();
    this->accept();
}

void clsWK3260::on_btnCancel_clicked()
{
    this->reject();
}
