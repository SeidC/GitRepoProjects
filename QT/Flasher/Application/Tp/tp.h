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
    enum TpParts_t
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
protected:
    int getNextData(void);
    void setToNextPart(void);
    TpParts_t getCurrentPart(void);

protected:
    QTimer *tpTimer;
    QByteArray *buffer;

private:

    TpParts_t currentPart;
    static uint dataAv[PART_QUANTITY];

signals:

public slots:
};

#endif // TP_H
