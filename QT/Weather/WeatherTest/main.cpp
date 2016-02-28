#include "widget.h"
#include <QApplication>
#include "weathercom.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    WeatherCom weather;
    QString city("A");

    weather.cityRequest(city);


    return a.exec();
}
