#ifndef TPBODY_H
#define TPBODY_H

#include "types.h"

class TpBody
{

private: //Parameter

    QByteArray *data;
    uint dataLength;

public:
    TpBody();
    uint getDataLength() const;
    QByteArray *getData() const;
};

#endif // TPBODY_H
