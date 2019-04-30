/*
Attack.cpp
Author : Cyriel
Contributors : BAKFR, torq, Navet56
File under GNU GPL v3.0 license
*/
#include "Attack.hpp"
#include "../../../nlohmann/json.hpp"
#include "../../../utils/defines.hpp"
#include "../../../utils/log.hpp"
#include "../save/Save.hpp"
#include "Attacks.hpp"
#include "OpMon.hpp"
#include <fstream>
#include <sstream>

namespace OpMon {
    namespace Model {

        std::map<std::string, AttackData> Attack::attackList;

        Attack *Attack::newAtk(std::string name) {
            try {
                return new Attack(attackList.at(name));
            } catch(std::out_of_range e) {
                Utils::Log::warn("Attack " + name + " not found.");
                return nullptr;
            }
        }

        void Attack::initAttacks(std::string file) {
            std::ifstream jsonStream(file);
            nlohmann::json json;

            jsonStream >> json;

            for(auto itor = json.begin(); itor != json.end(); ++itor) {
                std::string idStr = itor->at("id");
                std::vector<AttackEffect **> effects = {&attackList[idStr].preEffect, &attackList[idStr].postEffect, &attackList[idStr].ifFails};
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
                for(auto eitor = itor->at("effects").begin(); eitor != itor->at("effects").end(); ++eitor) {
                    if(!eitor->at("null")) {
                        std::string effectType = eitor->at("type");
                        if(effectType == "ChangeStatEffect") {
                            *(effects[i]) = new Attacks::ChangeStatEffect(eitor->at("data"));
                        }
                    }
                    i++;
                }
		for(unsigned int i = 0; i < itor->at("animationOrder").size(); i++){
		    attackList[idStr].animationOrder.push(itor->at("animationOrder").at(i));
		}
		for(auto aitor = itor->at("opMovements").begin(); aitor != itor->at("opMovements").end(); ++aitor){
		    attackList[idStr].opMovements.push(new View::Movement(aitor->at("mode").at(0), aitor->at("mode").at(1), aitor->at("formulas").at(0), aitor->at("formulas").at(1), aitor->at("time"), aitor->value("relative", true)));
		}
		for(unsigned int i = 0; i < itor->at("animations").size(); i++){
		    attackList[idStr].animations.push(itor->at("animations").at(i));
		}
            }
        }

        Attack::Attack(std::string nameKey, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::queue<TurnActionType> animationOrder, std::queue<View::Movement*> opMovements, std::queue<std::string> animations, AttackEffect *preEffect, AttackEffect *postEffect, AttackEffect *fails)
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
          , failEffect(fails)
	  , animationOrder(animationOrder)
	  , opMovements(opMovements)
	  , animations(animations) {}

        Attack::Attack(AttackData const &data)
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
          , failEffect(data.ifFails)
	  , animationOrder(data.animationOrder)
	  , opMovements(data.opMovements)
	  , animations(data.animations) {}


        Attack::~Attack() {
            delete(this->preEffect);
            delete(this->postEffect);
            delete(this->failEffect);
	    while(opMovements.size() != 0){
		delete(opMovements.front());
		opMovements.pop();
	    }
        }

        /* Return 1 : Inform to do the same attack at the next turn.
       * Return 2 : End the attack
       * Return -2 : Inform that the attack failed
       * Return -1 : Inform that the attack was ineffective against the target
       * In effectAfter : Return any number except 1 act like return 2.
       * If 1 is returned, it will do the same attack at the next turn.
	   * TODO : Create defines to make this more clear
       */
        int Attack::attack(OpMon &atk, OpMon &def, std::queue<TurnAction> &turnQueue, bool attacker) {
            pp--;
            turnQueue.push(createTurnDialogAction({Utils::OpString("battle.dialog.attack", {new sf::String(atk.getNickname()), new sf::String(this->name.getString())})}));
            //Attack fail
            if((Utils::Misc::randU(100)) > (accuracy * (atk.getStatACC() / def.getStatEVA())) && neverFails == false) {
                TurnAction failAction;
                turnQueue.push(createTurnDialogAction({Utils::OpString("battle.dialog.fail", {new sf::String(atk.getNickname())})}));
                failEffect->apply(*this, atk, def, turnQueue);
                return -2;
            }
            int effectBf = preEffect ? preEffect->apply(*this, atk, def, turnQueue) : 0;
            if(effectBf == 1 || effectBf == 2) { //If special returns 1 or 2, the attack ends.
                return effectBf;
            }
            //If type unefficiency
            if(ArrayTypes::calcEffectiveness(type, def.getType1(), def.getType2()) == 0 && (neverFails == false || status == false)) {
                turnQueue.push(createTurnDialogAction({Utils::OpString("battle.effectiveness.none", {new sf::String(atk.getNickname())})}));
                if(failEffect != nullptr)
                    failEffect->apply(*this, atk, def, turnQueue);
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

                def.attacked(hpLost);

                TurnAction loosingHp;
                newTurnAction(&loosingHp);
                loosingHp.type = attacker ? TurnActionType::DEF_UPDATE_HBAR : TurnActionType::ATK_UPDATE_HBAR;
                loosingHp.hpLost = hpLost;
                turnQueue.push(loosingHp);

                if(effectiveness == 0.25)
                    turnQueue.push(createTurnDialogAction({Utils::OpString("battle.effectiveness.almostnone")}));
                else if(effectiveness == 0.5)
                    turnQueue.push(createTurnDialogAction({Utils::OpString("battle.effectiveness.notvery")}));
                else if(effectiveness == 2)
                    turnQueue.push(createTurnDialogAction({Utils::OpString("battle.effectiveness.very")}));
                else if(effectiveness == 4)
                    turnQueue.push(createTurnDialogAction({Utils::OpString("battle.effectiveness.super")}));
            }
            return postEffect ? postEffect->apply(*this, atk, def, turnQueue) : 0;
        }

        std::string Attack::save() {
            std::ostringstream oss;
            oss << Save::intToChar(pp) << std::endl;
            oss << Save::intToChar(ppMax) << std::endl;
            return oss.str();
        }

    } // namespace Model
} // namespace OpMon
