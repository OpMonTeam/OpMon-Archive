#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
#include "srcCpp/jlppc/utils/Utils.hpp"
#include "Espece.hpp"
#include <cmath>
using namespace std;

class Pokemon
{
    public:
        Pokemon();
        bool captured(I_Pokeball pokeball);


    private:
    string surnom;
    int atkIV = Utils::randU(32);
    int defIV = Utils::randU(32);
    int atkSpeIV = Utils::randU(32);
    int defSpeIV = Utils::randU(32);
    int vitIV = Utils::randU(32);
    int pvIV = Utils::randU(32);
    int atkEV = 0;
    int defEV = 0;
    int atkSpeEV = 0;
    int defSpeEV = 0;
    int vitEV = 0;
    int pvEV = 0;
    //Les statistiques en general
    int statATK;
    int statDEF;
    int statATKSPE;
    int statDEFSPE;
    int statVIT;
    //Les autrees stats.
    int statESQ;
    float statPRE;
    int statPV;
    int statLove;
    //Les variables indiquant le niveau de changement.
    int atkChange = 0;
    int defChange = 0;
    int defSpeChange = 0;
    int atkSpeChange = 0;
    int esqChange = 0;
    int preChange = 0;
    int vitChange = 0;

    int level;

    Caractere caractere;

    Attaque attaques[4];

    Espece espece;

    int PV;

    Status status = Status::AUCUN;

    Type type1;

    Type type2;

    int exp;

    int toNextLevel;
    float expBoost = 1;
    bool confus = false;
    bool peur = false;
    bool amour = false;
    bool vampigraine = false;
    bool malediction = false;

    Item held;

    int tauxCapture;
};

#endif // POKEMON_HPP
