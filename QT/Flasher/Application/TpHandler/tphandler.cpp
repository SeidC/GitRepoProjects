#include "tphandler.h"

TpHandler::TpHandler(QObject *parent) : QThread(parent)
{

}

bool TpHandler::isCrcCheckActive(void) const
{
    return crcCheck;
}

void TpHandler::setCrcCheck(bool status)
{
    crcCheck = status;
}

bool TpHandler::isSqcCheckActive(void) const
{
    return sqcCheck;
}

bool TpHandler::isTpHandlingActive(void) const
{
    return tpHandling;
}

void TpHandler::setSqcCheck(bool status)
{
    sqcCheck = status;
}

void TpHandler::setTpHandling(bool status)
{
    tpHandling = status;
}
