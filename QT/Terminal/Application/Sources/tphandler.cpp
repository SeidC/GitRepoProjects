#include "tphandler.h"
#include "QDebug"





TpHandler::TpHandler(QObject *parent) : QObject(parent)
{
    tpMessages = new TpList();
    buffer     = new QByteArray();
    timer      = new QTimer();
    bufferTp   = NULL;
    connect(timer,SIGNAL(timeout()),this,SLOT(checkData()));


    connect(&sm,SIGNAL(onHeaderStart()     ),this,SLOT(doHeaderStart()      ));
    connect(&sm,SIGNAL(onHeaderId()        ),this,SLOT(doHeaderId()         ));
    connect(&sm,SIGNAL(onHeaderDataLength()),this,SLOT(doHeaderDataLength() ));
    connect(&sm,SIGNAL(onBodySize()        ),this,SLOT(doBodySize()         ));
    connect(&sm,SIGNAL(onBodyData()        ),this,SLOT(doBodyData()         ));
    connect(&sm,SIGNAL(onFooterSqc()       ),this,SLOT(doFooterSqc()        ));
    connect(&sm,SIGNAL(onFooterCrc()       ),this,SLOT(doFooterCrc()        ));
    connect(&sm,SIGNAL(onFooterStop()      ),this,SLOT(doFooterStop()       ));

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
       nByte = getNextDataSize();
       if (nByte > 0)
       {
            /*Copy buffered data into a new Byte Arry*/
            QByteArray quickBuf(buffer->right(nByte));
            /*Handover Byte Arry to TP Message*/
            setNextData(quickBuf);
            /*Chope last read data from Byte Array*/
            buffer->chop(nByte);
       }
       /*Execute Statemachine*/
       doStatemachine();
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

void TpHandler::storeTpMessage(TP *msg)
{
    if(msg != NULL)
    {
        tpMessages->push_back(msg);
    }
}

TP *TpHandler::getLastReceivedMessage(void)
{
    TP* tp = NULL;
    int i;
    if(tpMessages->size() > 0)
    {
        i = tpMessages->size() - 1;
        tp = tpMessages->at(i);
    }
    return tp;
}


int TpHandler::getDataSize(Statemachine::State_t state)
{
    int ret;
    switch(state)
    {
        case Statemachine::TP_HEADER_START:
            ret = bufferTp->getSIZE_OF_START_SIGN();
            break;
        case Statemachine::TP_HEADER_ID:
            ret = bufferTp->getSIZE_OF_ID();
            break;
        case Statemachine::TP_HEADER_DATA_LENGTH:
            ret = bufferTp->getSIZE_OF_DATA_LEN();
            break;
        case Statemachine::TP_BODY_SIZE:
            ret = bufferTp->getSIZE_OF_LENGTH();
            break;
        case Statemachine::TP_BODY_DATA:
            ret = bufferTp->getBoyLength();
            break;
        case Statemachine::TP_FOOTER_SQC:
            ret = bufferTp->getSIZE_OF_SQC();
             break;
        case Statemachine::TP_FOOTER_CRC:
            ret = bufferTp->getSIZE_OF_CRC();
             break;
        case Statemachine::TP_FOOTER_STOP:
            ret = bufferTp->getSIZE_OF_STOP_SIGN();
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}


int TpHandler::getNextDataSize()
{
    int ret;
     Statemachine::State_t state;
    if(sm.hasStateChanged())
    {
        state = sm.getState();
    }
    else
    {
        state = Statemachine::TP_NO_STATE;
    }

    switch(state)
    {
        case Statemachine::TP_HEADER_START:
            ret = bufferTp->getSIZE_OF_START_SIGN();
            break;
        case Statemachine::TP_HEADER_ID:
            ret = bufferTp->getSIZE_OF_ID();
            break;
        case Statemachine::TP_HEADER_DATA_LENGTH:
            ret = bufferTp->getSIZE_OF_DATA_LEN();
            break;
        case Statemachine::TP_BODY_SIZE:
            ret = bufferTp->getSIZE_OF_LENGTH();
            break;
        case Statemachine::TP_BODY_DATA:
            ret = bufferTp->getBoyLength();
            break;
        case Statemachine::TP_FOOTER_SQC:
            ret = bufferTp->getSIZE_OF_SQC();
             break;
        case Statemachine::TP_FOOTER_CRC:
            ret = bufferTp->getSIZE_OF_CRC();
             break;
        case Statemachine::TP_FOOTER_STOP:
            ret = bufferTp->getSIZE_OF_STOP_SIGN();
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

bool TpHandler::isTpMessage(void)
{

}

void TpHandler::doStatemachine(void)
{
    sm.exec();
    return;
}

void TpHandler::setNextData(const QByteArray &data)
{
    nextData = data;
}

void TpHandler::resetBufferTp(void)
{
    bufferTp = NULL;
    return;
}

void TpHandler::doHeaderStart(void)
{
   unsigned short sign = prepareIncomingStaticData(Statemachine::TP_HEADER_START);
   if(sign == bufferTp->getStartSign())
   {
     sm.setTransition(Statemachine::GO_TO_HEADER_ID_STATE);

   }
    return;
}

void TpHandler::doHeaderId(void)
{
    unsigned short id = prepareIncomingStaticData(Statemachine::TP_HEADER_ID);
    if(id > 0)
    {
        bufferTp->setId(id);
        sm.setTransition(Statemachine::GO_TO_HEADER_DATALENGTH_STATE);
    }
    return;
}

void TpHandler::doHeaderDataLength(void)
{
    unsigned short dataLen = prepareIncomingStaticData(Statemachine::TP_HEADER_DATA_LENGTH);
    if(dataLen > 0)
    {
        bufferTp->setDataLenth(dataLen);
        sm.setTransition(Statemachine::GO_TO_BODY_SIZE_STATE);
    }
    return;
}

void TpHandler::doBodySize(void)
{
    unsigned short int length = prepareIncomingStaticData(Statemachine::TP_BODY_SIZE);
    if(length > 0)
    {
        bufferTp->setLength(length);
        sm.setTransition(Statemachine::GO_TO_BODY_DATA_STATE);
    }
    return;
}

void TpHandler::doBodyData(void)
{
    QByteArray bodyData;
    pepareIncomingDynamicData(Statemachine::TP_BODY_DATA, bodyData);

    if(!bodyData.isEmpty())
    {
        bufferTp->setData(&bodyData);
        sm.setTransition(Statemachine::GO_TO_FOOTER_SQC_STATE);
    }
    return;
}

void TpHandler::doFooterSqc(void)
{
    unsigned short sqc = prepareIncomingStaticData(Statemachine::TP_FOOTER_SQC);
    if(sqc >= 0)
    {
        bufferTp->setSqc(sqc);
        sm.setTransition(Statemachine::GO_TO_FOOTER_CRC_STATE);
    }
    return;
}

void TpHandler::doFooterCrc(void)
{
    unsigned short crc = prepareIncomingStaticData(Statemachine::TP_FOOTER_SQC);
    if(crc >= 0)
    {
        bufferTp->setSqc(crc);
        sm.setTransition(Statemachine::GO_TO_FOOTER_STOP_STATE);
    }
    return;
}

void TpHandler::doFooterStop()
{
    unsigned short stopSign = prepareIncomingStaticData(Statemachine::TP_FOOTER_STOP);
    if(stopSign == bufferTp->getStopSign())
    {
        storeTpMessage(bufferTp);
        resetBufferTp();
        sm.setTransition(Statemachine::GO_TO_HEADER_START_STATE);
        emit tpMessageReceived();
    }
}

unsigned short int TpHandler::prepareIncomingStaticData(Statemachine::State_t state)
{
    unsigned short int data = 0;
    if(!nextData.isEmpty())
    {
        for(int i = getDataSize(state) - 1; i >= 0; i--)
        {
            data |= (((unsigned int) nextData.at(i) & 0x00FF) << (8*i));
        }
        nextData.clear();
    }
    return data;
}

void TpHandler::pepareIncomingDynamicData(Statemachine::State_t state, QByteArray &data)
{
    if(!nextData.isEmpty())
    {
        for(int i = getDataSize(state) - 1; i >= 0; i-- )
        {
            data.push_back(nextData.at(i));
        }
        nextData.clear();
    }
    return;
}
