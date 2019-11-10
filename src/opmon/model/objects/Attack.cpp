/*
Attack.cpp
Author : Cyrielle
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
            } catch(const std::out_of_range &) {
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
                for(unsigned int i = 0; i < itor->at("animationOrder").size(); i++) {
                    attackList[idStr].animationOrder.push_back(itor->at("animationOrder").at(i));
                }

                for(int i = 0; i < 2; i++) {
                    for(auto aitor = itor->at(i ? "opMovementsAtk" : "opMovementsDef").begin(); aitor != itor->at(i ? "opMovementsAtk" : "opMovementsDef").end(); ++aitor) {

                        nlohmann::json transObj = aitor->value("translation", nlohmann::json(nlohmann::json::value_t::object));
                        nlohmann::json rotObj = aitor->value("rotation", nlohmann::json(nlohmann::json::value_t::object));
                        nlohmann::json scalObj = aitor->value("scaling", nlohmann::json(nlohmann::json::value_t::object));

                        View::MovementData mov;
                        View::RotationData rot;
                        View::ScaleData scal;
                        if(!transObj.empty()) {
                            mov = View::Transformation::newMovementData(transObj.at("mode").at(0),
                                                                        transObj.at("mode").at(1),
                                                                        transObj.at("formulas").at(0),
                                                                        transObj.at("formulas").at(1));
                            std::cout << std::endl;
                        }

                        if(!rotObj.empty()) {
                            rot = View::Transformation::newRotationData(rotObj.at("mode"),
                                                                        rotObj.at("formula"),
                                                                        sf::Vector2f(rotObj.at("origin").at(0), rotObj.at("origin").at(1)));
                        }

                        if(!scalObj.empty()) {
                            scal = View::Transformation::newScaleData(scalObj.at("mode").at(0),
                                                                      scalObj.at("mode").at(1),
                                                                      scalObj.at("formulas").at(0),
                                                                      scalObj.at("formulas").at(1),
                                                                      sf::Vector2f(scalObj.at("origin").at(0), scalObj.at("origin").at(1)));
                        }
                        if(i) {
                            attackList[idStr].opAnimsAtk.push(View::Transformation(aitor->at("time"), mov, rot, scal));
                        } else {
                            attackList[idStr].opAnimsDef.push(View::Transformation(aitor->at("time"), mov, rot, scal));
                        }
                    }
                }
                for(auto aitor = itor->at("animations").begin(); aitor != itor->at("animations").end(); ++aitor) {
                    attackList[idStr].animations.push(*aitor);
                }
                std::string atkStr = itor->at("id");
                Utils::Log::oplog("Loaded attack " + atkStr);
            }
        }

        std::queue<View::Transformation> Attack::generateDefAnims(std::queue<View::Transformation> opAnims) {
            std::queue<View::Transformation> opAnimsDef;
            while(!opAnims.empty()) {
                opAnimsDef.push(opAnims.front().inverse());
                opAnims.pop();
            }
            return opAnimsDef;
        }

        Attack::Attack(std::string nameKey, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::vector<TurnActionType> animationOrder, std::queue<View::Transformation> opAnimsAtk, std::queue<View::Transformation> opAnimsDef, std::queue<std::string> animations, AttackEffect *preEffect, AttackEffect *postEffect, AttackEffect *fails)
          : nameKey(Utils::OpString(nameKey))
          , name(this->nameKey.getString())
          , power(power)
          , priority(priority)
          , accuracy(accuracy)
          , type(type)
          , special(special)
          , status(status)
          , pp(ppMax)
          , ppMax(ppMax)
          , criticalRate(criticalRate)
          , neverFails(neverFails)
          , preEffect(preEffect)
          , postEffect(postEffect)
          , failEffect(fails)
          , animationOrder(animationOrder)
          , opAnimsAtk(opAnimsAtk)
          , opAnimsDef(opAnimsDef)
          , animations(animations) {
        }

        Attack::Attack(AttackData const &data)
          : nameKey(Utils::OpString(data.nameKey))
          , name(nameKey.getString())
          , power(data.power)
          , priority(data.priority)
          , accuracy(data.accuracy)
          , type(data.type)
          , special(data.special)
          , status(data.status)
          , pp(data.ppMax)
          , ppMax(data.ppMax)
          , criticalRate(data.criticalRate)
          , neverFails(data.neverFails)
          , preEffect(data.preEffect)
          , postEffect(data.postEffect)
          , failEffect(data.ifFails)
          , animationOrder(data.animationOrder)
          , opAnimsAtk(data.opAnimsAtk)
          , opAnimsDef(data.opAnimsDef)
          , animations(data.animations) {}

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
	   * TODO : Create defines to make this more clear
       */
        int Attack::attack(OpMon &atk, OpMon &def, std::queue<TurnAction> &turnQueue, bool attacker) {
            pp--;
            turnQueue.push(createTurnDialogAction(Utils::OpString("battle.dialog.attack", {atk.getNicknamePtr(), &name})));
            //Attack fail
            if((Utils::Misc::randU(100)) > (accuracy * (atk.getStatACC() / def.getStatEVA())) && neverFails == false) {
                TurnAction failAction;
                turnQueue.push(createTurnDialogAction({Utils::OpString("battle.dialog.fail", {atk.getNicknamePtr()})}));
                failEffect->apply(*this, atk, def, turnQueue);
                return -2;
            }
            int effectBf = preEffect ? preEffect->apply(*this, atk, def, turnQueue) : 0;
            if(effectBf == 1 || effectBf == 2) { //If special returns 1 or 2, the attack ends.
                return effectBf;
            }
            //If type unefficiency
            if(ArrayTypes::calcEffectiveness(type, def.getType1(), def.getType2()) == 0 && (neverFails == false || status == false)) {
                turnQueue.push(createTurnDialogAction({Utils::OpString("battle.effectiveness.none", {atk.getNicknamePtr()})}));
                if(failEffect != nullptr)
                    failEffect->apply(*this, atk, def, turnQueue);
                return -1;
            }

            //Animation time
            for(TurnActionType tat : animationOrder) {
                TurnAction ta;
                ta.type = tat;
                turnQueue.push(ta);
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
