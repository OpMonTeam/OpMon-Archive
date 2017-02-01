
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include <iostream>
#include "includeAll.hxx"

using namespace std;


namespace Attaques {

	class Abime : public Attaque{
	public:
		Abime() : Attaque("Abime", 99999, Type::SOL, 30, false, false, -1, false, 5, 0){}
		int effetAvant(Pokemon, Pokemon);
		int effetApres(Pokemon, Pokemon){return 0;};
		static const Class<Abime> *classe = new Class<Abime>("Abime", 0xFFFF)
	};

	class Acidarmure : public Attaque{
		Acidarmure() : Attaque("Acidarmure", 0, Type::POISON, 100, false, true, -1, true, 20, 0){}
		int effetAvant(Pokemon, Pokemon){}
		int effetApres(Pokemon, Pokemon);
		static const Class<Abime> *classe = new Class<Acidarmure>("Acidarmure", 0xFFFE);
	};

}

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
