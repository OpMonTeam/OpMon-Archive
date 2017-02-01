#ifndef HASHARRAY_HPP
#define HASHARRAY_HPP

#include <iostream>

using namespace std;

class NumberedArray
{
    public:
        NumberedArray(int number, Attaque *attaque);
        ~NumberedArray();
        Attaque getAttaque() const {return *attaque;}
        int getNumber() const {return number;}
    private:
        int number;
        Attaque *attaque;

};

#endif // HASHARRAY_HPP
