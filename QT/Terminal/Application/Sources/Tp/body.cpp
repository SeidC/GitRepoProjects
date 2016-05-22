#include "body.h"

Body::Body(QWidget *parent) : QWidget(parent)
{

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
