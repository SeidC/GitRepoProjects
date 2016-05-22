#include "header.h"

Header::Header(QObject *parent) : QObject(parent)
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
