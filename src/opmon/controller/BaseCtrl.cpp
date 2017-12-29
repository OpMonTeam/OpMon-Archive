#include "BaseCtrl.hpp"

namespace OpMon{
  sf::Event events;
  void Controller::checkQuit(){
    Model::Data::Ui::window.pollEvent(events);
    switch (events.type) {
    case sf::Event::Closed:
      Model::Data::endGame = true;
    default:
      break;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
	Model::Data::endGame = true;
    }
  }
}
