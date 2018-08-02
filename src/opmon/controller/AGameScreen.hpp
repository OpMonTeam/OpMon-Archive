
#pragma once

#include "../start/GameStatus.hpp"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Event.hpp>

namespace OpMon {
    namespace Controller {

        /**
     * Interface of all first-level controllers.
     *
     * A game screen is handled by the GameLoop.
     * When running, two methods are called: processEvent() is called for each sf::Event detected, then update() is
     * called once per frame.
     *
     * In addition, suspend() and resume() are called when respectively the controller loose the focus (another
     * controller is added on top) and regain the focus.
     */
        class AGameScreen {
          public:
            AGameScreen()
              : _next_gs(nullptr) {}

            /**
       * process a new SFML Input (keyboard, mouse, ...).
       */
            virtual GameStatus checkEvent(sf::Event const &) { return GameStatus::CONTINUE; }

            /**
       * Update and draw the game.
       *
       * This method is called once per frame.
       */
            virtual GameStatus update(sf::RenderTexture &frame) = 0;

            virtual void suspend(){};
            virtual void resume(){};

            AGameScreen *getNextGameScreen() { return _next_gs; };
	  
            virtual ~AGameScreen() = default;

          protected:
            AGameScreen *_next_gs;
        };

    } // namespace Controller
} // namespace OpMon
