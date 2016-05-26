#include "tp.h"

TP::TP()
{
  connect(&sm,SIGNAL(onHeaderStart()     ),this,SLOT(doHeaderStart()      ));
  connect(&sm,SIGNAL(onHeaderId()        ),this,SLOT(doHeaderId()         ));
  connect(&sm,SIGNAL(onHeaderDataLength()),this,SLOT(doHeaderDataLength() ));
  connect(&sm,SIGNAL(onBodySize()        ),this,SLOT(doBodySize()         ));
  connect(&sm,SIGNAL(onBodyData()        ),this,SLOT(doBodyData()         ));
  connect(&sm,SIGNAL(onFooterSqc()       ),this,SLOT(doFooterSqc()        ));
  connect(&sm,SIGNAL(onFooterCrc()       ),this,SLOT(doFooterCrc()        ));
  connect(&sm,SIGNAL(onFooterStop()      ),this,SLOT(doFooterStop()       ));
}

Statemachine::State_t TP::getState(void)
{
    return sm.getState();
}

int TP::getNextDataSize()
{
    int ret;
     Statemachine::State_t state;
    if(sm.hasStateChanged())
    {
        state = getState();
    }
    else
    {
        state = Statemachine::TP_NO_STATE;
    }

    switch(state)
    {
        case Statemachine::TP_HEADER_START:
            ret = getSIZE_OF_START_SIGN();
            break;
        case Statemachine::TP_HEADER_ID:
            ret = getSIZE_OF_ID();
            break;
        case Statemachine::TP_HEADER_DATA_LENGTH:
            ret = getSIZE_OF_DATA_LEN();
            break;
        case Statemachine::TP_BODY_SIZE:
            ret = getSIZE_OF_LENGTH();
            break;
        case Statemachine::TP_BODY_DATA:
            ret = getBoyLength();
            break;
        case Statemachine::TP_FOOTER_SQC:
            ret = getSIZE_OF_SQC();
             break;
        case Statemachine::TP_FOOTER_CRC:
            ret = getSIZE_OF_CRC();
             break;
        case Statemachine::TP_FOOTER_STOP:
            ret = getSIZE_OF_STOP_SIGN();
            break;
        default:
            ret = 0;
            break;
    }
    return ret;
}

bool TP::isTpMessage(void)
{

}

void TP::doStatemachine(void)
{
    sm.exec();
    return;
}

void TP::setNextData(const QByteArray &data)
{
    nextData = data;
}

void TP::doHeaderStart(void)
{
    unsigned int signA,signB;
    if(!nextData.isEmpty())
    {
        //for(int i = 0; i < getSIZE_OF_START_SIGN(); i++)
        {
            signA = (unsigned int) nextData.at(0) ;
            signB = (unsigned int) nextData.at(1) ;
        }
        nextData.clear();
        //if(sign == getStartSign())
        {
            sm.setTransition(Statemachine::GO_TO_ID_STATE);
        }
    }
    return;
}

void TP::doHeaderId(void)
{

}

void TP::doHeaderDataLength(void)
{

}

void TP::doBodySize(void)
{

}

void TP::doBodyData(void)
{

}

void TP::doFooterSqc(void)
{

}

void TP::doFooterCrc(void)
{

}

void TP::doFooterStop()
{

}

