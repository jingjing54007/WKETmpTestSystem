#ifndef CLSTRACESETUP_H
#define CLSTRACESETUP_H

#include "ui_clsTraceSetup.h"
#include <QPushButton>

class clsTraceSetup : public QDialog, private Ui::clsTraceSetup
{
    Q_OBJECT

public:
    explicit clsTraceSetup(QWidget *parent = 0);
    QList<double> getBiasList() const;
    double getTemp();
    void setBiasList(QList<double> list);
    void setMaxTemp(double temp);
    void initTraceSetup();
    void writeSettings();
    void readSettings();
    double getDelayTime() const;
private slots:

    void on_btnBias1_clicked();

    void on_btnBias2_clicked();

    void on_btnBias3_clicked();

    void on_btnBias4_clicked();

    void on_btnBias5_clicked();

    void on_btnTemp_clicked();

    void on_btnCancel_clicked();

    void on_btnOK_clicked();

    void on_btnAdd_clicked();

    void on_btnSet_clicked();

    void on_btnDel_clicked();

    void on_btnSort_clicked();

    void on_btnDelay_clicked();

private:
    QList<double> biasList;
    QList<QPushButton*> unVisiableBtnList;
    QList<double> visiableList;
    double temp;
    int btnLength;
    int biasIndex;
    double delay;
    //QStringList suffixList;
    QStringList unit;
};

#endif // CLSTRACESETUP_H
