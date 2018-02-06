#include "Attacks.hpp"
#include "../../../utils/misc.hpp"


namespace OpMon{
  namespace Model{

    namespace Attacks {

      Attack *newAtk(std::string name) {
	IF_ATK(Abime)
	  IF_ATK(Acidarmure)
	  IF_ATK(Acide)
	  IF_ATK(Affutage)
	  IF_ATK(Aiguisage)
	  IF_ATK(Amnesie)
	  IF_ATK(Armure)
	  IF_ATK(Belier)
	  IF_ATK(Balayage)
	  IF_ATK(BecVrille)
	  IF_ATK(Berceuse)
	  IF_ATK(BombOeuf)
	  IF_ATK(Bouclier)
	  IF_ATK(Brouillard)
	  IF_ATK(BueeNoire)
	  IF_ATK(BullesDo)
	  IF_ATK(CageEclair)
	  IF_ATK(CanonGraine)
	  IF_ATK(Cascade)
	  IF_ATK(Charge)
	  IF_ATK(ChocMental)
	  IF_ATK(ChocPsy)
	  IF_ATK(ComboGriffe)
	  IF_ATK(Conversion)
	  IF_ATK(CoupdBoule)
	  IF_ATK(CoudKrane)
	  IF_ATK(CoupeVent)
	  IF_ATK(CrocDeMort)
	  IF_ATK(CrocFatal)
	  IF_ATK(CrocFeu)
	  IF_ATK(CruAiles)
	  IF_ATK(Damocles)
	  IF_ATK(DanseFleur)
	  IF_ATK(DanseLames)
	  IF_ATK(Deflagration)
	  IF_ATK(Destruction)
	  IF_ATK(Detritus)
	  IF_ATK(Devoreve)
	  IF_ATK(DoubleDard)
	  return nullptr;


      }

      int Abime::effectBefore(OpMon &atk, OpMon &def) {
	accuracy = ((atk.getLevel() - def.getLevel()) + 30);
	if (atk.getLevel() < def.getLevel()) {
	  return 2;
	}
	if (Utils::Misc::randU(100) > accuracy) {
	  return 2;
	} else {
	  def.attacked(def.getHP());
	  return 2;
	}
      }

      int Acidarmure::effectAfter(OpMon &atk, OpMon &def) {
	if (atk.changeDEF(2)) {
	  //Texte
	} else {
	  //Texte
	}
	return 2;
      }

      int Acide::effectAfter(OpMon &atk, OpMon &def) {
	if (Utils::Misc::randU(10) == 2) {
	  if (def.changeDEFSPE(-1)) {
            //Texte
	  } else {
            //Texte
	  }
	}
	return 0;
      }

      int Affutage::effectAfter(OpMon &atk, OpMon &def) {
	if (atk.changeATK(1)) {
	  //Texte
	} else {
	  //Texte
	}
	return 0;
      }

      int Aiguisage::effectAfter(OpMon &atk, OpMon &def) {
	if (atk.changeATK(1)) {
	} else {
	}
	if (atk.changeACC(1)) {
	} else {
	}
	return 0;
      }

      int Amnesie::effectAfter(OpMon &atk, OpMon &def) {
	if (atk.changeDEFSPE(2)) {

	} else {

	}
	return 0;
      }

      int Armure::effectAfter(OpMon &atk, OpMon &def) {
	if (atk.changeDEF(1)) {

	} else {

	}
	return 0;
      }

      int Belier::effectAfter(OpMon &atk, OpMon &def) {
	atk.attacked(round(hpPerdus / 4));
	return 0;
      }

      int Balayage::effectBefore(OpMon &atk, OpMon &def) {
	if (def.getSpecies().getWeight() <= 10) {
	  puissance = 20;
	} else if (def.getSpecies().getWeight() > 10 && def.getSpecies().getWeight() <= 25) {
	  puissance = 40;
	} else if (def.getSpecies().getWeight() > 25 && def.getSpecies().getWeight() <= 50) {
	  puissance = 60;
	} else if (def.getSpecies().getWeight() > 50 && def.getSpecies().getWeight() <= 100) {
	  puissance = 80;
	} else if (def.getSpecies().getWeight() > 100 && def.getSpecies().getWeight() <= 200) {
	  puissance = 100;
	} else {
	  puissance = 120;
	}
	return 0;
      }

      int Berceuse::effectAfter(OpMon &atk, OpMon &def) {
	if (def.setStatus(Status::SLEEPING)) {

	} else {

	}
	return 0;
      }

      int Blizzard::effectAfter(OpMon &atk, OpMon &def) {
	if(Utils::Misc::randU(10) == 2) {
	  //Texte
	  def.setStatus(Status::FROZEN);
	}
	return 0;
      }

      int Bouclier::effectAfter(OpMon &atk, OpMon &def) {
	if(atk.changeDEF(2)) {
	} else {
	}
	return 0;

      }

      int Brouillard::effectAfter(OpMon &atk, OpMon &def) {
	if(def.changeACC(-1)) {
	} else {
	}
	return 0;

      }

      int BueeNoire::effectAfter(OpMon &atk, OpMon &def) {
	// atk.setStats(Fight.oldStats[0], atk.getAttaques(), atk.getSpecies(), new Type[]{atk.getType1(), atk.getType2()});
	//def.setStats(Fight.oldStats[1], def.getAttaques(), def.getSpecies(), new Type[]{def.getType1(), def.getType2()});
	//TODO
	return 0;
      }


