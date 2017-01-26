#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
#include "srcCpp/jlppc/utils/Utils.hpp"

class Pokemon
{
    public:
        Pokemon();

    protected:

    private:
        string surnom;
        int atkIV = Utils::rand(32);
        int defIV = Utils::rand(32);
        int atkSpeIV = Utils::rand(32);
        int defSpeIV = Utils::rand(32);
        int vitIV = Utils::rand(32);
        int pvIV = Utils::rand(32);
};

#endif // POKEMON_HPP
