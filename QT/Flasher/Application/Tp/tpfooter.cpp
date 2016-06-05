#include "tpfooter.h"

TpFooter::TpFooter()
{

}

uint TpFooter::getFooterSign(void)
{
    return FOOTER_SIGN;
}

uint TpFooter::getCrc() const
{
    return crc;
}

void TpFooter::setCrc(const uint &value)
{
    crc = value;
}

uint TpFooter::getSqc() const
{
    return sqc;
}

void TpFooter::setSqc(const uint &value)
{
    sqc = value;
}
