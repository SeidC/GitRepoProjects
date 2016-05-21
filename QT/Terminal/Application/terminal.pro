QT += widgets serialport

TARGET = terminal
TEMPLATE = app

INCLUDEPATH +=  \
    Sources/

SOURCES += \
    Sources/main.cpp \
    Sources/mainwindow.cpp \
    Sources/settingsdialog.cpp \
    Sources/console.cpp

HEADERS += \
    Sources/mainwindow.h \
    Sources/settingsdialog.h \
    Sources/console.h

FORMS += \
    Ui/mainwindow.ui \
    Ui/settingsdialog.ui

RESOURCES += \
    terminal.qrc
