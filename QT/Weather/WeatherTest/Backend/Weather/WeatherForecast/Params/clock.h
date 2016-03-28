#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>

class Clock : public QObject
{
    Q_OBJECT
public:
    explicit Clock(QObject *parent = 0);

private:
    int hour;
    int minutes;
};

#endif // CLOCK_H
