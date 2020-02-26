/*
  BattleCtrl.cpp
  Author : Cyrielle
  Contributors : JonnyPtn, Navet56
  File under GNU GPL v3.0 license.
*/
#include "BattleCtrl.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include <string>

#include "../../utils/OpString.hpp"
#include "src/opmon/core/Core.hpp"
#include "src/opmon/core/UiData.hpp"
#include "src/opmon/model/Attack.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/model/OpMon.hpp"
#include "src/opmon/model/OpTeam.hpp"
#include "src/opmon/screens/Battle.hpp"
#include "src/opmon/screens/BattleData.hpp"
#include "src/opmon/view/elements/Events.hpp"
#include "src/opmon/view/elements/Turn.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"
#include "src/utils/misc.hpp"

namespace OpMon {
class Player;
class Species;

    BattleCtrl::BattleCtrl(OpTeam *one, Elements::Events::TrainerEvent *two, UiData *uidata, Player *player)
        : BattleCtrl(one, two->getOpTeam(), uidata, player) {
        this->trainer = two;
        next.type = Elements::TurnActionType::NEXT;
    }

    BattleCtrl::BattleCtrl(OpTeam *one, OpTeam *two, UiData *uidata, Player *player)
        : data(uidata, player)
        , playerTeam(one)
        , trainerTeam(two)
        , atk(one->getOp(0))
        , def(two->getOp(0))
        , view(one, two, "beta", "grass", this->data) {
        initBattle(0, 0);
        next.type = Elements::TurnActionType::NEXT;
    }

    GameStatus BattleCtrl::update(sf::RenderTexture &frame) {
        GameStatus returned = view.update(atkTurn, defTurn, actionsQueue, &turnActivated, atkFirst);
        frame.draw(view);
        return returned;
    }

