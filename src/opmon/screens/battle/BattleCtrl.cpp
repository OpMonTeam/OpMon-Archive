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
#include <string>

#include "src/opmon/core/GameData.hpp"
#include "src/opmon/core/Jukebox.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/model/Move.hpp"
#include "src/opmon/model/OpMon.hpp"
#include "src/opmon/model/OpTeam.hpp"
#include "src/opmon/model/Turn.hpp"
#include "src/opmon/screens/battle/Battle.hpp"
#include "src/opmon/screens/battle/BattleData.hpp"
#include "src/opmon/screens/overworld/events/BattleEvent.hpp"
#include "src/utils/OpString.hpp"
#include "src/utils/misc.hpp"
#include "src/utils/log.hpp"

namespace OpMon {

    BattleCtrl::BattleCtrl(OpTeam *one, BattleEvent *two, GameData *gamedata,
                           Player *player, OpMonData *opmondata)
        : BattleCtrl(one, two->getOpTeam(), gamedata, player, opmondata) {
        this->trainer = two;
        next.type = TurnActionType::NEXT;
    }

    BattleCtrl::BattleCtrl(OpTeam *one, OpTeam *two, GameData *gamedata,
                           Player *player, OpMonData *opmondata)
        : data(gamedata, player, opmondata),
          playerTeam(one),
          trainerTeam(two),
          atk(one->getOp(0)),
          def(two->getOp(0)),
          view(one, two, "beta", "grass", this->data) {
        initBattle(0, 0);
        next.type = TurnActionType::NEXT;
    }

    GameStatus BattleCtrl::update(sf::RenderTexture &frame) {
        GameStatus returned = view.update(atkTurn, defTurn, actionsQueue,
                                          &turnActivated, atkFirst);
        frame.draw(view);
        return returned;
    }

