#ifndef WEATHERCOM_H
#define WEATHERCOM_H

#include <QObject>
#include "regexp.h"

class WeatherCom : public QObject
{
    Q_OBJECT
public:
    explicit WeatherCom(QObject *parent = 0);

signals:

public slots:
};

#endif // WEATHERCOM_H
