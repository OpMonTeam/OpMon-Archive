#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/Overworld.hpp"
#include "../model/sysObjects/Player.hpp"

namespace OpMon{
  namespace Controller{
    namespace OverworldCtrl{
      GameStatus checkEvents(sf::Event const& events, View::Overworld& overworld, bool dialog, Model::Player& player);
      GameStatus checkEventsDialog(sf::Event const& events, View::Overworld& overworld);
      GameStatus checkEventsNoDialog(sf::Event const& events, Model::Player& player);
    }
  }
}

#endif
