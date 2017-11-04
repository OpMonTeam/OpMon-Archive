#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

namespace OpMon{
  namespace Controller{
    namespace OverworldCtrl{
      void checkEvents(sf::Event& events, View::Overworld& overworld);
      void move(Side direction);
      void checkEventsDialog(sf::Event& events, View::Overworld& overworld);
      void checkEventsNoDialog(sf::Event& events, View::Overworld& overworld);
    }
  }
}

#endif
