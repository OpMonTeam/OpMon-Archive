/*
NumberedArray.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
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
    std::string getAttack() const {
        return attack;
    }
    int getNumber() const {
        return number;
    }
private:
    int number;
    std::string attack;

};

#endif // HASHARRAY_HPP
