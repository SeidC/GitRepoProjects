#ifndef PATTERN_H
#define PATTERN_H

#include <QObject>
#include <QList>

class Pattern;

typedef QList<Pattern*> PatternList;
typedef QList<int>      MatchTypeList;


class Pattern : public QObject
{
    Q_OBJECT
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
