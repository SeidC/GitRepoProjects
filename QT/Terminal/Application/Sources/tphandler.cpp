#include "tphandler.h"

TpHandler::TpHandler(QObject *parent) : QObject(parent)
{
    tpMessages = new TpList();
    buffer     = new QByteArray();
    timer      = new QTimer();

    timer->start(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(checkData()));
}

void TpHandler::checkData(void)
{

}



