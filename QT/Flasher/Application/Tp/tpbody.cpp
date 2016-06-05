#include "tpbody.h"

uint TpBody::getDataLength() const
{
    return dataLength;
}

QUintArray *TpBody::getData() const
{
    return data;
}

TpBody::TpBody()
{

}
