#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

namespace OpMon{
  namespace Controller{
    namespace OverworldCtrl{
      void checkEvents(sf::Event const& events, View::Overworld& overworld, Player& player);
      void checkEventsDialog(sf::Event const& events, View::Overworld& overworld);
      void checkEventsNoDialog(sf::Event const& events, Player& player);
    }
  }
}

#endif
