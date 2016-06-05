QT += widgets serialport

TARGET = terminal
TEMPLATE = app

INCLUDEPATH +=              \
    Application             \
    Application\Console     \
    Application\MainWindow  \
    Application\Settings    \

SOURCES += \
    Application\main.cpp \
    Application\MainWindow\mainwindow.cpp \
    Application\Settings\settingsdialog.cpp \
    Application\Console\console.cpp

HEADERS += \
    Application\MainWindow\mainwindow.h \
    Application\Settings\settingsdialog.h \
    Application\Console\console.h

FORMS += \
    Ui\mainwindow.ui \
    Ui\settingsdialog.ui

RESOURCES += \
    terminal.qrc
