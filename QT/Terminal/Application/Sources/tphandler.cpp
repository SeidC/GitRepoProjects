#include "tphandler.h"
#include "QDebug"


TpHandler::TpHandler(QObject *parent) : QObject(parent)
{
    tpMessages = new TpList();
    buffer     = new QByteArray();
    timer      = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(checkData()));
}

void TpHandler::startCheck(void)
{
    timer->start(DEFAULT_CHECK_TIME);
    return;
}

void TpHandler::putData(QByteArray &data)
{
    buffer->append(data);
    startCheck();
    return;
}

void TpHandler::checkData(void)
{

}



