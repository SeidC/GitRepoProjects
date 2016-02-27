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
#define WEATER_WTYPE "\\>\\s*(\\w+\\s*[\\w+|\\-]+)[\\s*<\\/|\\w+|\\=\\\"\\-\\:\\;\\#\\>]+gefühlt"

/**
 *
 */
#define SEARCH_LIST_RESULT_COUNT "\\<.*resultcount.*(\\d)"

/**
 *
 */
#define SEARCH_LIST_PLACES_AND_URL "\\<.*resultcity.*\\s*.*.href\\=\\\"(.*)\\\"\\>\\s*(.*)\\<\\/a\\>"

Pattern WeatherTemp(QString(WEATHER_TEMP),2);
Pattern WeatherDay(QString(WEATHER_DAY_DATE),2);
Pattern WeatherSunshine(QString(WEATHER_SUNNSHINE),3);
Pattern WeatherWind(QString(WEATHER_WIND),2);
Pattern WeatherType(QString(WEATER_WTYPE),1);
Pattern CityAndUrl(QString(SEARCH_LIST_PLACES_AND_URL),2);
Pattern Count(QString(SEARCH_LIST_RESULT_COUNT),1);


/*******************************************************************************
 * QString getPattern
 ******************************************************************************/
QString Pattern::getPattern() const
{
    return pattern;
}

/*******************************************************************************
 * int getMatches
 ******************************************************************************/
int Pattern::getMatches() const
{
    return matches;
}

