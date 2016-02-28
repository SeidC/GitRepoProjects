#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include <QString>

class Result : public QObject
{
    Q_OBJECT
public:
    explicit Result(QObject *parent = 0);
    Result(int sSize,QString sTxt, QObject *parent = 0);

    QString getTxt() const;
    void setTxt(const QString &value);

    int getSize() const;
    void setSize(int value);

private:
    QString txt;
    int     size;

signals:

public slots:
};

#endif // RESULT_H
