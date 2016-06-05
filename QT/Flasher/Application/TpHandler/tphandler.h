#ifndef TPHANDLER_H
#define TPHANDLER_H

#include <QObject>
#include "tp.h"

class TpHandler : public QObject
{
    Q_OBJECT
public:
    explicit TpHandler(QObject *parent = 0);

    bool isCrcCheckActive() const;
    bool isSqcCheckActive() const;

    void setCrcCheck(bool value);
    void setSqcCheck(bool value);

private:
    bool crcCheck;
    bool sqcCheck;

signals:

public slots:
};

#endif // TPHANDLER_H
