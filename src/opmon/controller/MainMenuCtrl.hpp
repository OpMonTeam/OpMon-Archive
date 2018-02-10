
#pragma once

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "AGameScreen.hpp"

namespace OpMon {
    namespace Controller {

        class MainMenuCtrl : public AGameScreen {
          private:
            View::MainMenu view;
	  sf::Sound nope;
	  sf::Sound arrow;
	  sf::Sound push;
          public:
            MainMenuCtrl();
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update() override;
            void suspend() override;
            void resume() override;
        };

    } // namespace Controller
} // namespace OpMon
