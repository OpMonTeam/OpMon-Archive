#ifndef MENUCTRL_HPP
#define MENUCTRL_HPP

namespace OpMon{
  namespace Controller{
    namespace MenuCtrl{
      GameStatus checkEvents(sf::Events& event, View::MainMenu& menu);
      namespace Options{
	GameStatus checkEvents(sf::Event& event, View::OptionsMenu& menu);
      }
    }
  }
}

#endif
