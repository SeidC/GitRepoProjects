#include "DataHandler.h"

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{


}

bool DataHandler::isCrcCheckActive(void) const
{
    return crcCheck;
}

void DataHandler::setCrcCheck(bool status)
{
    crcCheck = status;
}

bool DataHandler::isSqcCheckActive(void) const
{
    return sqcCheck;
}

void DataHandler::receiveData(QByteArray &data)
{
    switch(activeJob)
    {
        case FLASH_JOB:
            rxHandler = new TpRxHandler();
            rxHandler->validateData(data);
        break;
        case RAW_DATA_JOB:

        break;
        default:
        break;
    }
}

void DataHandler::setJob(DataHandler::Job_t job)
{
    activeJob = job;
}


void DataHandler::setSqcCheck(bool status)
{
    sqcCheck = status;
}


