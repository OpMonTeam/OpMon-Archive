#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
#include "srcCpp/jlppc/utils/Utils.hpp"
#include "Espece.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"
#include "RegimysObject.hpp"
#include <cmath>
using namespace std;

namespace CalcCourbes{
	float p(int x);
	int erratique(int n);
	int fluctuante(int n);
	int lente(int n);
	int moyenne(int n);
	int parabolique(int n);
	int rapide(int n);
};

class Pokemon : public RegimysObject
{
    public:
        Pokemon(string surnom, Espece espece, int level, Attaque attaques[], Caractere caractere);
        bool captured(I_Pokeball pokeball);
        void setStat(string stat, int newStat);
        void levelUp();
        bool isHoldingItem(){return (held == NULL);}
        int win(Pokemon vaincu);
        static Class<Pokemon> *classe = new Class("Pokemon", 13644895);
        void calcStats();
        bool itemUsed(Item used);
        Item hold(Item item);
        void traded();
        void toolEvTrade();
        void evolve();
        void setStats(int stats[], Attaque attacks[], Espece espece, Type types[]);
        void attacked(int pvPerdus);
        bool changeATK(int power);
        bool changePRE(int power);
        bool changeESQ(int power);
        bool changeDEF(int power);
        bool changeATKSPE(int power);
        bool changeDEFSPE(int power);
        bool changeVIT(int power);
        bool setStatus(Status status);
        void heal(int PV);
        bool getLevel(){return level;}

    protected:
        void getEvs(Pokemon vaincu);

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
