#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QObject>


template<typename T, typename U>
class DataStorage
{

public:
    explicit DataStorage() {}

private:
    T p1;
    U p2;

public:
    void setParam(T &p) {p1 = p;}
    void setParam(U &p) {p2 = p;}

    T getParam1(void) {return p1;}
    U getParam2(void) {return p2;}
};


#endif // DATASTORAGE_H
