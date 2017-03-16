/*
Caractere.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Définit l'énumération des caractères
*/
#ifndef SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_
#define SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_

#include "Enums.hpp"
/**
Définit la classe des caractères
*/
//->EnumClass->Caractere
class CaractereClass {
	public:
	    /**La stat que boost le caractère*/
	    //->WaitEnum->Stats
		int bonus;
		/**La stat que réduit le caractère*/
		//->WaitEnum->Stats
		int malus;

		int id;
		CaractereClass(int bonus, int malus, int id) : bonus(bonus), malus(malus), id(id) {};
		//->DontUse
		CaractereClass() {};

};
/**
Enumère les caractères
*/
//->Enum
namespace Caractere {
	const CaractereClass ASSURE = CaractereClass(Stats::DEF, Stats::ATK, 0),
						 BIZARRE = CaractereClass(Stats::RIEN, Stats::RIEN, 1),
						 BRAVE = CaractereClass(Stats::ATK, Stats::VIT, 2),
						 CALME = CaractereClass(Stats::DEFSPE, Stats::ATK, 3),
						 DISCRET = CaractereClass(Stats::ATKSPE, Stats::VIT, 4),
						 DOCILE = CaractereClass(Stats::RIEN, Stats::RIEN, 5),
						 DOUX = CaractereClass(Stats::ATKSPE, Stats::DEF, 6),
						 FOUFOU = CaractereClass(Stats::ATKSPE, Stats::DEFSPE, 7),
						 GENTIL = CaractereClass(Stats::DEFSPE, Stats::DEF, 8),
						 HARDI = CaractereClass(Stats::RIEN, Stats::RIEN, 9),
						 JOVIAL = CaractereClass(Stats::VIT, Stats::ATKSPE, 10),
						 LACHE = CaractereClass(Stats::DEF, Stats::DEFSPE, 11),
						 MALIN = CaractereClass(Stats::DEF, Stats::ATKSPE, 12),
						 MALPOLI = CaractereClass(Stats::DEFSPE, Stats::VIT, 13),
						 MAUVAIS = CaractereClass(Stats::ATK, Stats::DEFSPE, 14),
						 MODESTE = CaractereClass(Stats::ATKSPE, Stats::ATK, 15),
						 NAIF = CaractereClass(Stats::VIT, Stats::DEFSPE, 16),
						 PRESSE = CaractereClass(Stats::VIT, Stats::DEF, 17),
						 PRUDENT = CaractereClass(Stats::DEFSPE, Stats::ATKSPE, 18),
						 PUDIQUE = CaractereClass(Stats::RIEN, Stats::RIEN, 19),
						 RELAX = CaractereClass(Stats::DEF, Stats::VIT, 20),
						 RIGIDE = CaractereClass(Stats::ATK, Stats::ATKSPE, 21),
						 SERIEUX = CaractereClass(Stats::RIEN, Stats::RIEN, 22),
						 SOLO = CaractereClass(Stats::ATK, Stats::DEF, 23),
						 TIMIDE = CaractereClass(Stats::VIT, Stats::ATK, 24);
    extern const CaractereClass *enumsList[25];
};

#endif /* SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_ */
