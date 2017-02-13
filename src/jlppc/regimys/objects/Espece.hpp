/*
Espece.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Définit l'énumération CourbeExp et la classe Espece
*/
#ifndef ESPECE_HPP
#define ESPECE_HPP

#include <iostream>
#include "../../utils/NumberedArray.hpp"
#include "item/CT.hpp"
#include <vector>

class Evolution;
/**
Namespace contenant une enumération des courbes d'exp possibles
*/
namespace CourbeExp{
	const int ERRATIQUE = 0,FLUCTUANTE = 1,LENTE = 2,MOYENNE = 3,PARABOLIQUE = 4,RAPIDE = 5;
};
/**
Classe permettant de définir une espèce de Pokémon.
*/
class Espece {

protected:

private:
	std::string nom;
	int numeroPokedex;
	Espece *evolution;
	int niveauEvolution;
	Evolution *evolType;
	int type1;
	int type2;
	NumberedArray<Class<Attaque> > atksByLevels[];
	std::string entreePokedex;
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
	int *EVgiven;
	//Images
	int expGiven;
	int tauxDeCapture;
	int evSize;

public:
	virtual ~Espece();
	Espece(int atk, int def, int atkSpe, int defSpe, int vit, int pv, std::string name, int type1, int type2,int maniereEvolution, int niveauEvolution, Evolution *evolType, std::vector<int> EVGiven, float taille, float poids, std::string entreePokedex, int expGiven,int expMax, int tauxDeCapture, int numeroPokedex);
	/**Methode permettant de récuperer l'espèce d'évolution, car le mode d'initialisation des espèces ne permet pas de le faire dans le constructeur*/
	void checkEvol();
	/**Methode ayant la même fonction que checkEvol mais pour les attaques par niveau*/
	void checkAtkLvls();
	int getBaseAtk() const {return baseAtk;}
	int getBaseDef() const {return baseDef;}
	int getBaseAtkSpe() const {return baseAtkSpe;}
	int getBaseDefSpe() const {return baseDefSpe;}
	int getBaseVit() const {return baseVit;}
	int getBasePV() const {return basePV;}
	std::string getNom() const {return nom;}
	int getTauxDeCapture() const {return tauxDeCapture;}
	int getType1() const {return type1;}
	int getType2() const {return type2;}
	int getExp() const {return expGiven;}
	Evolution* getEvolType() const {return evolType;}
	int getCourbe() const{return courbe;}
	Espece* getEvolution() const {return evolution;}
	float getPoids() const{return poids;}
	int* getEv() const{return EVgiven;}
	int getEvSize() const{return evSize;}

};
#endif // ESPECE_HPP
