#include "header.h"

Header::Header()
{

}

unsigned int Header::getStartSign() const
{
    return startSign;
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

int Header::getDataLenth() const
{
    return dataLenth;
}

void Header::setDataLenth(int value)
{
    dataLenth = value;
}
