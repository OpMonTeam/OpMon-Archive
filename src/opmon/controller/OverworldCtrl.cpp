#include "OverworldCtrl.hpp"

#include "../model/storage/Data.hpp"
#include "EventsCtrl.hpp"
#include "PlayerCtrl.hpp"

namespace OpMon {
    namespace Controller {

        OverworldCtrl::OverworldCtrl(Model::Player &player)
          : view("Player's home")
          , player(player) {}

        GameStatus OverworldCtrl::checkEvent(sf::Event const &events) {
            auto &overworld = view;

            bool is_dialog_open = overworld.getDialog() && !overworld.getDialog()->isDialogOver();

            switch(events.type) {
            case sf::Event::KeyPressed:
                if(events.key.code == sf::Keyboard::Equal) {
                    debugMode = !debugMode;
                    if(!debugMode) {
                        debugCol = false;
                        camUnlock = false;
                    }
                }
								if(events.key.code == sf::Keyboard::M) {
									reboot = true;
									return GameStatus::STOP;
								}
                if(debugMode) {
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
                        camUnlock = !camUnlock;
                    }
                }
            default:
                break;
            }
            if(camUnlock) {
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

            if(is_dialog_open) {
                return checkEventsDialog(events, overworld);
            } else {
                return checkEventsNoDialog(events, player);
            }
        }

        GameStatus OverworldCtrl::checkEventsDialog(sf::Event const &events, View::Overworld &overworld) {
            switch(events.type) {
            case sf::Event::KeyPressed:
                if(events.key.code == sf::Keyboard::Space) {
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
            Controller::PlayerCtrl::checkMove(player, event, view);
            return GameStatus::CONTINUE;
        }

        GameStatus OverworldCtrl::update() {
	  bool is_dialog_open = view.getDialog() && !view.getDialog()->isDialogOver();
	  if(!is_dialog_open){
            EventsCtrl::updateEvents(Model::Data::World::maps.at(player.getMapId())->getEvents(), player, view);
	  }
            //TODO: pass frame
            return view(getFrames());
        }

    } // namespace Controller
} // namespace OpMon
