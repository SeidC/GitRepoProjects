#include "tpbody.h"

uint TpBody::getDataLength() const
{
    return dataLength;
}

QByteArray *TpBody::getData() const
{
    return data;
}

TpBody::TpBody()
{

}
