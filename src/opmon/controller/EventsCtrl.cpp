/*
EventsCtrl.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "EventsCtrl.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "../model/objects/Enums.hpp"
#include "../model/sysObjects/Map.hpp"
#include "../view/Overworld.hpp"

namespace OpMon::Controller {
    void EventsCtrl::checkAction(sf::Event const &event, Model::Player &player, View::Overworld &overworld) {
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
        //Searches and activate the event which activate when the player is in the same square than the event.
        if(!player.getPosition().isMoving()) {
            std::vector<Model::Event *> eventList = overworld.getData().getCurrentMap()->getEvent(player.getPosition().getPosition());
            actionEvents(eventList, player, Model::Events::EventTrigger::BE_IN, overworld);
        }
    }

    void EventsCtrl::actionEvents(std::vector<Model::Event *> &events, Model::Player &player, Model::Events::EventTrigger toTrigger, View::Overworld &overworld) {
        //Checks if the player points at the right direction to activate the events. If yes, calls the events' action methods.
        Model::Side ppDir = player.getPosition().getDir();
        for(auto &event : events) {
            if(event->getEventTrigger() == toTrigger) {
                bool go = false;
                if(((event->getSide() & SIDE_UP) == SIDE_UP) && ppDir == Model::Side::TO_UP) {
                    go = true;
                } else if(((event->getSide() & SIDE_DOWN) == SIDE_DOWN) && ppDir == Model::Side::TO_DOWN) {
                    go = true;
                } else if(((event->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && ppDir == Model::Side::TO_RIGHT) {
                    go = true;
                } else if(((event->getSide() & SIDE_LEFT) == SIDE_LEFT) && ppDir == Model::Side::TO_LEFT) {
                    go = true;
                }
                if(go) {
                    event->action(player, overworld);
                }
            }
        }
    }

    void EventsCtrl::updateEvents(std::vector<Model::Event *> &events, Model::Player &player, View::Overworld &overworld) {
        for(Model::Event *event : events) {
            event->update(player, overworld);
        }
    }
} // namespace OpMon::Controller
