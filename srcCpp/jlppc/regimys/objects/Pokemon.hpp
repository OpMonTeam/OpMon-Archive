#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
#include "includeAll.hxx"
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
		virtual ~Pokemon();
        Pokemon(string surnom, Espece espece, int level, Attaque attaques[], Caractere caractere);
        bool captured(I_Pokeball const& pokeball);
        void setStat(string const& stat, int newStat);
        void levelUp();
        bool isHoldingItem() const {return (held == NULL);}
        int win(Pokemon const& vaincu);
        static Class<Pokemon> *classe = new Class("Pokemon", 13644895);
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
        virtual Class* getClass() const{return classe;}
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

    CaractereClass caractere;

    Attaque *attaques[4];

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

    Item *held;

    int tauxCapture;
};



#endif // POKEMON_HPP
