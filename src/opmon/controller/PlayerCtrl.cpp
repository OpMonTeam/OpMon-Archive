#include "PlayerCtrl.hpp"

#include "EventsCtrl.hpp"
#include "../model/storage/Data.hpp"

namespace OpMon{
  namespace Controller{
    void PlayerCtrl::checkMove(Model::Player& player, sf::Event const& events, View::Overworld const& overworld){
      switch(events.type){
      case sf::Event::KeyPressed:
	if(events.key.code == sf::Keyboard::F5) {
	  player.tp("Mom's room", sf::Vector2i(0, 1));
	} else if(events.key.code == sf::Keyboard::F6) {
	  player.tp("Player's room", sf::Vector2i(0, 0));
	} else if(events.key.code == sf::Keyboard::F1) {
	  player.tp("Fauxbourg Euvi", sf::Vector2i(25, 28));
	} else if(events.key.code == sf::Keyboard::F2) {
	  player.tp("Player's home", sf::Vector2i(8, 14));
	} else if(events.key.code == sf::Keyboard::F3) {
	  player.tp("Laboratory", sf::Vector2i(15, 14));
	} else if(events.key.code == sf::Keyboard::F4) {
	  player.tp("Rival's house", sf::Vector2i(8, 14));
	} else if(events.key.code == sf::Keyboard::F7){
	  player.tp("Route 14", sf::Vector2i(0, 31));
	} else if(events.key.code == sf::Keyboard::F8){
	  player.tp("MysteriouCity", sf::Vector2i(12, 0));
	}
	break;
      }
      if(!overworld.justTp) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	  player.getPosition().move(Model::Side::TO_UP);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	  player.getPosition().move(Model::Side::TO_DOWN);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	  player.getPosition().move(Model::Side::TO_LEFT);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	  player.getPosition().move(Model::Side::TO_RIGHT);
	}
      }

      
    }

    void move(Model::Side direction, Model::Player& player, View::Overworld& overworld){
      player.getPosition().move(direction);
      EventsCtrl::actionEvents(Model::Data::World::maps.at(player.getMapId())->getEvent(player.getPosition().getPositionPixel()), player, Model::Events::EventTrigger::GO_IN, overworld);

    }
  }
}
