
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include <iostream>
#include <cmath>
#include "Pokemon.hpp"
#include "Attaque.hpp"
#include "../../utils/Class.hpp"


using namespace std;

void initAttaquesClass(void);

namespace Attaques {

	class Abime : public Attaque{
	public:
		Abime() : Attaque("Abime", 99999, Type::SOL, 30, false, false, -1, false, 5, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def);
		int effetApres(Pokemon &atk, Pokemon &def){return 0;};
		static Class<Abime> *classe;
	};

	class Acidarmure : public Attaque{
	    public:
		Acidarmure() : Attaque("Acidarmure", 0, Type::POISON, 100, false, true, -1, true, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static Class<Acidarmure> *classe;
	};

	class Acide : public Attaque{
	    public:
		Acide() : Attaque("Acide", 40, Type::POISON, 100, true, false, 16, false, 30, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static Class<Acide> *classe;
	};

	class Affutage : public Attaque{
	    public:
		Affutage() : Attaque("Affutage", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static Class<Affutage> *classe;
	};

	class Aiguisage : public Attaque{
	    public:
		Aiguisage() : Attaque("Aiguisage", 0, Type::NORMAL, 100, false, true, -1, true, 15, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static Class<Aiguisage> *classe;
	};
	class Amnesie : public Attaque{
	    public:
		Amnesie() : Attaque("Amnésie", 0, Type::PSY, 100, false, true, -1, true, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static Class<Amnesie> *classe;

	};

	class Armure : public Attaque{
	    public:
		Armure() : Attaque("Armure", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static Class<Armure> *classe;
	};

	class Belier : public Attaque{
	    public:
		Belier() : Attaque("Bélier", 90, Type::NORMAL, 85, false, false, 16, false, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static Class<Belier> *classe;
	};

	class Balayage : public Attaque{
	    public:
		Balayage() : Attaque("Balayage", 0, Type::COMBAT, 100, false, false, 16, false, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def);
		int effetApres(Pokemon &atk, Pokemon &def){return 0;}
		static Class<Balayage> *classe;
	};
	class BecVrille : public Attaque{
	    public:
		BecVrille() : Attaque("Bec Vrille", 80, Type::VOL, 100, false, false, 16, false, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def){return 0;}
		static const Class<BecVrille> *classe;

	};

	class Berceuse : public Attaque{
	    public:
		Berceuse() : Attaque("Berceuse", 0, Type::NORMAL, 55, false, true, -1, false, 15, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 0;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Berceuse> *classe;
	};


};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
