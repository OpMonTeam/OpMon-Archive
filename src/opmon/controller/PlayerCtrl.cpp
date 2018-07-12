#include "PlayerCtrl.hpp"

#include "EventsCtrl.hpp"

namespace OpMon {
    namespace Controller {
        void PlayerCtrl::checkMove(Model::Player &player, sf::Event const &events, View::Overworld &overworld) {
            if(events.type == sf::Event::KeyPressed) {
                if(events.key.code == sf::Keyboard::F5) {
                    overworld.tp("Mom's room", sf::Vector2i(4, 4));
                } else if(events.key.code == sf::Keyboard::F6) {
                    overworld.tp("Player's room", sf::Vector2i(2, 4));
                } else if(events.key.code == sf::Keyboard::F1) {
                    overworld.tp("Fauxbourg Euvi", sf::Vector2i(26, 29));
                } else if(events.key.code == sf::Keyboard::F2) {
                    overworld.tp("Player's home", sf::Vector2i(10, 15));
                } else if(events.key.code == sf::Keyboard::F3) {
                    overworld.tp("Laboratory", sf::Vector2i(15, 14));
                } else if(events.key.code == sf::Keyboard::F4) {
                    overworld.tp("Rival's house", sf::Vector2i(8, 14));
                } else if(events.key.code == sf::Keyboard::F7) {
                    overworld.tp("Route 14", sf::Vector2i(9, 40));
                } else if(events.key.code == sf::Keyboard::F8) {
                    overworld.tp("MysteriouCity", sf::Vector2i(15, 15));
                } else if(events.key.code == sf::Keyboard::F9) {
                    overworld.tp("OpCenter", sf::Vector2i(9, 17));
                }
            }
	    
            if(!overworld.justTp && !player.getPosition().isAnim() && !player.getPosition().isLocked()) {
	      if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyUp())) {
		  overworld.setStartFrames();
                    move(Model::Side::TO_UP, player, overworld);
                } else if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyDown())) {
                    overworld.setStartFrames();
                    move(Model::Side::TO_DOWN, player, overworld);
                } else if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyLeft())) {
                    overworld.setStartFrames();
                    move(Model::Side::TO_LEFT, player, overworld);
                } else if(sf::Keyboard::isKeyPressed(overworld.getData().getUiDataPtr()->getKeyRight())) {
                    overworld.setStartFrames();
                    move(Model::Side::TO_RIGHT, player, overworld);
                }
            }
        }

        void PlayerCtrl::move(Model::Side direction, Model::Player &player, View::Overworld &overworld) {
	  player.getPosition().move(direction, overworld.getData().getCurrentMap());

            Model::Map *map = overworld.getData().getCurrentMap();
            auto eventList = map->getEvent(player.getPosition().getPosition());
            EventsCtrl().actionEvents(eventList, player, Model::Events::EventTrigger::GO_IN, overworld);
        }
    } // namespace Controller
} // namespace OpMon
