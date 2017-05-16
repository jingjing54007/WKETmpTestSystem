#include "clsRange.h"

clsRange::clsRange(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

QString clsRange::getRange()
{
    return this->range;
}

void clsRange::on_btnAuto_clicked()
{
    this->range="Auto";
    this->accept();
}

void clsRange::on_btn1_clicked()
{
    this->range="1";
    this->accept();
}

void clsRange::on_btn2_clicked()
{
    this->range="2";
    this->accept();
}

void clsRange::on_btn3_clicked()
{
    this->range="3";
    this->accept();
}

void clsRange::on_btn4_clicked()
{
    this->range="4";
    this->accept();
}

void clsRange::on_btn5_clicked()
{
    this->range="5";
    this->accept();
}

void clsRange::on_btn6_clicked()
{
    this->range="6";
    this->accept();
}

void clsRange::on_btn7_clicked()
{
    this->range="7";
    this->accept();
}
