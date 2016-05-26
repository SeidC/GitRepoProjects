#ifndef TP_H
#define TP_H

#include "header.h"
#include "body.h"
#include "footer.h"
#include "statemachine.h"


class TP : public QObject, public Header, public Body, public Footer
{
    Q_OBJECT

public: //Enum

public:
    explicit TP();
    void stateMachine(Statemachine &sm);
    Statemachine::State_t getState(void);
    int getNextDataSize(void);
    bool isTpMessage(void);
    void doStatemachine(void);

private:
    Statemachine sm;
    bool tpMessage;

public slots:
    void doHeaderStart(void);
    void doHeaderId(void);
    void doHeaderDataLength(void);
    void doBodySize(void);
    void doBodyData(void);
    void doFooterSqc(void);
    void doFooterCrc(void);
    void doFooterStop(void);
};


#endif // TP_H
