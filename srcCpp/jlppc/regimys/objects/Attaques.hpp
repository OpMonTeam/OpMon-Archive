
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include <iostream>
#include "../../includeAll.hxx"

using namespace std;


namespace Attaques {

	class Abime : public Attaque{
	public:
		Abime() : Attaque("Abime", 99999, Type::SOL, 30, false, false, -1, false, 5, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def);
		int effetApres(Pokemon &atk, Pokemon &def){return 0;};
		static const Class<Abime> *classe = new Class<Abime>("Abime", 0xFFFF);
	};

	class Acidarmure : public Attaque{
		Acidarmure() : Attaque("Acidarmure", 0, Type::POISON, 100, false, true, -1, true, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Acidarmure> *classe = new Class<Acidarmure>("Acidarmure", 0xFFFE);
	};
	
	class Acide : public Attaque{
		Acidarmure() : Attaque("Acide", 40, Type::POISON, 100, true, false, 16, false, 30, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Acide> *classe = new Class<Acide>("Acide", 0xFFFD);
	}
	
	class Affutage : public Attaque{
		Affutage() : Attaque("Affutage", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0);
		int effetAvant(Pokemon &atk, Pokemon &def){}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Affutage> *classe = new Class<Affutage>("Affutage", 0xFFFC);
	}
	
	class Aiguisage : public Attaque{
		Aiguisage() : Attaque("Aiguisage", 0, Type::NORMAL, 100, false, true, -1, true, 15, 0);
		int effetAvant(Pokemon &atk, Pokemon &def){}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Aiguisage> *classe = new Class<Aiguisage>("Aiguisage", 0xFFFB);
	}
	

}

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
