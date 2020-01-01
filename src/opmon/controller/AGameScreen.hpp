/*!
 * \file AGameScreen.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "../start/GameStatus.hpp"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

namespace OpMon {
    namespace Controller {

        /*!
         * \brief Interface of all first-level controllers.
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
            AGameScreen() = default;
            virtual ~AGameScreen() = default;

            /*!
             * \brief Processes a new SFML Input (keyboard, mouse, ...).
             */
            virtual GameStatus checkEvent(sf::Event const &) { return GameStatus::CONTINUE; }

            /*!
             * \brief Updates and draws the game.
             *
             * This method is called once per frame.
             */
            virtual GameStatus update(sf::RenderTexture &frame) = 0;

            virtual void suspend(){};
            virtual void resume(){};

            /*!
             * \brief Loads the next screen.
             * \details Method called by Gameloop when the status returned is GameStatus::NEXT. It loads the next screen in _next_gs
            */
            virtual void loadNextScreen(){};

            std::unique_ptr<AGameScreen> getNextGameScreen() { return std::move(_next_gs); };

          protected:
            /*!
             * \brief The next screen, loaded after loadNextScreen has been called.
             */
            std::unique_ptr<AGameScreen> _next_gs;
        };

    } // namespace Controller
} // namespace OpMon
