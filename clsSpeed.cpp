#include "clsSpeed.h"

clsSpeed::clsSpeed(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

QString clsSpeed::getSpeed()
{
    return speed;
}

void clsSpeed::on_btnMax_clicked()
{
    this->speed="Max";
    this->accept();
}

void clsSpeed::on_btnFast_clicked()
{
    this->speed="Fast";
    this->accept();
}

void clsSpeed::on_btnMed_clicked()
{
    this->speed="Med";
    this->accept();
}

void clsSpeed::on_btnSlow_clicked()
{
    this->speed="Slow";
    this->accept();
}
