#include "tphandler.h"

TpHandler::TpHandler(QObject *parent) : QObject(parent)
{

}

bool TpHandler::isCrcCheckActive() const
{
    return crcCheck;
}

void TpHandler::setCrcCheck(bool value)
{
    crcCheck = value;
}

bool TpHandler::isSqcCheckActive() const
{
    return sqcCheck;
}

void TpHandler::setSqcCheck(bool value)
{
    sqcCheck = value;
}
