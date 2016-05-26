#include "tphandler.h"
#include "QDebug"


TpHandler::TpHandler(QObject *parent) : QObject(parent)
{
    tpMessages = new TpList();
    buffer     = new QByteArray();
    timer      = new QTimer();
    bufferTp   = NULL;
    connect(timer,SIGNAL(timeout()),this,SLOT(checkData()));
}

void TpHandler::startCheck(void)
{
    timer->start(DEFAULT_CHECK_TIME);
    return;
}

void TpHandler::putData(QByteArray &data)
{
    buffer->push_front(data);
    createNewTp();
    startCheck();
    return;
}

void TpHandler::checkData(void)
{
    QByteArray quickBuf;
    int nByte;
    if(bufferTp != NULL)
    {
       bufferTp->doStatemachine();

       nByte = bufferTp->getNextDataSize();
       if (nByte > 0)
       {
           for(i = 0; i  < nByte; i++)
           {
                //quickBuf.append(buffer->)
           }
       }
    }
    return;
}


void TpHandler::createNewTp(void)
{
    bufferTp = new TP();
    return;
}

