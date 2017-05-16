#include "clsMainDialog.h"
#include "clsRuningSettings.h"
#include "UserfulFunctions.h"
#include "NumberInput.h"
#include "clsSettings.h"
#include "clsMeasSetup.h"
#include "clsInstrumentFactory.h"
#include "WKEMeasSetupFactory.h"
#include <QMessageBox>
#include "clsTraceSetup.h"
#include "doubleType.h"
#include <QFileDialog>
#include "clsResultDlg.h"
#include <Qwt/qwt_picker_machine.h>
#include "dlgLevelInputBox.h"

#include <QDebug>

clsMainDialog::clsMainDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
    meas= WKEMeasSetupFactory::getMeasSetup(clsRS::getInst().meterSeries);
    Instrument= clsInstrumentFactory::getWKEInstrument(clsRS::getInst().meterSeries);
    stop=false;
    waite=false;
    rBtnIndex=0;
    rbtnBias1->setChecked(true);
    readSettings();

    meas->readSettings();
    initInstrumet();
    Instrument->updateGPIBCommand();
    setCmbTcTypeText();
    temp=new clsGetTemp();
    inittcType= temp->setupTh(0.0,100.0, tcType);
    plot=new clsPlotWidget();

    QHBoxLayout *hLayout=new QHBoxLayout;
    hLayout->addWidget(plot);
    plotWidget->setLayout(hLayout);
    picker=new QwtPlotPicker(QwtPlot::xBottom,QwtPlot::yLeft,QwtPlotPicker::NoRubberBand,
                             QwtPicker::AlwaysOn,plot->canvas());
    picker->setTrackerMode(QwtPicker::AlwaysOff);
    picker->setStateMachine(new QwtPickerDragPointMachine());
    picker->setRubberBandPen(QColor(Qt::red));
    picker->setRubberBand(QwtPicker::NoRubberBand);
    picker->setTrackerPen(QColor(Qt::white));
    connect(picker,SIGNAL(moved(QPoint)),this,SLOT(moveMark(QPoint)));

    this->cmbTcType->setCurrentIndex(tcTypeIndex);
    setRbtnBiasText();
}

void clsMainDialog::testTemp()
{
    temp->run();
}

void clsMainDialog::writeSettings()
{
    clsSettings settings;
    QString strNode="Main/";
    settings.writeSetting(strNode+"TcTypeIndex",this->tcTypeIndex);
    settings.writeSetting(strNode+"DelayTime",this->delayTime);
    settings.writeSetting(strNode+"BiasSetup",this->biasStup);
    settings.writeSetting(strNode+"Item1",this->item1);
    settings.writeSetting(strNode+"Item2",this->item2);
    settings.writeSetting(strNode+"Speed",this->speed);
    settings.writeSetting(strNode+"Range",this->range);
    settings.writeSetting(strNode+"Equcct",this->equcct);
    settings.writeSetting(strNode+"BiasType",this->biasType);
    settings.writeSetting(strNode+"BiasSwitch",this->biasSwitch);
    //settings.writeSetting(strNode+"BiasStatus",this->biasStatus);
    settings.writeSetting(strNode+"BiasSetup",this->biasStup);
    settings.writeSetting(strNode+"Bias",this->bias);
    settings.writeSetting(strNode+"Level",this->level);
    settings.writeSetting(strNode+"Frequency",this->frequency);
    settings.writeSetting(strNode+"DelayTime",this->delayTime);

//    settings.writeSetting(strNode+"BiasList",this->biasList);
//    settings.writeSetting(strNode+"MaxTemp",this->maxTemp);
    // meas->writeSettings();
}

void clsMainDialog::readSettings()
{
    clsSettings settings;
    QString strNode="Main/";
    settings.readSetting(strNode+"TcTypeIndex",this->tcTypeIndex);
    settings.readSetting(strNode+"Item1",this->item1);
    settings.readSetting(strNode+"Item2",this->item2);
    settings.readSetting(strNode+"Speed",this->speed);
    settings.readSetting(strNode+"Range",this->range);
    settings.readSetting(strNode+"Equcct",this->equcct);
    settings.readSetting(strNode+"BiasType",this->biasType);
    settings.readSetting(strNode+"BiasSwicth",this->biasSwitch);
    //settings.readSetting(strNode+"BiasStatus",this->biasStatus);
    settings.readSetting(strNode+"BiasSetup",this->biasStup);
    settings.readSetting(strNode+"Bias",this->bias);
    settings.readSetting(strNode+"Frequency",this->frequency);
    settings.readSetting(strNode+"Level",this->level);
    settings.readSetting(strNode+"DelayTime",this->delayTime);
    strNode="Trace";
    settings.readSetting(strNode+"BiasList",this->biasList);
    settings.readSetting(strNode+"MaxTemp",this->maxTemp);
}

