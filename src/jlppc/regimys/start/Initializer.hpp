#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP
#define POKE_NUMBER 252

#include <iostream>
#include <vector>
#include "../../utils/NumberedArray.hpp"
#include "../objects/Espece.hpp"

namespace Initializer{
    Espece *listPoke[POKE_NUMBER];
    vector<NumberedArray> atkPokeLvl[POKE_NUMBER];//100 attaques max / poké
    extern E_Nope ne;//ne = No Evolution
    //std::string backgrounds[];

    void initPokemons();
    void initAtkLvls();
    void initSprites();
    void initBackgrounds();
    void initKeys();
    void initItems();
    void init();





};

#endif // INITIALIZER_HPP
