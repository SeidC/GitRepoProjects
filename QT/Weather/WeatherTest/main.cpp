#include "widget.h"
#include <QApplication>
#include "weather.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    Weather weather;
//    QString city("A");

//    weather.cityRequest(city);


    return a.exec();
}
