#ifndef HASHARRAY_HPP
#define HASHARRAY_HPP

#include <iostream>
#include "Class.hpp"

using namespace std;

template<typename T>
class NumberedArray//Bon en vrai c'est un truc d'attaques MAIS BON MERDE QUOI.
{
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
