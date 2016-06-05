#ifndef TP_H
#define TP_H

#include <QObject>
#include "tpheader.h"
#include "tpbody.h"
#include "tpfooter.h"

class Tp : public QObject, public TpHeader, public TpBody, public TpFooter
{
    Q_OBJECT
public:
    explicit Tp(QObject *parent = 0);

signals:

public slots:
};

#endif // TP_H
