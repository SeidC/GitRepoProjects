#ifndef TPFOOTER_H
#define TPFOOTER_H
#include "types.h"

class TpFooter
{

public: //Methods
    TpFooter();

public: //Static Methods
    static uint getFooterSign(void);

    uint getCrc() const;
    uint getSqc() const;

    void setCrc(const uint &value);
    void setSqc(const uint &value);

private: //Parameter
    static const uint FOOTER_SIGN = 0x55AA;
    uint crc;
    uint sqc;
};

#endif // TPFOOTER_H
