/*
PlayerCtrl.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "PlayerCtrl.hpp"

#include "EventsCtrl.hpp"

namespace OpMon {
    namespace Controller {
        void PlayerCtrl::checkMove(Model::Player &player, View::Overworld &overworld) {
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

        void PlayerCtrl::move(Model::Side direction, Model::Player &player, View::Overworld &overworld) {
            player.getPosition().move(direction, overworld.getData().getCurrentMap());

            Model::Map *map = overworld.getData().getCurrentMap();
            auto eventList = map->getEvent(player.getPosition().getPosition());
            EventsCtrl::actionEvents(eventList, player, Model::Events::EventTrigger::GO_IN, overworld);
        }
    } // namespace Controller
} // namespace OpMon
