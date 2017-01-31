#ifndef HASHARRAY_HPP
#define HASHARRAY_HPP

#include <iostream>

using namespace std;

template<typename O>
class NumberedArray final
{
    public:
        NumberedArray<O>(int number, O *object);
        ~NumberedArray<O>();
        O getObject(){return *object;}
        int getNumber(){return number;}
    private:
        int number;
        O *object;

};

#endif // HASHARRAY_HPP
