
#ifndef SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_
#define SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_

#include "Enums.hpp"

class CaractereClass {
public:
	CaractereClass(Stats bonus, Stats malus) : bonus(bonus), malus(malus){};
	const Stats bonus;
	const Stats malus;
};

enum class Caractere : CaractereClass{
		ASSURE = (Stats::DEF, Stats::ATK),
		BIZARRE = (Stats::RIEN, Stats::RIEN),
		BRAVE = (Stats::ATK, Stats::VIT),
		CALME = (Stats::DEFSPE, Stats::ATK),
		DISCRET = (Stats::ATKSPE, Stats::VIT),
		DOCILE = (Stats::RIEN, Stats::RIEN),
		DOUX = (Stats::ATKSPE, Stats::DEF),
		FOUFOU = (Stats::ATKSPE, Stats::DEFSPE),
		GENTIL = (Stats::DEFSPE, Stats::DEF),
		HARDI = (Stats::RIEN, Stats::RIEN),
		JOVIAL = (Stats::VIT, Stats::ATKSPE),
		LACHE = (Stats::DEF, Stats::DEFSPE),
		MALIN = (Stats::DEF, Stats::ATKSPE),
		MALPOLI = (Stats::DEFSPE, Stats::VIT),
		MAUVAIS = (Stats::ATK, Stats::DEFSPE),
		MODESTE = (Stats::ATKSPE, Stats::ATK),
		NAIF = (Stats::VIT, Stats::DEFSPE),
		PRESSE = (Stats::VIT, Stats::DEF),
		PRUDENT = (Stats::DEFSPE, Stats::ATKSPE),
		PUDIQUE = (Stats::RIEN, Stats::RIEN),
		RELAX = (Stats::DEF, Stats::VIT),
		RIGIDE = (Stats::ATK, Stats::ATKSPE),
		SERIEUX = (Stats::RIEN, Stats::RIEN),
		SOLO = (Stats::ATK, Stats::DEF),
		TIMIDE = (Stats::VIT, Stats::ATK)
};

#endif /* SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_ */
