#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

namespace OpMon{
  namespace Controller{
    namespace OverworldCtrl{
      GameStatus checkEvents(sf::Event& events);
      void move(Side direction);
    }
  }
}

#endif
