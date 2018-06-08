#include "Attack.hpp"
#include "../../../utils/defines.hpp"
#include "../save/Save.hpp"
#include "OpMon.hpp"
#include <sstream>

//TODO : Translate this file in english

namespace OpMon {
    namespace Model {

        Attack::Attack(std::string name, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::string className,
                       AttackEffect *preEffect, AttackEffect *postEffect)
          : className(className), name(name), preEffect(preEffect), postEffect(postEffect) {
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

      Attack::~Attack() {
        delete(this->preEffect);
        delete(this->postEffect);
      }

      /* Return 1 : Inform to do the same attack at the next turn.
     * Return 2 : End the attack
       Return -2 : Inform that the attack failed
       Return -1 : Inform that the attack was ineffective against the target
     * In effectAfter : Return any number except 1 act like return 2.
     * If 1 is returned, it will do the same attack at the next turn.
     */
      int Attack::attack(OpMon &atk, OpMon &def, Turn& attackTurn) {
            pp--;
            //Attack fail
            if((Utils::Misc::randU(100)) > (accuracy * (atk.getStatACC() / def.getStatEVA())) && neverFails == false) {
	      attackTurn.attackMissed = true;
	      ifFails(atk, def, attackTurn);
                return -2;
            }
            int effectBf = preEffect ? preEffect->apply(*this, atk, def, attackTurn) : 0;
            if(effectBf == 1 || effectBf == 2) { //If special return, the attack ends.
	      attackTurn.atkEnd = true;
                return effectBf;
            }
            //If type unefficiency
            if(ArrayTypes::calcEffectiveness(type, def.getType1(), def.getType2()) == 0 && (neverFails == false || status == false)) {
	      attackTurn.attackFailed = true;
	      ifFails(atk, def, attackTurn);
                return -1;
            }
            if(!status) { //Check if it isn't a status attack to calculate the hp lost
                hpLost = (((atk.getLevel() * 0.4 + 2) * (special ? atk.getStatATKSPE() : atk.getStatATK()) * power) / ((special ? def.getStatDEFSPE() : def.getStatDEF()) * 50) + 2);
                if(type == atk.getType1() || type == atk.getType2()) {
                    hpLost = round(hpLost * 1.5);
                }
                float effectiveness = (ArrayTypes::calcEffectiveness(type, def.getType1(), def.getType2()));
                //if(effectiveness)//Set effectiveness dialogs here
                hpLost = round(hpLost * effectiveness);
                if(Utils::Misc::randU(criticalRate) == 1) {
                    hpLost = round(hpLost * 1.5);
                }
                hpLost = round(hpLost * (Utils::Misc::randU(100 - 85 + 1) + 85) / 100);
		attackTurn.hpLost = hpLost;
                def.attacked(hpLost);
            }
            return postEffect ? postEffect->apply(*this, atk, def, attackTurn) : 0;
        }
      
        std::string Attack::save() {
            UNS
              ostringstream oss;
            oss << this->className << endl;
            oss << Save::intToChar(pp) << endl;
            oss << Save::intToChar(ppMax) << endl;
            return oss.str();
        }

    } // namespace Model
} // namespace OpMon
