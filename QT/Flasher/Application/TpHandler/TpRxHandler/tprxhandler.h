#ifndef TPRXHANDLER_H
#define TPRXHANDLER_H
#include "tphandler.h"
#include "QByteArray"


class TpRxHandler : public TpHandler
{
public:
    TpRxHandler();

private:
   void setConnections(void);

private slots:
    void readData(void);

protected:
     void run(void);

};

#endif // TPRXHANDLER_H
