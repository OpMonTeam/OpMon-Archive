#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
#include "srcCpp/jlppc/utils/Utils.hpp"
using namespace std;

class Pokemon
{
    public:
        Pokemon();

    protected:

    private:
        string surnom;
        int atkIV = Utils::randU(32);
        int defIV = Utils::randU(32);
        int atkSpeIV = Utils::randU(32);
        int defSpeIV = Utils::randU(32);
        int vitIV = Utils::randU(32);
        int pvIV = Utils::randU(32);
};

#endif // POKEMON_HPP
