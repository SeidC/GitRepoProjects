#ifndef WEATHERCOM_H
#define WEATHERCOM_H

#include <QObject>
#include "regexp.h"
#include "networkrequest.h"

class WeatherCom : public QObject
{
    Q_OBJECT
public:
    explicit WeatherCom(QObject *parent = 0);
    NetworkRequest* httpRequest;
signals:

private slots:

};

#endif // WEATHERCOM_H
