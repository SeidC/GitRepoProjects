#include "tpheader.h"

TpHeader::TpHeader()
{



}

uint TpHeader::getHeaderSign(void)
{
    return HEADER_SIGN_VALUE;
}

uint TpHeader::getHeaderSignSize(void)
{
    return HEADER_SIGN_SIZE;
}

bool TpHeader::isHeader(uint value)
{
    if (value == HEADER_SIGN_VALUE)
        return true;
    else return false;
}

