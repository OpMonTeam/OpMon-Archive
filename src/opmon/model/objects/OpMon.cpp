#include "OpMon.hpp"
#include "../../start/main.hpp"
#include "./evolution/Evolution.hpp"
#include "./evolution/evolutions.hpp"
#include "../save/Save.hpp"
#include <sstream>
#include "item/IHeal.hpp"
#include "Attacks.hpp"
#include <fstream>
#include "../../start/Initializer.hpp"
#include "../../../utils/defines.hpp"
#include "../../start/Core.hpp"
#include "../../../utils/log.hpp"

UNS

namespace OpMon{
  namespace Model{

    OpMon::~OpMon(){
      for(int i = 0; i < 4; i++){
        if(attacks[i] != nullptr){
          delete (attacks[i]);
        }

      }
    }

    float CalcCourbs::p(int x){
      switch(x){
        case 0:
          return 0;
        case 1:
          return 0.008;
        case 2:
          return 0.014;
        default:
          return 0.008;
      }
    }

    int CalcCourbs::erratic(int n){
      if(0 < n && n <= 50){
        return round(pow(n, 3) * ((100 - n) / 50));
      }else if(51 <= n && n <= 68){
        return round(pow(n, 3) * ((150 - n) / 50));
      }else if(69 <= n && n <= 98){
        return round(1.274f - ((1 / 50) * (n / 3)) - p(n % 3));
      }else if(n >= 99){
        return round(pow(n, 3) * ((160 - n) / 100));
      }else{
        handleError("Erreur dans le calcul d'experience : niveau <= 0",
                    true);
        return 0;
      }
    }

    int CalcCourbs::fluctuating(int n){
      if(0 < n && n <= 15){
        return round(pow(n, 3) * ((24 + ((n + 1) / 3) / 50)));
      }else if(16 <= n && n <= 35){
        return round(pow(n, 3) * ((14 + n) / 50));
      }else if(n >= 36){
        return round(pow(n, 3) * ((32 + (n / 2)) / 50));
      }else{
        handleError("Erreur dans le calcul d'experience : niveau <= 0",
                    true);
        return 0;
      }
    }

    int CalcCourbs::slow(int n){
      return round(1.25f * pow(n, 3));
    }

    int CalcCourbs::normal(int n){
      return round(pow(n, 3));
    }

    int CalcCourbs::parabolic(int n){
      return round(1.2f * pow(n, 3) - 15 * pow(n, 2) + (100 * n) - 140);
    }

    int CalcCourbs::quick(int n){
      return round(0.8f * pow(n, 3));
    }

    OpMon::OpMon(const string &nickname, const Species &species, int level, const std::vector<Attack *> &attacks,
                 Nature nature){
      atkIV = Utils::randU(32);
      defIV = Utils::randU(32);
      atkSpeIV = Utils::randU(32);
      defSpeIV = Utils::randU(32);
      speIV = Utils::randU(32);
      hpIV = Utils::randU(32);
      statATK = round(
        ((((2 * species.getBaseAtk() + atkIV + (atkEV / 4)) * level) / 100)
         + 5)
        * ((natures[(int) nature].bonus == Stats::ATK) ?
           1.1 : ((natures[(int) nature].malus == Stats::ATK) ? 0.9 : 1)));
      statDEF = round(
        ((((2 * species.getBaseDef() + defIV + (defEV / 4)) * level) / 100)
         + 5)
        * ((natures[(int) nature].bonus == Stats::DEF) ?
           1.1 : ((natures[(int) nature].malus == Stats::DEF) ? 0.9 : 1)));
      statATKSPE =
        round(
          ((((2 * species.getBaseAtkSpe() + atkSpeIV + (atkSpeEV / 4))
             * level) / 100) + 5)
          * ((natures[(int) nature].bonus == Stats::ATKSPE) ?
             1.1 :
             ((natures[(int) nature].malus == Stats::ATKSPE) ? 0.9 : 1)));
      statDEFSPE =
        round(
          ((((2 * species.getBaseDefSpe() + defSpeIV + (defSpeEV / 4))
             * level) / 100) + 5)
          * ((natures[(int) nature].bonus == Stats::DEFSPE) ?
             1.1 :
             ((natures[(int) nature].malus == Stats::DEFSPE) ? 0.9 : 1)));
      statSPE = round(
        ((((2 * species.getBaseVit() + speIV + (speEV / 4)) * level) / 100)
         + 5)
        * ((natures[(int) nature].bonus == Stats::SPE) ?
           1.1 : ((natures[(int) nature].malus == Stats::SPE) ? 0.9 : 1)));
      statHP = round(((2 * species.getBaseHP() + hpIV + (hpEV / 4)) * level) / 100)
               + level + 10;
      this->species = &species;
      this->level = level;

      this->attacks = attacks;

      //TODO attaquesChoix Quand les attaques seront ok
      this->nature = nature;
      if(nickname.empty()){
        this->nickname = species.getName();
      }else{
        this->nickname = nickname;
      }

      tauxCapture = species.getTauxDeCapture();
      HP = statHP;
      type1 = species.getType1();
      type2 = species.getType2();
      using namespace CalcCourbs;
      switch(this->species->getCurve()){
        case CurveExp::ERRATIC:
          toNextLevel = erratic(this->level + 1);
          exp = erratic(this->level);
          break;
        case CurveExp::FLUCTUATING:
          toNextLevel = fluctuating(this->level + 1);
          exp = fluctuating(this->level);
          break;
        case CurveExp::SLOW:
          toNextLevel = slow(this->level + 1);
          exp = slow(this->level);
          break;
        case CurveExp::AVERAGE:
          toNextLevel = normal(this->level + 1);
          exp = normal(this->level);
          break;
        case CurveExp::PARABOLIC:
          toNextLevel = parabolic(this->level + 1);
          exp = parabolic(this->level);
          break;
        case CurveExp::QUICK:
          toNextLevel = quick(this->level + 1);
          exp = quick(this->level);
          break;
      }
      held = nullptr;
      statLove = 100;
      statACC = 100;
      statEVA = 100;
      falsif = false;

    }

