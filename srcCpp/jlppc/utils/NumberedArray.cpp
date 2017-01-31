#include "NumberedArray.hpp"

HashArray::HashArray(int number, O *object)
{
    this->number = number;
    this->object = object;
}

HashArray::~HashArray()
{
    delete(object);
}
