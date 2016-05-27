#ifndef FOOTER_H
#define FOOTER_H


class Footer
{

public:
    explicit Footer();

    int getSqc() const;
    void setSqc(int value);

    int getCrc() const;
    void setCrc(int value);

    int getStopSign() const;

    static int getSIZE_OF_SQC();

    static int getSIZE_OF_CRC();

    static int getSIZE_OF_STOP_SIGN();

private:
    int sqc;
    int crc;
    static const int stopSign = 0x55AA;

    static const int SIZE_OF_SQC  = 1;
    static const int SIZE_OF_CRC  = 1;
    static const int SIZE_OF_STOP_SIGN = 2;

};

#endif // FOOTER_H