    bool OpMon::captured(I_Opball const &Opball){
      int a = round((((3 * statHP - 2 * HP) * tauxCapture * Opball.getTauxCapture() *
                      (status == Status::PARALYSED || status == Status::POISONED || status == Status::BURNING ? 1.5 : (
                        status == Status::FROZEN || status == Status::SLEEPING ? 2 : 1))) / (3 * statHP)));
      int b = round((pow(2, 16) - 1) * pow(a / (pow(2, 8) - 1), 0.25));
      int c[] = {Utils::randU(65535), Utils::randU(65535), Utils::randU(65535),
                 Utils::randU(65535)
      };
      int nbreOk = 0;
      int i = 0;
      for(i = 0; i < 4; i++){
        if(c[i] <= b){
          nbreOk++;
        }
      }
      if(nbreOk == 0){
        return false;
      }else{
        //System.out.println("Remue...");
        if(nbreOk == 1){
          return false;
        }
        //System.out.println("Remue...");
        if(nbreOk == 2){
          return false;
        }
        //System.out.println("Remue...");
        if(nbreOk == 3){
          return false;
        }
        if(nbreOk != 4){
          handleError("InternalError : OpMon.cpp : nbreOk != 4",
                      true);
        }
        return true;
      }
    }

    void OpMon::setStat(Stats stat, int newStat){
      switch(stat){
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
          oplog("[WARNING] - Incorrect value in a switch (OpMon::setStat). Expected a stat, got Stats::NOTHING.");
          break;
      }
    }

    void OpMon::levelUp(){
      using namespace CalcCourbs;
      level++;
      switch(this->species->getCurve()){
        case CurveExp::ERRATIC:
          toNextLevel = erratic(this->level + 1);
          exp = erratic(this->level);
          break;
        case CurveExp::FLUCTUATING:
          toNextLevel = fluctuating(this->level + 1);
          exp = fluctuating(this->level);
          break;
        case CurveExp::SLOW:
          toNextLevel = slow(this->level + 1);
          exp = slow(this->level);
          break;
        case CurveExp::AVERAGE:
          toNextLevel = normal(this->level + 1);
          exp = normal(this->level);
          break;
        case CurveExp::PARABOLIC:
          toNextLevel = parabolic(this->level + 1);
          exp = parabolic(this->level);
          break;
        case CurveExp::QUICK:
          toNextLevel = quick(this->level + 1);
          exp = quick(this->level);
          break;
      }
      calcStats();
      if(species->getEvolType()->checkEvolve(*this)){
        if((species->getEvolType()->getEvolID()) == (Evolutions::ETrade)){
          evolve();
        }
      }
    }

