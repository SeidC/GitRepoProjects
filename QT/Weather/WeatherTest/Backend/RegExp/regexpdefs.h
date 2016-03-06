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



extern Pattern WeatherTemp;
extern Pattern WeatherDay;
extern Pattern WeatherSunshine;
extern Pattern WeatherWind;
extern Pattern WeatherType;
extern Pattern CityAndUrl;
extern Pattern Count;

#endif // REGEXPDEFS_H
