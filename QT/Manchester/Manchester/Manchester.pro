TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH +=          \
           E:/Privat/Git/MyRepo/AVR/433MHzTest/RFTest/RFTest/Manchester/ \
           avr


SOURCES += main.c       \
           E:/Privat/Git/MyRepo/AVR/433MHzTest/RFTest/RFTest/Manchester/Manchester.c


HEADERS += E:/Privat/Git/MyRepo/AVR/433MHzTest/RFTest/RFTest/Manchester/Manchester.h    \
           avr/io.h



