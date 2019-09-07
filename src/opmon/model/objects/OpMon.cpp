/*
OpMon.cpp
Author : Cyrielle
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
#include "Item.hpp"
#include <fstream>
#include <sstream>
#include <utility>

namespace OpMon::Model {

    OpMon::~OpMon() {
        for(int i = 0; i < 4; i++) {
            delete(attacks[i]);
        }
    }

    OpMon::OpMon(const std::string &nickname, const Species *species, int level, std::vector<Attack *> attacks, Nature nature)
      : nickname((nickname.empty()) ? species->getName() : nickname)
      , species(species)
      , level(level)
      , attacks(std::move(attacks))
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
        float statusCoef = 1.f;
        if (status == Status::PARALYSED || status == Status::POISONED || status == Status::BURNING) {
            statusCoef = 1.5f;
        } else if (status == Status::FROZEN || status == Status::SLEEPING) {
            statusCoef = 2.f;
        }
        auto a = std::round(
            (1.f - (2.f * float(HP)) / (3.f * float(statHP)))
          * float(captureRate)
          * statusCoef); // TODO factor in OpBox.getCaptureRate()
        auto b = std::round(
            (std::pow(2, 16) - 1)
          * std::pow(a / (std::pow(2, 8) - 1), 0.25));
        int c[] = {
          Utils::Misc::randU(65535),
          Utils::Misc::randU(65535),
          Utils::Misc::randU(65535),
          Utils::Misc::randU(65535)
        };
        int nbreOk = 0;
        for(int i : c) {
            if(i <= b) {
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
            statACC = float(newStat);
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
        auto expWon = int(float(defeated.species->getExp() * defeated.level) / float(this->level) * expBoost);
        exp += expWon;
        //Handles the level won. The loops allows to increase the level as long as there is exp.
        while(exp >= toNextLevel && level < 100) {
            if(exp < toNextLevel) {
                break;
            }
            levelUp();
        }
        calcStats();
        return expWon;
    }

    void OpMon::getEvs(OpMon const &defeated) {
        //If the total of the EV is over 510, don't add EVs, since 510 is the maximum.
        if(atkEV + defEV + hpEV + atkSpeEV + defSpeEV + speEV <= 510) {
            std::vector<Stats> statsDefeated;
            for(unsigned int i = 0; i < defeated.species->getEv().size(); i++) {
                statsDefeated.push_back(defeated.species->getEv()[i]);
            }

            for(auto & i : statsDefeated) {
                switch(i) {
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
        auto statFun = [this](unsigned int base, int IV, int EV, Stats affectedStat) -> int {
            float natureCoef = 1.f;
            if (natures[static_cast<int>(nature)].bonus == affectedStat) {
                natureCoef = 1.1f;
            } else if (natures[static_cast<int>(nature)].malus == affectedStat) {
                natureCoef = 0.9f;
            }
            return int( float((2 * base + IV + (EV / 4)) * level / 100 + 5) * natureCoef );
        };
        statATK = statFun(species->getBaseAtk(), atkIV, atkEV, Stats::ATK);
        statDEF = statFun(species->getBaseDef(), defIV, defEV, Stats::DEF);
        statATKSPE = statFun(species->getBaseAtkSpe(), atkSpeIV, atkSpeEV, Stats::ATKSPE);
        statDEFSPE = statFun(species->getBaseDefSpe(), defSpeIV, defSpeEV, Stats::DEFSPE);
        statHP = int(((2 * species->getBaseHP() + hpIV + (hpEV / 4)) * level) / 100) + level + 10;
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

    void OpMon::setStats(const int _stats[], Attack *_attacks[], const Species &_species, Type types[]) {
        statATK = _stats[0];
        statDEF = _stats[1];
        statATKSPE = _stats[2];
        statDEFSPE = _stats[3];
        statSPE = _stats[4];
        statACC = 100;
        statEVA = 100;
        type1 = types[0];
        type2 = types[1];
        this->species = &_species;
        this->attacks[0] = _attacks[0];
        this->attacks[1] = _attacks[1];
        this->attacks[2] = _attacks[2];
        this->attacks[3] = _attacks[3];
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

                    statATK = int(statATK / 1.16);
                    atkChange--;
                    break;
                case -4:

                    statATK = int(statATK * 0.878788);
                    atkChange--;
                    break;
                case -3:

                    statATK = int(statATK * 0.825);
                    atkChange--;
                    break;
                case -2:

                    statATK = int(statATK / 1.25);
                    atkChange--;
                    break;
                case -1:

                    statATK = int(statATK / 1.34);
                    atkChange--;
                    break;
                case 0:

                    statATK = int(statATK * 0.67);
                    atkChange--;
                    break;
                case 1:

                    statATK = int(statATK / 1.5);
                    atkChange--;
                    break;
                case 2:

                    statATK = int(statATK * 0.75);
                    atkChange--;
                    break;
                case 3:

                    statATK = int(statATK / 1.25);
                    atkChange--;
                    break;
                case 4:

                    statATK = int(statATK / 1.2);
                    atkChange--;
                    break;
                case 5:

                    statATK = int(statATK / 1.1667);
                    atkChange--;
                    break;
                case 6:

                    statATK = int(statATK * 0.875);
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

                    statATK = int(statATK * 1.16);
                    atkChange++;
                    break;
                case -5:

                    statATK = int(statATK / 0.878788);
                    atkChange++;
                    break;
                case -4:

                    statATK = int(statATK / 0.825);
                    atkChange++;
                    break;
                case -3:

                    statATK = int(statATK * 1.25);
                    atkChange++;
                    break;
                case -2:

                    statATK = int(statATK * 1.34);
                    atkChange++;
                    break;
                case -1:

                    statATK = int(statATK / 0.67);
                    atkChange++;
                    break;
                case 0:

                    statATK = int(statATK * 1.5);
                    atkChange++;
                    break;
                case 1:

                    statATK = int(statATK / 0.75);
                    atkChange++;
                    break;
                case 2:

                    statATK = int(statATK * 1.25);
                    atkChange++;
                    break;
                case 3:

                    statATK = int(statATK * 1.2);
                    atkChange++;
                    break;
                case 4:

                    statATK = int(statATK * 1.1667);
                    atkChange++;
                    break;
                case 5:

                    statATK = int(statATK / 0.875);
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

                    statACC = std::round(statACC * 0.888f);
                    accChange--;
                    break;
                case -4:

                    statACC = std::round(statACC / 1.144f);
                    accChange--;
                    break;
                case -3:

                    statACC = std::round(statACC * 0.858f);
                    accChange--;
                    break;
                case -2:

                    statACC = std::round(statACC / 1.2f);
                    accChange--;
                    break;
                case -1:

                    statACC = std::round(statACC / 1.25f);
                    accChange--;
                    break;
                case 0:

                    statACC = std::round(statACC * 0.75f);
                    accChange--;
                    break;
                case 1:

                    statACC = std::round(statACC / 1.333f);
                    accChange--;
                    break;
                case 2:

                    statACC = std::round(statACC * 0.799640f);
                    accChange--;
                    break;
                case 3:

                    statACC = std::round(statACC * 0.8335f);
                    accChange--;
                    break;
                case 4:

                    statACC = std::round(statACC / 1.1665f);
                    accChange--;
                    break;
                case 5:

                    statACC = std::round(statACC * 0.8747657f);
                    accChange--;
                    break;
                case 6:

                    statACC = std::round(statACC * 0.889f);
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

                    statACC = std::round(statACC / 0.888f);
                    accChange++;
                    break;
                case -5:

                    statACC = std::round(statACC * 1.144f);
                    accChange++;
                    break;
                case -4:

                    statACC = std::round(statACC / 0.858f);
                    accChange++;
                    break;
                case -3:

                    statACC = std::round(statACC * 1.2f);
                    accChange++;
                    break;
                case -2:

                    statACC = std::round(statACC * 1.25f);
                    accChange++;
                    break;
                case -1:

                    statACC = std::round(statACC / 0.75f);
                    accChange++;
                    break;
                case 0:

                    statACC = std::round(statACC * 1.333f);
                    accChange++;
                    break;
                case 1:

                    statACC = std::round(statACC / 0.799640f);
                    accChange++;
                    break;
                case 2:

                    statACC = std::round(statACC / 0.8335f);
                    accChange++;
                    break;
                case 3:

                    statACC = std::round(statACC * 1.1665f);
                    accChange++;
                    break;
                case 4:

                    statACC = std::round(statACC / 0.8747657f);
                    accChange++;
                    break;
                case 5:

                    statACC = std::round(statACC / 0.889f);
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

                    statEVA = int(statEVA / 1.16);
                    evaChange--;
                    break;
                case -4:

                    statEVA = int(statEVA * 0.878788);
                    evaChange--;
                    break;
                case -3:

                    statEVA = int(statEVA * 0.825);
                    evaChange--;
                    break;
                case -2:

                    statEVA = int(statEVA / 1.25);
                    evaChange--;
                    break;
                case -1:

                    statEVA = int(statEVA / 1.34);
                    evaChange--;
                    break;
                case 0:

                    statEVA = int(statEVA * 0.67);
                    evaChange--;
                    break;
                case 1:

                    statEVA = int(statEVA / 1.5);
                    evaChange--;
                    break;
                case 2:

                    statEVA = int(statEVA * 0.75);
                    evaChange--;
                    break;
                case 3:

                    statEVA = int(statEVA / 1.25);
                    evaChange--;
                    break;
                case 4:

                    statEVA = int(statEVA / 1.2);
                    evaChange--;
                    break;
                case 5:

                    statEVA = int(statEVA / 1.1667);
                    evaChange--;
                    break;
                case 6:

                    statEVA = int(statEVA * 0.875);
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

                    statEVA = int(statEVA * 1.16);
                    evaChange++;
                    break;
                case -5:

                    statEVA = int(statEVA / 0.878788);
                    evaChange++;
                    break;
                case -4:

                    statEVA = int(statEVA / 0.825);
                    evaChange++;
                    break;
                case -3:

                    statEVA = int(statEVA * 1.25);
                    evaChange++;
                    break;
                case -2:

                    statEVA = int(statEVA * 1.34);
                    evaChange++;
                    break;
                case -1:

                    statEVA = int(statEVA / 0.67);
                    evaChange++;
                    break;
                case 0:

                    statEVA = int(statEVA * 1.5);
                    evaChange++;
                    break;
                case 1:

                    statEVA = int(statEVA / 0.75);
                    evaChange++;
                    break;
                case 2:

                    statEVA = int(statEVA * 1.25);
                    evaChange++;
                    break;
                case 3:

                    statEVA = int(statEVA * 1.2);
                    evaChange++;
                    break;
                case 4:

                    statEVA = int(statEVA * 1.1667);
                    evaChange++;
                    break;
                case 5:

                    statEVA = int(statEVA / 0.875);
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

                    statDEF = int(statDEF / 1.16);
                    defChange--;
                    break;
                case -4:

                    statDEF = int(statDEF * 0.878788);
                    defChange--;
                    break;
                case -3:

                    statDEF = int(statDEF * 0.825);
                    defChange--;
                    break;
                case -2:

                    statDEF = int(statDEF / 1.25);
                    defChange--;
                    break;
                case -1:

                    statDEF = int(statDEF / 1.34);
                    defChange--;
                    break;
                case 0:

                    statDEF = int(statDEF * 0.67);
                    defChange--;
                    break;
                case 1:

                    statDEF = int(statDEF / 1.5);
                    defChange--;
                    break;
                case 2:

                    statDEF = int(statDEF * 0.75);
                    defChange--;
                    break;
                case 3:

                    statDEF = int(statDEF / 1.25);
                    defChange--;
                    break;
                case 4:

                    statDEF = int(statDEF / 1.2);
                    defChange--;
                    break;
                case 5:

                    statDEF = int(statDEF / 1.1667);
                    defChange--;
                    break;
                case 6:

                    statDEF = int(statDEF * 0.875);
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

                    statDEF = int(statDEF * 1.16);
                    defChange++;
                    break;
                case -5:

                    statDEF = int(statDEF / 0.878788);
                    defChange++;
                    break;
                case -4:

                    statDEF = int(statDEF / 0.825);
                    defChange++;
                    break;
                case -3:

                    statDEF = int(statDEF * 1.25);
                    defChange++;
                    break;
                case -2:

                    statDEF = int(statDEF * 1.34);
                    defChange++;
                    break;
                case -1:

                    statDEF = int(statDEF / 0.67);
                    defChange++;
                    break;
                case 0:

                    statDEF = int(statDEF * 1.5);
                    defChange++;
                    break;
                case 1:

                    statDEF = int(statDEF / 0.75);
                    defChange++;
                    break;
                case 2:

                    statDEF = int(statDEF * 1.25);
                    defChange++;
                    break;
                case 3:

                    statDEF = int(statDEF * 1.2);
                    defChange++;
                    break;
                case 4:

                    statDEF = int(statDEF * 1.1667);
                    defChange++;
                    break;
                case 5:

                    statDEF = int(statDEF / 0.875);
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

                    statATKSPE = int(statATKSPE / 1.16);
                    atkSpeChange--;
                    break;
                case -4:

                    statATKSPE = int(statATKSPE * 0.878788);
                    atkSpeChange--;
                    break;
                case -3:

                    statATKSPE = int(statATKSPE * 0.825);
                    atkSpeChange--;
                    break;
                case -2:

                    statATKSPE = int(statATKSPE / 1.25);
                    atkSpeChange--;
                    break;
                case -1:

                    statATKSPE = int(statATKSPE / 1.34);
                    atkSpeChange--;
                    break;
                case 0:

                    statATKSPE = int(statATKSPE * 0.67);
                    atkSpeChange--;
                    break;
                case 1:

                    statATKSPE = int(statATKSPE / 1.5);
                    atkSpeChange--;
                    break;
                case 2:

                    statATKSPE = int(statATKSPE * 0.75);
                    atkSpeChange--;
                    break;
                case 3:

                    statATKSPE = int(statATKSPE / 1.25);
                    atkSpeChange--;
                    break;
                case 4:

                    statATKSPE = int(statATKSPE / 1.2);
                    atkSpeChange--;
                    break;
                case 5:

                    statATKSPE = int(statATKSPE / 1.1667);
                    atkSpeChange--;
                    break;
                case 6:

                    statATKSPE = int(statATKSPE * 0.875);
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

                    statATKSPE = int(statATKSPE * 1.16);
                    atkSpeChange++;
                    break;
                case -5:

                    statATKSPE = int(statATKSPE / 0.878788);
                    atkSpeChange++;
                    break;
                case -4:

                    statATKSPE = int(statATKSPE / 0.825);
                    atkSpeChange++;
                    break;
                case -3:

                    statATKSPE = int(statATKSPE * 1.25);
                    atkSpeChange++;
                    break;
                case -2:

                    statATKSPE = int(statATKSPE * 1.34);
                    atkSpeChange++;
                    break;
                case -1:

                    statATKSPE = int(statATKSPE / 0.67);
                    atkSpeChange++;
                    break;
                case 0:

                    statATKSPE = int(statATKSPE * 1.5);
                    atkSpeChange++;
                    break;
                case 1:

                    statATKSPE = int(statATKSPE / 0.75);
                    atkSpeChange++;
                    break;
                case 2:

                    statATKSPE = int(statATKSPE * 1.25);
                    atkSpeChange++;
                    break;
                case 3:

                    statATKSPE = int(statATKSPE * 1.2);
                    atkSpeChange++;
                    break;
                case 4:

                    statATKSPE = int(statATKSPE * 1.1667);
                    atkSpeChange++;
                    break;
                case 5:

                    statATKSPE = int(statATKSPE / 0.875);
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

                    statDEFSPE = int(statDEFSPE / 1.16);
                    defSpeChange--;
                    break;
                case -4:

                    statDEFSPE = int(statDEFSPE * 0.878788);
                    defSpeChange--;
                    break;
                case -3:

                    statDEFSPE = int(statDEFSPE * 0.825);
                    defSpeChange--;
                    break;
                case -2:

                    statDEFSPE = int(statDEFSPE / 1.25);
                    defSpeChange--;
                    break;
                case -1:

                    statDEFSPE = int(statDEFSPE / 1.34);
                    defSpeChange--;
                    break;
                case 0:

                    statDEFSPE = int(statDEFSPE * 0.67);
                    defSpeChange--;
                    break;
                case 1:

                    statDEFSPE = int(statDEFSPE / 1.5);
                    defSpeChange--;
                    break;
                case 2:

                    statDEFSPE = int(statDEFSPE * 0.75);
                    defSpeChange--;
                    break;
                case 3:

                    statDEFSPE = int(statDEFSPE / 1.25);
                    defSpeChange--;
                    break;
                case 4:

                    statDEFSPE = int(statDEFSPE / 1.2);
                    defSpeChange--;
                    break;
                case 5:

                    statDEFSPE = int(statDEFSPE / 1.1667);
                    defSpeChange--;
                    break;
                case 6:

                    statDEFSPE = int(statDEFSPE * 0.875);
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

                    statDEFSPE = int(statDEFSPE * 1.16);
                    defSpeChange++;
                    break;
                case -5:

                    statDEFSPE = int(statDEFSPE / 0.878788);
                    defSpeChange++;
                    break;
                case -4:

                    statDEFSPE = int(statDEFSPE / 0.825);
                    defSpeChange++;
                    break;
                case -3:

                    statDEFSPE = int(statDEFSPE * 1.25);
                    defSpeChange++;
                    break;
                case -2:

                    statDEFSPE = int(statDEFSPE * 1.34);
                    defSpeChange++;
                    break;
                case -1:

                    statDEFSPE = int(statDEFSPE / 0.67);
                    defSpeChange++;
                    break;
                case 0:

                    statDEFSPE = int(statDEFSPE * 1.5);
                    defSpeChange++;
                    break;
                case 1:

                    statDEFSPE = int(statDEFSPE / 0.75);
                    defSpeChange++;
                    break;
                case 2:

                    statDEFSPE = int(statDEFSPE * 1.25);
                    defSpeChange++;
                    break;
                case 3:

                    statDEFSPE = int(statDEFSPE * 1.2);
                    defSpeChange++;
                    break;
                case 4:

                    statDEFSPE = int(statDEFSPE * 1.1667);
                    defSpeChange++;
                    break;
                case 5:

                    statDEFSPE = int(statDEFSPE / 0.875);
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

                    statSPE = int(statSPE / 1.16);

                    speChange--;
                    break;
                case -4:

                    statSPE = int(statSPE * 0.878788);
                    speChange--;
                    break;
                case -3:

                    statSPE = int(statSPE * 0.825);
                    speChange--;
                    break;
                case -2:

                    statSPE = int(statSPE / 1.25);
                    speChange--;
                    break;
                case -1:

                    statSPE = int(statSPE / 1.34);
                    speChange--;
                    break;
                case 0:

                    statSPE = int(statSPE * 0.67);
                    speChange--;
                    break;
                case 1:

                    statSPE = int(statSPE / 1.5);
                    speChange--;
                    break;
                case 2:

                    statSPE = int(statSPE * 0.75);
                    speChange--;
                    break;
                case 3:

                    statSPE = int(statSPE / 1.25);
                    speChange--;
                    break;
                case 4:

                    statSPE = int(statSPE / 1.2);
                    speChange--;
                    break;
                case 5:

                    statSPE = int(statSPE / 1.1667);
                    speChange--;
                    break;
                case 6:

                    statSPE = int(statSPE * 0.875);
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

                    statSPE = int(statSPE * 1.16);
                    speChange++;
                    break;
                case -5:

                    statSPE = int(statSPE / 0.878788);
                    speChange++;
                    break;
                case -4:

                    statSPE = int(statSPE / 0.825);
                    speChange++;
                    break;
                case -3:

                    statSPE = int(statSPE * 1.25);
                    speChange++;
                    break;
                case -2:

                    statSPE = int(statSPE * 1.34);
                    speChange++;
                    break;
                case -1:

                    statSPE = int(statSPE / 0.67);
                    speChange++;
                    break;
                case 0:

                    statSPE = int(statSPE * 1.5);
                    speChange++;
                    break;
                case 1:

                    statSPE = int(statSPE / 0.75);
                    speChange++;
                    break;
                case 2:

                    statSPE = int(statSPE * 1.25);
                    speChange++;
                    break;
                case 3:

                    statSPE = int(statSPE * 1.2);
                    speChange++;
                    break;
                case 4:

                    statSPE = int(statSPE * 1.1667);
                    speChange++;
                    break;
                case 5:

                    statSPE = int(statSPE / 0.875);
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

    bool OpMon::setStatus(Status newStatus) {
        if(status == newStatus) {
            return false;
        } else if(status != Status::NOTHING) { //If the OpMon already has a special status
            return false;
        }
        //Some status needs to edit the stats
        if(newStatus == Status::BURNING) {
            changeATK(-1);
            atkChange++;
        } else if(newStatus == Status::NOTHING && status == Status::BURNING) {
            changeATK(1);
            atkChange--;
        } else if(newStatus == Status::PARALYSED) {
            changeSPE(-1);
            speChange++;
        } else if(newStatus == Status::NOTHING && status == Status::PARALYSED) {
            changeSPE(1);
            speChange--;
        }
        status = newStatus;
        return true;
    }

    void OpMon::heal(int amount) {
        HP = std::min(statHP, HP + amount);
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
        return std::string();
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

} // namespace OpMon::Model
