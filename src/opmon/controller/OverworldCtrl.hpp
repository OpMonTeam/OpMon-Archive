#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Player.hpp"
#include "../start/Core.hpp"
#include "../view/Overworld.hpp"
#include "AGameScreen.hpp"

namespace OpMon {
    namespace Controller {

        class OverworldCtrl : public AGameScreen {
          private:
            View::Overworld view;
            Model::Player &player;

          public:
            OverworldCtrl(Model::Player &player);
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus checkEventsDialog(sf::Event const &events, View::Overworld &overworld);
            GameStatus checkEventsNoDialog(sf::Event const &events, Model::Player &player);
            GameStatus update(sf::RenderTexture& frame) override;
        };

    } // namespace Controller
} // namespace OpMon

#endif
