/*
Attacks.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient les définitions des classes des attaques
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include <iostream>
#include <cmath>
#include "OpMon.hpp"
#include "Attack.hpp"
/**Macros permettant de facilité l'écriture des classes*/
#define ATK_CLASS(name) class name : public Attack {\
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
namespace Attacks {

Attack *newAtk(std::string name);

ATK_CLASS(Abime)
Abime() : Attack("Abime", 99999, Type::SOL, 30, false, false, -1, false, 5, 0, "Abime") {}
EAv;
EAp {return 0;}
};

ATK_CLASS(Acidarmure)
Acidarmure() : Attack("Acidarmure", 0, Type::POISON, 100, false, true, -1, true, 20, 0, "Acidarmure") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(Acide)
Acide() : Attack("Acide", 40, Type::POISON, 100, true, false, 16, false, 30, 0, "Acide") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(Affutage)
Affutage() : Attack("Affutage", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0, "Affutage") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(Aiguisage)
Aiguisage() : Attack("Aiguisage", 0, Type::NORMAL, 100, false, true, -1, true, 15, 0, "Aiguisage") {}
EAv {return 0;}
EAp;
};
ATK_CLASS(Amnesie)
Amnesie() : Attack("Amnésie", 0, Type::PSY, 100, false, true, -1, true, 20, 0, "Amnesie") {}
EAv {return 0;}
EAp;

};

ATK_CLASS(Armure)
Armure() : Attack("Armure", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0, "Armure") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(Belier)
Belier() : Attack("Bélier", 90, Type::NORMAL, 85, false, false, 16, false, 20, 0, "Belier") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(Balayage)
Balayage() : Attack("Balayage", 0, Type::COMBAT, 100, false, false, 16, false, 20, 0, "Balayage") {}
EAv;
EAp {return 0;}
};
ATK_CLASS(BecVrille)
BecVrille() : Attack("Bec Vrille", 80, Type::VOL, 100, false, false, 16, false, 20, 0, "BecVrille") {}
EAv {return 0;}
EAp {return 0;}

};

ATK_CLASS(Berceuse)
Berceuse() : Attack("Berceuse", 0, Type::NORMAL, 55, false, true, -1, false, 15, 0, "Berceuse") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(Blizzard)
Blizzard() : Attack("Blizzard", 110, Type::GLACE, 70, true, false, 16, false, 5, 0, "Blizzard") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(BombOeuf)
BombOeuf() : Attack("Bomb'\u0152uf", 100, Type::NORMAL, 75, false, false, 16, false, 10, 0, "BombOeuf") {}
EAv {return 0;}
EAp {return 0;}
};
ATK_CLASS(Bouclier)
Bouclier() : Attack("Bouclier", 0, Type::PSY, 100, false, true, -1, true, 20, 0, "Bouclier") {}
EAv {return 0;}
EAp;

};
ATK_CLASS(Brouillard)
Brouillard() : Attack("Brouillard", 0, Type::NORMAL, 100, false, true, -1, false, 20, 0, "Brouillard") {}
EAv {return 0;}
EAp;

};
ATK_CLASS(BueeNoire)
BueeNoire() : Attack("Buée Noire", 0, Type::GLACE, 100, false, true, -1, true, 35, 0, "BueeNoire") {}
EAv {return 0;}
EAp;

};
ATK_CLASS(BullesDo)
BullesDo() : Attack ("Bulles d'O", 65, Type::EAU, 100, true, false, 16, false, 20, 0, "BullesDo") {}
EAv {return 0;}
EAp;

};
ATK_CLASS(CageEclair)
CageEclair() : Attack ("Cage Eclair", 0, Type::ELECTRIQUE, 100, false, true, -1, false, 20, 0, "CageEclair") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(CanonGraine)
CanonGraine(): Attack ("Canon Graine", 80, Type::PLANTE, 100, false, false, 16, false, 15, 0, "CanonGraine") {}
EAv {return 0;}
EAp {return 0;}
};

ATK_CLASS(Cascade)
Cascade(): Attack ("Cascade", 80, Type::EAU, 100, false, false, 16, false, 15, 0, "Cascade") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(Charge)
Charge(): Attack ("Charge", 50, Type::NORMAL, 100, false, false, 16, false, 35, 0, "Charge") {}
EAv {return 0;}
EAp {return 0;};

};

