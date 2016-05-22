#ifndef FOOTER_H
#define FOOTER_H

#include <QObject>

class Footer : public QObject
{
    Q_OBJECT
public:
    explicit Footer(QObject *parent = 0);

    int getSqc() const;
    void setSqc(int value);

    int getCrc() const;
    void setCrc(int value);

    int getStopSign() const;
    void setStopSign(int value);

private:
    int sqc;
    int crc;
    int stopSign;

signals:

public slots:
};

#endif // FOOTER_H
