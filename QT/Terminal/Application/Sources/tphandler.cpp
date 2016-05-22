#include "tphandler.h"

TpHandler::TpHandler(QObject *parent) : QObject(parent)
{
    tpMessages = new TpList();
}

void TpHandler::checkData(QByteArray &data)
{

}



