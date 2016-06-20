#include "DataHandler.h"

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{
    tpBuffer = new TpBuffer();

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

        break;
        case RAW_DATA_JOB:

        break;
        default:
        break;
    }
}

void DataHandler::addTp(Tp *tp)
{
    tpBuffer->push_back(tp);
}

Tp *DataHandler::getLastTp()
{
    return tpBuffer->last();
}

void DataHandler::setJob(DataHandler::Job_t job)
{
    activeJob = job;
}

Tp* DataHandler::newTp(void)
{
    return new Tp(this);
}


void DataHandler::setSqcCheck(bool status)
{
    sqcCheck = status;
}




