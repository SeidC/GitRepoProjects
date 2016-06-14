#ifndef TP_H
#define TP_H

#include <QObject>
#include "tpheader.h"
#include "tpbody.h"
#include "tpfooter.h"
#include "QTimer"

class Tp : public QObject, public TpHeader, public TpBody, public TpFooter
{
    Q_OBJECT
public:
    enum MsgPart_t
    {
        HEADER_START_SIGN       = 0x00,
        HEADER_LENGTH           = 0x01,
        BODY_SIZE               = 0x02,
        BODY_DATA               = 0x03,
        FOOTER_SQC              = 0x04,
        FOOTER_CRC              = 0x05,
        FOOTER_STOP_SIGN        = 0x06,
        PART_QUANTITY           = 0x07
   };



public:
    explicit Tp(QObject *parent = 0);
    void setMsgValidStatus(bool val);
    bool isMsgValid(void);
    void setToNextPart(void);
    MsgPart_t getCurrentMsgPart(void);
    static uint getNextMsgPartSize(MsgPart_t part);

private:

    MsgPart_t currentPart;
    static uint dataAv[PART_QUANTITY];
    bool valid;

signals:

public slots:
};

#endif // TP_H
