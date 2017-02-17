/*
Class.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
D�finit le classe... Class.
*/
#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>

/**
D�finit une classe. Pratique pour le newInstance()
*/
template <typename T>
class Class {
	public:
		Class(std::string name, int ID) {//ID doit etre en hexad�cimal, c'est mieux.
			this->name = name;
			this->id = id;
		}
		Class() {}
		T *newInstance() const {
			return new T();
		}
		std::string getName() const {return name;}
		int getID() const {return id;}
		template<typename U>bool operator==(Class<U> const &y) {
			if (id == y.id) {
				return true;
			}
		}
	private:
		std::string name;
		int id;
};

#endif /* CLASS_HPP */
