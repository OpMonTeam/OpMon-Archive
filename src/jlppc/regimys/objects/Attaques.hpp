/*
Attaques.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient les définitions des classes des attaques
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include <iostream>
#include <cmath>
#include "OpMon.hpp"
#include "Attaque.hpp"
#include "../../utils/Class.hpp"
/**Macros permettant de facilité l'écriture des classes*/
#define ATK_CLASS(name) class name : public Attaque {\
public:

#define EAv int effetAvant(OpMon &atk, OpMon &def)
#define EAp int effetApres(OpMon &atk, OpMon &def)
/**
Namespace contenant les définitions des attaques
*/
//->NoDoc
namespace Attaques {

	ATK_CLASS(Abime)
			Abime() : Attaque("Abime", 99999, Type::SOL, 30, false, false, -1, false, 5, 0) {}
			EAv;
			EAp {return 0;};
			static Class<Abime> *classe;
	};

	ATK_CLASS(Acidarmure)
			Acidarmure() : Attaque("Acidarmure", 0, Type::POISON, 100, false, true, -1, true, 20, 0) {}
			EAv {return 0;}
			EAp;
			static Class<Acidarmure> *classe;
	};

	ATK_CLASS(Acide)
			Acide() : Attaque("Acide", 40, Type::POISON, 100, true, false, 16, false, 30, 0) {}
			EAv {return 0;}
			EAp;
			static Class<Acide> *classe;
	};

	ATK_CLASS(Affutage)
			Affutage() : Attaque("Affutage", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0) {}
			EAv {return 0;}
			EAp;
			static Class<Affutage> *classe;
	};

	ATK_CLASS(Aiguisage)
			Aiguisage() : Attaque("Aiguisage", 0, Type::NORMAL, 100, false, true, -1, true, 15, 0) {}
			EAv {return 0;}
			EAp;
			static Class<Aiguisage> *classe;
	};
	ATK_CLASS(Amnesie)
			Amnesie() : Attaque("Amnésie", 0, Type::PSY, 100, false, true, -1, true, 20, 0) {}
			EAv {return 0;}
			EAp;
			static Class<Amnesie> *classe;

	};

	ATK_CLASS(Armure)
			Armure() : Attaque("Armure", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0) {}
			EAv {return 0;}
			EAp;
			static Class<Armure> *classe;
	};

	ATK_CLASS(Belier)
			Belier() : Attaque("Bélier", 90, Type::NORMAL, 85, false, false, 16, false, 20, 0) {}
			EAv {return 0;}
			EAp;
			static Class<Belier> *classe;
	};

	ATK_CLASS(Balayage)
			Balayage() : Attaque("Balayage", 0, Type::COMBAT, 100, false, false, 16, false, 20, 0) {}
			EAv;
			EAp {return 0;}
			static Class<Balayage> *classe;
	};
	ATK_CLASS(BecVrille)
			BecVrille() : Attaque("Bec Vrille", 80, Type::VOL, 100, false, false, 16, false, 20, 0) {}
			EAv {return 0;}
			EAp {return 0;}
			static  Class<BecVrille> *classe;

	};

	ATK_CLASS(Berceuse)
			Berceuse() : Attaque("Berceuse", 0, Type::NORMAL, 55, false, true, -1, false, 15, 0) {}
			EAv {return 0;}
			EAp;
			static  Class<Berceuse> *classe;
	};

    ATK_CLASS(Blizzard)
            Blizzard() : Attaque("Blizzard", 110, Type::GLACE, 70, true, false, 16, false, 5, 0) {}
            EAv {return 0;}
            EAp;
            static Class<Blizzard> *classe;
    };
};
//Permet de ne pas a devoir utiliser Attaques:: partout
using namespace Attaques;


#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
