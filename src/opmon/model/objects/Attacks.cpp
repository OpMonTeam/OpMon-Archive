#include "Attacks.hpp"
#include "../../../utils/misc.hpp"

namespace OpMon {
    namespace Model {

        namespace Attacks {

            using namespace Utils;

            Attack *newAtk(std::string name) {

                IF_ATK(Abime, Attack("Abime", 99999, Type::GROUND, 30, false, false, -1, false, 5, 0, "Abime",
                                     new AbimeBeforeEffect()))
                IF_ATK(Acidarmure, Attack("Acidarmure", 0, Type::TOXIC, 100, false, true, -1, true, 20, 0, "Acidarmure",
                                          nullptr, new ChangeStatEffect(ChangeStatEffect::ATTACKER, Stats::DEF, 2)))
                IF_ATK(Acide, Attack("Acide", 40, Type::TOXIC, 100, true, false, 16, false, 30, 0, "Acide",
                                     nullptr, new AcideAfterEffect()))
                IF_ATK(Affutage, Attack("Affutage", 0, Type::NEUTRAL, 100, false, true, -1, true, 30, 0, "Affutage",
                                        nullptr, new ChangeStatEffect(ChangeStatEffect::ATTACKER, Stats::ATK, 1)))
                IF_ATK(Aiguisage, Attack("Aiguisage", 0, Type::NEUTRAL, 100, false, true, -1, true, 15, 0, "Aiguisage",
                                         nullptr, new AiguisageAfterEffect()))
                IF_ATK(Amnesie, Attack("Amnésie", 0, Type::MENTAL, 100, false, true, -1, true, 20, 0, "Amnesie",
                                       nullptr, new ChangeStatEffect(ChangeStatEffect::ATTACKER, Stats::DEFSPE, 2)))
                IF_ATK(Armure, Attack("Armure", 0, Type::NEUTRAL, 100, false, true, -1, true, 30, 0, "Armure",
                                      nullptr, new ChangeStatEffect(ChangeStatEffect::ATTACKER, Stats::DEF, 1)))
                IF_ATK(Belier, Attack("Bélier", 90, Type::NEUTRAL, 85, false, false, 16, false, 20, 0, "Belier",
                                      nullptr, new BelierAfterEffect()))
                IF_ATK(Balayage, Attack("Balayage", 0, Type::FIGHT, 100, false, false, 16, false, 20, 0, "Balayage",
                                        new BalayageBeforeEffect()))
                IF_ATK(BecVrille, Attack("Bec Vrille", 80, Type::SKY, 100, false, false, 16, false, 20, 0, "BecVrille"))
                IF_ATK(Berceuse, Attack("Berceuse", 0, Type::NEUTRAL, 55, false, true, -1, false, 15, 0, "Berceuse",
                                        nullptr, new BerceuseAfterEffect()))
                IF_ATK(Blizzard, Attack("Blizzard", 110, Type::COLD, 70, true, false, 16, false, 5, 0, "Blizzard",
                                        nullptr, new BlizzardAfterEffect()))
                IF_ATK(BombOeuf, Attack("Bomb'\u0152uf", 100, Type::NEUTRAL, 75, false, false, 16, false, 10, 0, "BombOeuf"))
                IF_ATK(Bouclier, Attack("Bouclier", 0, Type::MENTAL, 100, false, true, -1, true, 20, 0, "Bouclier",
                                        nullptr, new ChangeStatEffect(ChangeStatEffect::ATTACKER, Stats::DEF, 2)))
                IF_ATK(Brouillard, Attack("Brouillard", 0, Type::NEUTRAL, 100, false, true, -1, false, 20, 0, "Brouillard",
                                          nullptr, new ChangeStatEffect(ChangeStatEffect::DEFENDER, Stats::ACC, -1)))
                IF_ATK(BueeNoire, Attack("Buée Noire", 0, Type::COLD, 100, false, true, -1, true, 35, 0, "BueeNoire",
                                         nullptr, new BueeNoireAfterEffect()))
                IF_ATK(BullesDo, Attack("Bulles d'O", 65, Type::LIQUID, 100, true, false, 16, false, 20, 0, "BullesDo",
                                        nullptr, new BullesDoAfterEffect()))
                IF_ATK(CageEclair, Attack("Cage Eclair", 0, Type::ELECTRON, 100, false, true, -1, false, 20, 0, "CageEclair",
                                          nullptr, new CageEclairAfterEffect()))
                IF_ATK(CanonGraine, Attack("Canon Graine", 80, Type::VEGETAL, 100, false, false, 16, false, 15, 0, "CanonGraine"))
                IF_ATK(Cascade, Attack("Cascade", 80, Type::LIQUID, 100, false, false, 16, false, 15, 0, "Cascade",
                                       nullptr, new CascadeAfterEffect()))
                IF_ATK(Charge, Attack("Charge", 50, Type::NEUTRAL, 100, false, false, 16, false, 35, 0, "Charge"))
                IF_ATK(ChocMental, Attack("Choc Mental", 50, Type::MENTAL, 100, true, false, 16, false, 25, 0, "ChocMental",
                                          nullptr, new ChocMentalAfterEffect()))
                IF_ATK(ChocPsy, Attack("Choc Psy", 80, Type::MENTAL, 100, true, false, 16, false, 10, 0, "ChocPsy",
                                       new ChocPsyBeforeEffect(), new ChocPsyAfterEffect()))
                IF_ATK(ComboGriffe, Attack("Combo-Griffe", 18, Type::NEUTRAL, 80, false, false, 16, false, 15, 0, "ComboGriffe",
                                           nullptr, new ComboGriffeAfterEffect()))
                IF_ATK(Conversion, Attack("Conversion", 0, Type::NEUTRAL, 100, false, true, -1, true, 30, 0, "Conversion",
                                          nullptr, new ConversionAfterEffect()))
                IF_ATK(CoupdBoule, Attack("Coup d'Boule", 70, Type::NEUTRAL, 100, false, false, 16, false, 15, 0, "CoupdBoule",
                                          nullptr, new CoupdBouleAfterEffect()))
                IF_ATK(CoudKrane, Attack("Coud'Krâne", 130, Type::NEUTRAL, 100, false, false, 16, false, 10, 0, "CoudKrane",
                                         new CoudKraneBeforeEffect()))
                IF_ATK(CoupeVent, Attack("Coupe-Vent", 80, Type::NEUTRAL, 100, true, false, 8, false, 10, 0, "CoupeVent",
                                         new CoupeVentBeforeEffect()))
                IF_ATK(CrocDeMort, Attack("Croc de Mort", 80, Type::NEUTRAL, 90, false, false, 16, false, 15, 0, "CrocDeMort",
                                          nullptr, new CrocDeMortAfterEffect()))

                /*

              IF_ATK(CrocFatal, Attack("Croc Fatal", 0, Type::NEUTRAL, 90, false, true, -1, false, 10, 0, "CrocFatal",
                                       new CrocFatalBeforeEffect()))
              IF_ATK(CrocFeu, Attack("Crocs Feu", 65, Type::BURNING, 95, false, false, 16, false, 15, 0, "CrocFeu",
                                     nullptr, new CrocFeuAfterEffect()))
              IF_ATK(CruAiles, Attack("Cru-Ailes", 60, Type::SKY, 100, false, false, 16, false, 35, 0, "CruAiles"))
              IF_ATK(Damocles, Attack("Damoclès", 120, Type::NEUTRAL, 100, false, false, 16, false, 15, 0, "Damocles",
                                      nullptr, new DamoclesAfterEffect()))
              IF_ATK(DanseFleur, Attack("Danse-Fleur", 120, Type::VEGETAL, 100, true, false, 16, false, 10, 0, "DanseFleur",
                                        nullptr, new DanseFleurAfterEffect()))
              IF_ATK(DanseLames, Attack("Danse-Lames", 0, Type::NEUTRAL, 100, false, true, -1, true, 20, 0, "DanseLames",
                                        nullptr, new DanseLamesAfterEffect()))
              IF_ATK(Deflagration, Attack("Déflagration", 110, Type::BURNING, 85, true, false, 16, false, 5, 0, "Deflagration",
                                          nullptr, new DeflagrationAfterEffect()))
              IF_ATK(Destruction, Attack("Destruction", 200, Type::NEUTRAL, 100, false, false, 16, false, 5, 0, "Destruction",
                                         nullptr, new DestructionAfterEffect()))
              IF_ATK(Detritus, Attack("Détritus", 65, Type::TOXIC, 100, true, false, 16, false, 20, 0, "Detritus",
                                      nullptr, new DetritusAfterEffect()))
              IF_ATK(Devoreve, Attack("Dévorêve", 100, Type::MENTAL, 100, true, false, 16, false, 15, 0, "Devoreve",
                                      new DevoreveBeforeEffect(), new DevoreveAfterEffect()))
              IF_ATK(DoubleDard, Attack("Double-Dard", 25, Type::BUG, 100, false, false, 16, false, 20, 0, "DoubleDard",
                                        nullptr, new DoubleDardAfterEffect()))

              */
                return nullptr;
            }

