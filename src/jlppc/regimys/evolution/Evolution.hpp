/*
Evolution.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la d�finition da la classe Evolution
*/
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
#include "../objects/Pokemon.hpp"
#include "../../utils/Class.hpp"

class Espece;
/**
Permet de d�finir un type d'�volution
*/
class Evolution {
	public:
		virtual ~Evolution() {}
		Evolution(int evo);
		virtual bool checkEvolve(Pokemon const &toCheck) const = 0;
		Espece *getEvolution() const;
		/**Check evo permet de r�cuperer l'espece d'�volution.*/
		void checkEvo();
		virtual int getEvolID() const {return evolID;}
		/**Sert juste a E_Item*/
		virtual bool itemEvolve(Item *tem) const {return false;}


	protected:
		static const int evolID = 0;
		Espece *toEvolve;
		int evo;
};

#endif /* EVOLUTION_HPP */
