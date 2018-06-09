
#pragma once

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "../view/OptionsMenu.hpp"
#include "AGameScreen.hpp"

namespace OpMon {
    namespace Controller {

        class OptionsMenuCtrl : public AGameScreen {
          private:
            View::OptionsMenu view;
            sf::Sound nope = sf::Sound();
            sf::Sound arrow = sf::Sound();
            sf::Sound push = sf::Sound();
            void toggleVolume();
            void raiseVolume();
            void lowerVolume();

          public:
            OptionsMenuCtrl();
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update() override;

            void resume();
            void suspend();
        };

    } // namespace Controller
} // namespace OpMon
