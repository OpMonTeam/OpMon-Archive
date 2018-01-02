#include "BaseCtrl.hpp"


namespace OpMon{
  sf::Event events;
  GameStatus Controller::checkQuit(sf::Event& event){
    switch (events.type) {
    case sf::Event::Closed:
      return GameStatus::STOP;
    default:
      break;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
      return GameStatus::STOP;
    }
    return GameStatus::CONTINUE;
  }
}
