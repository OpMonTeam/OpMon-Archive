/*
Attacks.hpp
Author : Jlppc
File under GPL-3.0 license
http://opmon-game.ga
Contains the attacks classes definitions
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_

#include "Attack.hpp"
#include "OpMon.hpp"
#include <cmath>
#include <iostream>

#define ATK_CLASS(name)          \
    class name : public Attack { \
      public:

#define EB int effectBefore(OpMon &atk, OpMon &def)
#define EA int effectAfter(OpMon &atk, OpMon &def)
#define IF_ATK(NAME)       \
    if(name == #NAME) {    \
        return new NAME(); \
    }

namespace OpMon {
    namespace Model {
        /**
Namespace containing attacks' definitions
*/
        //->NoDoc
        namespace Attacks {

            /**
     TODO : Put the attacks' names in english, put all the attacks' names in the rkeys files for translation. 
   */

            Attack *newAtk(std::string name);

            ATK_CLASS(Abime)
            Abime()
              : Attack("Abime", 99999, Type::SOL, 30, false, false, -1, false, 5, 0, "Abime") {}
            EB;
        }; // namespace Attacks

        ATK_CLASS(Acidarmure)
        Acidarmure()
          : Attack("Acidarmure", 0, Type::POISON, 100, false, true, -1, true, 20, 0, "Acidarmure") {}
        EA;
    }; // namespace Model

    ATK_CLASS(Acide)
    Acide()
      : Attack("Acide", 40, Type::POISON, 100, true, false, 16, false, 30, 0, "Acide") {}
    EA;
}; // namespace OpMon

ATK_CLASS(Affutage)
Affutage()
  : Attack("Affutage", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0, "Affutage") {}
EA;
}
;

ATK_CLASS(Aiguisage)
Aiguisage()
  : Attack("Aiguisage", 0, Type::NORMAL, 100, false, true, -1, true, 15, 0, "Aiguisage") {}
EA;
}
;
ATK_CLASS(Amnesie)
Amnesie()
  : Attack("Amnésie", 0, Type::PSY, 100, false, true, -1, true, 20, 0, "Amnesie") {}
EA;
}
;

ATK_CLASS(Armure)
Armure()
  : Attack("Armure", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0, "Armure") {}
EA;
}
;

ATK_CLASS(Belier)
Belier()
  : Attack("Bélier", 90, Type::NORMAL, 85, false, false, 16, false, 20, 0, "Belier") {}
EA;
}
;

ATK_CLASS(Balayage)
Balayage()
  : Attack("Balayage", 0, Type::COMBAT, 100, false, false, 16, false, 20, 0, "Balayage") {}
EB;
}
;
ATK_CLASS(BecVrille)
BecVrille()
  : Attack("Bec Vrille", 80, Type::VOL, 100, false, false, 16, false, 20, 0, "BecVrille") {}
}
;

ATK_CLASS(Berceuse)
Berceuse()
  : Attack("Berceuse", 0, Type::NORMAL, 55, false, true, -1, false, 15, 0, "Berceuse") {}
EA;
}
;

ATK_CLASS(Blizzard)
Blizzard()
  : Attack("Blizzard", 110, Type::GLACE, 70, true, false, 16, false, 5, 0, "Blizzard") {}
EA;
}
;

ATK_CLASS(BombOeuf)
BombOeuf()
  : Attack("Bomb'\u0152uf", 100, Type::NORMAL, 75, false, false, 16, false, 10, 0, "BombOeuf") {}
}
;
ATK_CLASS(Bouclier)
Bouclier()
  : Attack("Bouclier", 0, Type::PSY, 100, false, true, -1, true, 20, 0, "Bouclier") {}
EA;
}
;
ATK_CLASS(Brouillard)
Brouillard()
  : Attack("Brouillard", 0, Type::NORMAL, 100, false, true, -1, false, 20, 0, "Brouillard") {}
EA;
}
;
ATK_CLASS(BueeNoire)
BueeNoire()
  : Attack("Buée Noire", 0, Type::GLACE, 100, false, true, -1, true, 35, 0, "BueeNoire") {}
EA;
}
;
ATK_CLASS(BullesDo)
BullesDo()
  : Attack("Bulles d'O", 65, Type::EAU, 100, true, false, 16, false, 20, 0, "BullesDo") {}
EA;
}
;
ATK_CLASS(CageEclair)
CageEclair()
  : Attack("Cage Eclair", 0, Type::ELECTRIQUE, 100, false, true, -1, false, 20, 0, "CageEclair") {}
EA;
}
;

