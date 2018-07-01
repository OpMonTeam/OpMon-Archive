#include "EventsCtrl.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "../model/objects/Enums.hpp"
#include "../model/storage/Data.hpp"
#include "../model/sysObjects/Map.hpp"

namespace OpMon {
    namespace Controller {
#pragma GCC diagnostic ignored "-Wunused-parameter"
        void EventsCtrl::checkAction(sf::Event const &event, Model::Player &player, View::Overworld &overworld) {
            if(!player.getPosition().isAnim()) {
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
#pragma GCC diagnostic pop

            if(!player.getPosition().isMoving()) {
	      std::vector<Model::Event *> eventList = overworld.getData().getCurrentMap()->getEvent(player.getPosition().getPosition());
                actionEvents(eventList, player, Model::Events::EventTrigger::BE_IN, overworld);
            }
        }

        void EventsCtrl::actionEvents(std::vector<Model::Event *> &events, Model::Player &player, Model::Events::EventTrigger toTrigger, View::Overworld &overworld) {
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

        void EventsCtrl::updateEvents(std::vector<Model::Event *> &events, Model::Player &player, View::Overworld &overworld) {
            for(Model::Event *event : events) {
                event->update(player, overworld);
            }
        }
    } // namespace Controller
} // namespace OpMon