    int OpMon::win(OpMon const &vaincu){
      getEvs(vaincu);
      exp += ((vaincu.species->getExp() * vaincu.level) / this->level) * expBoost;
      while(exp >= toNextLevel && level < 100){
        if(exp < toNextLevel){
          break;
        }
        levelUp();
      }
      calcStats();
      return (((vaincu.species->getExp() * vaincu.level) / this->level) * expBoost);
    }

    void OpMon::getEvs(OpMon const &vaincu){
      if(!((atkEV + defEV + hpEV + atkSpeEV + defSpeEV + speEV) > 510)){
        vector <Stats> statsVaincu;
        for(int i = 0; i < vaincu.species->getEvSize(); i++){
          statsVaincu.push_back(vaincu.species->getEv()[i]);
        }

        for(unsigned int i = 0; i < statsVaincu.size(); i++){
          switch(statsVaincu[i]){ //Creer enumération Stats
            case Stats::ATK:
              if(atkEV < 252){
                atkEV++;
              }
              break;
            case Stats::ATKSPE:
              if(atkSpeEV < 252){
                atkSpeEV++;
              }
              break;
            case Stats::DEF:
              if(defEV < 252){
                atkEV++;
              }
              break;
            case Stats::DEFSPE:
              if(defSpeEV < 252){
                defSpeEV++;
              }
              break;
            case Stats::HP:
              if(hpEV < 252){
                hpEV++;
              }
              break;
            case Stats::NOTHING:
              break;
            case Stats::SPE:
              if(speEV < 252){
                speEV++;
              }
              break;

          }
        }

      }
    }

    void OpMon::calcStats(){
      statATK = round(
        ((((2 * species->getBaseAtk() + atkIV + (atkEV / 4)) * level) / 100)
         + 5)
        * ((natures[(int) nature].bonus == Stats::ATK) ?
           1.1 : ((natures[(int) nature].malus == Stats::ATK) ? 0.9 : 1)));
      statDEF = round(
        ((((2 * species->getBaseDef() + defIV + (defEV / 4)) * level) / 100)
         + 5)
        * ((natures[(int) nature].bonus == Stats::DEF) ?
           1.1 : ((natures[(int) nature].malus == Stats::DEF) ? 0.9 : 1)));
      statATKSPE =
        round(
          ((((2 * species->getBaseAtkSpe() + atkSpeIV + (atkSpeEV / 4))
             * level) / 100) + 5)
          * ((natures[(int) nature].bonus == Stats::ATKSPE) ?
             1.1 :
             ((natures[(int) nature].malus == Stats::ATKSPE) ? 0.9 : 1)));
      statDEFSPE =
        round(
          ((((2 * species->getBaseDefSpe() + defSpeIV + (defSpeEV / 4))
             * level) / 100) + 5)
          * ((natures[(int) nature].bonus == Stats::DEFSPE) ?
             1.1 :
             ((natures[(int) nature].malus == Stats::DEFSPE) ? 0.9 : 1)));
      statSPE = round(
        ((((2 * species->getBaseVit() + speIV + (speEV / 4)) * level) / 100)
         + 5)
        * ((natures[(int) nature].bonus == Stats::SPE) ?
           1.1 : ((natures[(int) nature].malus == Stats::SPE) ? 0.9 : 1)));
      statHP = round(((2 * species->getBaseHP() + hpIV + (hpEV / 4)) * level) / 100)
               + level + 10;
    }

    bool OpMon::itemUsed(Item *used){
      if((species->getEvolType()->getEvolID()) == Evolutions::EItem){
        if(species->getEvolType()->itemEvolve(used)){
          evolve();
          return true;
        }
      }
      if(used->getItemTypeID() == ItemType::IHeal){

        I_Heal *usedI = dynamic_cast<I_Heal *>(used);
        if(usedI->getHpHeal() > 0){
          heal(usedI->getHpHeal());

        }
        if(usedI->isHealAll() && status == Status::NOTHING){
          setStatus(Status::NOTHING);

        }else if(usedI->getStatusHeald() != Status::NOTHING && status == usedI->getStatusHeald()){
          setStatus(Status::NOTHING);
          switch(usedI->getStatusHeald()){
            case Status::NOTHING:
              break;
            case Status::BURNING:
              //keyout(key("status.brulure.heal"), nickname);
              break;
            case Status::FROZEN:
              //keyout(key("status.gel.heal"), nickname);
              break;
            case Status::PARALYSED:
              //keyout(key("status.para.heal"), nickname);
              break;
            case Status::POISONED:
              //keyout(key("status.poison.heal"), nickname);
              break;
            case Status::SLEEPING:
              //keyout(key("status.sommeil.heal"), nickname);
              break;
            default:
              break;

          }
        }


      }
      return false;
    }

