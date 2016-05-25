#ifndef BODY_H
#define BODY_H
#include <QByteArray>

class Body
{

public:
    explicit Body();

    int getLength() const;
    void setLength(int value);

    QByteArray *getData() const;
    void setData(QByteArray *value);

private:
    int length;
    QByteArray *data;


};

#endif // BODY_H