void clsMainDialog::setCmbTcTypeText()
{

    switch (tcTypeIndex) {
    case 0:
        tcType=clsGetTemp::J_Type_TC;
        break;
    case 1:
        tcType=clsGetTemp::K_Type_TC;
        break;
    case 2:
        tcType=clsGetTemp::N_Type_TC;
        break;
    case 3:
        tcType=clsGetTemp::TC;
        break;
    case 4:
        tcType=clsGetTemp::S_Type_TC;
        break;
    case 5:
        tcType=clsGetTemp::T_Type_TC;
        break;
    case 6:
        tcType=clsGetTemp::B_Type_TC;
        break;
    case 7:
        tcType=clsGetTemp::E_Type_TC;
        break;
    default:
        break;
    }
    //inittcType=temp->setupTh(0.0,100.0, tcType);
    // cmbTcType->setCurrentIndex(tcTypeIndex);

}

void clsMainDialog::setRbtnBiasText()
{
    QList<QRadioButton*> rbtnList;
    rbtnList<<rbtnBias1<<rbtnBias2<<rbtnBias3<<rbtnBias4<<rbtnBias5;
    doubleType dt;
    for(int i=0;i<rbtnList.length();i++)
    {
        if(i<biasList.length())
        {
            dt.setData(biasList.at(i),"");
            rbtnList.at(i)->setVisible(true);
            rbtnList.at(i)->setText(dt.formateToString(4)+"A");
        }
        else
            rbtnList.at(i)->setVisible(false);
    }
}

void clsMainDialog::initInstrumet()
{
    item1=meas->getItem1();
    item2=meas->getItem2();
    equcct=meas->getEqucct();
    speed=meas->getSpeed();
    range=meas->getRange();
    biasType=meas->getBiasType();
    biasSwitch=meas->getBiasSwitch();
    bias=meas->getBias();
    frequency=meas->getFrequency();
    level=meas->getLevel();

    Instrument->setItem1(item1);
    Instrument->setItem2(item2);
    Instrument->setEqucct(equcct);
    Instrument->setSpeed(speed);
    Instrument->setRange(range);
    Instrument->setBiasType(biasType);
    Instrument->setBiasSwitch(biasSwitch);
    Instrument->setBias(bias);
    Instrument->setFrequency(frequency);
    Instrument->setLevel(level);
    Instrument->updateGPIBCommand();
}

void clsMainDialog::autoSaveResult()
{
    QFile file(strFilePath);
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        return;
    }
    QTextStream stream(&file);
    stream.setCodec("GBK");

    if(yDataMap.count()<=0)
        return;

    for(int j=0;j<biasList.length();j++)
    {
        QString strBias=tr("%1,%2").arg("偏置电流").arg(QString::number(biasList.at(j)));
        stream<<strBias<<"\n";
        QString strTitle=tr("%1,%2").arg(tr("时间")) .arg("温度");
        stream<<strTitle<<"\n";
        for(int m=0;m<yDataMap[j].length();m++)
        {
            double value=yDataMap[j].at(m);
            QString strData=tr("%1,%2").arg(QString::number(xData.at(m))).arg(QString::number(value));
            stream<<strData<<"\n";
        }
    }
    stream.flush();
    file.close();
}

void clsMainDialog::on_btnTrig_clicked()
{
    int i;
    if(btnTrig->isChecked())
    {
        btnTrig->setText("停止\n测试");
        btnTrig->setIcon(QIcon(":/Icon/Icons/stop.png"));

        if(!inittcType)
        {
            QMessageBox::warning(this,"Warning","Config thermocouple failed!",QMessageBox::Ok,QMessageBox::Cancel);
            btnTrig->setChecked(false);
            btnTrig->setText("开始\n测试");
            btnTrig->setIcon(QIcon(":/Icon/Icons/single.png"));
            return;
        }
        xData.clear();
        yLeftData.clear();
        yDataMap.clear();
        plot->turnOffCurves();
        plot->addNewCurve(biasList.length());
        QTime testTime;
        double maxTime=delayTime;

        double normTemp=temp->trig(0,false);;
        for( i=0;i<biasList.length() && btnTrig->isChecked();i++)
        {
            stop=false;
            waite=false;
            double time=0.0;
            double dbTemp=temp->trig(0,stop);
            yDataMap[i]<<dbTemp;
            plot->setAxisScale(QwtPlot::xBottom,0,maxTime);
            while(btnTrig->isChecked() &&(!stop))
            {
                testTime.start();
                dbTemp= temp->trig(delayTime*1000,stop);
                Instrument->trig();
                yDataMap[i]<<dbTemp;
                xData<<time;
                plot->plotShowCurves(i,xData,yDataMap[i]);
                double dbTime=testTime.elapsed();
                if(i==0)
                {
                    plot->setAxisScale(QwtPlot::xBottom,0,time);
                    maxTime=time;
                }
                time+=(dbTime)/1000.0;
                if(dbTemp>=maxTemp)
                {
                    stop=true;
                }
            }
            if(i!=biasList.length()-1 && btnTrig->isChecked() )
            {
                while(!waite)
                {
                    double value=temp->trig(delayTime*1000,waite);
                    if((value-normTemp)<1)
                    {
                        waite=true;
                        QMessageBox::question(this,tr("提示"),tr("是否开始测试"),QMessageBox::Ok);
                    }
                }
            }
        }
        waite=true;
        btnTrig->setChecked(false);
        btnTrig->setText("开始\n测试");
        btnTrig->setIcon(QIcon(":/Icon/Icons/single.png"));
    }
    else
    {
        waite=true;
        stop=true;
        btnTrig->setChecked(false);
        btnTrig->setText("开始\n测试");
        btnTrig->setIcon(QIcon(":/Icon/Icons/single.png"));
    }
    autoSaveResult();
}

