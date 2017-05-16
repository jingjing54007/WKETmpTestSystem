#include "clsSelectConnetion.h"
#include <QApplication>
#include "clsMainDialog.h"
#include "UserfulFunctions.h"
#include <QSplashScreen>
#include <QFont>
#include "clsDog.h"
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pix(":/Icon/Icons/screen.jpg");
    QSplashScreen screen(pix);
    screen.setFont(QFont("楷体",16, QFont::Bold));
    screen.show();
    screen.showMessage("程序加载中，请稍等......",Qt::AlignRight | Qt::AlignBottom,Qt::red);
    UserfulFunctions::sleepMs(500);
    QString strProductName;
    if((!clsDog::getName(strProductName))|| (strProductName !="WKE FactoryView 2014"))
    {
        QMessageBox::warning(0,QObject::tr("WKE FactoryView 2014"),QObject::tr("请插入加密狗！"));
        return 0;
    }
    clsSelectConnetion w;
    if(w.exec()==QDialog::Accepted)
    {
        clsMainDialog dlg;
        dlg.showMaximized();
        return a.exec();
    }
    else
        return 0;
}