    Item *OpMon::hold(Item *item){
      Item *ancien = held;
      held = item;
      return ancien;
    }

    void OpMon::traded(){
      expBoost = 1.5;
      toolEvTrade();
    }

    void OpMon::toolEvTrade(){
      if(species->getEvolType()->getEvolID() == Evolutions::ETrade){
        evolve();
      }
    }

    void OpMon::evolve(){
      //bool changeName = (nickname == species->getName());
      species = species->getEvolution();
    }

    void OpMon::setStats(int stats[], Attack *attacks[], const Species &species, Type types[]){
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

    void OpMon::attacked(int hpPerdus){
      HP -= hpPerdus;
      HP = (HP < 0) ? 0 : HP;
    }

    bool OpMon::changeATK(int power){
      if(power < 0){
        for(int i = 0; i > power; i--){
          switch(atkChange){
            case -6:
              return false;
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
      }else{

        for(int i = 0; i > power; i--){
          switch(atkChange){
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
              return false;
            default:
              break;
          }
        }

      }

      return true;
    }

    bool OpMon::changeACC(int power){
      if(power < 0){
        for(int i = 0; i > power; i--){
          switch(accChange){
            case -6:
              return false;
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
      }else{

        for(int i = 0; i > power; i--){
          switch(accChange){
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
              return false;
            default:
              break;
          }
        }

      }

      return true;
    }

    bool OpMon::changeEVA(int power){
      if(power < 0){
        for(int i = 0; i > power; i--){
          switch(evaChange){
            case -6:
              return false;
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
      }else{

        for(int i = 0; i > power; i--){
          switch(evaChange){
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
              return false;
            default:
              break;
          }
        }

      }

      return true;
    }

    bool OpMon::changeDEF(int power){
      if(power < 0){
        for(int i = 0; i > power; i--){
          switch(defChange){
            case -6:
              return false;
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
      }else{

        for(int i = 0; i > power; i--){
          switch(defChange){
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
              return false;

            default:
              break;
          }
        }

      }
      return true;

    }

    bool OpMon::changeATKSPE(int power){
      if(power < 0){
        for(int i = 0; i > power; i--){
          switch(atkSpeChange){
            case -6:
              return false;
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
      }else{

        for(int i = 0; i > power; i--){
          switch(atkSpeChange){
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
              return false;
            default:
              break;
          }
        }

      }
      return true;
    }

    bool OpMon::changeDEFSPE(int power){
      if(power < 0){
        for(int i = 0; i > power; i--){
          switch(defSpeChange){
            case -6:
              return false;
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
      }else{

        for(int i = 0; i > power; i--){
          switch(defSpeChange){
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
              return false;
            default:
              break;
          }
        }

      }
      return true;
    }

    bool OpMon::changeSPE(int power){
      if(power < 0){
        for(int i = 0; i > power; i--){
          switch(speChange){
            case -6:
              return false;
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
      }else{

        for(int i = 0; i > power; i--){
          switch(speChange){
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
              return false;
            default:
              break;
          }
        }

      }
      return true;
    }

    bool OpMon::setStatus(Status status){
      if(status == Status::BURNING && this->status == Status::BURNING){
        //System.out.println(nickname + " est déjà  brulé!");
        return false;
      }else if(status == Status::SLEEPING && this->status == Status::SLEEPING){
        //System.out.println("Mais " + nickname + " dort déjà !");
        return false;
      }else if(status == Status::PARALYSED && this->status == Status::PARALYSED){
        //System.out.println(nickname + " est déjà  paralysé!");
        return false;
      }else if(status == Status::FROZEN && this->status == Status::FROZEN){
        //System.out.println(nickname + " est déjà  gelé!");
        return false;
      }else if(status == Status::POISONED && this->status == Status::POISONED){
        //System.out.println(nickname + " est déjà  empoisonné!");
        return false;
      }else if(this->status != Status::NOTHING && status != Status::NOTHING){
        //System.out.println("Mais " + nickname + " a déjà  un status!");
        return false;
      }else if(status == Status::BURNING){
        changeATK(-1);
        atkChange++;
      }else if(status == Status::NOTHING && this->status == Status::BURNING){
        changeATK(1);
        atkChange--;
      }else if(status == Status::PARALYSED){
        changeSPE(-1);
        speChange++;
      }else if(status == Status::NOTHING && this->status == Status::PARALYSED){
        changeSPE(1);
        speChange--;
      }
      this->status = status;
      return true;
    }

    void OpMon::heal(int HP){
      if((HP + this->HP) > statHP){
        this->HP = statHP;
      }else{
        this->HP += HP;
      }
    }

    void OpMon::setType1(Type type){
      this->type1 = type;
    }

    void OpMon::setType2(Type type){
      this->type2 = type;
    }

    string OpMon::save(){
      if(!falsif){

        ostringstream oss;
        oss << nickname << endl;
        oss << Save::intToChar(atkIV) << endl;
        oss << Save::intToChar(defIV) << endl;
        oss << Save::intToChar(atkSpeIV) << endl;
        oss << Save::intToChar(defSpeIV) << endl;
        oss << Save::intToChar(speIV) << endl;
        oss << Save::intToChar(hpIV) << endl;
        oss << Save::intToChar(atkEV) << endl;
        oss << Save::intToChar(defEV) << endl;
        oss << Save::intToChar(atkSpeEV) << endl;
        oss << Save::intToChar(defSpeEV) << endl;
        oss << Save::intToChar(speEV) << endl;
        oss << Save::intToChar(hpEV) << endl;
        oss << Save::intToChar(statLove) << endl;
        oss << Save::intToChar(level) << endl;
        oss << Save::intToChar(natures[(int) nature].id) << endl;
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
        if(attacks[0] != nullptr){
          oss << attacks[0]->save();
        }else{
          oss << "NULL" << endl;
        }
        if(attacks[1] != nullptr){
          oss << attacks[1]->save();
        }else{
          oss << "NULL" << endl;
        }
        if(attacks[2] != nullptr){
          oss << attacks[2]->save();
        }else{
          oss << "NULL" << endl;
        }
        if(attacks[3] != nullptr){
          oss << attacks[3]->save();
        }else{
          oss << "NULL" << endl;
        }
        oss << Save::intToChar(species->getOpdexNumber()) << endl;
        oss << Save::intToChar(HP) << endl;
        oss << Save::intToChar(exp) << endl;
        oss << Save::intToChar(toNextLevel) << endl;
        oss << Save::intToChar(expBoost * 10) << endl;
        if(held != nullptr){
          oss << "Y" << endl;
          oss << Save::intToChar(held->getID()) << endl;
        }else{
          oss << "N" << endl;
          oss << endl;
        }
        oss << Save::intToChar(tauxCapture) << endl;
        return oss.str();
      }else{
        return "NULL\n";
      }

    }

    OpMon::OpMon(ifstream &in){
      this->nickname = Save::readLine(in);
      if(nickname != "NULL"){
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
        int toSearch = in.get();
        //nature = toSearch;
        in.get();
        attacks[0] = Attacks::newAtk(Save::readLine(in));
        if(attacks[0] != nullptr){
          attacks[0]->setPP(in.get());
          in.get();
          attacks[0]->setPPMax(in.get());
          in.get();
        }

        attacks[1] = Attacks::newAtk(Save::readLine(in));
        if(attacks[1] != nullptr){
          attacks[1]->setPP(in.get());
          in.get();
          attacks[1]->setPPMax(in.get());
          in.get();
        }

        attacks[2] = Attacks::newAtk(Save::readLine(in));
        if(attacks[2] != nullptr){
          attacks[2]->setPP(in.get());
          in.get();
          attacks[2]->setPPMax(in.get());
          in.get();
        }
        attacks[3] = Attacks::newAtk(Save::readLine(in));
        if(attacks[3] != nullptr){
          attacks[3]->setPP(in.get());
          in.get();
          attacks[3]->setPPMax(in.get());
          in.get();
        }
        int speciesID = in.get();
        species = &Initializer::listOp.at(speciesID);
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
        tauxCapture = in.get();
        in.get();
        calcStats();
        type1 = species->getType1();
        type2 = species->getType2();
        statACC = 100;
        statEVA = 100;
        falsif = false;
      } else {
        falsif = true;
      }


    }

  }
}
