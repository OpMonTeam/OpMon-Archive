#ifndef EVENTSCTRL_HPP
#define EVENTSCTRL_HPP

#include <vector>

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Events.hpp"

namespace OpMon {
  namespace Controller {
    namespace EventsCtrl {
      void updateEvents(std::vector<Model::Event *> &events, Model::Player &player);

      void
      actionEvents(std::vector<Model::Event *> &events, Model::Player &player, Model::Events::EventTrigger toTrigger);

      void checkAction(sf::Event const &event, Model::Player &player);
    }
  }
}

#endif