            ChangeStatEffect::ChangeStatEffect(Target target, Model::Stats stat, int coef)
              : target(target)
              , stat(stat)
              , coef(coef) {}

            int ChangeStatEffect::apply(Attack &, OpMon &attacker, OpMon &defender, Turn &atkTurn) {
                std::map<Stats, int (OpMon::*)(int)> stat_to_method = {
                  {Stats::ACC, &OpMon::changeACC},
                  {Stats::ATK, &OpMon::changeATK},
                  {Stats::ATKSPE, &OpMon::changeATKSPE},
                  {Stats::DEF, &OpMon::changeDEF},
                  {Stats::DEFSPE, &OpMon::changeDEFSPE},
                  {Stats::EVA, &OpMon::changeEVA},
                  {Stats::SPE, &OpMon::changeSPE},
                };
                auto change_method = stat_to_method[stat];

                if(target == Target::ATTACKER) {
                    int diff_value = (attacker.*change_method)(coef); // diff_value = attacker.changeXXX(coef)
                    atkTurn.changedStatsAtk.emplace(stat, diff_value);
                } else {
                    int diff_value = (defender.*change_method)(coef); // diff_value = defender.changeXXX(coef)
                    atkTurn.changedStatsDef.emplace(stat, diff_value);
                }
                return 0;
            }

