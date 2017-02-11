#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
using namespace std;
template <typename T>
class Class {
public:
	Class(string name, int ID) {
	this->name = name;
	this->id = id;
    }
	Class(){}
    T* newInstance() const{
        return new T();
    }
	string getName() const {return name;}
	int getID() const {return id;}
	template<typename U>bool operator==(Class<U> const& y){
	    if(id == y.id){
		return true;
        }
	}
private:
	string name;
	int id;
};

#endif /* CLASS_HPP */
