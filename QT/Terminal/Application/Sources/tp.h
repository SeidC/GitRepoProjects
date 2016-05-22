#ifndef TP_H
#define TP_H

#include "header.h"
#include "body.h"
#include "footer.h"


class TP : public Header, public Body, public Footer
{

public: //Enum
    typedef enum
    {
        TP_HEADER_START         = 0x00,
        TP_HEADER_ID            = 0x01,
        TP_HEADER_DATA_LENGTH   = 0x02,

        TP_BODY_SIZE            = 0x10,
        TP_BODY_DATA            = 0x11,

        TP_FOOTER_SQC           = 0x20,
        TP_FOOTER_CRC           = 0x21,
        TP_FOOTER_STOP          = 0x22,

    }Tp_StateMachine_t;
public:
    TP();
    void stateMachine(Tp_StateMachine_t state);

private:

};

#endif // TP_H