            int AbimeBeforeEffect::apply(Attack &attack, OpMon &atk, OpMon &def, Turn &atkTurn) {
                attack.setAccuracy((atk.getLevel() - def.getLevel()) + 30);
                if(atk.getLevel() < def.getLevel()) {
                    atkTurn.attackFailed = true;
                    return 2;
                }
                if(Utils::Misc::randU(100) > attack.getAccuracy()) {
                    atkTurn.attackFailed = true;
                    return 2;
                } else {
                    def.attacked(def.getHP());
                    atkTurn.OHKO = true;
                    return 2;
                }
            }

            int AcideAfterEffect::apply(Attack &, OpMon &, OpMon &def, Turn &atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
                    atkTurn.changedStatsDef.emplace(Stats::DEFSPE, def.changeDEFSPE(-1));
                }
                return 0;
            }

            int AiguisageAfterEffect::apply(Attack &, OpMon &atk, OpMon &, Turn &atkTurn) {
                atkTurn.changedStatsAtk.emplace(Stats::ATK, atk.changeATK(1));
                atkTurn.changedStatsAtk.emplace(Stats::ACC, atk.changeACC(1));
                return 0;
            }

            int BelierAfterEffect::apply(Attack &attack, OpMon &atk, OpMon &, Turn &atkTurn) {
                atk.attacked(round(attack.getHpLost() / 4));
                atkTurn.attackHurt = round(attack.getHpLost() / 4);
                return 0;
            }

            int BalayageBeforeEffect::apply(Attack &attack, OpMon &, OpMon &def, Turn &) {
                if(def.getSpecies().getWeight() <= 10) {
                    attack.setPower(20);
                } else if(def.getSpecies().getWeight() > 10 && def.getSpecies().getWeight() <= 25) {
                    attack.setPower(40);
                } else if(def.getSpecies().getWeight() > 25 && def.getSpecies().getWeight() <= 50) {
                    attack.setPower(60);
                } else if(def.getSpecies().getWeight() > 50 && def.getSpecies().getWeight() <= 100) {
                    attack.setPower(80);
                } else if(def.getSpecies().getWeight() > 100 && def.getSpecies().getWeight() <= 200) {
                    attack.setPower(100);
                } else {
                    attack.setPower(120);
                }
                return 0;
            }

            int BerceuseAfterEffect::apply(Attack & /*attack*/, OpMon &, OpMon &def, Turn &atkTurn) {
                if(def.setStatus(Status::SLEEPING)) {
                    atkTurn.toPrintAfter.push_back(OpString("battle.status.sleep.in", def.getNickname()));
                } else {
                    atkTurn.attackFailed = true;
                }
                return 0;
            }

            int BlizzardAfterEffect::apply(Attack & /*attack*/, OpMon &, OpMon &def, Turn &atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
                    if(def.setStatus(Status::FROZEN)) {
                        atkTurn.toPrintAfter.push_back(OpString("battle.status.frozen.in", def.getNickname()));
                    }
                }
                return 0;
            }

            int BueeNoireAfterEffect::apply(Attack & /*attack*/, OpMon &atk, OpMon &def, Turn &atkTurn) {
                // atk.setStats(Fight.oldStats[0], atk.getAttaques(), atk.getSpecies(), new Type[]{atk.getType1(), atk.getType2()});
                //def.setStats(Fight.oldStats[1], def.getAttaques(), def.getSpecies(), new Type[]{def.getType1(), def.getType2()});
                //TODO
                return 0;
            }

