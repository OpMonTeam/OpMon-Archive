/*
NumberedArray.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Définit la classe NumberedArray
*/
#ifndef HASHARRAY_HPP
#define HASHARRAY_HPP

#include <iostream>
#include "Class.hpp"

/**
A l'origine prévue pour tout, cette classe permet une association d'un objet string a un nombre
*/
class NumberedArray {
public:
    NumberedArray(int number, std::string str);
    std::string getAttaque() const {
        return attaque;
    }
    int getNumber() const {
        return number;
    }
private:
    int number;
    std::string attaque;

};

#endif // HASHARRAY_HPP
