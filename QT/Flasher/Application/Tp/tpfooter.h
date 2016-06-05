#ifndef TPFOOTER_H
#define TPFOOTER_H
#include "types.h"

class TpFooter
{

public: //Methods
    TpFooter();

public: //Static Methods
    static uint getFooterSign(void);

private: //Parameter
    static const uint FOOTER_SIGN = 0x55AA;


};

#endif // TPFOOTER_H
