#include "PlayerCtrl.hpp"

namespace OpMon{
  namespace Controller{
    void PlayerCtrl::checkMove(Player& player, sf::Event const& events, View::Overworld const& overworld){
      switch(events){
      case sf::Event::KeyPressed:
	if(events.key.code == sf::Keyboard::F5) {
	    player.tp("Mom's room", sf::Vector2i(0, 1), true);
	  } else if(events.key.code == sf::Keyboard::F6) {
	    player.tp("Player's room", sf::Vector2i(0, 0), true);
	  } else if(events.key.code == sf::Keyboard::F1) {
	    player.tp("Fauxbourg Euvi", sf::Vector2i(25, 28), true);
	  } else if(events.key.code == sf::Keyboard::F2) {
	    player.tp("Player's home", sf::Vector2i(8, 14), true);
	  } else if(events.key.code == sf::Keyboard::F3) {
	    player.tp("Laboratory", sf::Vector2i(15, 14), true);
	  } else if(events.key.code == sf::Keyboard::F4) {
	    player.tp("Rival's house", sf::Vector2i(8, 14), true);
	  } else if(events.key.code == sf::Keyboard::F7){
	    player.tp("Route 14", sf::Vector2i(0, 31), true);
	  } else if(events.key.code == sf::Keyboard::F8){
	    player.tp("MysteriouCity", sf::Vector2i(12, 0), true);
	  }
	break;
      }
      if(!overworld.justTp) {
	if(isKeyPressed(sf::Keyboard::Up)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_UP);
	} else if(isKeyPressed(sf::Keyboard::Down)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_DOWN);
	} else if(isKeyPressed(sf::Keyboard::Left)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_LEFT);
	} else if(isKeyPressed(sf::Keyboard::Right)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_RIGHT);
	}
      }

      
    }

    void move(Side direction, Player& player){
      player.getPosition().move(direction);
      EventsCtrl::actionEvent(Model::Data::World::maps.at(player.getPosition().getMapId()).getEvent(gameloop.getPlayer().getPosition().getPositionPixel()), player, Events::EventTrigger::GO_IN);

    }
  }
}
