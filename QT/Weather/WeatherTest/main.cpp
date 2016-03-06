#include "widget.h"
#include <QApplication>
#include "weather.h"
#include "patternhandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    PatternHandler* handler;
    handler = PatternHandler::getInstance();
    handler->addPattern(&WeatherTemp     );
    handler->addPattern(&WeatherDay      );
    handler->addPattern(&WeatherSunshine );
    handler->addPattern(&WeatherWind     );
    handler->addPattern(&WeatherType     );
    handler->addPattern(&CityAndUrl      );
    handler->addPattern(&Count           );

    w.show();

//    Weather weather;
//    QString city("A");

//    weather.cityRequest(city);


    return a.exec();
}


