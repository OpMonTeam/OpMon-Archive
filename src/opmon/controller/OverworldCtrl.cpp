/*
OverworldCtrl.cpp
Author : Cyrielle
Contributors : BAKFR, Navet56
File under GNU GPL v3.0 license
*/
#include "OverworldCtrl.hpp"

#include "../model/objects/Attacks.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "AnimationCtrl.hpp"
#include "BattleCtrl.hpp"
#include "GameMenuCtrl.hpp"
#include "PlayerCtrl.hpp"

//Defines created to make the code easier to read
#define LOAD_BATTLE 1
#define LOAD_MENU_OPEN 2
#define LOAD_MENU 3
#define LOAD_MENU_CLOSE 4

namespace OpMon::Controller {

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
        EventsCtrl::checkAction(event, player, view);
        Controller::PlayerCtrl::checkMove(player, view);

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
            EventsCtrl::updateEvents(data.getMap(player.getMapId())->getEvents(), player, view);
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
            _next_gs = std::make_unique<AnimationCtrl>(std::make_unique<View::Animations::WooshAnim>(screenTexture, data.getGameMenuData().getMenuTexture(), View::Animations::WooshSide::UP, 15, true));
            break;
        case LOAD_MENU:
            _next_gs = std::make_unique<GameMenuCtrl>(data.getGameMenuData(), player);
            break;
        case LOAD_MENU_CLOSE:
            _next_gs = std::make_unique<AnimationCtrl>(std::make_unique<View::Animations::WooshAnim>(screenTexture, data.getGameMenuData().getMenuTexture(), View::Animations::WooshSide::DOWN, 15, false));
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

} // namespace OpMon::Controller
