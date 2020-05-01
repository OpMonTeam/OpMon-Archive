/*
  Move.cpp
  Author : Cyrielle
  Contributors : BAKFR, torq, Navet56
  File under GNU GPL v3.0 license
*/
#include "Move.hpp"

#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>

#include "../../nlohmann/json.hpp"
#include "../../utils/log.hpp"
#include "Moves.hpp"
#include "OpMon.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/view/elements/Turn.hpp"
#include "src/opmon/view/ui/Elements.hpp"
#include "src/utils/OpString.hpp"
#include "src/utils/misc.hpp"

namespace OpMon {

    std::map<std::string, MoveData> Move::moveList;

    Move *Move::newMove(std::string name) {
        try {
            return new Move(moveList.at(name));
        } catch(const std::out_of_range &) {
            Utils::Log::warn("Move " + name + " not found.");
            return nullptr;
        }
    }

    void Move::initMoves(std::string file) {
        std::ifstream jsonStream(file);
        nlohmann::json json;

        jsonStream >> json;

        for(auto itor = json.begin(); itor != json.end(); ++itor) {
            std::string idStr = itor->at("id");
            std::vector<MoveEffect **> effects = {&moveList[idStr].preEffect, &moveList[idStr].postEffect, &moveList[idStr].ifFails};
            moveList[idStr].nameKey = std::string("moves.") + idStr + ".name";
            moveList[idStr].power = itor->at("power");
            moveList[idStr].type = itor->at("type");
            moveList[idStr].accuracy = itor->at("accuracy");
            moveList[idStr].special = itor->at("special");
            moveList[idStr].status = itor->at("status");
            moveList[idStr].criticalRate = itor->at("criticalRate");
            moveList[idStr].neverFails = itor->at("neverFails");
            moveList[idStr].ppMax = itor->at("ppMax");
            moveList[idStr].priority = itor->at("priority");
            int i = 0;
            for(auto eitor = itor->at("effects").begin(); eitor != itor->at("effects").end(); ++eitor) {
                if(!eitor->at("null")) {
                    std::string effectType = eitor->at("type");
                    if(effectType == "ChangeStatEffect") {
                        *(effects[i]) = new Moves::ChangeStatEffect(eitor->at("data"));
                    }
                }
                i++;
            }
            for(unsigned int i = 0; i < itor->at("animationOrder").size(); i++) {
                moveList[idStr].animationOrder.push_back(itor->at("animationOrder").at(i));
            }

            for(int i = 0; i < 2; i++) {
                for(auto aitor = itor->at(i ? "opMovementsAtk" : "opMovementsDef").begin(); aitor != itor->at(i ? "opMovementsAtk" : "opMovementsDef").end(); ++aitor) {

                    nlohmann::json transObj = aitor->value("translation", nlohmann::json(nlohmann::json::value_t::object));
                    nlohmann::json rotObj = aitor->value("rotation", nlohmann::json(nlohmann::json::value_t::object));
                    nlohmann::json scalObj = aitor->value("scaling", nlohmann::json(nlohmann::json::value_t::object));

                    Ui::MovementData mov;
                    Ui::RotationData rot;
                    Ui::ScaleData scal;
                    if(!transObj.empty()) {
                        mov = Ui::Transformation::newMovementData(transObj.at("mode").at(0),
                                                                    transObj.at("mode").at(1),
                                                                    transObj.at("formulas").at(0),
                                                                    transObj.at("formulas").at(1));
                        std::cout << std::endl;
                    }

                    if(!rotObj.empty()) {
                        rot = Ui::Transformation::newRotationData(rotObj.at("mode"),
                                                                    rotObj.at("formula"),
                                                                    sf::Vector2f(rotObj.at("origin").at(0), rotObj.at("origin").at(1)));
                    }

                    if(!scalObj.empty()) {
                        scal = Ui::Transformation::newScaleData(scalObj.at("mode").at(0),
                                                                  scalObj.at("mode").at(1),
                                                                  scalObj.at("formulas").at(0),
                                                                  scalObj.at("formulas").at(1),
                                                                  sf::Vector2f(scalObj.at("origin").at(0), scalObj.at("origin").at(1)));
                    }
                    if(i) {
                        moveList[idStr].opAnimsAtk.push(Ui::Transformation(aitor->at("time"), mov, rot, scal));
                    } else {
                        moveList[idStr].opAnimsDef.push(Ui::Transformation(aitor->at("time"), mov, rot, scal));
                    }
                }
            }
            for(auto aitor = itor->at("animations").begin(); aitor != itor->at("animations").end(); ++aitor) {
                moveList[idStr].animations.push(*aitor);
            }
            std::string atkStr = itor->at("id");
            Utils::Log::oplog("Loaded move " + atkStr);
        }
    }

    std::queue<Ui::Transformation> Move::generateDefAnims(std::queue<Ui::Transformation> opAnims) {
        std::queue<Ui::Transformation> opAnimsDef;
        while(!opAnims.empty()) {
            opAnimsDef.push(opAnims.front().inverse());
            opAnims.pop();
        }
        return opAnimsDef;
    }

