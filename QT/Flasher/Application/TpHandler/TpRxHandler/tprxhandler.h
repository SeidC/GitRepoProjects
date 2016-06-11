#ifndef TPRXHANDLER_H
#define TPRXHANDLER_H
#include "tp.h"
#include "QByteArray"

class TpRxHandler : public Tp
{
public:
    TpRxHandler();
    void validateData(QByteArray &data);
    void verifyTpOffsetData(Tp::TpParts_t part, QByteArray &data);
    bool isHeaderSign(uint data);
    bool isFooterSign(uint data);
private:


private slots:
    void run(void);
};

#endif // TPRXHANDLER_H
