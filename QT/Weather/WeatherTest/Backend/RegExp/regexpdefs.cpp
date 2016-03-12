#include "regexpdefs.h"


/**
 *
 */
#define WEATHER_TEMP "\\s*([-]?\\d+)\\s*\\/\\s*\\<.*\\>([-]?\\d+)\\s*°C"

/**
 *
 */
#define WEATHER_DAY_DATE "\\>(\\s*\\w+)\\<.*\\>\\s*(\\d+\\.\\d+\\.\\d+)"

/**
 *
 */
#define WEATHER_SUNNSHINE "\\>\\w+\\:\\s+(\\d*[\\.\\d*]*)\\s+\\w\\<.*\\>(\\d*\\:\\d*)<.*>(\\d*\\:\\d*)"

/**
 *
 */
#define WEATHER_WIND ">(\\w+\\-*\\w+)\\<.*\\s*\\>\\s*\\<.*\\>(\\d+\\s+[\\w+|\\/]+)"

/**
 *
 */
#define WEATER_WTYPE "\\>\\s*(\\w+\\s*[\\w+|\\-|\\ö]+)[\\s*<\\/|\\w+|\\=\\\"\\-\\:\\;\\#\\>]+gefühlt"

/**
 *
 */
#define SEARCH_LIST_RESULT_COUNT "\\<.*r\\\"\\>(\\d*)\\s*\\w*\\s*\\w*(.*)\\<\\/li\\>"

/**
 *
 */
#define SEARCH_LIST_PLACES_AND_URL "\\<.*resultcity.*\\s*.*.href\\=\\\"(.*)\\\"\\>\\s*(.*)\\<\\/a\\>"

/**
 *
 */
#define WEATHER_RAIN "\\<.*\\>(\\d*[\\.\\d]+)*\\s+\\l\\/\\m.*\\s+(\\d*)\\%"



Pattern WeatherTemp(QString(WEATHER_TEMP));
Pattern WeatherDayAndDate(QString(WEATHER_DAY_DATE));
Pattern WeatherSunshine(QString(WEATHER_SUNNSHINE));
Pattern WeatherWind(QString(WEATHER_WIND));
Pattern WeatherType(QString(WEATER_WTYPE));
Pattern CityAndUrl(QString(SEARCH_LIST_PLACES_AND_URL));
Pattern Count(QString(SEARCH_LIST_RESULT_COUNT));
Pattern WeatherRain(QString(WEATHER_RAIN));


void initPatternHandler(void)
{
    PatternHandler* handler;
    handler = PatternHandler::getInstance();

    WeatherTemp.addMatchType(Pattern::TEMPERATURE_MIN);
    WeatherTemp.addMatchType(Pattern::TEMPERATURE_MAX);
    handler->addPattern(&WeatherTemp     );

    WeatherDayAndDate.addMatchType(Pattern::DAY);
    WeatherDayAndDate.addMatchType(Pattern::DATE);
    handler->addPattern(&WeatherDayAndDate);

    WeatherSunshine.addMatchType(Pattern::SUNSHINE_UP);
    WeatherSunshine.addMatchType(Pattern::SUNSHINE_DOWN);
    WeatherSunshine.addMatchType(Pattern::SUNSHINE_DURATION);
    handler->addPattern(&WeatherSunshine);

    WeatherWind.addMatchType(Pattern::WIND_DRIECTION);
    WeatherWind.addMatchType(Pattern::WIND_FORCE);
    handler->addPattern(&WeatherWind);

    WeatherType.addMatchType(Pattern::TYPE);
    handler->addPattern(&WeatherType);

    CityAndUrl.addMatchType(Pattern::CITY);
    CityAndUrl.addMatchType(Pattern::URL);
    handler->addPattern(&CityAndUrl);

    Count.addMatchType(Pattern::RESULT_QUANTITY);
    Count.addMatchType(Pattern::RESULT_COUNTRY);
    handler->addPattern(&Count);

    WeatherRain.addMatchType(Pattern::RAIN_QUANTITY);
    WeatherRain.addMatchType(Pattern::RAIN_RISK);
    handler->addPattern(&WeatherRain);
    return;
}
