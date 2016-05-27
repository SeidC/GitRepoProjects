#include "footer.h"

Footer::Footer()
{

}

int Footer::getSqc() const
{
    return sqc;
}

void Footer::setSqc(int value)
{
    sqc = value;
}

int Footer::getCrc() const
{
    return crc;
}

void Footer::setCrc(int value)
{
    crc = value;
}

int Footer::getStopSign() const
{
    return stopSign;
}


int Footer::getSIZE_OF_SQC()
{
    return SIZE_OF_SQC;
}

int Footer::getSIZE_OF_CRC()
{
    return SIZE_OF_CRC;
}

int Footer::getSIZE_OF_STOP_SIGN()
{
    return SIZE_OF_STOP_SIGN;
}
