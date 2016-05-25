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

private:
    int startSign;
    int id;
    int dataLenth;

    static const int SIZE_OF_START_SING = 2;

};

#endif // HEADER_H
