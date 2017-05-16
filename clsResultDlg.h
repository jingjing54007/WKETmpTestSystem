#ifndef CLSRESULTDLG_H
#define CLSRESULTDLG_H

#include "ui_clsResultDlg.h"

class clsResultDlg : public QDialog, private Ui::clsResultDlg
{
    Q_OBJECT

public:
    explicit clsResultDlg(QWidget *parent = 0);
private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();
    void on_cmbBias_currentIndexChanged(int index);

private:
    int index;
};

#endif // CLSRESULTDLG_H
