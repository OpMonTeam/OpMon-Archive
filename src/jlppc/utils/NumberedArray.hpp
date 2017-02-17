/*
NumberedArray.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
D�finit la classe NumberedArray
*/
#ifndef HASHARRAY_HPP
#define HASHARRAY_HPP

#include <iostream>
#include "Class.hpp"

/**
A l'origine pr�vue pour tout, cette classe permet une association d'un objet Class (souvent une attaque) a un nombre
*/
template<typename T>
class NumberedArray { //Bon en vrai c'est un truc d'attaques MAIS BON MERDE QUOI.
	public:
		NumberedArray(int number, Class<T> *attaque);
		virtual ~NumberedArray();
		Class<T> getAttaque() const {return *attaque;}
		int getNumber() const {return number;}
	private:
		int number;
		Class<T> *attaque;

};

#endif // HASHARRAY_HPP
