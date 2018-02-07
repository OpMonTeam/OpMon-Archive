#include "Attack.hpp"
#include "OpMon.hpp"
#include <sstream>
#include "../save/Save.hpp"
#include "../../../utils/defines.hpp"

//TODO : Translate this file in english

namespace OpMon{
  namespace Model{

    Attack::Attack(std::string name, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::string className) :
      className(className), name(name) {
      this->power = power;
      this->type = type;
      this->accuracy = accuracy;
      this->special = special;
      this->status = status;
      this->criticalRate = criticalRate;
      this->neverFails = neverFails;
      this->pp = this->ppMax = ppMax;
      this->priority = priority;
    }

    /* Return 1 : Inform to do the same attack at the next turn.
     * Return 2 : End the attack
     * In effectAfter : Return any number except 1 act like return 2.
     * If 1 is returned, it will do the same attack at the next turn.
     */
    int Attack::attack(OpMon &atk, OpMon &def) {
      pp--;
      //Fail d'attaque
      if ((Utils::Misc::randU(100)) > (accuracy * (atk.getStatACC() / def.getStatEVA())) && neverFails == false) {
        ifFails(atk, def);
        return -2;
      }
      int effectBf = effectBefore(atk, def);
      if (effectBf == 1 || effectBf == 2) {//Si renvoi spécial, arrêt de l'attaque.
        return effectBf;
      }
      //Fail de types
      if (ArrayTypes::calcEfficacite(type, def.getType1(), def.getType2()) == 0 && (neverFails == false || status == false)) {
        ifFails(atk, def);
        return -1;
      }
      if (!status) {//Attack de PV si ce n'est pas une attaque de status
        hpLost = (((atk.getLevel() * 0.4 + 2) * (special ? atk.getStatATKSPE() : atk.getStatATK()) * power) / ((special ? def.getStatDEFSPE() : def.getStatDEF()) * 50) + 2);
        if (type == atk.getType1() || type == atk.getType2()) {
	  hpLost = round(hpLost * 1.5);
        }
        float efficacite = (ArrayTypes::calcEfficacite(type, def.getType1(), def.getType2()));
        //if(efficacite)//A utiliser pour les dialogues
        hpLost = round(hpLost * efficacite);
        if (Utils::Misc::randU(criticalRate) == 1) {
	  hpLost = round(hpLost * 1.5);
        }
        hpLost = round(hpLost * (Utils::Misc::randU(100 - 85 + 1) + 85) / 100);
        def.attacked(hpLost);
      }
      return effectAfter(atk, def);
    }
    std::string Attack::save() {
      UNS
	ostringstream oss;
      oss << this->className << endl;
      oss << Save::intToChar(pp) << endl;
      oss << Save::intToChar(ppMax) << endl;
      return oss.str();
    }

  }
}
