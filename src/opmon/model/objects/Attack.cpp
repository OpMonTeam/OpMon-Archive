/*
Attack.cpp
Author : Cyriel
Contributors : BAKFR, torq, Navet56
File under GNU GPL v3.0 license
*/
#include "Attack.hpp"
#include "../../../utils/defines.hpp"
#include "../../../utils/log.hpp"
#include "../../../nlohmann/json.hpp"
#include "../save/Save.hpp"
#include "OpMon.hpp"
#include "Attacks.hpp"
#include <sstream>
#include <fstream>

namespace OpMon {
    namespace Model {

      std::map<std::string, AttackData> Attack::attackList;
      
      Attack *Attack::newAtk(std::string name) {
	try{
	  return new Attack(attackList.at(name));
	}catch(std::out_of_range e){
	  Utils::Log::warn("Attack " + name + " not found.");
	  return nullptr;
	}
      }

      void Attack::initAttacks(std::string file){
	std::ifstream jsonStream(file);
	nlohmann::json json;
	
	jsonStream >> json;

	for(auto itor = json.begin(); itor != json.end(); ++itor){
	    std::string idStr = itor->at("id");
	  std::vector<AttackEffect**> effects = {&attackList[idStr].preEffect, &attackList[idStr].postEffect, &attackList[idStr].ifFails};
	  attackList[idStr].nameKey = std::string("attacks.") + idStr + ".name";
	  attackList[idStr].power = itor->at("power");
	  attackList[idStr].type = itor->at("type");
	  attackList[idStr].accuracy = itor->at("accuracy");
	  attackList[idStr].special = itor->at("special");
	  attackList[idStr].status = itor->at("status");
	  attackList[idStr].criticalRate = itor->at("criticalRate");
	  attackList[idStr].neverFails = itor->at("neverFails");
	  attackList[idStr].ppMax = itor->at("ppMax");
	  attackList[idStr].priority = itor->at("priority");
	  int i = 0;
	  for(auto eitor = itor->at("effects").begin(); eitor != itor->at("effects").end(); ++eitor){
	    if(!eitor->at("null")){
	      std::string effectType = eitor->at("type");
	      if(effectType == "ChangeStatEffect"){
		*(effects[i]) = new Attacks::ChangeStatEffect(eitor->at("data"));
	      }
	    }
	    i++;
	  }
	}
       
      }
      
      
      Attack::Attack(std::string nameKey, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, AttackEffect *preEffect, AttackEffect *postEffect, AttackEffect *fails)
          : name(Utils::OpString(nameKey))
	  , power(power)
	  , priority(priority)
	  , accuracy(accuracy)
	  , type(type)
	  , special(special)
	  , status(status)
	  , criticalRate(criticalRate)
	  , neverFails(neverFails)
	  , pp(ppMax)
	  , ppMax(ppMax)
	  , preEffect(preEffect)
	  , postEffect(postEffect)
	  , failEffect(fails){}

      Attack::Attack(AttackData const& data)
          : name(Utils::OpString(data.nameKey))
	  , power(data.power)
	  , priority(data.priority)
	  , accuracy(data.accuracy)
	  , type(data.type)
	  , special(data.special)
	  , status(data.status)
	  , criticalRate(data.criticalRate)
	  , neverFails(data.neverFails)
	  , pp(data.ppMax)
	  , ppMax(data.ppMax)
	  , preEffect(data.preEffect)
	  , postEffect(data.postEffect)
	  , failEffect(data.ifFails){}

        Attack::~Attack() {
            delete(this->preEffect);
            delete(this->postEffect);
	    delete(this->failEffect);
        }

        /* Return 1 : Inform to do the same attack at the next turn.
       * Return 2 : End the attack
       * Return -2 : Inform that the attack failed
       * Return -1 : Inform that the attack was ineffective against the target
       * In effectAfter : Return any number except 1 act like return 2.
       * If 1 is returned, it will do the same attack at the next turn.
       */
        int Attack::attack(OpMon &atk, OpMon &def, Turn &attackTurn) {
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
            std::ostringstream oss;
            oss << Save::intToChar(pp) << std::endl;
            oss << Save::intToChar(ppMax) << std::endl;
            return oss.str();
        }

    } // namespace Model
} // namespace OpMon
