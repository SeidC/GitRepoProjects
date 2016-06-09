QT += widgets serialport

TARGET = Flasher
TEMPLATE = app

INCLUDEPATH +=                          \
    Application                         \
    Application/Console                 \
    Application/MainWindow              \
    Application/Settings                \
    Application/Flash                   \
    Application/TpHandler               \
    Application/TpHandler/TpTxHandler   \
    Application/TpHandler/TpRxHandler   \
    Application/Tp

SOURCES += \
    Application/main.cpp \
    Application/MainWindow/mainwindow.cpp \
    Application/Settings/settingsdialog.cpp \
    Application/Console/console.cpp \
    Application/Flash/flash.cpp \
    Application/TpHandler/TpRxHandler/tprxhandler.cpp \
    Application/TpHandler/TpTxHandler/tptxhandler.cpp \
    Application/Tp/tp.cpp \
    Application/Tp/tpheader.cpp \
    Application/Tp/tpbody.cpp \
    Application/Tp/tpfooter.cpp \
    Application/TpHandler/datahandler.cpp

HEADERS += \
    Application/MainWindow/mainwindow.h \
    Application/Settings/settingsdialog.h \
    Application/Console/console.h \
    Application/Flash/flash.h \
    Application/TpHandler/TpRxHandler/tprxhandler.h \
    Application/TpHandler/TpTxHandler/tptxhandler.h \
    Application/Tp/tp.h \
    Application/Tp/tpheader.h \
    Application/Tp/tpbody.h \
    Application/Tp/tpfooter.h \
    Application/types.h \
    Application/TpHandler/datahandler.h

FORMS += \
    Ui/mainwindow.ui \
    Ui/settingsdialog.ui \
    Ui/flash.ui

RESOURCES += \
	Flasher.qrc
