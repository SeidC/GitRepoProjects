#ifndef DATASI_H
#define DATASI_H
#include <QString>
#include "datastorage.h"

class DataSI : public DataStorage<QString,int>
{
public:
    DataSI();
};

#endif // DATASI_H
