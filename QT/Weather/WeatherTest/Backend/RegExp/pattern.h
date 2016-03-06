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
    explicit Pattern(QObject *parent = 0);
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

signals:

public slots:
};

#endif // PATTERN_H
