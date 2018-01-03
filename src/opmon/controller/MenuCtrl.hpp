#ifndef MENUCTRL_HPP
#define MENUCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "../view/OptionsMenu.hpp"

namespace OpMon{
  namespace Controller{
    namespace MenuCtrl{
      GameStatus checkEvents(sf::Event& event, View::MainMenu& menu);
      namespace Options{
	GameStatus checkEvents(sf::Event& event, View::OptionsMenu& menu);
      }
    }
  }
}

#endif
