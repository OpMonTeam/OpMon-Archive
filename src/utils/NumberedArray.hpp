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
In java, this class was used to associate to objects.
EDIT October 2017 : I discovered std::map. Now this class is deprecated
*/
OP_DEPRECATED class NumberedArray {
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
