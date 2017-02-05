#include "NumberedArray.hpp"

NumberedArray::NumberedArray(int number, ClassAttaque *attaque)
{
    this->number = number;
    this->attaque = attaque;
}
NumberedArray::~NumberedArray()
{
    delete(attaque);
}
