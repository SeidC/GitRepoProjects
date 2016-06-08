#include "tprxhandler.h"


TpRxHandler::TpRxHandler()
{

}

void TpRxHandler::setConnections()
{
    if(serialPort != NULL)
    {
        connect(serialPort,SIGNAL(readyRead()),this,SLOT(readData()));
    }
}

void TpRxHandler::readData(void)
{
   QByteArray data = serialPort->readAll();
   buffer->append(data);
   setDataAvailableStatus(true);
}

void TpRxHandler::run(void)
{
    forever
    {
        if(isDataAvailable())
        {

            if(buffer->isEmpty())
            {
                setDataAvailableStatus(false);
            }
        }
    }
}
