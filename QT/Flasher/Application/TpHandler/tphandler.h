#ifndef TPHANDLER_H
#define TPHANDLER_H

#include <QThread>
#include "tp.h"

class TpHandler : public QThread
{
    Q_OBJECT
public:
    explicit TpHandler(QObject *parent = 0);

    /**
     * @brief isCrcCheckActive
     * @return
     */
    bool isCrcCheckActive(void) const;
    /**
     * @brief isSqcCheckActive
     * @return
     */
    bool isSqcCheckActive(void) const;
    /**
     * @brief isTpHandlingActive
     * @return
     */
    bool isTpHandlingActive(void) const;


private:
    bool crcCheck;
    bool sqcCheck;
    bool tpHandling;

signals:

public slots:
    /**
     * @brief setCrcCheck
     * @param status
     */
    void setCrcCheck(bool status);
    /**
     * @brief setSqcCheck
     * @param status
     */
    void setSqcCheck(bool status);
    /**
     * @brief setTpHandling
     * @param status
     */
    void setTpHandling(bool status);

};

#endif // TPHANDLER_H
