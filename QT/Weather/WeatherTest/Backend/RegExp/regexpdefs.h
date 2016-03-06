#ifndef REGEXPDEFS_H
#define REGEXPDEFS_H
#include <QString>
#include "pattern.h"


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
#define SEARCH_LIST_RESULT_COUNT "\\<.*resultcount\\\"\\>(\\d*)\\s*\\w*\\s*\\w*(.*)\\<\\/li\\>"

/**
 *
 */
#define SEARCH_LIST_PLACES_AND_URL "\\<.*resultcity.*\\s*.*.href\\=\\\"(.*)\\\"\\>\\s*(.*)\\<\\/a\\>"



extern Pattern WeatherTemp(QString(WEATHER_TEMP),2);
extern Pattern WeatherDay(QString(WEATHER_DAY_DATE),2);
extern Pattern WeatherSunshine(QString(WEATHER_SUNNSHINE),3);
extern Pattern WeatherWind(QString(WEATHER_WIND),2);
extern Pattern WeatherType(QString(WEATER_WTYPE),1);
extern Pattern CityAndUrl(QString(SEARCH_LIST_PLACES_AND_URL),2);
extern Pattern Count(QString(SEARCH_LIST_RESULT_COUNT),2);

#endif // REGEXPDEFS_H
