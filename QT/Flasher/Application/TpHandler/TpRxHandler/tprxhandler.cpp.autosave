#include "tprxhandler.h"


TpRxHandler::TpRxHandler()
{
    tpTimer = new QTimer();
    connect(tpTimer,SIGNAL(timeout()),this,SLOT(run()));
}

void TpRxHandler::validateReceivedData(QByteArray &data)
{
   Tp *tp;
   if(!tpTimer->isActive())
   {
       tp = new Tp();
       addTp(tp);
       buffer->append(data);
       tpTimer->start(0);
   }
}

QByteArray TpRxHandler::getNextData(uint nBytes)
{
    return buffer->mid(0,nBytes);
}

bool TpRxHandler::checkHeaderLength(QByteArray &data)
{

}

bool TpRxHandler::checkHeaderSign(QByteArray &data)
{
    uint header;
    bool ret = false;
    if(((uint)data.size()) == Tp::getHeaderSignSize())
    {
        for(int i = 0; i < data.size(); i++)
        {
            header |= ((data.at(i) & 0x00FF) << (i*4));
        }

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
        tp = getLastTp();
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