void clsMainDialog::on_btnMeasStup_clicked()
{
    if(meas->exec()==QDialog::Accepted)
    {
        item1=meas->getItem1();
        item2=meas->getItem2();
        equcct=meas->getEqucct();
        speed=meas->getSpeed();
        range=meas->getRange();
        biasType=meas->getBiasType();
        biasSwitch=meas->getBiasSwitch();
        bias=meas->getBias();
        frequency=meas->getFrequency();
        level=meas->getLevel();

        initInstrumet();
    }
    meas->writeSettings();
}

void clsMainDialog::on_btnAutoFit_clicked()
{
    plot->autoScale();
}

void clsMainDialog::on_cmbTcType_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        tcType=clsGetTemp::J_Type_TC;
        break;
    case 1:
        tcType=clsGetTemp::K_Type_TC;
        break;
    case 2:
        tcType=clsGetTemp::N_Type_TC;
        break;
    case 3:
        tcType=clsGetTemp::TC;
        break;
    case 4:
        tcType=clsGetTemp::S_Type_TC;
        break;
    case 5:
        tcType=clsGetTemp::T_Type_TC;
        break;
    case 6:
        tcType=clsGetTemp::B_Type_TC;
        break;
    case 7:
        tcType=clsGetTemp::E_Type_TC;
        break;
    default:
        break;
    }
    tcTypeIndex=index;

    temp->setThermocoupleTyple(tcType);
    temp->setupTh(0.0,100,tcType);
    writeSettings();
}

void clsMainDialog::on_btnTraceSetup_clicked()
{
    clsTraceSetup *trace=new clsTraceSetup();
    if(trace->exec()==QDialog::Accepted)
    {
        biasList=trace->getBiasList();
        maxTemp=trace->getTemp();
        delayTime=trace->getDelayTime();
        setRbtnBiasText();
    }
}

void clsMainDialog::on_btnData_clicked()
{
    QString strPath=tr("默认");
    QString fileName=QFileDialog::getSaveFileName(this,tr("保存测试结果"),strPath,
                                                  "CSV files (*.csv)", NULL);
    if(fileName.isNull())
        return;
    if(QFile::exists(fileName))
    {
        QDir fileDir=QFileInfo(fileName).dir();
        if(!fileDir.remove(fileName))
            return;
    }
    if(!fileName.isNull())
    {
        strFilePath=fileName;
    }
}

void clsMainDialog::on_btnSaveImg_clicked()
{
    QPixmap pixMap=QPixmap::grabWidget(this);
    QString format="png";
    //QString strPath=QDir::currentPath()+"untitled"+format;
    QString strPath=tr("untitled");
    QString fileName=QFileDialog::getSaveFileName(this,tr("保存测试图像"),strPath,
                                   tr("%1 Files (*.%2);;All Files (*)").arg(format.toUpper()).arg(format));
    if(!fileName.isEmpty())
    {
        pixMap.save(fileName,"png");
    }
}

void clsMainDialog::moveMark(const QPoint &pos)
{
    QString info;
    info=plot->setMark(plot->invTransform(QwtPlot::xBottom,pos.x()),this->rBtnIndex);
}

void clsMainDialog::on_rbtnBias1_clicked()
{
    this->rBtnIndex=0;
}

void clsMainDialog::on_rbtnBias2_clicked()
{
    this->rBtnIndex=1;
}

void clsMainDialog::on_rbtnBias3_clicked()
{
    this->rBtnIndex=2;
}

void clsMainDialog::on_rbtnBias4_clicked()
{
    this->rBtnIndex=3;
}

void clsMainDialog::on_rbtnBias5_clicked()
{
    this->rBtnIndex=4;
}
