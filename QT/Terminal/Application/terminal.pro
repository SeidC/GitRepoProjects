QT += widgets serialport

TARGET = terminal
TEMPLATE = app

INCLUDEPATH +=  \
    Sources/    \
    Sources/Tp/

SOURCES += \
    Sources/main.cpp \
    Sources/mainwindow.cpp \
    Sources/settingsdialog.cpp \
    Sources/console.cpp \
    Sources/Tp/header.cpp \
    Sources/Tp/footer.cpp \
    Sources/Tp/body.cpp \
    Sources/tp.cpp \
    Sources/tphandler.cpp \
    Sources/statemachine.cpp \

HEADERS += \
    Sources/mainwindow.h \
    Sources/settingsdialog.h \
    Sources/console.h \
    Sources/Tp/header.h \
    Sources/Tp/footer.h \
    Sources/Tp/body.h \
    Sources/tp.h \
    Sources/tphandler.h \
    Sources/statemachine.h \

FORMS += \
    Ui/mainwindow.ui \
    Ui/settingsdialog.ui

RESOURCES += \
    terminal.qrc
