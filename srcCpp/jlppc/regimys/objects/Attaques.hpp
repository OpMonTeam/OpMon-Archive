
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include <iostream>
#include <cmath>
#include "Attaque.hpp"
#include "Pokemon.hpp"
#include "../../utils/Class.hpp"
#include "../enums/Enums.hpp"

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
		int effetAvant(Pokemon &atk, Pokemon &def){return 2;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Acidarmure> *classe = new Class<Acidarmure>("Acidarmure", 0xFFFE);
	};
	
	class Acide : public Attaque{
		Acide() : Attaque("Acide", 40, Type::POISON, 100, true, false, 16, false, 30, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 2;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Acide> *classe = new Class<Acide>("Acide", 0xFFFD);
	};
	
	class Affutage : public Attaque{
		Affutage() : Attaque("Affutage", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 2;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Affutage> *classe = new Class<Affutage>("Affutage", 0xFFFC);
	};
	
	class Aiguisage : public Attaque{
		Aiguisage() : Attaque("Aiguisage", 0, Type::NORMAL, 100, false, true, -1, true, 15, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 2;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Aiguisage> *classe = new Class<Aiguisage>("Aiguisage", 0xFFFB);
	};

	class Amnesie : public Attaque{
		Amnesie() : Attaque("Amnésie", 0, Type::PSY, 100, false, true, -1, true, 20){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 2;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Amnesie> *classe = new Class<Amnesie>("Amnesie", 0xFFFA);

	};
	
	class Armure : public Attaque{
		Armure() : Attaque("Armure", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 2;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Armure> *classe = new Class<Armure>("Armure", 0xFFF9);
	};

	class Belier : public Attaque{
		Belier() : Attaque("Bélier", 90, Type::NORMAL, 85, false, false, 16, false, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def){return 2;}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Belier> *classe = new Class<Belier>("Belier", 0xFFF8);
	};
	
	class Balayage : public Attaque{
		Balayage() : Attaque("Balayage", 0, Type::COMBAT, 100, false, false, 16, false, 20, 0){}
		int effetAvant(Pokemon &atk, Pokemon &def);
		int effetApres(Pokemon &atk, Pokemon &def){}
		static const Class<Balayage> *classe = new Class<Balayage>("Balayage", 0xFFF7);
	
	class BecVrille : public Attaque{
		BecVrille() : Attaque("Bec Vrille", 80, Type::VOL, 100, false, false, 16, false, 20){}
		int effetAvant(Pokemon &atk, Pokemon &def){}
		int effetApres(Pokemon &atk, Pokemon &def){}
		static const Class<BecVrille> *classe = new Class<BecVrille>("Bec Vrille", 0xFFF6);
	
	};
									     
	class Berceuse : public Attaque{
		Berceuse() : Attaque("Berceuse", 0, Type::NORMAL, 55, false, true, -1, false, 15){}
		int effetAvant(Pokemon &atk, Pokemon &def){}
		int effetApres(Pokemon &atk, Pokemon &def);
		static const Class<Berceuse> *classe = new Class<Berceuse>("Berceuse", 0xFFF5);
	};


};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
