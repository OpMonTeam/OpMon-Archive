
#ifndef SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_
#define SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_

#include "Enums.hpp"

class CaractereClass {
public:
	int bonus;
	int malus;
	CaractereClass(int bonus, int malus) : bonus(bonus), malus(malus){};
	CaractereClass(){};

};

namespace Caractere{
		const CaractereClass ASSURE = CaractereClass(Stats::DEF, Stats::ATK),
		BIZARRE = CaractereClass(Stats::RIEN, Stats::RIEN),
		BRAVE = CaractereClass(Stats::ATK, Stats::VIT),
		CALME = CaractereClass(Stats::DEFSPE, Stats::ATK),
		DISCRET = CaractereClass(Stats::ATKSPE, Stats::VIT),
		DOCILE = CaractereClass(Stats::RIEN, Stats::RIEN),
		DOUX = CaractereClass(Stats::ATKSPE, Stats::DEF),
		FOUFOU = CaractereClass(Stats::ATKSPE, Stats::DEFSPE),
		GENTIL = CaractereClass(Stats::DEFSPE, Stats::DEF),
		HARDI = CaractereClass(Stats::RIEN, Stats::RIEN),
		JOVIAL = CaractereClass(Stats::VIT, Stats::ATKSPE),
		LACHE = CaractereClass(Stats::DEF, Stats::DEFSPE),
		MALIN = CaractereClass(Stats::DEF, Stats::ATKSPE),
		MALPOLI = CaractereClass(Stats::DEFSPE, Stats::VIT),
		MAUVAIS = CaractereClass(Stats::ATK, Stats::DEFSPE),
		MODESTE = CaractereClass(Stats::ATKSPE, Stats::ATK),
		NAIF = CaractereClass(Stats::VIT, Stats::DEFSPE),
		PRESSE = CaractereClass(Stats::VIT, Stats::DEF),
		PRUDENT = CaractereClass(Stats::DEFSPE, Stats::ATKSPE),
		PUDIQUE = CaractereClass(Stats::RIEN, Stats::RIEN),
		RELAX = CaractereClass(Stats::DEF, Stats::VIT),
		RIGIDE = CaractereClass(Stats::ATK, Stats::ATKSPE),
		SERIEUX = CaractereClass(Stats::RIEN, Stats::RIEN),
		SOLO = CaractereClass(Stats::ATK, Stats::DEF),
		TIMIDE = CaractereClass(Stats::VIT, Stats::ATK);
};

#endif /* SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_ */
