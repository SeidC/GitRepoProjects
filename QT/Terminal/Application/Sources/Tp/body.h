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

    static int getSIZE_OF_LENGTH();

    int getBoyLength(void);
private:
    int length;
    QByteArray *data;

    static const int SIZE_OF_LENGTH = 1;

};

#endif // BODY_H