      int BullesDo::effectAfter(OpMon &atk, OpMon &def) {
	if (Utils::Misc::randU(10) ==2) {
	  if(def.changeSPE(-1)) {
	  } else {
	  }
	}
	return 0;
      }

      int CageEclair::effectAfter(OpMon &atk, OpMon &def) {
	if (def.getType1()==Type::ELECTRIQUE || def.getType2()==Type::ELECTRIQUE) {
	} else {
	  if(def.setStatus(Status::PARALYSED)) {
	  } else {
	  }
	}
	return 0;
      }

      int Cascade::effectAfter(OpMon &atk, OpMon &def) {
	if (Utils::Misc::randU(5) ==2) {
	  def.peur = true;
	}
	return 0;
      }

      int ChocMental::effectAfter(OpMon &atk, OpMon &def) {
	if (Utils::Misc::randU(10) ==2) {
	  def.confus = true;
	}
	return 0;
      }

      int ChocPsy::effectBefore(OpMon &atk, OpMon &def) {
	this->def = def.getStatDEF();
	this->defspe = def.getStatDEFSPE();
	def.setStat(Stats::DEFSPE, this->def);
	return 0;
      }

      int ChocPsy::effectAfter(OpMon &atk, OpMon &def) {
	def.setStat(Stats::DEFSPE, this->defspe);
	return 0;
      }

      int ComboGriffe::effectAfter(OpMon &atk, OpMon &def) {
	if(def.getHP() <= 0) {
	  return 0;
	}
	int it = 0;
	int coups = Utils::Misc::randU(4);
	for(it = 0; it != coups + 1; it++) {
	  def.attacked(hpPerdus);
	  if(def.getHP() <= 0) {
            return 0;
	  }
	}
	return 0;
      }

      int Conversion::effectAfter(OpMon &atk, OpMon &def) {
	std::vector<Attack*> arr = atk.getAttacks();
	atk.setType1(arr[0]->getType());
	atk.setType2(Type::NOTHING);
	return 0;
      }

      int CoupdBoule::effectAfter(OpMon &atk, OpMon &def) {
	if (Utils::Misc::randU(100) <= 30) {
	}
	return 0;
      }
      int CoudKrane::effectBefore(OpMon &atk, OpMon &def) {
	if (part==0) {
	  def.changeDEF(1);
	  part = 1;
	  return 1;
	} else {
	  part = 0;
	  def.changeDEF(-1);
	  return 0;
	}
      }
      int CoupeVent::effectBefore(OpMon &atk, OpMon &def) {
	if(part == 0) {
	  part = 1;
	  return 1;
	} else {
	  part = 0;
	}

	return 0;

      }

      int CrocDeMort::effectAfter(OpMon &atk, OpMon &def) {
	if (Utils::Misc::randU(10) ==2) {
	}
	return 0;
      }
      int CrocFatal::effectBefore(OpMon &atk, OpMon &def) {
	if(def.getHP() != 1) {
	  def.attacked(def.getHP() / 2);
	} else {
	  def.attacked(1);
	}
	return 2;
      }

      int CrocFeu::effectAfter(OpMon &atk, OpMon &def) {
	if(Utils::Misc::randU(10) ==5) {
	  if(def.setStatus(Status::BURNING)) {

	  }
	}
	if(Utils::Misc::randU(10) ==7) {
	  def.peur = true;
	}
	return 0;

      }

      int Damocles::effectAfter(OpMon &atk, OpMon &def) {
	atk.attacked(hpPerdus / 3);
	return 0;
      }


      int DanseFleur::effectAfter(OpMon &atk, OpMon &def) {
	if(part == 0) {
	  part = 1;
	} else if(part == 1) {
	  pp++;
	  if(Utils::Misc::randU(1) == 0) {
            part = 2;
	  } else {
            part = 0;
            atk.confus = true;
	  }
	} else {
	  pp++;
	  part = 0;
	  atk.confus = true;

	}
	return 0;
      }
      int DanseLames::effectAfter(OpMon &atk, OpMon &def) {
	if(atk.changeATK(2)) {
	}
	return 0;
      }

      int Deflagration::effectAfter(OpMon &atk, OpMon &def) {
	if(Utils::Misc::randU(10) == 5) {
	  if(def.setStatus(Status::BURNING)) {

	  }
	}
	return 0;
      }

      int Destruction::effectAfter(OpMon &atk, OpMon &def) {
	atk.attacked(atk.getHP());
	return 0;
      }

      int Detritus::effectAfter(OpMon &atk, OpMon &def) {
	if(Utils::Misc::randU(10) < 3) {
	  if(def.setStatus(Status::POISONED)) {
	  }
	}
	return 0;
      }

      int Devoreve::effectBefore(OpMon &atk, OpMon &def) {
	if(!(def.getStatus() == Status::SLEEPING)) {

	}
	return 0;
      }

      int Devoreve::effectAfter(OpMon &atk, OpMon &def) {
	atk.heal(hpPerdus / 2);
	return 0;
      }

      int DoubleDard::effectAfter(OpMon &atk, OpMon &def) {
	if(Utils::Misc::randU(10) < 2) {
	  def.setStatus(Status::POISONED);
	}
	if(def.getHP() <= 0) {
	  def.attacked(hpPerdus);
	  if(Utils::Misc::randU(10) < 2) {
            def.setStatus(Status::POISONED);
	  }
	}
	return 0;
      }


    }

  }
}
