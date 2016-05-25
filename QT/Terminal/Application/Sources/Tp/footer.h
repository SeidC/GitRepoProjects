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
    void setStopSign(int value);

private:
    int sqc;
    int crc;
    int stopSign;

};

#endif // FOOTER_H
