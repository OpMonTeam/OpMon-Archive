#include "Class.hpp"

template<typename T>Class<T>::Class(string name, int id) {
	this->name = name;
	this->id = id;

}

template<typename T> T* Class<T>::newInstance() const{
	return new T();
}
template<typename T, U>
bool Class<T>::operator==(Class<U> const& y){
	if(id == y.id){
		return true;
	}
}
