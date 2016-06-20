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
    static uint getHeaderSignSize(void);
    static uint getHeaderLengthSize(void);
    static bool isHeader(uint value);

    void setDataLength(const uint &value);

protected:
    static const uint HEADER_SIGN_SIZE = 2;
    static const uint HEADER_LENGTH_SIZE = 1;

private: //parameter
    static const uint HEADER_SIGN_VALUE = 0xAA55;
    uint id;
    uint dataLength;
};

#endif // TPHEADER_H
