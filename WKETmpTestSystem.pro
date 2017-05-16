#-------------------------------------------------
#
# Project created by QtCreator 2017-03-07T14:26:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WKETmpTestSystem
TEMPLATE = app

INCLUDEPATH +=connections \

LIBS += dog_windows_3149756.dll

LIBS    += $$PWD/libs/gpib488.obj \
           $$PWD/libs/visa.lib \
           $$PWD/libs/AduHid.lib \
           $$PWD/libs/AduHid.dll \
           $$PWD/libs/NIDAQmx.lib \

DEFINES    += QT_DLL QWT_DLL

win32:CONFIG(release, debug|release): LIBS += -L$(QTDIR)/bin -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$(QTDIR)/bin  -lqwtd


SOURCES += main.cpp\
        clsSelectConnetion.cpp \
    connections/clsConnection.cpp \
    connections/clsGpib.cpp \
    connections/clsLan.cpp \
    connections/clsUsb.cpp \
    connections/Cnnt.cpp \
    UserfulFunctions.cpp \
    clsSettings.cpp \
    clsRuningSettings.cpp \
    clsMainDialog.cpp \
    doubleType.cpp \
    clsPlotWidget.cpp \
    clsGetTemp.cpp \
    NumberInput.cpp \
    clsMeasSetup.cpp \
    clsWK6500Items.cpp \
    clsSpeed.cpp \
    clsRange.cpp \
    clsFormat.cpp \
    WKEInstrument.cpp \
    clsWK6500Instrument.cpp \
    clsWK3260Instrument.cpp \
    clsWK3260.cpp \
    WKEMeasStetup.cpp \
    clsTraceSetup.cpp \
    clsResultDlg.cpp \
    dlgLevelInputBox.cpp \
    clsDog.cpp \
    DogControl.cpp

HEADERS  += clsSelectConnetion.h \
    connections/clsConnection.h \
    connections/clsGpib.h \
    connections/clsLan.h \
    connections/clsUsb.h \
    connections/Cnnt.h \
    connections/GPIB.h \
    connections/gpib488.h \
    connections/visa.h \
    connections/visatype.h \
    UserfulFunctions.h \
    clsSettings.h \
    clsRuningSettings.h \
    clsMainDialog.h \
    clsRefTraceProperty.h \
    doubleType.h \
    clsPlotWidget.h \
    NIDAQmx.h \
    clsGetTemp.h \
    NumberInput.h \
    clsMeasSetup.h \
    clsWK6500Items.h \
    clsSpeed.h \
    clsRange.h \
    clsFormat.h \
    WKEInstrument.h \
    clsWK6500Instrument.h \
    clsInstrumentFactory.h \
    clsWK3260Instrument.h \
    clsWK3260.h \
    WKEMeasStetup.h \
    WKEMeasSetupFactory.h \
    clsTraceSetup.h \
    clsResultDlg.h \
    dlgLevelInputBox.h \
    clsDog.h \
    dog_api.h \
    dog_vcode.h \
    DogControl.h

FORMS    += clsSelectConnetion.ui \
    clsMainDialog.ui \
    NumberInput.ui \
    clsMeasSetup.ui \
    clsWK6500Items.ui \
    clsSpeed.ui \
    clsRange.ui \
    clsWK3260.ui \
    clsTraceSetup.ui \
    clsResultDlg.ui \
    dlgLevelInputBox.ui

OTHER_FILES += \
    Icons/2T.png \
    Icons/4T.png \
    Icons/add.png \
    Icons/admin.png \
    Icons/advance.png \
    Icons/Analysis.png \
    Icons/Auto.png \
    Icons/autoFit.png \
    Icons/BiasOff.png \
    Icons/BiasOn.png \
    Icons/BiasSettings.png \
    Icons/calibration.png \
    Icons/chennal.png \
    Icons/clear1.png \
    Icons/com.png \
    Icons/copy.png \
    Icons/data.png \
    Icons/data2.png \
    Icons/dataFile.png \
    Icons/del.png \
    Icons/delete.png \
    Icons/delete1.png \
    Icons/detect.png \
    Icons/dir.png \
    Icons/down.png \
    Icons/down1.png \
    Icons/DownBmp.png \
    Icons/edit.png \
    Icons/exit.png \
    Icons/export.png \
    Icons/factory.png \
    Icons/file.png \
    Icons/HILowLimit.png \
    Icons/import.png \
    Icons/info.png \
    Icons/instrument.png \
    Icons/LastPage.png \
    Icons/marker.png \
    Icons/multiStep.png \
    Icons/new.png \
    Icons/new1.png \
    Icons/NextPage.png \
    Icons/open.png \
    Icons/opertator.png \
    Icons/Peak.png \
    Icons/Percentage.png \
    Icons/picture.png \
    Icons/repeat.png \
    Icons/Result.png \
    Icons/rot1.png \
    Icons/rot2.png \
    Icons/rot3.png \
    Icons/rot4.png \
    Icons/save.png \
    Icons/save2.png \
    Icons/saveData.png \
    Icons/single.png \
    Icons/sound.png \
    Icons/splashScreen.png \
    Icons/splashScreen1.png \
    Icons/splashScreen2.png \
    Icons/splashScreen3.png \
    Icons/splashScreen6500.png \
    Icons/standard.png \
    Icons/stepSave.png \
    Icons/stop.png \
    Icons/stop2.png \
    Icons/switch.png \
    Icons/test.png \
    Icons/trace.png \
    Icons/up.png \
    Icons/up1.png \
    Icons/UpBmp.png \
    Icons/zoom.png \
    Icons/Delete.ico \
    Icons/First.ico \
    Icons/Last.ico \
    Icons/Next.ico \
    Icons/savePro.ico \
    Icons/Snap1.ico \
    Icons/Stop3.ico \
    Icons/wk.ico \
    Icons/ReleaseNote.txt \
    Icons/version.txt

RESOURCES += \
    myIcon.qrc
