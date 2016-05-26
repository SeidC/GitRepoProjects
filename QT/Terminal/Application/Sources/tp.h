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

private:

public slots:

};


#endif // TP_H