ATK_CLASS(ChocMental)
ChocMental(): Attack ("Choc Mental", 50, Type::PSY, 100, true, false, 16, false, 25, 0, "ChocMental") {}
EAv {return 0;}
EAp;

};

ATK_CLASS(ChocPsy)
int def, defspe;
ChocPsy(): Attack ("Choc Psy", 80, Type::PSY, 100, true, false, 16, false, 10, 0, "ChocPsy") {}
EAv;
EAp;
};

ATK_CLASS(ComboGriffe)
ComboGriffe(): Attack ("Combo-Griffe", 18, Type::NORMAL, 80, false, false, 16, false, 15, 0, "ComboGriffe") {}
EAv {return 0;}
EAp;
};
ATK_CLASS(Conversion)
Conversion(): Attack ("Conversion", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0, "ComboGriffe") {}
EAv {return 0;}
EAp;

};

ATK_CLASS(CoupdBoule)
CoupdBoule(): Attack ("Coup d'Boule", 70, Type::NORMAL, 100, false, false, 16, false, 15, 0, "CoupdBoule") {}
EAv {return 0;}
EAp;
};

ATK_CLASS(CoudKrane)
CoudKrane(): Attack ("Coud'Krâne", 130, Type::NORMAL, 100, false, false, 16, false, 10, 0, "CoudKrane") {}
EAv;
EAp {return 0;}
};
ATK_CLASS(CoupeVent)
CoupeVent(): Attack ("Coupe-Vent", 80, Type::NORMAL, 100, true, false, 8, false, 10, 0, "CoupeVent") {}
EAv;
EAp {return 0;}
};
ATK_CLASS(CrocDeMort)
CrocDeMort(): Attack ("Croc de Mort", 80, Type::NORMAL, 90, false, false, 16, false, 15, 0, "CrocDeMort") {}
EAv {return 0;}
EAp;
};
ATK_CLASS(CrocFatal)
CrocFatal(): Attack ("Croc Fatal", 0, Type::NORMAL, 90, false, true, -1, false, 10, 0, "CrocFatal") {}
EAv;
EAp {return 0;}
};
ATK_CLASS(CrocFeu)
CrocFeu(): Attack ("Crocs Feu", 65, Type::FEU, 95, false, false, 16, false, 15, 0, "CrocFeu") {}
EAv {return 0;}
EAp;
};
ATK_CLASS(CruAiles)
CruAiles(): Attack ("Cru-Ailes", 60, Type::VOL, 100, false, false, 16, false, 35, 0, "CruAiles") {}
EAv {return 0;}
EAp {return 0;}

};
ATK_CLASS(Damocles)
Damocles(): Attack("Damoclès", 120, Type::NORMAL, 100, false, false, 16, false, 15, 0, "Damocles") {}
EAv {return 0;}
EAp;
};
ATK_CLASS(DanseFleur)
DanseFleur(): Attack("Danse-Fleur", 120, Type::PLANTE, 100, true, false, 16, false, 10, 0, "DanseFleur") {}
EAv {return 0;}
EAp;
};
ATK_CLASS(DanseLames)
DanseLames(): Attack("Danse-Lames", 0, Type::NORMAL, 100, false, true, -1, true, 20, 0, "DanseLames") {}
EAv {return 0;}
EAp;
};
ATK_CLASS(Deflagration)
Deflagration(): Attack("Déflagration", 110, Type::FEU, 85,true, false, 16, false, 5, 0, "Deflagration") {}
EAv {return 0;}
EAp;

};
ATK_CLASS(Destruction)
Destruction(): Attack ("Destruction", 200, Type::NORMAL, 100, false, false, 16, false, 5, 0, "Destruction") {}
EAv {return 0;}
EAp;

};
ATK_CLASS(Detritus)
Detritus(): Attack ("Détritus", 65, Type::POISON, 100, true, false, 16, false, 20, 0, "Detritus") {}
EAv {return 0;}
EAp;

};
ATK_CLASS(Devoreve)
Devoreve(): Attack ("Dévorêve", 100, Type::PSY, 100, true, false, 16, false, 15, 0, "Devoreve") {}
EAv;
EAp;

};
ATK_CLASS(DoubleDard)
DoubleDard(): Attack ("Double-Dard", 25, Type::INSECTE, 100, false, false, 16, false, 20, 0, "DoubleDard") {}
EAv {return 0;}
EAp;

};

}
//Permet de ne pas a devoir utiliser Attacks:: partout
using namespace Attacks;


#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
