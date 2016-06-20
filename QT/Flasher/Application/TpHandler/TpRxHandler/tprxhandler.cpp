#include "tprxhandler.h"


TpRxHandler::TpRxHandler()
{
    tpTimer = new QTimer();
    connect(tpTimer,SIGNAL(timeout()),this,SLOT(run()));
}

void TpRxHandler::validateReceivedData(QByteArray &data)
{
   if(!tpTimer->isActive())
   {
       buffer->append(data);
       tpTimer->start(0);
   }
}

QByteArray TpRxHandler::getNextData(uint nBytes)
{
    return buffer->mid(0,nBytes);
}

uint TpRxHandler::convertUintValue(QByteArray &data)
{
    uint value;
    for(int i = 0; i < data.size(); i++)
    {
        value |= ((data.at(i) & 0x00FF) << (i*4));
    }
    return value;
}

bool TpRxHandler::checkHeaderLength(QByteArray &data)
{
    bool ret = false;
    if(((uint)data.size()) == Tp::getHeaderLengthSize())
    {
        if(convertUintValue(data) > 0)
        {
            ret = true;
        }
    }
    return ret;
}

bool TpRxHandler::checkHeaderSign(QByteArray &data)
{
    uint header;
    bool ret = false;
    if(((uint)data.size()) == Tp::getHeaderSignSize())
    {
        header = convertUintValue(data);

        if(Tp::isHeader(header))
        {
            ret = true;
        }
    }
    return ret;
}



void TpRxHandler::run()
{
    Tp *tp;
    Tp::MsgPart_t part;
    QByteArray nextData;
    uint nextDataSize;
    bool status;

    if(!buffer->isEmpty())
    {
        if(tp == NULL)
            tp = newTp();

        part = tp->getCurrentMsgPart();
        nextDataSize = tp->getNextMsgPartSize(part);
        nextData = getNextData(nextDataSize);

        switch(part)
        {
            case Tp::HEADER_START_SIGN:
                status = checkHeaderSign(nextData);
            break;
            case Tp::HEADER_LENGTH:
                status = checkHeaderLength(nextData);
                if(status == true)
                {
                   tp->setDataLength(convertUintValue(nextData));
                }
            break;
            case Tp::BODY_SIZE:

            break;
            case Tp::BODY_DATA:

            break;
            case Tp::FOOTER_SQC:

            break;
            case Tp::FOOTER_CRC:

            break;
            case Tp::FOOTER_STOP_SIGN:
            default:

            break;
        }

        if(status == true)
            tp->setToNextPart();
    }
    else
    {
        tpTimer->stop();
    }
}


