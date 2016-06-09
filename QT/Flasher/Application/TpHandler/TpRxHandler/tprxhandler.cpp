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

void TpRxHandler::run()
{
    QByteArray nextData;
    int count;
    if(!buffer->isEmpty())
    {
        count = getNextData();


        setToNextPart();
    }
    else
    {
        tpTimer->stop();
    }
}


