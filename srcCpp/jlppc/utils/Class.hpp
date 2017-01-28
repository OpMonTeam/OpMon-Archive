#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
using namespace std;
template <typename T>
class Class {
public:
	Class(string name, int ID);
	T newInstance();
	string getName(){return name;}
	int getID(){return id;}
	bool operator==(Class x, Class y);
private:
	string name;
	int id;
};

#endif /* CLASS_HPP */
