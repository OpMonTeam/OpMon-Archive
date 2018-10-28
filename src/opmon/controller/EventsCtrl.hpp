/*
EventsCtrl.hpp
Author : Cyrion
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef EVENTSCTRL_HPP
#define EVENTSCTRL_HPP

#include <vector>

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Events.hpp"

namespace OpMon {
    namespace Controller {
        //Class used to activate and update the events.
        class EventsCtrl {
          public:
            static void updateEvents(std::vector<Model::Event *> &events, Model::Player &player, View::Overworld &overworld);
            static void actionEvents(std::vector<Model::Event *> &events, Model::Player &player, Model::Events::EventTrigger toTrigger, View::Overworld &overworld);
            static void checkAction(sf::Event const &event, Model::Player &player, View::Overworld &overworld);
        };
    } // namespace Controller
} // namespace OpMon

#endif
