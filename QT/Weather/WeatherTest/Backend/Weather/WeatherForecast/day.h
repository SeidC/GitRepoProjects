#ifndef DAY_H
#define DAY_H

#include <QObject>
#include <QList>

class Day;

typedef QList<Day*> DayList;

class Day : public QObject
{
    Q_OBJECT
public:
    explicit Day(QObject *parent = 0);

private:

signals:

public slots:
};

#endif // DAY_H
