#ifndef TPHEADER_H
#define TPHEADER_H
#include "types.h"

class TpHeader
{
public:
    TpHeader();

public: //methods

public: //static methods
    static uint getHeaderSign(void);
private: //parameter
    static const uint HEADER_SIGN = 0xAA55;



};

#endif // TPHEADER_H
