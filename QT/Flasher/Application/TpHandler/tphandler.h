#ifndef TPHANDLER_H
#define TPHANDLER_H

#include <QThread>
#include <QSerialPort>
#include <QByteArray>
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

    bool isDataAvailable(void);

    void setDataAvailableStatus(bool status);

private:
    virtual void setConnections(void);

private:
    bool crcCheck;
    bool sqcCheck;
    bool tpHandling;
protected:
    QSerialPort *serialPort;
    QByteArray *buffer;
    bool dataAvailable;
    Tp *tp;


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
    /**
     * @brief setSerialPort
     * @param port
     */
    void setSerialPort(QSerialPort *port);

};

#endif // TPHANDLER_H
