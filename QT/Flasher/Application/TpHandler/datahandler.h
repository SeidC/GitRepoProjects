#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QByteArray>
#include <QTimer>
#include "tprxhandler.h"
#include "tptxhandler.h"
#include "tp.h"

class DataHandler : public QObject
{
    Q_OBJECT
public:
    enum Job_t
    {
        FLASH_JOB       = 0x01,
        RAW_DATA_JOB    = 0x02,
    };

public:
    explicit DataHandler(QObject *parent = 0);

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

    void receiveData(QByteArray &data);

    void setJob(Job_t job);
private:
    bool crcCheck;
    bool sqcCheck;

    Job_t activeJob;

    TpRxHandler *rxHandler;
    TpTxHandler *txHandler;

protected:

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



};

#endif // DataHandler_H
