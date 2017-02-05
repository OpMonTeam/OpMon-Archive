#ifndef HASHARRAY_HPP
#define HASHARRAY_HPP

#include <iostream>
#include "../regimys/objects/Attaque.hpp"

using namespace std;

typedef Class<Attaque*> ClassAttaque;

class NumberedArray
{
    public:
        NumberedArray(int number, ClassAttaque *attaque);
        ~NumberedArray();
        ClassAttaque getAttaque() const {return *attaque;}
        int getNumber() const {return number;}
    private:
        int number;
        ClassAttaque *attaque;

};

#endif // HASHARRAY_HPP
