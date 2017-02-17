#include "NumberedArray.hpp"
template<typename T>
NumberedArray<T>::NumberedArray(int number, Class<T> *attaque)
{
	this->number = number;
	this->attaque = attaque;
}
template<typename T>
NumberedArray<T>::~NumberedArray()
{
	delete(attaque);
}
