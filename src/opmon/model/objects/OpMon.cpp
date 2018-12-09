/*
OpMon.cpp
Author : Cyrion
Contributors : BAKFR, JonnyPtn, torq, Stelyus
File under GNU GPL v3.0 license
*/
#include "OpMon.hpp"
#include "../../../utils/defines.hpp"
#include "../../../utils/log.hpp"
#include "../../../utils/misc.hpp"
#include "../../start/Core.hpp"
#include "../save/Save.hpp"
#include "./evolution/Evolution.hpp"
#include "./evolution/evolutions.hpp"
#include "Attacks.hpp"
#include <fstream>
#include <sstream>
#include "Item.hpp"

namespace OpMon {
    namespace Model {

        OpMon::~OpMon() {
            for(int i = 0; i < 4; i++) {
                delete(attacks[i]);
            }
        }

        OpMon::OpMon(const std::string &nickname, const Species *species, int level, const std::vector<Attack *> &attacks, Nature nature)
          : nickname((nickname.empty()) ? species->getName() : nickname)
          , species(species)
          , level(level)
          , attacks(attacks)
          , nature(nature) {
            atkIV = Utils::Misc::randU(32);
            defIV = Utils::Misc::randU(32);
            atkSpeIV = Utils::Misc::randU(32);
            defSpeIV = Utils::Misc::randU(32);
            speIV = Utils::Misc::randU(32);
            hpIV = Utils::Misc::randU(32);

            calcStats();

            captureRate = species->getCaptureRate();
            HP = statHP;
            type1 = species->getType1();
            type2 = species->getType2();

            auto curve = this->species->getCurve();
            this->toNextLevel = curve->getNeededExp(this->level + 1);
            this->exp = curve->getNeededExp(this->level);

            held = nullptr;
            statLove = 100;
            statACC = 100;
            statEVA = 100;
            initialized = false;
        }

        bool OpMon::captured(Item const &OpBox) {
            //Big formulas
	  int a = round((((3 * statHP - 2 * HP) * captureRate * /*TODO OpBox.getCaptureRate() */ (status == Status::PARALYSED || status == Status::POISONED || status == Status::BURNING ? 1.5 : (status == Status::FROZEN || status == Status::SLEEPING ? 2 : 1))) / (3 * statHP)));
            int b = round((pow(2, 16) - 1) * pow(a / (pow(2, 8) - 1), 0.25));
            int c[] = {Utils::Misc::randU(65535), Utils::Misc::randU(65535), Utils::Misc::randU(65535),
                       Utils::Misc::randU(65535)};
            int nbreOk = 0;
            for(int i = 0; i < 4; i++) {
                if(c[i] <= b) {
                    nbreOk++;
                }
            }
            //nbreOk represents the number of times the OpBall wriggles
            if(nbreOk == 0) {
                return false;
            } else {
                //there is multiple "if" here because the printed dialog is different. Since this method is unused for now, this isn't very problematic to leave it as it is.
                if(nbreOk == 1) {
                    return false;
                }
                if(nbreOk == 2) {
                    return false;
                }
                if(nbreOk == 3) {
                    return false;
                }
                if(nbreOk != 4) { //An OpBall can't wriggle four times
                    handleError("InternalError : OpMon.cpp : nbreOk != 4", true);
                }
                return true;
            }
        }

        void OpMon::setStat(Stats stat, int newStat) {
            switch(stat) {
            case Stats::ATK:
                statATK = newStat;
                break;
            case Stats::DEF:
                statDEF = newStat;
                break;
            case Stats::ATKSPE:
                statATKSPE = newStat;
                break;
            case Stats::DEFSPE:
                statDEFSPE = newStat;
                break;
            case Stats::SPE:
                statSPE = newStat;
                break;
            case Stats::HP:
                statHP = newStat;
                break;
            case Stats::EVA:
                statEVA = newStat;
                break;
            case Stats::ACC:
                statACC = newStat;
                break;
            case Stats::NOTHING:
                Utils::Log::oplog("[WARNING] - Incorrect value in a switch (OpMon::setStat). Expected a stat, got Stats::NOTHING.");
                break;
            }
        }

        void OpMon::levelUp() {
            level++;

            //Calcs the exp needed for the next level
            auto curve = this->species->getCurve();
            this->toNextLevel = curve->getNeededExp(this->level + 1);
            this->exp = curve->getNeededExp(this->level);

            calcStats();
            //Check if the OpMon evolves
            if(species->getEvolType()->checkEvolve(*this)) {
	      evolve();
            }
        }

