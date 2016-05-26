#ifndef HEADER_H
#define HEADER_H



class Header
{

public:
    explicit Header();

    int getStartSign() const;
    void setStartSign(int value);

    int getId() const;
    void setId(int value);

    static int getSIZE_OF_DATA_LEN();

    static int getSIZE_OF_ID();

    static int getSIZE_OF_START_SIGN();

private:
    int startSign;
    int id;
    int dataLenth;

    static const int SIZE_OF_START_SIGN = 2;
    static const int SIZE_OF_ID = 2;
    static const int SIZE_OF_DATA_LEN = 1;
};

#endif // HEADER_H
