#ifndef PLAYERCTRL_HPP
#define PLAYERCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Player.hpp"
#include "../model/sysObjects/Events.hpp"
#include "../view/Overworld.hpp"


namespace OpMon{
  namespace Controller{
    namespace PlayerCtrl{
      void checkMove(Model::Player& player, sf::Event const& events, View::Overworld & overworld);
      void move(Model::Side direction, Model::Player& player);
    }
  }
}

#endif
