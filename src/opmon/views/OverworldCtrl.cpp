/*
OverworldCtrl.cpp
Author : Cyrielle
Contributors : BAKFR, Navet56
File under GNU GPL v3.0 license
*/
#include "OverworldCtrl.hpp"

#include "../objects/Attacks.hpp"
#include "../objects/OpMon.hpp"
#include "../objects/OpTeam.hpp"
#include "AnimationCtrl.hpp"
#include "BattleCtrl.hpp"
#include "GameMenuCtrl.hpp"

//Defines created to make the code easier to read
#define LOAD_BATTLE 1
#define LOAD_MENU_OPEN 2
#define LOAD_MENU 3
#define LOAD_MENU_CLOSE 4

namespace OpMon {
    namespace Controller {

        OverworldCtrl::OverworldCtrl(Model::Player &player, Model::UiData *uidata)
          : data(uidata, &player)
          , view("Player's room", this->data)
          , player(player) {}

        GameStatus OverworldCtrl::checkEvent(sf::Event const &events) {
            if(loadNext == LOAD_MENU_OPEN) {
                loadNext = LOAD_MENU;
                return GameStatus::NEXT_NLS;
            } else if(loadNext == LOAD_MENU) {
                loadNext = LOAD_MENU_CLOSE;
                return GameStatus::NEXT_NLS;
            }
            auto &overworld = view;

            bool is_dialog_open = overworld.getDialog() && !overworld.getDialog()->isDialogOver();

            switch(events.type) {
            case sf::Event::KeyPressed:
                //The key equals starts the debug mode
                if(events.key.code == sf::Keyboard::Equal) {
                    debugMode = !debugMode;
                    if(!debugMode) {
                        debugCol = false;
                        overworld.setCameraLock(false);
                    }
                }
                //M reboots the game
                /*if(events.key.code == sf::Keyboard::M) {
                    reboot = true;
                    return GameStatus::STOP;
                }*/
                if(debugMode) {
                    //Debug, chooses the layers to print
                    if(events.key.code == sf::Keyboard::F10) {
                        overworld.printlayer[0] = !overworld.printlayer[0];
                    }
                    if(events.key.code == sf::Keyboard::F11) {
                        overworld.printlayer[1] = !overworld.printlayer[1];
                    }
                    if(events.key.code == sf::Keyboard::F12) {
                        overworld.printlayer[2] = !overworld.printlayer[2];
                    }

                    if(events.key.code == sf::Keyboard::C) {
                        overworld.printCollisions = !overworld.printCollisions;
                    }
                    if(events.key.code == sf::Keyboard::N) {
                        debugCol = !debugCol;
                    }
                    if(events.key.code == sf::Keyboard::Numpad5) {
                        overworld.setCameraLock(!overworld.isCameraLocked());
                    }
                    if(events.key.code == sf::Keyboard::PageUp) {
                        data.decrementItorMap();
                        overworld.tp(data.getCurrentItorMap(), sf::Vector2i(5, 5));
                    }
                    if(events.key.code == sf::Keyboard::PageDown) {
                        data.incrementItorMap();
                        overworld.tp(data.getCurrentItorMap(), sf::Vector2i(5, 5));
                    }
                    if(events.key.code == sf::Keyboard::B) {
                        overworld.tp("Road 14", sf::Vector2i(10, 32));
                    }
                }
                if(events.key.code == sf::Keyboard::M) {
                    loadNext = LOAD_MENU_OPEN;
                    return GameStatus::NEXT_NLS;
                }
            default:
                break;
            }
            if(overworld.isCameraLocked()) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
                    overworld.moveCamera(Model::Side::TO_DOWN);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
                    overworld.moveCamera(Model::Side::TO_LEFT);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
                    overworld.moveCamera(Model::Side::TO_UP);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
                    overworld.moveCamera(Model::Side::TO_RIGHT);
                }
            }