    Move::Move(std::string nameKey, int power, Type type, int accuracy, bool special, bool status, int criticalRate, bool neverFails, int ppMax, int priority, std::vector<Elements::TurnActionType> animationOrder, std::queue<Ui::Transformation> opAnimsAtk, std::queue<Ui::Transformation> opAnimsDef, std::queue<std::string> animations, MoveEffect *preEffect, MoveEffect *postEffect, MoveEffect *fails)
        : nameKey(Utils::OpString(stringkeys, nameKey))
        , name(this->nameKey.getString(stringkeys))
        , power(power)
        , type(type)
        , accuracy(accuracy)
        , special(special)
        , status(status)
        , criticalRate(criticalRate)
        , neverFails(neverFails)
        , pp(ppMax)
        , ppMax(ppMax)
        , priority(priority)
        , preEffect(preEffect)
        , postEffect(postEffect)
        , failEffect(fails)
        , animationOrder(animationOrder)
        , opAnimsAtk(opAnimsAtk)
        , opAnimsDef(opAnimsDef)
        , animations(animations) {
    }

    Move::Move(MoveData const &data)
        : nameKey(Utils::OpString(stringkeys, data.nameKey))
        , name(nameKey.getString(stringkeys))
        , power(data.power)
        , type(data.type)
        , accuracy(data.accuracy)
        , special(data.special)
        , status(data.status)
        , criticalRate(data.criticalRate)
        , neverFails(data.neverFails)
        , pp(data.ppMax)
        , ppMax(data.ppMax)
        , priority(data.priority)
        , preEffect(data.preEffect)
        , postEffect(data.postEffect)
        , failEffect(data.ifFails)
        , animationOrder(data.animationOrder)
        , opAnimsAtk(data.opAnimsAtk)
        , opAnimsDef(data.opAnimsDef)
        , animations(data.animations) {}

    Move::~Move() {
        delete(this->preEffect);
        delete(this->postEffect);
        delete(this->failEffect);
    }

    /* Return 1 : Inform to do the same move at the next turn.
     * Return 2 : End the move
     * Return -2 : Inform that the move failed
     * Return -1 : Inform that the move was ineffective against the target
     * In effectAfter : Return any number except 1 act like return 2.
     * If 1 is returned, it will do the same move at the next turn.
     * TODO : Create defines to make this more clear
     */
    int Move::move(OpMon &atk, OpMon &def, std::queue<Elements::TurnAction> &turnQueue, bool attacker) {
        pp--;
        turnQueue.push(Elements::createTurnDialogAction(Utils::OpString(stringkeys, "battle.dialog.move", {atk.getNicknamePtr(), &name})));
        //Move fail
        if((Utils::Misc::randU(100)) > (accuracy * (atk.getStatACC() / def.getStatEVA())) && neverFails == false) {
            Elements::TurnAction failAction;
            turnQueue.push(Elements::createTurnDialogAction(Utils::OpString(stringkeys, "battle.dialog.fail", {atk.getNicknamePtr()})));
            failEffect->apply(*this, atk, def, turnQueue);
            return -2;
        }
        int effectBf = preEffect ? preEffect->apply(*this, atk, def, turnQueue) : 0;
        if(effectBf == 1 || effectBf == 2) { //If special returns 1 or 2, the move ends.
            return effectBf;
        }
        //If type unefficiency
        if(ArrayTypes::calcEffectiveness(type, def.getType1(), def.getType2()) == 0 && (neverFails == false || status == false)) {
            turnQueue.push(Elements::createTurnDialogAction(Utils::OpString(stringkeys, "battle.effectiveness.none", {atk.getNicknamePtr()})));
            if(failEffect != nullptr)
                failEffect->apply(*this, atk, def, turnQueue);
            return -1;
        }

        //Animation time
        for(Elements::TurnActionType tat : animationOrder) {
            Elements::TurnAction ta;
            ta.type = tat;
            turnQueue.push(ta);
        }

        if(!status) { //Check if it isn't a status move to calculate the hp lost
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

            Elements::TurnAction loosingHp;
            newTurnAction(&loosingHp);
            loosingHp.type = attacker ? Elements::TurnActionType::DEF_UPDATE_HBAR : Elements::TurnActionType::ATK_UPDATE_HBAR;
            loosingHp.hpLost = hpLost;
            turnQueue.push(loosingHp);

            if(effectiveness == 0.25)
                turnQueue.push(Elements::createTurnDialogAction(Utils::OpString(stringkeys, "battle.effectiveness.almostnone")));
            else if(effectiveness == 0.5)
                turnQueue.push(Elements::createTurnDialogAction(Utils::OpString(stringkeys, "battle.effectiveness.notvery")));
            else if(effectiveness == 2)
                turnQueue.push(Elements::createTurnDialogAction(Utils::OpString(stringkeys, "battle.effectiveness.very")));
            else if(effectiveness == 4)
                turnQueue.push(Elements::createTurnDialogAction(Utils::OpString(stringkeys, "battle.effectiveness.super")));
        }
        return postEffect ? postEffect->apply(*this, atk, def, turnQueue) : 0;
    }

    void Move::onLangChanged(){
    	name = nameKey.getString(stringkeys);
    }

} // namespace OpMon