ATK_CLASS(CanonGraine)
CanonGraine()
  : Attack("Canon Graine", 80, Type::PLANTE, 100, false, false, 16, false, 15, 0, "CanonGraine") {}
}
;

ATK_CLASS(Cascade)
Cascade()
  : Attack("Cascade", 80, Type::EAU, 100, false, false, 16, false, 15, 0, "Cascade") {}
EA;
}
;

ATK_CLASS(Charge)
Charge()
  : Attack("Charge", 50, Type::NORMAL, 100, false, false, 16, false, 35, 0, "Charge") {}
}
;

ATK_CLASS(ChocMental)
ChocMental()
  : Attack("Choc Mental", 50, Type::PSY, 100, true, false, 16, false, 25, 0, "ChocMental") {}
EA;
}
;

ATK_CLASS(ChocPsy)
int def, defspe;
ChocPsy()
  : Attack("Choc Psy", 80, Type::PSY, 100, true, false, 16, false, 10, 0, "ChocPsy") {}
EB;
EA;
}
;

ATK_CLASS(ComboGriffe)
ComboGriffe()
  : Attack("Combo-Griffe", 18, Type::NORMAL, 80, false, false, 16, false, 15, 0, "ComboGriffe") {}
EA;
}
;
ATK_CLASS(Conversion)
Conversion()
  : Attack("Conversion", 0, Type::NORMAL, 100, false, true, -1, true, 30, 0, "ComboGriffe") {}
EA;
}
;

ATK_CLASS(CoupdBoule)
CoupdBoule()
  : Attack("Coup d'Boule", 70, Type::NORMAL, 100, false, false, 16, false, 15, 0, "CoupdBoule") {}
EA;
}
;

ATK_CLASS(CoudKrane)
CoudKrane()
  : Attack("Coud'Krâne", 130, Type::NORMAL, 100, false, false, 16, false, 10, 0, "CoudKrane") {}
EB;
}
;
ATK_CLASS(CoupeVent)
CoupeVent()
  : Attack("Coupe-Vent", 80, Type::NORMAL, 100, true, false, 8, false, 10, 0, "CoupeVent") {}
EB;
}
;
ATK_CLASS(CrocDeMort)
CrocDeMort()
  : Attack("Croc de Mort", 80, Type::NORMAL, 90, false, false, 16, false, 15, 0, "CrocDeMort") {}
EA;
}
;
ATK_CLASS(CrocFatal)
CrocFatal()
  : Attack("Croc Fatal", 0, Type::NORMAL, 90, false, true, -1, false, 10, 0, "CrocFatal") {}
EB;
}
;
ATK_CLASS(CrocFeu)
CrocFeu()
  : Attack("Crocs Feu", 65, Type::FEU, 95, false, false, 16, false, 15, 0, "CrocFeu") {}
EA;
}
;
ATK_CLASS(CruAiles)
CruAiles()
  : Attack("Cru-Ailes", 60, Type::VOL, 100, false, false, 16, false, 35, 0, "CruAiles") {}
}
;
ATK_CLASS(Damocles)
Damocles()
  : Attack("Damoclès", 120, Type::NORMAL, 100, false, false, 16, false, 15, 0, "Damocles") {}
EA;
}
;
ATK_CLASS(DanseFleur)
DanseFleur()
  : Attack("Danse-Fleur", 120, Type::PLANTE, 100, true, false, 16, false, 10, 0, "DanseFleur") {}
EA;
}
;
ATK_CLASS(DanseLames)
DanseLames()
  : Attack("Danse-Lames", 0, Type::NORMAL, 100, false, true, -1, true, 20, 0, "DanseLames") {}
EA;
}
;
ATK_CLASS(Deflagration)
Deflagration()
  : Attack("Déflagration", 110, Type::FEU, 85, true, false, 16, false, 5, 0, "Deflagration") {}
EA;
}
;
ATK_CLASS(Destruction)
Destruction()
  : Attack("Destruction", 200, Type::NORMAL, 100, false, false, 16, false, 5, 0, "Destruction") {}
EA;
}
;
ATK_CLASS(Detritus)
Detritus()
  : Attack("Détritus", 65, Type::POISON, 100, true, false, 16, false, 20, 0, "Detritus") {}
EA;
}
;
ATK_CLASS(Devoreve)
Devoreve()
  : Attack("Dévorêve", 100, Type::PSY, 100, true, false, 16, false, 15, 0, "Devoreve") {}
EB;
EA;
}
;
ATK_CLASS(DoubleDard)
DoubleDard()
  : Attack("Double-Dard", 25, Type::INSECTE, 100, false, false, 16, false, 20, 0, "DoubleDard") {}
EA;
}
;
}
}
}

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUES_HPP_ */
