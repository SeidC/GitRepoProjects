#ifndef RAIN_H
#define RAIN_H

#include <QObject>
#include <QString>

#include "datastorage.h"

class Rain : public DataStorage<int,QString>
{
public:
    Rain();
};

#endif // RAIN_H
