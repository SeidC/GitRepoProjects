#include "footer.h"

Footer::Footer(QObject *parent) : QObject(parent)
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

void Footer::setStopSign(int value)
{
    stopSign = value;
}
