#ifndef ESPECE_HPP
#define ESPECE_HPP

#include <iostream>
#include "../../utils/Class.hpp"
#include "RegimysObject.hpp"
#include "../evolution/Evolution.hpp"
#include "../../utils/NumberedArray.hpp"
#include "item/CT.hpp"
#include "../enums/Enums.hpp"

using namespace std;

namespace CourbeExp{
	const int ERRATIQUE = 0,FLUCTUANTE = 1,LENTE = 2,MOYENNE = 3,PARABOLIQUE = 4,RAPIDE = 5;
};

class Espece{
public:
	virtual ~Espece();
	Espece(int atk, int def, int atkSpe, int defSpe, int vit, int pv, string name, int type1, int type2,int maniereEvolution, int niveauEvolution, Evolution *evolType, NumberedArray attacksByLevels[],CT ctCombatibles[], int EVGiven[], float taille, float poids, string entreePokedex, int expGiven,int expMax, int tauxDeCapture);
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
	Espece getEvolution() const {return evolution;}
protected:

private:
	string nom;
	int numeroPokedex;
	Espece evolution;
	int niveauEvolution;
	Evolution *evolType;
	int type1;
	int type2;
	NumberedArray atksByLevels[];
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
	int EVgiven[];
	//Images
	int expGiven;
	int tauxDeCapture;

};

#endif // ESPECE_HPP
