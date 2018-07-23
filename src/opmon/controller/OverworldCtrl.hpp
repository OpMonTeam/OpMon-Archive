#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Player.hpp"
#include "../start/Core.hpp"
#include "../view/Overworld.hpp"
#include "AGameScreen.hpp"
#include "EventsCtrl.hpp"

namespace OpMon {
    namespace Controller {

        class OverworldCtrl : public AGameScreen {
          private:
            Model::OverworldData data;

            View::Overworld view;
            Model::Player &player;

            EventsCtrl eventsctrl;

          public:
            OverworldCtrl(Model::Player &player, Model::UiData *uidata);
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus checkEventsDialog(sf::Event const &events, View::Overworld &overworld);
            GameStatus checkEventsNoDialog(sf::Event const &events, Model::Player &player);
            GameStatus update(sf::RenderTexture &frame) override;
        };

    } // namespace Controller
} // namespace OpMon

#endif
