#ifndef CLSSPEED_H
#define CLSSPEED_H

#include "ui_clsSpeed.h"

class clsSpeed : public QDialog, private Ui::clsSpeed
{
    Q_OBJECT

public:
    explicit clsSpeed(QWidget *parent = 0);
    QString getSpeed();
private slots:
    void on_btnMax_clicked();
    void on_btnFast_clicked();
    void on_btnMed_clicked();
    void on_btnSlow_clicked();
private:
    QString speed;
};

#endif // CLSSPEED_H
