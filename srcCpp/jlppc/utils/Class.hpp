#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
using namespace std;
template <typename T>
class Class {
public:
	Class(string name, int ID);
	T* newInstance() const;
	string getName() const {return name;}
	int getID() const {return id;}
	bool operator==(Class const& y);
private:
	string name;
	int id;
};

#endif /* CLASS_HPP */
