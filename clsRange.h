#ifndef CLSRANGE_H
#define CLSRANGE_H

#include "ui_clsRange.h"

class clsRange : public QDialog, private Ui::clsRange
{
    Q_OBJECT

public:
    explicit clsRange(QWidget *parent = 0);
    QString getRange();
private slots:
    void on_btnAuto_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
private:
    QString range;
};

#endif // CLSRANGE_H
