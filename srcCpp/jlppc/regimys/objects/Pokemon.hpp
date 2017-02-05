#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Espece.hpp"
#include <iostream>
#include <cmath>
#include "Attaque.hpp"
#include "../../utils/NumberedArray.hpp"
#include "item/IPokeball.hpp"
#include "item/Item.hpp"
#include "../../utils/Class.hpp"
#include "../enums/Enums.hpp"
#include "../../utils/Utils.hpp"

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

class Pokemon
{
    public:
		virtual ~Pokemon();
		Pokemon(){};
        Pokemon(string surnom, Espece espece, int level, Attaque *attaques[], CaractereClass caractere);
        bool captured(I_Pokeball const& pokeball);
        void setStat(string const& stat, int newStat);
        void levelUp();
        bool isHoldingItem() const {return (held == NULL);}
        int win(Pokemon const& vaincu);
        void calcStats();
        bool itemUsed(Item const *used);
        Item* hold(Item const *item);
        void traded();
        void toolEvTrade();
        void evolve();
        void setStats(int const& stats[], Attaque const *attacks[], Espece const& espece, Type const& types[]);
        void attacked(int pvPerdus);
        bool changeATK(int power);
        bool changePRE(int power);
        bool changeESQ(int power);
        bool changeDEF(int power);
        bool changeATKSPE(int power);
        bool changeDEFSPE(int power);
        bool changeVIT(int power);
        bool setStatus(Status status);
        int getStatPV() const{return statPV;}
        int getStatLove() const{return statLove;}
        int getPV() const{return PV;}
        void heal(int PV);
        bool getLevel() const{return level;}
        Attaque** getAttaques() const{return &attaques;}
        int getStatESQ() const{return statESQ;}
        int getStatPRE() const{return statPRE;}
    protected:
        void getEvs(Pokemon const& vaincu);
        Type getType1() const{return type1;}
        Type getType2() const{return type2;}
        int getStatATK() const{return statATK;}
        int getStatATKSPE() const{return statATKSPE;}
        int getStatDEF() const{return statDEF;}
        int getStatDEFSPE() const{return statDEFSPE;}
        bool operator==(Pokemon const& a, int b){if(b == NULL){return falsif;}else{return false;}}
        bool operator!=(Pokemon const& a, int b){return !(a == b);}

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
    bool falsif = true;
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

    static const Pokemon NULL = Pokemon();

    int level;

    CaractereClass caractere;

    Attaque *attaques[4];

    Espece espece;

    int PV;

    int status = Status::AUCUN;

    int type1;

    int type2;

    int exp;

    int toNextLevel;
    float expBoost = 1;
    bool confus = false;
    bool peur = false;
    bool amour = false;
    bool vampigraine = false;
    bool malediction = false;

    Item *held;

    int tauxCapture;
};



#endif // POKEMON_HPP
