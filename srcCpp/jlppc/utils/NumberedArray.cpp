#include "NumberedArray.hpp"

NumberedArray::NumberedArray(int number, Attaque *attaque)
{
    this->number = number;
    this->attaque = attaque;
}
NumberedArray::~NumberedArray()
{
    delete(object);
}
