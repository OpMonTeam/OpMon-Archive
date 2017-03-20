/*
Attaque.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la définition de la classe Attaque
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include <iostream>
#include "../../utils/Utils.hpp"
#include "../enums/Enums.hpp"
#include "../../utils/Class.hpp"

class OpMon;
/**
Représente une attaque Pokémon
*/
//->PureVirtual
class Attaque {
	public:
		virtual ~Attaque() {}
		Attaque(std::string nom, int puissance, int type, int precision, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite, std::string className);
		//->PureVirtual
		virtual int effetAvant(OpMon &atk, OpMon &def) = 0;
		//->PureVirtual
		virtual int effetApres(OpMon &atk, OpMon &def) = 0;
		void healPP() {pp = ppMax;}
		int getType() {return type;}
		/**atk attaque le pokémon def*/
		//->Final
		virtual int attack(OpMon &atk, OpMon &def);
		virtual void siEchoue(OpMon &atk, OpMon &def) {}
		virtual Class<Attaque>* getClass() {return classe;}
		virtual std::string getClassName() {return className;}
		virtual std::string save();
	protected:
	    std::string className;
		std::string nom;
		int puissance;
		int priorite;
		int precision;
		int type;
		bool special;
		bool status;
		int part = 0;
		int pp;
		int ppMax;
		/**La chance de coups critiques, en 1/nombre (Par défaut, 16)*/
		int chanceDeCoups;
		bool rateJamais;
		/**Variable utilisée dans effetAvant et effetAprès*/
		int pvPerdus = 0;
    private:
        static Class<Attaque> *classe;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
