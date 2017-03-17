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
#define IF_ATK(NAME) if(name == #NAME){\
                        return new NAME();\
                    }
/**
Namespace contenant les définitions des attaques
*/
//->NoDoc
namespace Attaques {

    Attaque* newAtk(std::string name);

	ATK_CLASS(Abime)
			Abime() : Attaque("Abime", 99999, Type::SOL, 30, false, false, -1, false, 5, 0) {}
			EAv;
			EAp {return 0;}
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

    ATK_CLASS(BombOeuf)
        BombOeuf() : Attaque("Bomb'\u0152uf", 100, Type::NORMAL, 75, false, false, 16, false, 10, 0) {}
        EAv {return 0;}
        EAp {return 0;}
        static Class<BombOeuf> *classe;
    };
    ATK_CLASS(Bouclier)
        Bouclier() : Attaque("Bouclier", 0, Type::PSY, 100, false, true, -1, true, 20, 0 ) {}
        EAv {return 0;}
        EAp;
        static Class<Bouclier> *classe;

    };
    ATK_CLASS(Brouillard)
        Brouillard() : Attaque("Brouillard", 0, Type::NORMAL, 100, false, true, -1, false, 20, 0) {}
        EAv {return 0;}
        EAp;
        static Class<Brouillard> *classe;

    };
    ATK_CLASS(BueeNoire)
        BueeNoire() : Attaque("Buée Noire", 0, Type::GLACE, 100, false, true, -1, true, 35, 0) {}
        EAv {return 0;}
        EAp;
        static Class<BueeNoire> *classe;

    };
    ATK_CLASS(BullesDo)
        BullesDo() : Attaque ("Bulles d'O", 65, Type::EAU, 100, true, false, 16, false, 20, 0) {}
        EAv {return 0;}
        EAp;
        static Class<BullesDo> *classe;

    };
    ATK_CLASS(CageEclair)
        CageEclair() : Attaque ("Cage Eclair", 0, Type::ELECTRIQUE, 100, false, true, -1, false, 20, 0) {}
        EAv {return 0;}
        EAp;
        static Class<CageEclair> *classe;
    };

    ATK_CLASS(CanonGraine)
	    CanonGraine(): Attaque ("Canon Graine", 80, Type::PLANTE, 100, false, false, 16, false, 15, 0) {}
	    EAv {return 0;}
	    EAp {return 0;}
            static Class<CanonGraine> *classe;
    };

   ATK_CLASS(Cascade)
	   Cascade(): Attaque ("Cascade", 80, Type::EAU, 100, false, false, 16, false, 15, 0) {}
	   EAv {return 0;}
	   EAp;
	   static Class<Cascade> *classe;
    };

   ATK_CLASS(Charge)
	   Charge(): Attaque ("Charge", 50, Type::NORMAL, 100, false, false, 16, false, 35, 0) {}
	   EAv {return 0;}
	   EAp {return 0;};
	   static Class<Charge> *classe;

    };

   ATK_CLASS(ChocMental)
	   ChocMental(): Attaque ("Choc Mental", 50, Type::PSY, 100, true, false, 16, false, 25, 0) {}
	   EAv {return 0;}
	   EAp;
           static Class<ChocMental> *classe;

    };

  ATK_CLASS(ChocPsy)
	  int def, defspe;
	  ChocPsy(): Attaque ("Choc Psy", 80, Type::PSY, 100, true, false, 16, false, 10, 0) {}
	  EAv;
	  EAp;
	  static Class<ChocPsy> *classe;
    };

  ATK_CLASS(ComboGriffe)
	  ComboGriffe(): Attaque ("Combo-Griffe", 18, Type::NORMAL, 80, false, false, 16, false, 15, 0) {}
	  EAv {return 0;}
	  EAp;
	  static Class<ComboGriffe> *classe;
    };
  ATK_CLASS(Conversion)
	  Conversion(): Attaque ("Conversion", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0) {}
	  EAv {return 0;}
	  EAp;
	  static Class<Conversion> *classe;

    };

ATK_CLASS(CoupdBoule)
	CoupdBoule(): Attaque ("Coup d'Boule", 70, Type::NORMAL, 100, false, false, 16, false, 15, 0) {}
	EAv {return 0;}
	EAp;
	static Class<CoupdBoule> *classe;
    };

ATK_CLASS(CoudKrane)
	CoudKrane(): Attaque ("Coud'Krâne", 130, Type::NORMAL, 100, false, false, 16, false, 10, 0) {}
	EAv;
	EAp {return 0;}
    	static Class<CoudKrane> *classe;
    };
ATK_CLASS(CoupeVent)
	CoupeVent(): Attaque ("Coupe-Vent", 80, Type::NORMAL, 100, true, false, 8, false, 10, 0) {}
	EAv;
	EAp {return 0;}
        static Class<CoupeVent> *classe;
   };
ATK_CLASS(CrocDeMort)
	CrocDeMort(): Attaque ("Croc de Mort", 80, Type::NORMAL, 90, false, false, 16, false, 15, 0) {}
	EAv {return 0;}
	EAp;
	static Class<CrocDeMort> *classe;
   };
ATK_CLASS(CrocFatal)
	CrocFatal(): Attaque ("Croc Fatal", 0, Type::NORMAL, 90, false, true, -1, false, 10, 0) {}
	EAv;
	EAp {return 0;}
	static Class<CrocFatal> *classe;
  };
ATK_CLASS(CrocFeu)
	CrocFeu(): Attaque ("Crocs Feu", 65, Type::FEU, 95, false, false, 16, false, 15, 0) {}
	EAv {return 0;}
	EAp;
	static Class<CrocFeu> *classe;
  };
ATK_CLASS(CruAiles)
	CruAiles(): Attaque ("Cru-Ailes", 60, Type::VOL, 100, false, false, 16, false, 35, 0) {}
	EAv {return 0;}
	EAp {return 0;}
       static Class<CruAiles> *classe;

};
ATK_CLASS(Damocles)
	Damocles(): Attaque ("Damoclès", 120, Type::NORMAL, 100, false, false, 16, false, 15, 0) {}
	EAv {return 0;}
	EAp;
	static Class<Damocles> *classe;
};


}
//Permet de ne pas a devoir utiliser Attaques:: partout
using namespace Attaques;


#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
