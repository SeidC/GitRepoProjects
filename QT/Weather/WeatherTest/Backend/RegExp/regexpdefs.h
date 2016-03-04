#ifndef REGEXPDEFS_H
#define REGEXPDEFS_H
#include <QString>
#include <QList>


class Pattern;


/**
 * @brief PatternList
 */
typedef QList<Pattern> PatternList;


/**
 * @brief The Pattern class
 */
class Pattern
{

public:
    /**
     * @brief Pattern
     * @param sPattern
     * @param iMatches
     */
    Pattern(QString sPattern, int iMatches);
    /**
     * @brief getPattern
     * @return
     */
    QString getPattern() const;
    /**
     * @brief getMatches
     * @return
     */
    int getMatches() const;


private:
    /**
     * @brief pattern
     */
    QString pattern;
    /**
     * @brief matches
     */
    int matches;

};

/**
 * @brief WeatherTemp
 */
extern Pattern WeatherTemp;
/**
 * @brief WeatherDay
 */
extern Pattern WeatherDay;
/**
 * @brief WeatherSunshine
 */
extern Pattern WeatherSunshine;
/**
 * @brief WeatherWind
 */
extern Pattern WeatherWind;
/**
 * @brief WeatherType
 */
extern Pattern WeatherType;
/**
 * @brief CityAndUrl
 */
extern Pattern CityAndUrl;
/**
 * @brief Count
 */
extern Pattern Count;


#endif // REGEXPDEFS_H
