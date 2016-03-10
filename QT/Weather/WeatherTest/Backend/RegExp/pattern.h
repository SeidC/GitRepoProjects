#ifndef PATTERN_H
#define PATTERN_H

#include <QObject>
#include <QList>

class Pattern;

typedef QList<Pattern*> PatternList;
typedef QList<Pattern::MatchType_t> MatchTypeList;


class Pattern : public QObject
{
    Q_OBJECT
public:
    typedef enum
    {
    /*--- Sunshine Match Types --------------*/
        SUNSHINE_UP,
        SUNSHINE_DOWN,
        SUNSHINE_DURATION,
    /*--- Day and Date Match Types ----------*/
        DAY,
        DATE,
    /*--- Type Match Types ------------------*/
        TYPE,
    /*--- Temperature Match Types -----------*/
        TEMPERATURE_MIN,
        TEMPERATURE_MAX,
    /*--- Rain Match Types ------------------*/
        RAIN_QUANTITY,
        RAIN_RISK,
    /*--- Wind Match Types ------------------*/
        WIND_DRIECTION,
        WIND_FORCE,
    /*--- City Match Types -------------------*/
        URL,
        CITY,
    /*--- Result Match Types -----------------*/
        RESULT_QUANTITY,
        RESULT_COUNTRY,

    }MatchType_t;

public:

    explicit Pattern(QObject *parent = 0);
    /**
     * @brief Pattern
     * @param sPattern
     * @param iMatches
     */
    Pattern(QString sPattern, int iMatches);

    /**
     * @brief Pattern
     * @param sPattern
     * @param iMatches
     * @param matchList
     */
    Pattern(QString sPattern, int iMatches, MatchTypeList matchList);

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

    /**
     * @brief getMatchTypes
     * @return
     */
    MatchTypeList getMatchTypes(void);


private:
    /**
     * @brief pattern
     */
    QString pattern;
    /**
     * @brief matches
     */
    int matches;

    MatchTypeList matchTypes;

signals:

public slots:
};

#endif // PATTERN_H