    GameStatus BattleCtrl::checkEvent(sf::Event const &event) {

        switch(event.type) {
        case sf::Event::KeyPressed:
            switch(event.key.code) {
                //Selection events
            case sf::Keyboard::Left:
                view.moveCur(Side::TO_LEFT);
                data.getUiDataPtr()->getJukebox().playSound("arrow");
                break;
            case sf::Keyboard::Right:
                data.getUiDataPtr()->getJukebox().playSound("arrow");
                view.moveCur(Side::TO_RIGHT);
                break;
            case sf::Keyboard::Up:
                data.getUiDataPtr()->getJukebox().playSound("arrow");
                view.moveCur(Side::TO_UP);
                break;
            case sf::Keyboard::Down:
                data.getUiDataPtr()->getJukebox().playSound("arrow");
                view.moveCur(Side::TO_DOWN);
                break;
            case sf::Keyboard::Return:
                //If it the attack selection screen is not the active screen, and if the turn is not activated, the battle's main menu is printed.
                if(!view.isAttackChoice() && !turnActivated) {
                    switch(view.getCurPos()) {
                        //Currently, there is only one choice avilable, the "attack" choice.
                    case 0:
                        view.toggleAttackChoice();
                        break;
                        /*case 3:
                          return GameStatus::PREVIOUS; //Run*/
                    default:
                        data.getUiDataPtr()->getJukebox().playSound("nope");
                        break;
                    }

                } else if(!turnActivated) { //In this case, the attack selection screen is the active screen.
                    //Gets the selected attack, checks if it isn't a invalid attack (PP check and existence check), and then launches the turn.
                    atkTurn.attackUsed = atk->getAttacks()[view.getCurPos()];
                    if(atkTurn.attackUsed != nullptr) {
                        if(atkTurn.attackUsed->getPP() > 0) {
                            atkTurn.type = Elements::TurnType::ATTACK;
                            turn();
                            view.toggleAttackChoice();
                            turnActivated = true;
                        }
                    } else { //The attack is invalid
                        data.getUiDataPtr()->getJukebox().playSound("nope");
                    }
                } else if(turnActivated) {
                    view.passDialog();
                }

                break;
            case sf::Keyboard::BackSpace:
                //From the attack selection screen, returns to the battle's main menu.
                if(view.isAttackChoice()) {
                    view.toggleAttackChoice();
                }
                break;

            case sf::Keyboard::Space:
                //During the dialogs, passes to the next one.
                if(turnActivated) {
                    view.passDialog();
                }
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }

        return GameStatus::CONTINUE;
    }

    void BattleCtrl::initBattle(int opId, int opId2) {
        //Saves the OpMons' stats before the battle, to reset the stats after it.
        atk = playerTeam->getOp(opId);
        def = trainerTeam->getOp(opId2);
        oldStats[0][0] = atk->getStatATK();
        oldStats[0][1] = atk->getStatDEF();
        oldStats[0][2] = atk->getStatATKSPE();
        oldStats[0][3] = atk->getStatDEFSPE();
        oldStats[0][4] = atk->getStatSPE();

        oldStats[1][0] = def->getStatATK();
        oldStats[1][1] = def->getStatDEF();
        oldStats[1][2] = def->getStatATKSPE();
        oldStats[1][3] = def->getStatDEFSPE();
        oldStats[1][4] = def->getStatSPE();

        oldTypes[0][0] = atk->getType1();
        oldTypes[0][1] = atk->getType2();
        oldTypes[1][0] = def->getType1();
        oldTypes[1][1] = def->getType2();

        const Species &atkSpecies = atk->getSpecies();
        const Species &defSpecies = def->getSpecies();

        oldSpecies[0] = &atkSpecies;
        oldSpecies[1] = &defSpecies;

        oldAttacks[0] = atk->getAttacks();
        oldAttacks[1] = def->getAttacks();

        atk->setStat(Stats::EVA, 100);
        atk->setStat(Stats::ACC, 100);
        def->setStat(Stats::EVA, 100);
        def->setStat(Stats::ACC, 100);
        //Clear the turns
        newTurnData(&atkTurn);
        newTurnData(&defTurn);

        //Register the opmons' addresses in the Turns
        atkTurn.opmon = atk;
        defTurn.opmon = def;
    }

#pragma GCC diagnostic ignored "-Wunused-parameter"
    //Unfinished method, the IA will be programmed in the future.
    Elements::TurnData *BattleCtrl::turnIA(int level) {
        defTurn.attackUsed = def->getAttacks()[0];
        defTurn.type = Elements::TurnType::ATTACK;
        return &defTurn;
    }
#pragma GCC diagnostic pop

    bool BattleCtrl::checkBattleEnd() {
        if(def->getHP() <= 0) {

            if(trainer != nullptr) {
                trainer->defeat();
            }
            Elements::TurnAction victory;
            victory.type = Elements::TurnActionType::VICTORY;
            actionsQueue.push(victory);
            return true;
        } else if(atk->getHP() <= 0) {
            if(trainer != nullptr) { //TODO : Only for the test battle, should be removed at some point.
                trainer->defeat();
            }
            Elements::TurnAction defeat;
            defeat.type = Elements::TurnActionType::DEFEAT;
            actionsQueue.push(defeat);
            return true;
        }
        return false;
    }

    bool BattleCtrl::turn() {
        //These variables are used to check if the turn of one of the OpMons' is over.
        bool atkDone = false;
        bool defDone = false;

        turnIA(0);

        if(!actionsQueue.empty()) {
            handleError("Error : Actions Queue not empty but beginning a new turn anyway. Undefined behavior my result, because I won't fix that for you. And it could be funny to see.");
        }

        //Item use or switching always comes before the attack. It is calculated before everything else.
        if(atkTurn.type != Elements::TurnType::ATTACK) {
            //Actions
            atkDone = true;
        }
        if(defTurn.type != Elements::TurnType::ATTACK) {
            //Actions
            defDone = true;
        }
        //If the two of them attack, then the priority must be calculated. Else, the only attacking OpMon will attack, obviously.
        if(defTurn.type == Elements::TurnType::ATTACK && atkTurn.type == Elements::TurnType::ATTACK) {
            atkFirst = (atkTurn.attackUsed->getPriority() == defTurn.attackUsed->getPriority()) ? (atk->getStatSPE() > def->getStatSPE()) : (atkTurn.attackUsed->getPriority() > defTurn.attackUsed->getPriority());
        } else {
            atkFirst = !atkDone;
        }

        if(!atkDone || !defDone) {
            if(atkFirst) {
                if(!atkDone && canAttack(atk, &atkTurn)) {
                    atkTurn.attackUsed->attack(*atk, *def, actionsQueue, true);
                }
                actionsQueue.push(next);
                if(!defDone && canAttack(def, &defTurn) && !checkBattleEnd()) {
                    defTurn.attackUsed->attack(*def, *atk, actionsQueue, false);
                }

                checkBattleEnd();

            } else {
                if(!defDone && canAttack(def, &defTurn)) {
                    defTurn.attackUsed->attack(*def, *atk, actionsQueue, false);
                }
                actionsQueue.push(next);
                if(!atkDone && canAttack(atk, &atkTurn) && !checkBattleEnd()) {
                    atkTurn.attackUsed->attack(*atk, *def, actionsQueue, true);
                }
                checkBattleEnd();
            }
        }

        return false;
    }

#pragma GCC diagnostic ignored "-Wunused-parameter"
    bool BattleCtrl::canAttack(OpMon *opmon, Elements::TurnData *opTurn) {
        bool canAttack = true;
        std::vector<sf::String *> opName(1);
        opName[0] = new sf::String(opmon->getNickname());
        //Checks if frozen
        if(opmon->getStatus() == Status::FROZEN) {
            //The OpMon have one chance out of 5 to be able to move again.
            if(Utils::Misc::randU(5) == 2) {
                actionsQueue.push(Elements::createTurnDialogAction({Utils::OpString("battle.status.frozen.out", opName)}));
                opmon->setStatus(Status::NOTHING);
            } else {
                actionsQueue.push(Elements::createTurnDialogAction({Utils::OpString("battle.status.frozen.attack", opName)}));
                canAttack = false;
            }
            //Checks if sleeping
        } else if(opmon->getStatus() == Status::SLEEPING) {
            //Checks the sleep counter.
            if(opmon->getSleepingCD() <= 0) {
                actionsQueue.push(Elements::createTurnDialogAction({Utils::OpString("battle.status.sleep.out", opName)}));
                opmon->setStatus(Status::NOTHING);
            } else {
                actionsQueue.push(Elements::createTurnDialogAction({Utils::OpString("battle.status.sleep.attack", opName)}));
                canAttack = false;
                opmon->passCD(true);
            }
            //Checks if paralysed
        } else if(opmon->getStatus() == Status::PARALYSED) {
            //The opmon have one chance out of three to can't attack when paralysed
            if(Utils::Misc::randU(4) == 2) {
                actionsQueue.push(Elements::createTurnDialogAction(Utils::OpString("battle.status.paralysed.attack.fail", opName)));
                canAttack = false;
            } else {
                actionsQueue.push(Elements::createTurnDialogAction(Utils::OpString("battle.status.paralysed.attack.success", opName)));
            }
        }
        //Checks if confused
        if(opmon->confused) {
            //Checks the confused counter
            if(opmon->getConfusedCD() <= 0) {
                opmon->confused = false;
                actionsQueue.push(Elements::createTurnDialogAction({Utils::OpString("battle.status.confused.out", opName)}));
            } else {
                opmon->passCD(false);
                //The OpMon have one chance out of two of failing their attack.
                if(Utils::Misc::randU(2) == 1) {
                    actionsQueue.push(Elements::createTurnDialogAction({Utils::OpString("battle.status.confused.attack.fail", opName)}));
                    opmon->attacked(opmon->getStatHP() / 8);
                } else {
                    actionsQueue.push(Elements::createTurnDialogAction(Utils::OpString("battle.status.confused.attack.success", opName)));
                }
            }
        }
        //Checks if afraid
        if(opmon->afraid) {
            actionsQueue.push(Elements::createTurnDialogAction({Utils::OpString("battle.status.afraid", opName)}));
            opmon->afraid = false;
            canAttack = false;
        }
        delete(opName[0]);
        return canAttack;
    }
#pragma GCC diagnostic pop

    void BattleCtrl::suspend() {
        data.getUiDataPtr()->getJukebox().pause();
    }

    void BattleCtrl::resume() {
        data.getUiDataPtr()->getJukebox().play("Wild Battle");
    }
} // namespace OpMon
