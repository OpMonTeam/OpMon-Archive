#include "Espece.hpp"

Espece::Espece(int atk, int def, int atkSpe, int defSpe, int vit, int pv, string name, Type type1, Type type2,int maniereEvolution, int niveauEvolution, Evolution evolType, HashArray attacksByLevels[],CT ctCombatibles[], Stats EVGiven[], float taille, float poids, string entreePokedex, int expGiven,int expMax, int tauxDeCapture){
    if(atk < 0 || def < 0 || atkSpe < 0 || defSpe < 0 || vit < 0 || pv < 0){
			Main::gererErreur("Stats < 0 Espece<Initializer>", true);
		}
		if(expGiven < 0){
			Main::gererErreur("expGiven < 0 Espece<Initializer>");
		}
		this->tauxDeCapture = tauxDeCapture;
		this->baseAtk = atk;
		this->baseDef = def;
		this->baseAtkSpe = atkSpe;
		this->baseDefSpe = defSpe;
		this->baseVit = vit;
		this->surnom = name;
		this->basePV = pv;
		this->type1 = type1;
		this->type2 = type2;
		this->maniereEvolution = maniereEvolution;
		this->niveauEvolution = niveauEvolution;
		this->evolType = evolType;
		this->evolution = this.evolType.getEvolution();
		this->atksByLevels = attacksByLevels;
		this->EVgiven = EVGiven;
		this->poids = poids;
		this->taille = taille;
		this->entreePokedex = entreePokedex;
		this->ctCompatibles = ctCombatibles;
		this->expGiven = expGiven;

		this->expMax = expMax;
		switch (this->expMax) {
		case 800000:
			courbe = CourbeExp.RAPIDE;
			break;
		case 1000000:
			courbe = CourbeExp.MOYENNE;
			break;
		case 1059860:
			courbe = CourbeExp.PARABOLIQUE;
			break;
		case 1250000:
			courbe = CourbeExp.LENTE;
			break;
		case 600000:
			courbe = CourbeExp.ERRATIQUE;
			break;
		case 1640000:
			courbe = CourbeExp.FLUCTUANTE;
			break;
		default:
			courbe = CourbeExp.MOYENNE;
        }
}

Espece::checkEvol(){
    evolType.checkEvo();
    this->evolution = evolType.getEvolution();
}

Espece::checkAtkLvls(){
    this->atksByLevels = Initializer.atkPokeLvl[pokedexNumberInit];
    this->numeroPokedex = pokedexNumberInit;
    pokedexNumberInit++;
}
