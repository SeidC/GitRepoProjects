#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include <QString>


class Result;

/**
 * @brief QResultList
 */
typedef QList<Result*> QResultList;


/**
 * @brief The Result class
 */
class Result : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Result
     * @param parent
     */
    explicit Result(QObject *parent = 0);
    /**
     * @brief Result
     * @param sSize
     * @param sTxt
     * @param parent
     */
    Result(int sSize,QString sTxt, QObject *parent = 0);
    /**
     * @brief getTxt
     * @return
     */
    QString getTxt() const;
    /**
     * @brief setTxt
     * @param value
     */
    void setTxt(const QString &value);
    /**
     * @brief getSize
     * @return
     */
    int getSize() const;
    void setSize(int value);

private:
    /**
     * @brief txt
     */
    QString txt;
    /**
     * @brief size
     */
    int     size;

signals:

public slots:
};

#endif // RESULT_H
