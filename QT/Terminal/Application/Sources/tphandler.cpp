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

void TpHandler::putData(const QByteArray &data)
{
    bufferData(data);
    createNewTp();
    startCheck();
    return;
}

void TpHandler::checkData(void)
{
    int nByte;
    /*check data only when new Tp Message was generated
     *and buffer is not empty (data is available
     */
    if(bufferTp != NULL && !buffer->isEmpty())
    {
       nByte = bufferTp->getNextDataSize();
       if (nByte > 0)
       {
            /*Copy buffered data into a new Byte Arry*/
            QByteArray quickBuf(buffer->right(nByte));
            /*Handover Byte Arry to TP Message*/
            bufferTp->setNextData(quickBuf);
            /*Chope last read data from Byte Array*/
            buffer->chop(nByte);
       }
       /*Execute Statemachine*/
       bufferTp->doStatemachine();
    }
    return;
}


void TpHandler::createNewTp(void)
{
    bufferTp = new TP();
    return;
}

void TpHandler::bufferData(const QByteArray &data)
{
    for(int i = data.size()-1; i >= 0; i-- )
    {
        buffer->push_back(data.at(i));
    }
    return;
}
