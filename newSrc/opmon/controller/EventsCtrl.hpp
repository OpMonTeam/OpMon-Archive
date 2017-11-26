#ifndef EVENTSCTRL_HPP
#define EVENTSCTRL_HPP

#include <vector>

namespace OpMon{
  namespace Controller{
    namespace EventsCtrl{
      void updateEvents(std::vector<Event*> events, Player& player);
      void actionEvents(std::vector<Event*> events, Player& player, EventTrigger eventTrigger);
      void checkAction(sf::Event const& event, Player& player);
    }
  }
}

#endif
