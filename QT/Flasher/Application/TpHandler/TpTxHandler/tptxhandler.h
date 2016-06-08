#ifndef TPTXHANDLER_H
#define TPTXHANDLER_H

#include "tphandler.h"


class TpTxHandler : public TpHandler
{
public:
    TpTxHandler();
private:
    void setConnections(void);
protected:
    void run(void);
};

#endif // TPTXHANDLER_H
