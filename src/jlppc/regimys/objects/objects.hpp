#ifndef OBJECTS_HPP_INCLUDED
#define OBJECTS_HPP_INCLUDED

#include "Evoluti

class Espece;
class Attaque;
class Pokemon;


namespace CourbeExp{
	const int ERRATIQUE = 0,FLUCTUANTE = 1,LENTE = 2,MOYENNE = 3,PARABOLIQUE = 4,RAPIDE = 5;
};

class Espece {

protected:

private:
	string nom;
	int numeroPokedex;
	Espece *evolution;
	int niveauEvolution;
	Evolution *evolType;
	int type1;
	int type2;
	NumberedArray<Class<Attaque> > atksByLevels[];
	string entreePokedex;
	float taille;
	float poids;
	CT ctCompatibles[];
	int baseAtk;
	int baseDef;
	int baseAtkSpe;
	int baseDefSpe;
	int baseVit;
	int basePV;
	int courbe;
	int expMax;
	int EVgiven[3];
	//Images
	int expGiven;
	int tauxDeCapture;

public:
	virtual ~Espece();
	Espece(int atk, int def, int atkSpe, int defSpe, int vit, int pv, string name, int type1, int type2,int maniereEvolution, int niveauEvolution, Evolution *evolType, int EVGiven[], float taille, float poids, string entreePokedex, int expGiven,int expMax, int tauxDeCapture);
	void checkEvol();
	void checkAtkLvls();
	static int pokedexNumberInit;
	int getBaseAtk() const {return baseAtk;}
	int getBaseDef() const {return baseDef;}
	int getBaseAtkSpe() const {return baseAtkSpe;}
	int getBaseDefSpe() const {return baseDefSpe;}
	int getBaseVit() const {return baseVit;}
	int getBasePV() const {return basePV;}
	string getNom() const {return nom;}
	int getTauxDeCapture() const {return tauxDeCapture;}
	int getType1() const {return type1;}
	int getType2() const {return type2;}
	int getExp() const {return expGiven;}
	Evolution* getEvolType() const {return evolType;}
	int getCourbe() const{return courbe;}
	Espece* getEvolution() const {return evolution;}
	float getPoids() const{return poids;}
	int* getEv() {return EVgiven;}

};

namespace CalcCourbes{
float p(int x);
int erratique(int n);
int fluctuante(int n);
int lente(int n);
int moyenne(int n);
int parabolique(int n);
int rapide(int n);
};


class Pokemon{

protected:


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

	Espece *espece;

	int PV;

	int status = Status::AUCUN;

	int type1;

	int type2;

	int exp;

	int toNextLevel;
	float expBoost = 1;


	Item *held;

	int tauxCapture;
public:
	bool falsif = true;
	bool confus = false;
    bool peur = false;
    bool amour = false;
    bool vampigraine = false;
    bool malediction = false;
	virtual ~Pokemon();
	Pokemon(){};
	Pokemon(string surnom, Espece *espece, int level, Attaque *attaques[], CaractereClass caractere);
	bool captured(I_Pokeball const& pokeball);
	void setStat(string const& stat, int newStat);
	void levelUp();
	bool isHoldingItem() const {return (held == NULL);}
	int win(Pokemon const& vaincu);
	void calcStats();
	bool itemUsed(Item *used);
	Item* hold(Item *item);
	void traded();
	void toolEvTrade();
	void evolve();
	void setStats(int stats[], Attaque *attacks[], Espece *espece, int types[]);
	void attacked(int pvPerdus);
	bool changeATK(int power);
	bool changePRE(int power);
	bool changeESQ(int power);
	bool changeDEF(int power);
	bool changeATKSPE(int power);
	bool changeDEFSPE(int power);
	bool changeVIT(int power);
	bool setStatus(int status);
	int getStatPV() const{return statPV;}
	int getStatLove() const{return statLove;}
	int getPV() const{return PV;}
	void heal(int PV);
	bool getLevel() const{return level;}
	Attaque** getAttaques() {return attaques;}
	int getStatESQ() const{return statESQ;}
	int getStatPRE() const{return statPRE;}
	void getEvs(Pokemon const& vaincu);
	int getType1() const{return type1;}
	int getType2() const{return type2;}
	int getStatATK() const{return statATK;}
	int getStatATKSPE() const{return statATKSPE;}
	int getStatDEF() const{return statDEF;}
	int getStatDEFSPE() const{return statDEFSPE;}
	Espece* getEspece() const{return espece;}
	bool operator==(Pokemon const& a){return (falsif == a.falsif);}
	bool operator!=(Pokemon const& a){return !(falsif == a.falsif);}
	Item* itemHeld() const{return held;}
};

class Attaque{
public:
	virtual ~Attaque(){}
	Attaque(string nom, int puissance, int type, int precision, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite);
	virtual int effetAvant(Pokemon &atk, Pokemon &def) = 0;
	virtual int effetApres(Pokemon &atk, Pokemon &def) = 0;
	void healPP(){pp = ppMax;}
	virtual int attack(Pokemon &atk, Pokemon &def) final;
	virtual void siEchoue(Pokemon &atk, Pokemon &def){}
protected:
	string nom;
	int puissance;
	int priorite;
	int precision;
	int type;
	bool special;
	bool status;
	int part = 0;
	int pp;
	int ppMax;
	int chanceDeCoups;
	bool rateJamais;
	int pvPerdus = 0;
};


#endif // OBJECTS_HPP_INCLUDED