        int OpMon::win(OpMon const &defeated) {
            getEvs(defeated);
            exp += ((defeated.species->getExp() * defeated.level) / this->level) * expBoost;
            //Handles the level won. The loops allows to increase the level as long as there is exp.
            while(exp >= toNextLevel && level < 100) {
                if(exp < toNextLevel) {
                    break;
                }
                levelUp();
            }
            calcStats();
            return (((defeated.species->getExp() * defeated.level) / this->level) * expBoost);
        }

        void OpMon::getEvs(OpMon const &defeated) {
            //If the total of the EV is over 510, don't add EVs, since 510 is the maximum.
            if(!((atkEV + defEV + hpEV + atkSpeEV + defSpeEV + speEV) > 510)) {
                std::vector<Stats> statsDefeated;
                for(unsigned int i = 0; i < defeated.species->getEv().size(); i++) {
                    statsDefeated.push_back(defeated.species->getEv()[i]);
                }

                for(unsigned int i = 0; i < statsDefeated.size(); i++) {
                    switch(statsDefeated[i]) {
                    case Stats::ATK:
                        if(atkEV < 252) {
                            atkEV++;
                        }
                        break;
                    case Stats::ATKSPE:
                        if(atkSpeEV < 252) {
                            atkSpeEV++;
                        }
                        break;
                    case Stats::DEF:
                        if(defEV < 252) {
                            atkEV++;
                        }
                        break;
                    case Stats::DEFSPE:
                        if(defSpeEV < 252) {
                            defSpeEV++;
                        }
                        break;
                    case Stats::HP:
                        if(hpEV < 252) {
                            hpEV++;
                        }
                        break;
                    case Stats::NOTHING:
                        break;
                    case Stats::SPE:
                        if(speEV < 252) {
                            speEV++;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        void OpMon::calcStats() {
            //Big annoying formulas
            statATK = round(
              ((((2 * species->getBaseAtk() + atkIV + (atkEV / 4)) * level) / 100) + 5) * ((natures[(int)nature].bonus == Stats::ATK) ? 1.1 : ((natures[(int)nature].malus == Stats::ATK) ? 0.9 : 1)));
            statDEF = round(
              ((((2 * species->getBaseDef() + defIV + (defEV / 4)) * level) / 100) + 5) * ((natures[(int)nature].bonus == Stats::DEF) ? 1.1 : ((natures[(int)nature].malus == Stats::DEF) ? 0.9 : 1)));
            statATKSPE =
              round(
                ((((2 * species->getBaseAtkSpe() + atkSpeIV + (atkSpeEV / 4)) * level) / 100) + 5) * ((natures[(int)nature].bonus == Stats::ATKSPE) ? 1.1 : ((natures[(int)nature].malus == Stats::ATKSPE) ? 0.9 : 1)));
            statDEFSPE =
              round(
                ((((2 * species->getBaseDefSpe() + defSpeIV + (defSpeEV / 4)) * level) / 100) + 5) * ((natures[(int)nature].bonus == Stats::DEFSPE) ? 1.1 : ((natures[(int)nature].malus == Stats::DEFSPE) ? 0.9 : 1)));
            statSPE = round(
              ((((2 * species->getBaseSpe() + speIV + (speEV / 4)) * level) / 100) + 5) * ((natures[(int)nature].bonus == Stats::SPE) ? 1.1 : ((natures[(int)nature].malus == Stats::SPE) ? 0.9 : 1)));
            statHP = round(((2 * species->getBaseHP() + hpIV + (hpEV / 4)) * level) / 100) + level + 10;
        }

        //This method will be removed in the future
        bool OpMon::itemUsed(Item *used) {
            //if the OpMon evolves by using an item, check if the item used is the item to make the OpMon evolve.
            //TODO : Update this method for the new item system

            /*if(used->getItemTypeID() == ItemType::IHeal) {

                I_Item *usedI = used;
                if(usedI->getHpHeal() > 0) {
                    heal(usedI->getHpHeal());
                }
                if(usedI->isHealAll() && status == Status::NOTHING) {
                    setStatus(Status::NOTHING);

                } else if(usedI->getStatusHeald() != Status::NOTHING && status == usedI->getStatusHeald()) {
                    setStatus(Status::NOTHING);
                    //Choose HERE the different dialogs to show
                    switch(usedI->getStatusHeald()) {
                    case Status::NOTHING:
                        break;
                    case Status::BURNING:
                        break;
                    case Status::FROZEN:
                        break;
                    case Status::PARALYSED:
                        break;
                    case Status::POISONED:
                        break;
                    case Status::SLEEPING:
                        break;
                    default:
                        break;
                    }
                }
            }
            return false;*/
        }

        Item *OpMon::hold(Item *item) {
            Item *old = held;
            held = item;
            return old;
        }

        void OpMon::traded() {
            expBoost = 1.5;
        }

        void OpMon::evolve() {
            //bool changeName = (nickname == species->getName());
            species = species->getEvolution();
        }

        void OpMon::setStats(int stats[], Attack *attacks[], const Species &species, Type types[]) {
            statATK = stats[0];
            statDEF = stats[1];
            statATKSPE = stats[2];
            statDEFSPE = stats[3];
            statSPE = stats[4];
            statACC = 100;
            statEVA = 100;
            type1 = types[0];
            type2 = types[1];
            this->species = &species;
            this->attacks[0] = attacks[0];
            this->attacks[1] = attacks[1];
            this->attacks[2] = attacks[2];
            this->attacks[3] = attacks[3];
            type1 = types[0];
            type2 = types[1];
        }

        void OpMon::attacked(int hpLost) {
            HP -= hpLost;
            //HP can't go below 0
            HP = (HP < 0) ? 0 : HP;
        }

        //This is some annoying methods.

        int OpMon::changeATK(int power) {
            if(power < 0) {
                for(int i = 0; i > power; i--) {
                    switch(atkChange) {
                    case -6:
                        return -7;
                    case -5:

                        statATK = round(statATK / 1.16);
                        atkChange--;
                        break;
                    case -4:

                        statATK = round(statATK * 0.878788);
                        atkChange--;
                        break;
                    case -3:

                        statATK = round(statATK * 0.825);
                        atkChange--;
                        break;
                    case -2:

                        statATK = round(statATK / 1.25);
                        atkChange--;
                        break;
                    case -1:

                        statATK = round(statATK / 1.34);
                        atkChange--;
                        break;
                    case 0:

                        statATK = round(statATK * 0.67);
                        atkChange--;
                        break;
                    case 1:

                        statATK = round(statATK / 1.5);
                        atkChange--;
                        break;
                    case 2:

                        statATK = round(statATK * 0.75);
                        atkChange--;
                        break;
                    case 3:

                        statATK = round(statATK / 1.25);
                        atkChange--;
                        break;
                    case 4:

                        statATK = round(statATK / 1.2);
                        atkChange--;
                        break;
                    case 5:

                        statATK = round(statATK / 1.1667);
                        atkChange--;
                        break;
                    case 6:

                        statATK = round(statATK * 0.875);
                        atkChange--;
                        break;
                    default:
                        break;
                    }
                }
            } else {
                for(int i = 0; i > power; i--) {
                    switch(atkChange) {
                    case -6:

                        statATK = round(statATK * 1.16);
                        atkChange++;
                        break;
                    case -5:

                        statATK = round(statATK / 0.878788);
                        atkChange++;
                        break;
                    case -4:

                        statATK = round(statATK / 0.825);
                        atkChange++;
                        break;
                    case -3:

                        statATK = round(statATK * 1.25);
                        atkChange++;
                        break;
                    case -2:

                        statATK = round(statATK * 1.34);
                        atkChange++;
                        break;
                    case -1:

                        statATK = round(statATK / 0.67);
                        atkChange++;
                        break;
                    case 0:

                        statATK = round(statATK * 1.5);
                        atkChange++;
                        break;
                    case 1:

                        statATK = round(statATK / 0.75);
                        atkChange++;
                        break;
                    case 2:

                        statATK = round(statATK * 1.25);
                        atkChange++;
                        break;
                    case 3:

                        statATK = round(statATK * 1.2);
                        atkChange++;
                        break;
                    case 4:

                        statATK = round(statATK * 1.1667);
                        atkChange++;
                        break;
                    case 5:

                        statATK = round(statATK / 0.875);
                        atkChange++;
                        break;
                    case 6:
                        return 7;
                    default:
                        break;
                    }
                }
            }

            return power;
        }

        int OpMon::changeACC(int power) {
            if(power < 0) {
                for(int i = 0; i > power; i--) {
                    switch(accChange) {
                    case -6:
                        return -7;
                    case -5:

                        statACC = round(statACC * 0.888);
                        accChange--;
                        break;
                    case -4:

                        statACC = round(statACC / 1.144);
                        accChange--;
                        break;
                    case -3:

                        statACC = round(statACC * 0.858);
                        accChange--;
                        break;
                    case -2:

                        statACC = round(statACC / 1.2);
                        accChange--;
                        break;
                    case -1:

                        statACC = round(statACC / 1.25);
                        accChange--;
                        break;
                    case 0:

                        statACC = round(statACC * 0.75);
                        accChange--;
                        break;
                    case 1:

                        statACC = round(statACC / 1.333);
                        accChange--;
                        break;
                    case 2:

                        statACC = round(statACC * 0.799640);
                        accChange--;
                        break;
                    case 3:

                        statACC = round(statACC * 0.8335);
                        accChange--;
                        break;
                    case 4:

                        statACC = round(statACC / 1.1665);
                        accChange--;
                        break;
                    case 5:

                        statACC = round(statACC * 0.8747657);
                        accChange--;
                        break;
                    case 6:

                        statACC = round(statACC * 0.889);
                        accChange--;
                        break;
                    default:
                        break;
                    }
                }
            } else {

                for(int i = 0; i > power; i--) {
                    switch(accChange) {
                    case -6:

                        statACC = round(statACC / 0.888);
                        accChange++;
                        break;
                    case -5:

                        statACC = round(statACC * 1.144);
                        accChange++;
                        break;
                    case -4:

                        statACC = round(statACC / 0.858);
                        accChange++;
                        break;
                    case -3:

                        statACC = round(statACC * 1.2);
                        accChange++;
                        break;
                    case -2:

                        statACC = round(statACC * 1.25);
                        accChange++;
                        break;
                    case -1:

                        statACC = round(statACC / 0.75);
                        accChange++;
                        break;
                    case 0:

                        statACC = round(statACC * 1.333);
                        accChange++;
                        break;
                    case 1:

                        statACC = round(statACC / 0.799640);
                        accChange++;
                        break;
                    case 2:

                        statACC = round(statACC / 0.8335);
                        accChange++;
                        break;
                    case 3:

                        statACC = round(statACC * 1.1665);
                        accChange++;
                        break;
                    case 4:

                        statACC = round(statACC / 0.8747657);
                        accChange++;
                        break;
                    case 5:

                        statACC = round(statACC / 0.889);
                        accChange++;
                        break;
                    case 6:
                        return 7;
                    default:
                        break;
                    }
                }
            }

            return power;
        }

        int OpMon::changeEVA(int power) {
            if(power < 0) {
                for(int i = 0; i > power; i--) {
                    switch(evaChange) {
                    case -6:
                        return -7;
                    case -5:

                        statEVA = round(statEVA / 1.16);
                        evaChange--;
                        break;
                    case -4:

                        statEVA = round(statEVA * 0.878788);
                        evaChange--;
                        break;
                    case -3:

                        statEVA = round(statEVA * 0.825);
                        evaChange--;
                        break;
                    case -2:

                        statEVA = round(statEVA / 1.25);
                        evaChange--;
                        break;
                    case -1:

                        statEVA = round(statEVA / 1.34);
                        evaChange--;
                        break;
                    case 0:

                        statEVA = round(statEVA * 0.67);
                        evaChange--;
                        break;
                    case 1:

                        statEVA = round(statEVA / 1.5);
                        evaChange--;
                        break;
                    case 2:

                        statEVA = round(statEVA * 0.75);
                        evaChange--;
                        break;
                    case 3:

                        statEVA = round(statEVA / 1.25);
                        evaChange--;
                        break;
                    case 4:

                        statEVA = round(statEVA / 1.2);
                        evaChange--;
                        break;
                    case 5:

                        statEVA = round(statEVA / 1.1667);
                        evaChange--;
                        break;
                    case 6:

                        statEVA = round(statEVA * 0.875);
                        evaChange--;
                        break;
                    default:
                        break;
                    }
                }
            } else {

                for(int i = 0; i > power; i--) {
                    switch(evaChange) {
                    case -6:

                        statEVA = round(statEVA * 1.16);
                        evaChange++;
                        break;
                    case -5:

                        statEVA = round(statEVA / 0.878788);
                        evaChange++;
                        break;
                    case -4:

                        statEVA = round(statEVA / 0.825);
                        evaChange++;
                        break;
                    case -3:

                        statEVA = round(statEVA * 1.25);
                        evaChange++;
                        break;
                    case -2:

                        statEVA = round(statEVA * 1.34);
                        evaChange++;
                        break;
                    case -1:

                        statEVA = round(statEVA / 0.67);
                        evaChange++;
                        break;
                    case 0:

                        statEVA = round(statEVA * 1.5);
                        evaChange++;
                        break;
                    case 1:

                        statEVA = round(statEVA / 0.75);
                        evaChange++;
                        break;
                    case 2:

                        statEVA = round(statEVA * 1.25);
                        evaChange++;
                        break;
                    case 3:

                        statEVA = round(statEVA * 1.2);
                        evaChange++;
                        break;
                    case 4:

                        statEVA = round(statEVA * 1.1667);
                        evaChange++;
                        break;
                    case 5:

                        statEVA = round(statEVA / 0.875);
                        evaChange++;
                        break;
                    case 6:
                        return 7;
                    default:
                        break;
                    }
                }
            }

            return power;
        }

        int OpMon::changeDEF(int power) {
            if(power < 0) {
                for(int i = 0; i > power; i--) {
                    switch(defChange) {
                    case -6:
                        return -7;
                    case -5:

                        statDEF = round(statDEF / 1.16);
                        defChange--;
                        break;
                    case -4:

                        statDEF = round(statDEF * 0.878788);
                        defChange--;
                        break;
                    case -3:

                        statDEF = round(statDEF * 0.825);
                        defChange--;
                        break;
                    case -2:

                        statDEF = round(statDEF / 1.25);
                        defChange--;
                        break;
                    case -1:

                        statDEF = round(statDEF / 1.34);
                        defChange--;
                        break;
                    case 0:

                        statDEF = round(statDEF * 0.67);
                        defChange--;
                        break;
                    case 1:

                        statDEF = round(statDEF / 1.5);
                        defChange--;
                        break;
                    case 2:

                        statDEF = round(statDEF * 0.75);
                        defChange--;
                        break;
                    case 3:

                        statDEF = round(statDEF / 1.25);
                        defChange--;
                        break;
                    case 4:

                        statDEF = round(statDEF / 1.2);
                        defChange--;
                        break;
                    case 5:

                        statDEF = round(statDEF / 1.1667);
                        defChange--;
                        break;
                    case 6:

                        statDEF = round(statDEF * 0.875);
                        defChange--;
                        break;
                    default:
                        break;
                    }
                }
            } else {

                for(int i = 0; i > power; i--) {
                    switch(defChange) {
                    case -6:

                        statDEF = round(statDEF * 1.16);
                        defChange++;
                        break;
                    case -5:

                        statDEF = round(statDEF / 0.878788);
                        defChange++;
                        break;
                    case -4:

                        statDEF = round(statDEF / 0.825);
                        defChange++;
                        break;
                    case -3:

                        statDEF = round(statDEF * 1.25);
                        defChange++;
                        break;
                    case -2:

                        statDEF = round(statDEF * 1.34);
                        defChange++;
                        break;
                    case -1:

                        statDEF = round(statDEF / 0.67);
                        defChange++;
                        break;
                    case 0:

                        statDEF = round(statDEF * 1.5);
                        defChange++;
                        break;
                    case 1:

                        statDEF = round(statDEF / 0.75);
                        defChange++;
                        break;
                    case 2:

                        statDEF = round(statDEF * 1.25);
                        defChange++;
                        break;
                    case 3:

                        statDEF = round(statDEF * 1.2);
                        defChange++;
                        break;
                    case 4:

                        statDEF = round(statDEF * 1.1667);
                        defChange++;
                        break;
                    case 5:

                        statDEF = round(statDEF / 0.875);
                        defChange++;
                        break;
                    case 6:
                        return 7;

                    default:
                        break;
                    }
                }
            }
            return power;
        }

        int OpMon::changeATKSPE(int power) {
            if(power < 0) {
                for(int i = 0; i > power; i--) {
                    switch(atkSpeChange) {
                    case -6:
                        return -7;
                    case -5:

                        statATKSPE = round(statATKSPE / 1.16);
                        atkSpeChange--;
                        break;
                    case -4:

                        statATKSPE = round(statATKSPE * 0.878788);
                        atkSpeChange--;
                        break;
                    case -3:

                        statATKSPE = round(statATKSPE * 0.825);
                        atkSpeChange--;
                        break;
                    case -2:

                        statATKSPE = round(statATKSPE / 1.25);
                        atkSpeChange--;
                        break;
                    case -1:

                        statATKSPE = round(statATKSPE / 1.34);
                        atkSpeChange--;
                        break;
                    case 0:

                        statATKSPE = round(statATKSPE * 0.67);
                        atkSpeChange--;
                        break;
                    case 1:

                        statATKSPE = round(statATKSPE / 1.5);
                        atkSpeChange--;
                        break;
                    case 2:

                        statATKSPE = round(statATKSPE * 0.75);
                        atkSpeChange--;
                        break;
                    case 3:

                        statATKSPE = round(statATKSPE / 1.25);
                        atkSpeChange--;
                        break;
                    case 4:

                        statATKSPE = round(statATKSPE / 1.2);
                        atkSpeChange--;
                        break;
                    case 5:

                        statATKSPE = round(statATKSPE / 1.1667);
                        atkSpeChange--;
                        break;
                    case 6:

                        statATKSPE = round(statATKSPE * 0.875);
                        atkSpeChange--;
                        break;
                    default:
                        break;
                    }
                }
            } else {

                for(int i = 0; i > power; i--) {
                    switch(atkSpeChange) {
                    case -6:

                        statATKSPE = round(statATKSPE * 1.16);
                        atkSpeChange++;
                        break;
                    case -5:

                        statATKSPE = round(statATKSPE / 0.878788);
                        atkSpeChange++;
                        break;
                    case -4:

                        statATKSPE = round(statATKSPE / 0.825);
                        atkSpeChange++;
                        break;
                    case -3:

                        statATKSPE = round(statATKSPE * 1.25);
                        atkSpeChange++;
                        break;
                    case -2:

                        statATKSPE = round(statATKSPE * 1.34);
                        atkSpeChange++;
                        break;
                    case -1:

                        statATKSPE = round(statATKSPE / 0.67);
                        atkSpeChange++;
                        break;
                    case 0:

                        statATKSPE = round(statATKSPE * 1.5);
                        atkSpeChange++;
                        break;
                    case 1:

                        statATKSPE = round(statATKSPE / 0.75);
                        atkSpeChange++;
                        break;
                    case 2:

                        statATKSPE = round(statATKSPE * 1.25);
                        atkSpeChange++;
                        break;
                    case 3:

                        statATKSPE = round(statATKSPE * 1.2);
                        atkSpeChange++;
                        break;
                    case 4:

                        statATKSPE = round(statATKSPE * 1.1667);
                        atkSpeChange++;
                        break;
                    case 5:

                        statATKSPE = round(statATKSPE / 0.875);
                        atkSpeChange++;
                        break;
                    case 6:
                        return 7;
                    default:
                        break;
                    }
                }
            }
            return power;
        }

        int OpMon::changeDEFSPE(int power) {
            if(power < 0) {
                for(int i = 0; i > power; i--) {
                    switch(defSpeChange) {
                    case -6:
                        return -7;
                    case -5:

                        statDEFSPE = round(statDEFSPE / 1.16);
                        defSpeChange--;
                        break;
                    case -4:

                        statDEFSPE = round(statDEFSPE * 0.878788);
                        defSpeChange--;
                        break;
                    case -3:

                        statDEFSPE = round(statDEFSPE * 0.825);
                        defSpeChange--;
                        break;
                    case -2:

                        statDEFSPE = round(statDEFSPE / 1.25);
                        defSpeChange--;
                        break;
                    case -1:

                        statDEFSPE = round(statDEFSPE / 1.34);
                        defSpeChange--;
                        break;
                    case 0:

                        statDEFSPE = round(statDEFSPE * 0.67);
                        defSpeChange--;
                        break;
                    case 1:

                        statDEFSPE = round(statDEFSPE / 1.5);
                        defSpeChange--;
                        break;
                    case 2:

                        statDEFSPE = round(statDEFSPE * 0.75);
                        defSpeChange--;
                        break;
                    case 3:

                        statDEFSPE = round(statDEFSPE / 1.25);
                        defSpeChange--;
                        break;
                    case 4:

                        statDEFSPE = round(statDEFSPE / 1.2);
                        defSpeChange--;
                        break;
                    case 5:

                        statDEFSPE = round(statDEFSPE / 1.1667);
                        defSpeChange--;
                        break;
                    case 6:

                        statDEFSPE = round(statDEFSPE * 0.875);
                        defSpeChange--;
                        break;
                    default:
                        break;
                    }
                }
            } else {

                for(int i = 0; i > power; i--) {
                    switch(defSpeChange) {
                    case -6:

                        statDEFSPE = round(statDEFSPE * 1.16);
                        defSpeChange++;
                        break;
                    case -5:

                        statDEFSPE = round(statDEFSPE / 0.878788);
                        defSpeChange++;
                        break;
                    case -4:

                        statDEFSPE = round(statDEFSPE / 0.825);
                        defSpeChange++;
                        break;
                    case -3:

                        statDEFSPE = round(statDEFSPE * 1.25);
                        defSpeChange++;
                        break;
                    case -2:

                        statDEFSPE = round(statDEFSPE * 1.34);
                        defSpeChange++;
                        break;
                    case -1:

                        statDEFSPE = round(statDEFSPE / 0.67);
                        defSpeChange++;
                        break;
                    case 0:

                        statDEFSPE = round(statDEFSPE * 1.5);
                        defSpeChange++;
                        break;
                    case 1:

                        statDEFSPE = round(statDEFSPE / 0.75);
                        defSpeChange++;
                        break;
                    case 2:

                        statDEFSPE = round(statDEFSPE * 1.25);
                        defSpeChange++;
                        break;
                    case 3:

                        statDEFSPE = round(statDEFSPE * 1.2);
                        defSpeChange++;
                        break;
                    case 4:

                        statDEFSPE = round(statDEFSPE * 1.1667);
                        defSpeChange++;
                        break;
                    case 5:

                        statDEFSPE = round(statDEFSPE / 0.875);
                        defSpeChange++;
                        break;
                    case 6:
                        return 7;
                    default:
                        break;
                    }
                }
            }
            return power;
        }

        int OpMon::changeSPE(int power) {
            if(power < 0) {
                for(int i = 0; i > power; i--) {
                    switch(speChange) {
                    case -6:
                        return -7;
                    case -5:

                        statSPE = round(statSPE / 1.16);

                        speChange--;
                        break;
                    case -4:

                        statSPE = round(statSPE * 0.878788);
                        speChange--;
                        break;
                    case -3:

                        statSPE = round(statSPE * 0.825);
                        speChange--;
                        break;
                    case -2:

                        statSPE = round(statSPE / 1.25);
                        speChange--;
                        break;
                    case -1:

                        statSPE = round(statSPE / 1.34);
                        speChange--;
                        break;
                    case 0:

                        statSPE = round(statSPE * 0.67);
                        speChange--;
                        break;
                    case 1:

                        statSPE = round(statSPE / 1.5);
                        speChange--;
                        break;
                    case 2:

                        statSPE = round(statSPE * 0.75);
                        speChange--;
                        break;
                    case 3:

                        statSPE = round(statSPE / 1.25);
                        speChange--;
                        break;
                    case 4:

                        statSPE = round(statSPE / 1.2);
                        speChange--;
                        break;
                    case 5:

                        statSPE = round(statSPE / 1.1667);
                        speChange--;
                        break;
                    case 6:

                        statSPE = round(statSPE * 0.875);
                        speChange--;
                        break;
                    default:
                        break;
                    }
                }
            } else {

                for(int i = 0; i > power; i--) {
                    switch(speChange) {
                    case -6:

                        statSPE = round(statSPE * 1.16);
                        speChange++;
                        break;
                    case -5:

                        statSPE = round(statSPE / 0.878788);
                        speChange++;
                        break;
                    case -4:

                        statSPE = round(statSPE / 0.825);
                        speChange++;
                        break;
                    case -3:

                        statSPE = round(statSPE * 1.25);
                        speChange++;
                        break;
                    case -2:

                        statSPE = round(statSPE * 1.34);
                        speChange++;
                        break;
                    case -1:

                        statSPE = round(statSPE / 0.67);
                        speChange++;
                        break;
                    case 0:

                        statSPE = round(statSPE * 1.5);
                        speChange++;
                        break;
                    case 1:

                        statSPE = round(statSPE / 0.75);
                        speChange++;
                        break;
                    case 2:

                        statSPE = round(statSPE * 1.25);
                        speChange++;
                        break;
                    case 3:

                        statSPE = round(statSPE * 1.2);
                        speChange++;
                        break;
                    case 4:

                        statSPE = round(statSPE * 1.1667);
                        speChange++;
                        break;
                    case 5:

                        statSPE = round(statSPE / 0.875);
                        speChange++;
                        break;
                    case 6:
                        return 7;
                    default:
                        break;
                    }
                }
            }
            return power;
        }

        bool OpMon::setStatus(Status status) {
            if(this->status == status) {
                return false;
            } else if(status != Status::NOTHING) { //If the OpMon already has a special status
                return false;
            }
            //Some status needs to edit the stats
            if(status == Status::BURNING) {
                changeATK(-1);
                atkChange++;
            } else if(status == Status::NOTHING && this->status == Status::BURNING) {
                changeATK(1);
                atkChange--;
            } else if(status == Status::PARALYSED) {
                changeSPE(-1);
                speChange++;
            } else if(status == Status::NOTHING && this->status == Status::PARALYSED) {
                changeSPE(1);
                speChange--;
            }
            this->status = status;
            return true;
        }

        void OpMon::heal(int HP) {
            this->HP = std::min(statHP, HP + this->HP);
        }

        void OpMon::setType1(Type type) {
            this->type1 = type;
        }

        void OpMon::setType2(Type type) {
            this->type2 = type;
        }

        //I'll redo this soon

        std::string OpMon::save() {
            if(!initialized) {
	      /*
                std::ostringstream oss;
                oss << nickname.toAnsiString() << std::endl;
                oss << Save::intToChar(atkIV) << std::endl;
                oss << Save::intToChar(defIV) << std::endl;
                oss << Save::intToChar(atkSpeIV) << std::endl;
                oss << Save::intToChar(defSpeIV) << std::endl;
                oss << Save::intToChar(speIV) << std::endl;
                oss << Save::intToChar(hpIV) << std::endl;
                oss << Save::intToChar(atkEV) << std::endl;
                oss << Save::intToChar(defEV) << std::endl;
                oss << Save::intToChar(atkSpeEV) << std::endl;
                oss << Save::intToChar(defSpeEV) << std::endl;
                oss << Save::intToChar(speEV) << std::endl;
                oss << Save::intToChar(hpEV) << std::endl;
                oss << Save::intToChar(statLove) << std::endl;
                oss << Save::intToChar(level) << std::endl;
                oss << Save::intToChar(natures[(int)nature].id) << std::endl;*/
                /*for(unsigned int it = 0; it < 4; it++){
                cout << "Attack : " << it << " Pointer : " << attaques[it] << endl;
                Attack *atk = attaques[it];
                cout << "Pointer : " << atk << endl;
                if(atk != nullptr){
                    cout << "Attack no NULL" << endl;
                    oss << atk->save();
                }else{
                    cout << "Attack nullptr" << endl;
                    oss << "nullptr" << endl;
                }
            }*/
                /*for(int i = 0; i < 4; i++) {
                    if(attacks[i] != nullptr)
                        oss << attacks[i]->save();
                    else
                        oss << "NULL" << std::endl;
                }
                oss << Save::intToChar(species->getOpdexNumber()) << std::endl;
                oss << Save::intToChar(HP) << std::endl;
                oss << Save::intToChar(exp) << std::endl;
                oss << Save::intToChar(toNextLevel) << std::endl;
                oss << Save::intToChar(expBoost * 10) << std::endl;
                if(held != nullptr) {
                    oss << "Y" << std::endl;
                    oss << Save::intToChar(held->getID()) << std::endl;
                } else {
                    oss << "N" << std::endl;
                    oss << std::endl;
                }
                oss << Save::intToChar(captureRate) << std::endl;
                return oss.str();*/
            } else {
                return "NULL\n";
		}
        }
        /*
        OpMon::OpMon(std::ifstream &in) {
            this->nickname = Save::readLine(in);
            if(nickname != "NULL") {
                atkIV = in.get();
                in.get();
                defIV = in.get();
                in.get();
                atkSpeIV = in.get();
                in.get();
                defSpeIV = in.get();
                in.get();
                speIV = in.get();
                in.get();
                hpIV = in.get();
                in.get();
                atkEV = in.get();
                in.get();
                defEV = in.get();
                in.get();
                atkSpeEV = in.get();
                in.get();
                defSpeEV = in.get();
                in.get();
                speEV = in.get();
                in.get();

                hpEV = in.get();
                in.get();
                statLove = in.get();
                in.get();

                level = in.get();
                in.get();
                //int toSearch = in.get();
                //nature = toSearch;
                in.get();

                for(int i = 0; i < 4; i++) {
                    attacks[i] = Attacks::newAtk(Save::readLine(in));
                    if(attacks[i] != nullptr) {
                        attacks[i]->setPP(in.get());
                        in.get();
                        attacks[i]->setPPMax(in.get());
                        in.get();
                    }
                }
                //int speciesID = in.get();
                //species = Data::OpMons::listOp.at(speciesID);
                in.get();
                HP = in.get();
                in.get();
                exp = in.get();
                in.get();
                toNextLevel = in.get();
                in.get();
                expBoost = in.get() / 10.0;
                in.get();
                if(Save::intToChar(in.get()) == 'Y') {
                    in.get();
                    held = Item::itemsLst[in.get()];
                    in.get();
                } else {
                    in.get();
                    held = nullptr;
                    in.get();
                }
                captureRate = in.get();
                in.get();
                calcStats();
                type1 = species->getType1();
                type2 = species->getType2();
                statACC = 100;
                statEVA = 100;
                initialized = false;
            } else {
                initialized = true;
            }
        }
		*/

        void OpMon::passCD(bool sleep) {
            if(confusedCD > 0 && !sleep) {
                confusedCD--;
            } else if(sleepingCD > 0 && sleep) {
                sleepingCD--;
            }
        }

    } // namespace Model
} // namespace OpMon
