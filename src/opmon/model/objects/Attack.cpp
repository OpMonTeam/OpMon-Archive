#include "Attack.hpp"
#include "OpMon.hpp"
#include <sstream>
#include "../../start/main.hpp"
#include "../save/Save.hpp"
#include "../../../utils/defines.hpp"


namespace OpMon{
  namespace Model{

    Attack::Attack(std::string nom, int puissance, Type type, int accuracy, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite, std::string className) :
      className(className), nom(nom) {
      this->puissance = puissance;
      this->type = type;
      this->accuracy = accuracy;
      this->special = special;
      this->status = status;
      this->chanceDeCoups = chanceDeCoups;
      this->rateJamais = rateJamais;
      this->pp = this->ppMax = ppMax;
      this->priorite = priorite;
    }

    /* Return 1 : Inform to do the same attack at the next turn.
     * Return 2 : End the attack
     * In effectAfter : Return any number except 1 act like return 2.
     * If 1 is returned, it will do the same attack at the next turn.
     */
    int Attack::attack(OpMon &atk, OpMon &def) {
      pp--;
      //Fail d'attaque
      if ((Utils::Misc::randU(100)) > (accuracy * (atk.getStatACC() / def.getStatEVA())) && rateJamais == false) {
        siEchoue(atk, def);
        return -2;
      }
      int effetAv = effetAvant(atk, def);
      if (effetAv == 1 || effetAv == 2) {//Si renvoi spécial, arrêt de l'attaque.
        return effetAv;
      }
      //Fail de types
      if (ArrayTypes::calcEfficacite(type, def.getType1(), def.getType2()) == 0 && (rateJamais == false || status == false)) {
        siEchoue(atk, def);
        return -1;
      }
      if (!status) {//Attack de PV si ce n'est pas une attaque de status
        hpPerdus = (((atk.getLevel() * 0.4 + 2) * (special ? atk.getStatATKSPE() : atk.getStatATK()) * puissance) / ((special ? def.getStatDEFSPE() : def.getStatDEF()) * 50) + 2);
        if (type == atk.getType1() || type == atk.getType2()) {
	  hpPerdus = round(hpPerdus * 1.5);
        }
        float efficacite = (ArrayTypes::calcEfficacite(type, def.getType1(), def.getType2()));
        //if(efficacite)//A utiliser pour les dialogues
        hpPerdus = round(hpPerdus * efficacite);
        if (Utils::Misc::randU(chanceDeCoups) == 1) {
	  hpPerdus = round(hpPerdus * 1.5);
        }
        hpPerdus = round(hpPerdus * (Utils::Misc::randU(100 - 85 + 1) + 85) / 100);
        def.attacked(hpPerdus);
      }
      return effetApres(atk, def);
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
