#include "data.h"

Data* Data::data_ = nullptr;

Data *Data::getInstance()
{
    // static InstanceGuard guard;
    if(data_ == nullptr)
    {
        data_ = new Data;
    }
    return data_;
}

void Data::setArr1Pointer(double * arr)
{
    this->array1 = arr;
}

void Data::setArr2Pointer(double * arr)
{
    this->array2 = arr;
}

double * Data::getArray1Pointer()
{
    return this->array1;
}
double * Data::getArray2Pointer()
{
    return this->array2;
}


