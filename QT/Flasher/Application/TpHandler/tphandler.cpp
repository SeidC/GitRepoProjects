#include "tphandler.h"

TpHandler::TpHandler(QObject *parent) : QThread(parent)
{
    serialPort = NULL;
    buffer = new QByteArray;
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

bool TpHandler::isDataAvailable()
{
    return dataAvailable;
}

void TpHandler::setDataAvailableStatus(bool status)
{
    dataAvailable = status;
}

void TpHandler::setConnections()
{

}

void TpHandler::setSerialPort(QSerialPort *port)
{
    serialPort = port;
}

void TpHandler::setSqcCheck(bool status)
{
    sqcCheck = status;
}

void TpHandler::setTpHandling(bool status)
{
    tpHandling = status;
}
