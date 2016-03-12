#ifndef PATTERN_H
#define PATTERN_H

#include <QObject>
#include <QList>

class Pattern;

typedef QList<Pattern*> PatternList;


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
    /*--- Ohter Match Types ------------------*/
        URL_ID
    }MatchType_t;

    typedef QList<Pattern::MatchType_t> MatchTypeList;

public:

    explicit Pattern(QObject *parent = 0);
    /**
     * @brief Pattern
     * @param sPattern
     * @param iMatches
     */
    Pattern(QString sPattern);

    /**
     * @brief Pattern
     * @param sPattern
     * @param iMatches
     * @param matchList
     */
    Pattern(QString sPattern, MatchTypeList matchList);

    /**
     * @brief getPattern
     * @return
     */
    QString getPattern(void) const;
    /**
     * @brief getMatches
     * @return
     */
    int getMatches(void) const;

    /**
     * @brief getMatchTypes
     * @return
     */
    MatchTypeList getMatchTypes(void);

    void addMatchType(MatchType_t type);

    void addMatchType(MatchTypeList lst);
private:
    /**
     * @brief pattern
     */
    QString pattern;
    /**
     * @brief matchTypes
     */
    MatchTypeList matchTypes;

signals:

public slots:
};

#endif // PATTERN_H