    GameStatus BattleCtrl::checkEvent(sf::Event const &event) {
        switch(event.type) {
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                        // Selection events
                    case sf::Keyboard::Left:
                        view.moveCur(Side::TO_LEFT);
                        data.getGameDataPtr()->getJukebox().playSound("arrow");
                        break;
                    case sf::Keyboard::Right:
                        data.getGameDataPtr()->getJukebox().playSound("arrow");
                        view.moveCur(Side::TO_RIGHT);
                        break;
                    case sf::Keyboard::Up:
                        data.getGameDataPtr()->getJukebox().playSound("arrow");
                        view.moveCur(Side::TO_UP);
                        break;
                    case sf::Keyboard::Down:
                        data.getGameDataPtr()->getJukebox().playSound("arrow");
                        view.moveCur(Side::TO_DOWN);
                        break;
                    case sf::Keyboard::Return:
                        // If it the move selection screen is not the active
                        // screen, and if the turn is not activated, the
                        // battle's main menu is printed.
                        if(!view.isMoveChoice() && !turnActivated) {
                            switch(view.getCurPos()) {
                                    // Currently, there is only one choice
                                    // avilable, the "move" choice.
                                case 0:
                                    view.toggleMoveChoice();
                                    break;
                                    /*case 3:
                                      return GameStatus::PREVIOUS; //Run*/
                                default:
                                    data.getGameDataPtr()
                                        ->getJukebox()
                                        .playSound("nope");
                                    break;
                            }

                        } else if(!turnActivated) { // In this case, the move
                                                    // selection screen is the
                                                    // active screen.
                            // Gets the selected move, checks if it isn't a
                            // invalid move (PP check and existence check), and
                            // then launches the turn.
                            atkTurn.moveUsed =
                                atk->getMoves()[view.getCurPos()];
                            if(atkTurn.moveUsed != nullptr) {
                                if(atkTurn.moveUsed->getPP() > 0) {
                                    atkTurn.type = TurnType::MOVE;
                                    turn();
                                    view.toggleMoveChoice();
                                    turnActivated = true;
                                }
                            } else { // The move is invalid
                                data.getGameDataPtr()->getJukebox().playSound(
                                    "nope");
                            }
                        } else if(turnActivated) {
                            view.passDialog();
                        }

                        break;
                    case sf::Keyboard::BackSpace:
                        // From the move selection screen, returns to the
                        // battle's main menu.
                        if(view.isMoveChoice()) {
                            view.toggleMoveChoice();
                        }
                        break;

                    case sf::Keyboard::Space:
                        // During the dialogs, passes to the next one.
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
        // Saves the OpMons' stats before the battle, to reset the stats after
        // it.
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

        oldMoves[0] = atk->getMoves();
        oldMoves[1] = def->getMoves();

        atk->setStat(Stats::EVA, 100);
        atk->setStat(Stats::ACC, 100);
        def->setStat(Stats::EVA, 100);
        def->setStat(Stats::ACC, 100);
        // Clear the turns
        newTurnData(&atkTurn);
        newTurnData(&defTurn);

        // Register the opmons' addresses in the Turns
        atkTurn.opmon = atk;
        defTurn.opmon = def;
    }

#pragma GCC diagnostic ignored "-Wunused-parameter"
    // Unfinished method, the IA will be programmed in the future.
    TurnData *BattleCtrl::turnIA(int level) {
        defTurn.moveUsed = def->getMoves()[0];
        defTurn.type = TurnType::MOVE;
        return &defTurn;
    }
#pragma GCC diagnostic pop

    bool BattleCtrl::checkBattleEnd() {
        if(def->getHP() <= 0 || atk->getHP() <= 0) {
            trainer->setOver();
            TurnAction batEnd;
            batEnd.type = (def->getHP() <= 0) ? TurnActionType::VICTORY :
                                                TurnActionType::DEFEAT;
            actionsQueue.push(batEnd);
            return true;
        }
        return false;
    }

    bool BattleCtrl::turn() {
        // These variables are used to check if the turn of one of the OpMons'
        // is over.
        bool atkDone = false;
        bool defDone = false;

        turnIA(0);

        if(!actionsQueue.empty()) {
            Utils::Log::warn(
                "Battle: Action queue not empty when beginning a new turn. "
                "Emptying it, hope it won't mess everything up. Good luck.");
            actionsQueue = std::queue<TurnAction>();
        }

        // Item use or switching always comes before the move. It is calculated
        // before everything else.
        if(atkTurn.type != TurnType::MOVE) {
            // Actions
            atkDone = true;
        }
        if(defTurn.type != TurnType::MOVE) {
            // Actions
            defDone = true;
        }
        // If the two of them move, then the priority must be calculated. Else,
        // the only attacking OpMon will move, obviously.
        if(defTurn.type == TurnType::MOVE && atkTurn.type == TurnType::MOVE) {
            atkFirst = (atkTurn.moveUsed->getPriority() ==
                        defTurn.moveUsed->getPriority()) ?
                           (atk->getStatSPE() > def->getStatSPE()) :
                           (atkTurn.moveUsed->getPriority() >
                            defTurn.moveUsed->getPriority());
        } else {
            atkFirst = !atkDone;
        }

        if(!atkDone || !defDone) {
            if(atkFirst) {
                if(!atkDone && canMove(atk, &atkTurn)) {
                    atkTurn.moveUsed->move(*atk, *def, actionsQueue, true);
                }
                actionsQueue.push(next);
                if(!defDone && canMove(def, &defTurn) && !checkBattleEnd()) {
                    defTurn.moveUsed->move(*def, *atk, actionsQueue, false);
                }

                checkBattleEnd();

            } else {
                if(!defDone && canMove(def, &defTurn)) {
                    defTurn.moveUsed->move(*def, *atk, actionsQueue, false);
                }
                actionsQueue.push(next);
                if(!atkDone && canMove(atk, &atkTurn) && !checkBattleEnd()) {
                    atkTurn.moveUsed->move(*atk, *def, actionsQueue, true);
                }
                checkBattleEnd();
            }
        }

        return false;
    }

#pragma GCC diagnostic ignored "-Wunused-parameter"
    bool BattleCtrl::canMove(OpMon *opmon, TurnData *opTurn) {
        bool canMove = true;
        std::vector<sf::String *> opName(1);
        opName[0] = new sf::String(opmon->getNickname());
        // Checks if frozen
        if(opmon->getStatus() == Status::FROZEN) {
            // The OpMon have one chance out of 5 to be able to move again.
            if(Utils::Misc::randU(5) == 2) {
                actionsQueue.push(createTurnDialogAction(
                    Utils::OpString(data.getGameDataPtr()->getStringKeys(),
                                    "battle.status.frozen.out", opName)));
                opmon->setStatus(Status::NOTHING);
            } else {
                actionsQueue.push(createTurnDialogAction(
                    Utils::OpString(data.getGameDataPtr()->getStringKeys(),
                                    "battle.status.frozen.move", opName)));
                canMove = false;
            }
            // Checks if sleeping
        } else if(opmon->getStatus() == Status::SLEEPING) {
            // Checks the sleep counter.
            if(opmon->getSleepingCD() <= 0) {
                actionsQueue.push(createTurnDialogAction(
                    Utils::OpString(data.getGameDataPtr()->getStringKeys(),
                                    "battle.status.sleep.out", opName)));
                opmon->setStatus(Status::NOTHING);
            } else {
                actionsQueue.push(createTurnDialogAction(
                    Utils::OpString(data.getGameDataPtr()->getStringKeys(),
                                    "battle.status.sleep.move", opName)));
                canMove = false;
                opmon->passCD(true);
            }
            // Checks if paralysed
        } else if(opmon->getStatus() == Status::PARALYSED) {
            // The opmon have one chance out of three to can't move when
            // paralysed
            if(Utils::Misc::randU(4) == 2) {
                actionsQueue.push(createTurnDialogAction(Utils::OpString(
                    data.getGameDataPtr()->getStringKeys(),
                    "battle.status.paralysed.move.fail", opName)));
                canMove = false;
            } else {
                actionsQueue.push(createTurnDialogAction(Utils::OpString(
                    data.getGameDataPtr()->getStringKeys(),
                    "battle.status.paralysed.move.success", opName)));
            }
        }
        // Checks if confused
        if(opmon->confused) {
            // Checks the confused counter
            if(opmon->getConfusedCD() <= 0) {
                opmon->confused = false;
                actionsQueue.push(createTurnDialogAction(
                    Utils::OpString(data.getGameDataPtr()->getStringKeys(),
                                    "battle.status.confused.out", opName)));
            } else {
                opmon->passCD(false);
                // The OpMon have one chance out of two of failing their move.
                if(Utils::Misc::randU(2) == 1) {
                    actionsQueue.push(createTurnDialogAction(Utils::OpString(
                        data.getGameDataPtr()->getStringKeys(),
                        "battle.status.confused.move.fail", opName)));
                    opmon->attacked(opmon->getStatHP() / 8);
                } else {
                    actionsQueue.push(createTurnDialogAction(Utils::OpString(
                        data.getGameDataPtr()->getStringKeys(),
                        "battle.status.confused.move.success", opName)));
                }
            }
        }
        // Checks if afraid
        if(opmon->afraid) {
            actionsQueue.push(createTurnDialogAction(
                Utils::OpString(data.getGameDataPtr()->getStringKeys(),
                                "battle.status.afraid", opName)));
            opmon->afraid = false;
            canMove = false;
        }
        delete(opName[0]);
        return canMove;
    }
#pragma GCC diagnostic pop

    void BattleCtrl::suspend() { data.getGameDataPtr()->getJukebox().pause(); }

    void BattleCtrl::resume() {
        data.getGameDataPtr()->getJukebox().play("Wild Battle");
    }
} // namespace OpMon
