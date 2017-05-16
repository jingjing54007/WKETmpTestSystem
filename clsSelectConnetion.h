#ifndef CLSSELECTCONNETION_H
#define CLSSELECTCONNETION_H

#include "ui_clsSelectConnetion.h"

class clsSelectConnetion : public QDialog, private Ui::clsSelectConnetion
{
    Q_OBJECT

public:
    explicit clsSelectConnetion(QWidget *parent = 0);
    void readSettings();
    void writeSettings();

private slots:
    void on_btnConnct_clicked();
    void on_rBtnGPIB_clicked();

    void on_rBtnLAN_clicked();

    void on_rBtnUSB_clicked();

private:
    int intSelect;
    QString strAddress;
};

#endif // CLSSELECTCONNETION_H
