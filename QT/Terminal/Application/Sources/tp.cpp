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

