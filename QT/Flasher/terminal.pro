QT += widgets serialport

TARGET = terminal
TEMPLATE = app

INCLUDEPATH +=              \
    Application             \
    Application/Console     \
    Application/MainWindow  \
    Application/Settings    \
    Application/Flash

SOURCES += \
    Application/main.cpp \
    Application/MainWindow/mainwindow.cpp \
    Application/Settings/settingsdialog.cpp \
    Application/Console/console.cpp \
    Application/Flash/flash.cpp

HEADERS += \
    Application/MainWindow/mainwindow.h \
    Application/Settings/settingsdialog.h \
    Application/Console/console.h \
    Application/Flash/flash.h

FORMS += \
    Ui/mainwindow.ui \
    Ui/settingsdialog.ui \
    Ui/flash.ui

RESOURCES += \
    terminal.qrc