            int BullesDoAfterEffect::apply(Attack & /*attack*/, OpMon &atk, OpMon &def, Turn &atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
                    atkTurn.changedStatsDef.emplace(Stats::SPE, def.changeSPE(-1));
                }
                return 0;
            }

            int CageEclairAfterEffect::apply(Attack & /*attack*/, OpMon &atk, OpMon &def, Turn &atkTurn) {
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

            int CascadeAfterEffect::apply(Attack & /*attack*/, OpMon &atk, OpMon &def, Turn &atkTurn) {
                if(Utils::Misc::randU(5) == 2) {
                    def.afraid = true;
                    atkTurn.toPrintAfter.push_back(OpString("battle.status.afraid", def.getNickname()));
                }
                return 0;
            }

            int ChocMentalAfterEffect::apply(Attack & /*attack*/, OpMon &atk, OpMon &def, Turn &atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
                    def.confused = true;
                    atkTurn.toPrintAfter.push_back(OpString("battle.status.confused.in", def.getNickname()));
                }
                return 0;
            }

            int ChocPsyBeforeEffect::apply(Attack &attack, OpMon &atk, OpMon &def, Turn &atkTurn) {
                attack.setSavedDefSpe(def.getStatDEFSPE());
                def.setStat(Stats::DEFSPE, def.getStatDEF());
                return 0;
            }

            int ChocPsyAfterEffect::apply(Attack &attack, OpMon &atk, OpMon &def, Turn &atkTurn) {
                def.setStat(Stats::DEFSPE, attack.getSavedDefSpe());
                return 0;
            }

            int ComboGriffeAfterEffect::apply(Attack & /*attack*/, OpMon & /*atk*/, OpMon & /*def*/, Turn & /*atkTurn*/) {
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

            int ConversionAfterEffect::apply(Attack & /*attack*/, OpMon &, OpMon &, Turn &) {
                //TODO later
                /*
                std::vector<Attack *> arr = atk.getAttacks();
                atk.setType1(arr[0]->getType());
                atk.setType2(Type::NOTHING);
	      */
                return 0;
            }

            int CoupdBouleAfterEffect::apply(Attack & /*attack*/, OpMon &, OpMon &, Turn & /*atkTurn*/) {
                if(Utils::Misc::randU(100) <= 30) {
                    //?
                }
                return 0;
            }
            int CoudKraneBeforeEffect::apply(Attack &attack, OpMon &, OpMon &def, Turn & /*atkTurn*/) {
                if(attack.getPart() == 0) {
                    def.changeDEF(1);
                    //atkTurn.toPrintBefore.push_back(OpString("battle.*coudkrane?(To change)*.charge"), {atk.getNickname()});
                    //TODO add the string
                    attack.setPart(1);
                    return 1;
                } else {
                    attack.setPart(0);
                    def.changeDEF(-1);
                    return 0;
                }
            }
            int CoupeVentBeforeEffect::apply(Attack &attack, OpMon & /*atk*/, OpMon & /*def*/, Turn & /*atkTurn*/) {
                if(attack.getPart() == 0) {
                    //atkTurn.toPrintBefore.push_back(OpString("battle.*coupevent?(To change)*.charge"), {atk.getNickname()});
                    //TODO add the string
                    attack.setPart(1);
                    return 1;
                } else {
                    attack.setPart(0);
                }

                return 0;
            }

            int CrocDeMortAfterEffect::apply(Attack & /*attack*/, OpMon & /*atk*/, OpMon &def, Turn &atkTurn) {
                if(Utils::Misc::randU(10) == 2) {
                    def.afraid = true;
                    atkTurn.toPrintAfter.push_back(OpString("battle.status.afraid", def.getNickname()));
                }
                return 0;
            }
            //TODO theses attacks (Not important for the 0.15)
            /*
            int CrocFatalBeforeEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(def.getHP() != 1) {
                    def.attacked(def.getHP() / 2);
                } else {
                    def.attacked(1);
                }
                return 2;
            }

            int CrocFeuAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 5) {
                    if(def.setStatus(Status::BURNING)) {
                    }
                }
                if(Utils::Misc::randU(10) == 7) {
                    def.peur = true;
                }
                return 0;
            }

            int DamoclesAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                atk.attacked(hpLost / 3);
                return 0;
            }

            int DanseFleurAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
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
            int DanseLamesAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(atk.changeATK(2)) {
                }
                return 0;
            }

            int DeflagrationAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) == 5) {
                    if(def.setStatus(Status::BURNING)) {
                    }
                }
                return 0;
            }

            int DestructionAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                atk.attacked(atk.getHP());
                return 0;
            }

            int DetritusAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(Utils::Misc::randU(10) < 3) {
                    if(def.setStatus(Status::POISONED)) {
                    }
                }
                return 0;
            }

            int DevoreveBeforeEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                if(!(def.getStatus() == Status::SLEEPING)) {
                }
                return 0;
            }

            int DevoreveAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
                atk.heal(hpLost / 2);
                return 0;
            }

            int DoubleDardAfterEffect::apply(Attack& attack, OpMon &atk, OpMon &def, Turn& atkTurn) {
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
