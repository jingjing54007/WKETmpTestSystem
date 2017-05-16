#include "clsTraceSetup.h"
#include "dlgLevelInputBox.h"
#include "clsFormat.h"
#include "NumberInput.h"
#include "clsSettings.h"


clsTraceSetup::clsTraceSetup(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    readSettings();
    initTraceSetup();
    biasIndex=0;
}

QList<double> clsTraceSetup::getBiasList() const
{
    return biasList;
}

double clsTraceSetup::getTemp()
{
    return this->temp;
}

double clsTraceSetup::getDelayTime() const
{
    return delay;
}

void clsTraceSetup::setBiasList(QList<double> list)
{
    biasList=list;
}

void clsTraceSetup::setMaxTemp(double temp)
{
    this->temp=temp;
}

void clsTraceSetup::initTraceSetup()
{
    clsFormat *f=new clsFormat();
    QList<QPushButton*> btnList;
    btnList.clear();
    btnList<<btnBias1<<btnBias2<<btnBias3<<btnBias4<<btnBias5;
    int j=0;
    for(int i=0;i<btnList.length();i++)
    {
        if(visiableList.length()>i)
        {
            if(bool(visiableList.at(i)))
            {
                btnList.at(i)->setText(f->format(biasList.at(j),3)+"A");
                j++;
            }
            else
                btnList.at(i)->setVisible(false);
        }
    }
    btnTemp->setText(f->format(temp,2)+"℃");
    btnDelay->setText(f->format(delay,2)+"s");
}

void clsTraceSetup::writeSettings()
{
    clsSettings settings;
    QString strNode="Trace/";
    settings.writeSetting(strNode+"MaxTemp",this->temp);
    settings.writeSetting(strNode+"BiasList",this->biasList);
    settings.writeSetting(strNode+"VisiableList",this->visiableList);
    settings.writeSetting(strNode+"Delay",this->delay);
}

void clsTraceSetup::readSettings()
{
    clsSettings settings;
    QString strNode="Trace/";
    settings.readSetting(strNode+"MaxTemp",this->temp);
    settings.readSetting(strNode+"BiasList",this->biasList);
    settings.readSetting(strNode+"VisiableList",this->visiableList);
    settings.readSetting(strNode+"Delay",this->delay);
}

void clsTraceSetup::on_btnBias1_clicked()
{
    biasIndex=0;
}

void clsTraceSetup::on_btnBias2_clicked()
{
    biasIndex=1;
}

void clsTraceSetup::on_btnBias3_clicked()
{
    biasIndex=2;
}

void clsTraceSetup::on_btnBias4_clicked()
{
    biasIndex=3;
}

void clsTraceSetup::on_btnBias5_clicked()
{
    biasIndex=4;
}

void clsTraceSetup::on_btnTemp_clicked()
{
    NumberInput *num=new NumberInput();
    if(num->exec()==QDialog::Accepted)
    {
        this->temp=num->getNumber();
    }
    clsFormat *f=new clsFormat();
    QString str=f->format(temp,2);
    this->btnTemp->setText(str);
}

void clsTraceSetup::on_btnCancel_clicked()
{
    this->reject();
}

void clsTraceSetup::on_btnOK_clicked()
{
    writeSettings();
    this->accept();
}

void clsTraceSetup::on_btnAdd_clicked()
{
    int i=0;
    QList<QPushButton*> btnList;
    btnList<<btnBias1<<btnBias2<<btnBias3<<btnBias4<<btnBias5;
    while(i<5)
    {
        if(!(btnList.at(i)->isVisible()))
        {
            btnList.at(i)->setVisible(true);
            i=100;
        }
        else
            i++;
    }
}

void clsTraceSetup::on_btnSet_clicked()
{
    QList<QPushButton*> btnList;
    btnList<<btnBias1<<btnBias2<<btnBias3<<btnBias4<<btnBias5;
    dlgLevelInputBox *dlg=new dlgLevelInputBox();
    dlg->setWindowTitle(tr("设置偏置"));
    if(dlg->exec()==QDialog::Accepted)
    {
        double value=dlg->getValue();
        QString suffix=dlg->getSuffix();
        QString unit=dlg->getUnit();
        doubleType dt(value,suffix);
        value=dt.Data();
        if(biasList.length()<btnList.length())
        {
            biasList.append(value);
        }
        else if(biasList.length()==btnList.length())
        {
            biasList.replace(biasIndex,value);
        }
        dt.setData(value,"");
        btnList.at(biasIndex)->setText(dt.formateToString(5)+unit);
        visiableList.replace(biasIndex,true);
    }
}

void clsTraceSetup::on_btnDel_clicked()
{
    QList<QPushButton*> btnList;
    btnList<<btnBias1<<btnBias2<<btnBias3<<btnBias4<<btnBias5;
    int j=biasIndex;
    for(int i=0;i<biasIndex;i++)
    {
        if(!(btnList.at(i)->isVisible()))
        {
            j--;
        }
    }
    btnList.at(biasIndex)->setVisible(false);
    visiableList.replace(biasIndex,false);
    biasList.removeAt(j);
}

void clsTraceSetup::on_btnSort_clicked()
{
    std::sort(biasList.begin(),biasList.end());
    QList<QPushButton*> btnList;
    btnList<<btnBias1<<btnBias2<<btnBias3<<btnBias4<<btnBias5;
    doubleType dt;
    int j=0;
    for(int i=0;i<btnList.length();i++)
    {
        if(btnList.at(i)->isVisible())
        {
            dt.setData(biasList.at(j),"");
            btnList.at(i)->setText(dt.formateToString(5)+"A");
            j++;
        }
    }
}

void clsTraceSetup::on_btnDelay_clicked()
{
    NumberInput *dlg=new NumberInput();
    if(dlg->exec()==QDialog::Accepted)
    {
        delay=dlg->getNumber();
        doubleType dt;
        dt.setData(delay,"");
        btnDelay->setText(dt.formateToString(5)+"s");
    }
}
