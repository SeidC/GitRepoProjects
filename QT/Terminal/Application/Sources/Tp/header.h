#ifndef HEADER_H
#define HEADER_H

#include <QObject>

class Header : public QObject
{
    Q_OBJECT
public:
    explicit Header(QObject *parent = 0);

    int getStartSign() const;
    void setStartSign(int value);

    int getId() const;
    void setId(int value);

private:
    int startSign;
    int id;
    int dataLenth;

signals:

public slots:
};

#endif // HEADER_H
