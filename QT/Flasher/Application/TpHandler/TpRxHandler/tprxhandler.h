#ifndef TPRXHANDLER_H
#define TPRXHANDLER_H
#include "tp.h"
#include "QByteArray"
#include "datahandler.h"

class TpRxHandler : public DataHandler
{
public:
    TpRxHandler();
    void validateReceivedData(QByteArray &data);
    void verifyTpOffsetData(Tp::MsgPart_t part, QByteArray &data);
    QByteArray getNextData(uint nBytes);

    bool checkHeaderSign(QByteArray &data);
    bool checkHeaderLength(QByteArray &data);

private:


private slots:
    void run(void);
};

#endif // TPRXHANDLER_H
