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
    Statemachine::State_t state = getState();
    swtich(state)
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

void TP::doStatemachine()
{
    sm.exec();
    return;
}

void TP::doHeaderStart()
{

}

void TP::doHeaderId()
{

}

void TP::doHeaderDataLength()
{

}

void TP::doBodySize()
{

}

void TP::doBodyData()
{

}

void TP::doFooterSqc()
{

}

void TP::doFooterCrc()
{

}

void TP::doFooterStop()
{

}

