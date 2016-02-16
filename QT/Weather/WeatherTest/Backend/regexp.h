#ifndef REGEXP_H
#define REGEXP_H

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

#define WEATHER_TEMP "\\s*([-]?\\d+)\\s*\\/\\s*\\<.*\\>([-]?\\d+)\\s*°C"
#define WEATHER_DAY_DATE "\\>(\\s*\\w+)\\<.*\\>\\s*(\\d+\\.\\d+\\.\\d+)"
#define WEATHER_SUNNSHINE "\\>\\w+\\:\\s+(\\d*[\\.\\d*]*)\\s+\\w\\<.*\\>(\\d*\\:\\d*)<.*>(\\d*\\:\\d*)"
#define WEATHER_WIND ">(\\w+\\-*\\w+)\\<.*\\s*\\>\\s*\\<.*\\>(\\d+\\s+[\\w+|\\/]+)"
#define WEATER_WTYPE "\\>\\s*(\\w+\\s*[\\w+|\\-]+)[\\s*<\\/|\\w+|\\=\\\"\\-\\:\\;\\#\\>]+gefühlt"



class RegExp : public QRegularExpression
{
public:
    RegExp();
};

#endif // REGEXP_H
