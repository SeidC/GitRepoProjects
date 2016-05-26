#include "header.h"

Header::Header()
{

}

int Header::getStartSign() const
{
    return startSign;
}

void Header::setStartSign(int value)
{
    startSign = value;
}

int Header::getId() const
{
    return id;
}

void Header::setId(int value)
{
    id = value;
}

int Header::getSIZE_OF_DATA_LEN()
{
    return SIZE_OF_DATA_LEN;
}

int Header::getSIZE_OF_ID()
{
    return SIZE_OF_ID;
}

int Header::getSIZE_OF_START_SIGN()
{
    return SIZE_OF_START_SIGN;
}
