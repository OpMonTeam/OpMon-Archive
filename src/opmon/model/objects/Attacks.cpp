#include "Attacks.hpp"
#include "../../../utils/misc.hpp"

namespace OpMon {
    namespace Model {

        namespace Attacks {

	  using namespace Utils;
	  
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
		  /*IF_ATK(CrocDeMort)
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
                IF_ATK(DoubleDard)*/
                return nullptr;
            }

            int Abime::effectBefore(OpMon &atk, OpMon &def, Turn& atkTurn) {
                accuracy = ((atk.getLevel() - def.getLevel()) + 30);
                if(atk.getLevel() < def.getLevel()) {
		  atkTurn.attackFailed = true;
                    return 2;
                }
                if(Utils::Misc::randU(100) > accuracy) {
		  atkTurn.attackFailed = true;
                    return 2;
                } else {
                    def.attacked(def.getHP());
		    atkTurn.OHKO = true;
                    return 2;
                }
            }

            int Acidarmure::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
		atkTurn.changedStatsAtk.emplace(Stats::DEF, atk.changeDEF(2));
                return 2;
            }

            int Acide::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
		    atkTurn.changedStatsDef.emplace(Stats::DEFSPE, def.changeDEFSPE(-1));
                }
                return 0;
            }

            int Affutage::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
		atkTurn.changedStatsAtk.emplace(Stats::ATK, atk.changeATK(1));
                return 0;
            }

            int Aiguisage::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
		atkTurn.changedStatsAtk.emplace(Stats::ATK, atk.changeATK(1));
		atkTurn.changedStatsAtk.emplace(Stats::ACC, atk.changeACC(1));
                return 0;
            }

            int Amnesie::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
		atkTurn.changedStatsAtk.emplace(Stats::DEFSPE, atk.changeDEFSPE(2));
                return 0;
            }

            int Armure::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
		atkTurn.changedStatsAtk.emplace(Stats::DEF, atk.changeDEF(1));
                return 0;
            }

            int Belier::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                atk.attacked(round(hpLost / 4));
		atkTurn.attackHurt = round(hpLost / 4);
                return 0;
            }

            int Balayage::effectBefore(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(def.getSpecies().getWeight() <= 10) {
                    power = 20;
                } else if(def.getSpecies().getWeight() > 10 && def.getSpecies().getWeight() <= 25) {
                    power = 40;
                } else if(def.getSpecies().getWeight() > 25 && def.getSpecies().getWeight() <= 50) {
                    power = 60;
                } else if(def.getSpecies().getWeight() > 50 && def.getSpecies().getWeight() <= 100) {
                    power = 80;
                } else if(def.getSpecies().getWeight() > 100 && def.getSpecies().getWeight() <= 200) {
                    power = 100;
                } else {
                    power = 120;
                }
                return 0;
            }

            int Berceuse::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
	      if(def.setStatus(Status::SLEEPING)){
		atkTurn.toPrintAfter.push_back(OpString("battle.status.sleep.in", def.getNickname()));
	      }else{
		atkTurn.attackFailed = true;
	      }
                return 0;
            }

            int Blizzard::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
		  if(def.setStatus(Status::FROZEN)){
		    atkTurn.toPrintAfter.push_back(OpString("battle.status.frozen.in", def.getNickname()));
		  }
                }
                return 0;
            }

            int Bouclier::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
		atkTurn.changedStatsAtk.emplace(Stats::DEF, atk.changeDEF(2));
                return 0;
            }

            int Brouillard::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
		atkTurn.changedStatsDef.emplace(Stats::ACC, def.changeACC(-1));
                return 0;
            }

            int BueeNoire::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                // atk.setStats(Fight.oldStats[0], atk.getAttaques(), atk.getSpecies(), new Type[]{atk.getType1(), atk.getType2()});
                //def.setStats(Fight.oldStats[1], def.getAttaques(), def.getSpecies(), new Type[]{def.getType1(), def.getType2()});
                //TODO
                return 0;
            }

            int BullesDo::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
		    atkTurn.changedStatsDef.emplace(Stats::SPE, def.changeSPE(-1));
                }
                return 0;
            }


            int CageEclair::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(def.getType1() == Type::ELECTRON || def.getType2() == Type::ELECTRON) {
		  atkTurn.attackFailed = true;
                } else {
                    if(def.setStatus(Status::PARALYSED)) {
		      atkTurn.toPrintAfter.push_back(OpString("battle.status.paralysed.in", def.getNickname()));
                     } else {
		      atkTurn.attackFailed = true;
                    }
		    
                }
                return 0;
            }

            int Cascade::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(5) == 2) {
                    def.afraid = true;
		    atkTurn.toPrintAfter.push_back(OpString("battle.status.afraid", def.getNickname()));
                }
                return 0;
            }

            int ChocMental::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
                    def.confused = true;
		    atkTurn.toPrintAfter.push_back(OpString("battle.status.confused.in", def.getNickname()));
                }
                return 0;
            }

            int ChocPsy::effectBefore(OpMon &atk, OpMon &def, Turn& atkTurn) {
                this->def = def.getStatDEF();
                this->defspe = def.getStatDEFSPE();
                def.setStat(Stats::DEFSPE, this->def);
                return 0;
            }

            int ChocPsy::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                def.setStat(Stats::DEFSPE, this->defspe);
                return 0;
            }

            int ComboGriffe::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
	      //TODO later
	      /*
                if(def.getHP() <= 0) {
                    return 0;
                }
                int it = 0;
                int coups = Utils::Misc::randU(4);
                for(it = 0; it != coups + 1; it++) {
                    def.attacked(hpLost);
                    if(def.getHP() <= 0) {
                        return 0;
                    }
                }
	      */
                return 0;
	      
            }

            int Conversion::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
	      //TODO later
	      /*
                std::vector<Attack *> arr = atk.getAttacks();
                atk.setType1(arr[0]->getType());
                atk.setType2(Type::NOTHING);
	      */
                return 0;
            }

            int CoupdBoule::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(100) <= 30) {
		  //?
                }
                return 0;
            }
            int CoudKrane::effectBefore(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(part == 0) {
                    def.changeDEF(1);
		    //atkTurn.toPrintBefore.push_back(OpString("battle.*coudkrane?(To change)*.charge"), {atk.getNickname()});
		    //TODO add the string
                    part = 1;
                    return 1;
                } else {
                    part = 0;
                    def.changeDEF(-1);
                    return 0;
                }
            }
            int CoupeVent::effectBefore(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(part == 0) {
		  //atkTurn.toPrintBefore.push_back(OpString("battle.*coupevent?(To change)*.charge"), {atk.getNickname()});
		  //TODO add the string
                    part = 1;
                    return 1;
                } else {
                    part = 0;
                }

                return 0;
            }

            int CrocDeMort::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
		  def.afraid = true;
		  atkTurn.toPrintAfter.push_back(OpString("battle.status.afraid", def.getNickname()));
                }
                return 0;
	    }
	  //TODO theses attacks (Not important for the 0.15)
	  /*
            int CrocFatal::effectBefore(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(def.getHP() != 1) {
                    def.attacked(def.getHP() / 2);
                } else {
                    def.attacked(1);
                }
                return 2;
            }

            int CrocFeu::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 5) {
                    if(def.setStatus(Status::BURNING)) {
                    }
                }
                if(Utils::Misc::randU(10) == 7) {
                    def.peur = true;
                }
                return 0;
            }

            int Damocles::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                atk.attacked(hpLost / 3);
                return 0;
            }

            int DanseFleur::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(part == 0) {
                    part = 1;
                } else if(part == 1) {
                    pp++;
                    if(Utils::Misc::randU(1) == 0) {
                        part = 2;
                    } else {
                        part = 0;
                        atk.confused = true;
                    }
                } else {
                    pp++;
                    part = 0;
                    atk.confused = true;
                }
                return 0;
            }
            int DanseLames::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(atk.changeATK(2)) {
                }
                return 0;
            }

            int Deflagration::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 5) {
                    if(def.setStatus(Status::BURNING)) {
                    }
                }
                return 0;
            }

            int Destruction::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                atk.attacked(atk.getHP());
                return 0;
            }

            int Detritus::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) < 3) {
                    if(def.setStatus(Status::POISONED)) {
                    }
                }
                return 0;
            }

            int Devoreve::effectBefore(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(!(def.getStatus() == Status::SLEEPING)) {
                }
                return 0;
            }

            int Devoreve::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                atk.heal(hpLost / 2);
                return 0;
            }

            int DoubleDard::effectAfter(OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) < 2) {
                    def.setStatus(Status::POISONED);
                }
                if(def.getHP() <= 0) {
                    def.attacked(hpLost);
                    if(Utils::Misc::randU(10) < 2) {
                        def.setStatus(Status::POISONED);
                    }
                }
                return 0;
            }
	  */

        } // namespace Attacks

    } // namespace Model
} // namespace OpMon
