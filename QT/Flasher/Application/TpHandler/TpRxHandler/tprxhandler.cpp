#include "tprxhandler.h"


TpRxHandler::TpRxHandler()
{
    tpTimer = new QTimer();
    connect(tpTimer,SIGNAL(timeout()),this,SLOT(run()));
}

void TpRxHandler::validateData(QByteArray &data)
{
    buffer->append(data);
    tpTimer->start(0);
}

void TpRxHandler::verifyTpOffsetData(Tp::TpParts_t part, QByteArray &data)
{
    uint result;
    bool status;

    if(part != Tp::BODY_DATA)
    {
        for(int i = 0;i < data.size(); i++)
        {
            result |= ((data.at(i) & 0x00FF) << (i*4));
        }

        switch(part)
        {
            case Tp::HEADER_START_SIGN:
              status = isHeaderSign();
            break;

        }

    }
}

bool TpRxHandler::isHeaderSign(uint data)
{

}

void TpRxHandler::run()
{
    QByteArray nextData;
    Tp::TpParts_t part;
    int count;
    if(!buffer->isEmpty())
    {
        count = getNextData();
        nextData.push_back(buffer->mid(0,count));
        part = getCurrentPart();
        verifyTpOffsetData(part,nextData);
        setToNextPart();
    }
    else
    {
        tpTimer->stop();
    }
}


