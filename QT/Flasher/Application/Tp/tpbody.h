#ifndef TPBODY_H
#define TPBODY_H

#include "types.h"

class TpBody
{

private: //Parameter

    QUintArray *data;
    uint dataLength;

public:
    TpBody();
    uint getDataLength() const;
    QUintArray *getData() const;
};

#endif // TPBODY_H