            return is_dialog_open ? checkEventsDialog(events, overworld) : checkEventsNoDialog(events, player);
        }

        GameStatus OverworldCtrl::checkEventsDialog(sf::Event const &events, View::Overworld &overworld) {
            switch(events.type) {
            case sf::Event::KeyPressed:
                if(events.key.code == data.getUiDataPtr()->getKeyTalk()) {
                    overworld.getDialog()->pass();
                }
                break;
            default:
                break;
            }
            return GameStatus::CONTINUE;
        }

        GameStatus OverworldCtrl::checkEventsNoDialog(sf::Event const &event, Model::Player &player) {
            checkAction(event, player, view);
            checkMove(player, view);

            if(view.getBattleDeclared() != nullptr) {
                if(view.getBattleDeclared()->isDefeated()) {
                    view.endBattle();
                } else {
                    loadNext = LOAD_BATTLE;
                    return GameStatus::NEXT;
                }
            }

            return GameStatus::CONTINUE;
        }

        GameStatus OverworldCtrl::update(sf::RenderTexture &frame) {
            bool is_dialog_open = view.getDialog() && !view.getDialog()->isDialogOver();
            if(!is_dialog_open) {
                updateEvents(data.getMap(player.getMapId())->getEvents(), player, view);
            }

            GameStatus toReturn = view(frame);
            screenTexture = frame.getTexture();
            return toReturn;
        }

        void OverworldCtrl::loadNextScreen() {
            data.getGameMenuData().setBackground(screenTexture);
            switch(loadNext) {
            case LOAD_BATTLE:
                _next_gs = std::make_unique<BattleCtrl>(data.getPlayer().getOpTeam(), view.getBattleDeclared(), data.getUiDataPtr(), data.getPlayerPtr());
                break;
            case LOAD_MENU_OPEN:
                _next_gs = std::make_unique<AnimationCtrl>(std::make_unique<View::Animations::WooshAnim>(screenTexture, data.getGameMenuData().getMenuTexture(), View::Animations::WooshDir::UP, 15, true));
                break;
            case LOAD_MENU:
                _next_gs = std::make_unique<GameMenuCtrl>(data.getGameMenuData(), player);
                break;
            case LOAD_MENU_CLOSE:
                _next_gs = std::make_unique<AnimationCtrl>(std::make_unique<View::Animations::WooshAnim>(screenTexture, data.getGameMenuData().getMenuTexture(), View::Animations::WooshDir::DOWN, 15, false));
                break;
            default:
                handleError("Error : Unknown view to load in OverworldCtrl", true);
            }
        }

        void OverworldCtrl::suspend() {
            if(loadNext == LOAD_BATTLE) {
                data.getUiDataPtr()->getJukebox().pause();
            }
        }

        void OverworldCtrl::resume() {
            data.getUiDataPtr()->getJukebox().play(data.getCurrentMap()->getBg());
        }

        void OverworldCtrl::checkMove(Model::Player &player, View::Overworld &overworld) {
            if(!overworld.justTp && !player.getPosition().isAnim() && !player.getPosition().isLocked()) {
                //TODO Factorise code
                if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyUp())) {
                    overworld.startPlayerAnimation();
                    move(Model::Side::TO_UP, player, overworld);
                } else if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyDown())) {
                    overworld.startPlayerAnimation();
                    move(Model::Side::TO_DOWN, player, overworld);
                } else if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyLeft())) {
                    overworld.startPlayerAnimation();
                    move(Model::Side::TO_LEFT, player, overworld);
                } else if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyRight())) {
                    overworld.startPlayerAnimation();
                    move(Model::Side::TO_RIGHT, player, overworld);
                }
            }
        }

        void OverworldCtrl::move(Model::Side direction, Model::Player &player, View::Overworld &overworld) {
            player.getPosition().move(direction, overworld.getData().getCurrentMap());

            Model::Map *map = overworld.getData().getCurrentMap();
            auto eventList = map->getEvent(player.getPosition().getPosition());
            actionEvents(eventList, player, Model::Events::EventTrigger::GO_IN, overworld);
        }

        void OverworldCtrl::checkAction(sf::Event const &event, Model::Player &player, View::Overworld &overworld) {
            //If the player isn't moving, then this checks if the player want to activate an event.
            if(!player.getPosition().isAnim()) {
                //Get the event coordinates and activate it if the player interacted with it.
                if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyInteract())) {
                    int lx = player.getPosition().getPosition().x;
                    int ly = player.getPosition().getPosition().y;
                    switch(player.getPosition().getDir()) {
                    case Model::Side::TO_UP:
                        ly--;
                        break;
                    case Model::Side::TO_DOWN:
                        ly++;
                        break;
                    case Model::Side::TO_LEFT:
                        lx--;
                        break;
                    case Model::Side::TO_RIGHT:
                        lx++;
                        break;
                    default:
                        break;
                    }

                    std::vector<Model::Event *> eventList = overworld.getData().getCurrentMap()->getEvent(sf::Vector2i(lx, ly));
                    actionEvents(eventList, player, Model::Events::EventTrigger::PRESS, overworld);
                }
            }

            //Searches for events at the same position as the player and activates them if they are triggered when the playeris in them.
            if(!player.getPosition().isMoving()) {
                std::vector<Model::Event *> eventList = overworld.getData().getCurrentMap()->getEvent(player.getPosition().getPosition());
                actionEvents(eventList, player, Model::Events::EventTrigger::BE_IN, overworld);
            }
        }

        void OverworldCtrl::actionEvents(std::vector<Model::Event *> &events, Model::Player &player, Model::Events::EventTrigger toTrigger, View::Overworld &overworld) {
            //Checks if the player points at the right direction to activate the events. If yes, calls the events' action methods.
            Model::Side ppDir = player.getPosition().getDir();
            for(unsigned int i = 0; i < events.size(); i++) {
                if(events[i]->getEventTrigger() == toTrigger) {
                    bool go = false;
                    if(((events[i]->getSide() & SIDE_UP) == SIDE_UP) && ppDir == Model::Side::TO_UP) {
                        go = true;
                    } else if(((events[i]->getSide() & SIDE_DOWN) == SIDE_DOWN) && ppDir == Model::Side::TO_DOWN) {
                        go = true;
                    } else if(((events[i]->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && ppDir == Model::Side::TO_RIGHT) {
                        go = true;
                    } else if(((events[i]->getSide() & SIDE_LEFT) == SIDE_LEFT) && ppDir == Model::Side::TO_LEFT) {
                        go = true;
                    }
                    if(go) {
                        events[i]->action(player, overworld);
                    }
                }
            }
        }

        void OverworldCtrl::updateEvents(std::vector<Model::Event *> &events, Model::Player &player, View::Overworld &overworld) {
            for(Model::Event *event : events) {
                event->update(player, overworld);
            }
        }

    } // namespace Controller
} // namespace OpMon
