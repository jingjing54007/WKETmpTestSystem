#include "clsWK6500Items.h"

clsWK6500Items::clsWK6500Items(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

QString clsWK6500Items::getItem()
{
    return this->item;
}

void clsWK6500Items::on_btnC_clicked()
{
    this->item="C";
    this->accept();
}

void clsWK6500Items::on_btnD_clicked()
{
    this->item="D";
    this->accept();
}

void clsWK6500Items::on_btnL_clicked()
{
    this->item="L";
    this->accept();
}

void clsWK6500Items::on_btnQ_clicked()
{
    this->item="Q";
    this->accept();
}

void clsWK6500Items::on_btnR_clicked()
{
    this->item="R";
    this->accept();
}

void clsWK6500Items::on_btnX_clicked()
{
    this->item="X";
    this->accept();
}

void clsWK6500Items::on_btnG_clicked()
{
    this->item="G";
    this->accept();
}

void clsWK6500Items::on_btnB_clicked()
{
    this->item="B";
    this->accept();
}

void clsWK6500Items::on_btnZ_clicked()
{
    this->item="Z";
    this->accept();
}

void clsWK6500Items::on_btnA_clicked()
{
    this->item="θ";
    this->accept();
}

void clsWK6500Items::on_btnY_clicked()
{
    this->item="Y";
    this->accept();
}

void clsWK6500Items::on_btnCancel_clicked()
{
    this->reject();
}
