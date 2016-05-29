#include "body.h"

Body::Body()
{
    data = NULL;
}

Body::~Body()
{
    if(data != NULL)
    {
        delete data;
    }
}

int Body::getLength() const
{
    return length;
}

void Body::setLength(int value)
{
    length = value;
}

QByteArray *Body::getData() const
{
    return data;
}

void Body::setData(QByteArray *value)
{
    data = value;
}

int Body::getSIZE_OF_LENGTH()
{
    return SIZE_OF_LENGTH;
}

int Body::getBoyLength()
{
    return length;
}
