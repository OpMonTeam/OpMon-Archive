#include "Class.hpp"

template<typename T>Class<T>::Class(string name, int id) {
	this->name = name;
	this->id = id;

}

template<typename T> T Class<T>::newInstance() const{
	return T();
}
template<typename T>
bool Class<T>::operator==(Class x, Class y) const{
	if(x.id == y.id){
		return true;
	}
}
