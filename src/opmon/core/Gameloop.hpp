/*!
 * \dir src/opmon/core
 * \brief Contains the core elements of the game.
 *
 * This directory contains the utilities, the main objects and the starting code
 * for the game.
 */
/*!
 * \file Gameloop.hpp
 * \authors Cyrielle
 * \authors Stelyus
 * \authors BAKFR
 * \authors Navet56
 * \copyright GNU GPL v3.0
 * \date 02/11/17
 */

#pragma once

#include <stack>

#include "AGameScreen.hpp"
#include "GameData.hpp"

namespace sf {
    class Event;
} // namespace sf

namespace OpMon {
    namespace Ui {
        class Window;
    } // namespace Ui

    /*!
      \class GameLoop Gameloop.hpp "src/start/Gameloop.hpp"
      \brief Class managing the game loop.
     */
    class GameLoop {
      public:
        GameLoop();
        ~GameLoop() = default;

        /*!
         * \brief Launches the loop.
         * \return GameStatus::STOP
         */
        GameStatus operator()();

        /*!
         * \brief Checks the event to know if the game must be stopped.
         * \param event The event checked.
         * \return GameStatus::STOP if escape is pressed or if the game is closed, GameStatus::CONTINUE if the game must continue.
         */
        GameStatus _checkQuit(const sf::Event &event);

        /*!
         * \brief Checks the event for window resize, and updates the window view if it's the case.
         * \param event The native SFML event
         * \param window A reference to the window in case an update is necessary
         */
        void _checkWindowResize(const sf::Event &event,
                                Ui::Window &window) const;

      private:
        /*!
         * \brief The pointer containing the GameData object shared in the different data objects.
         */
        GameData *gamedata;
        /*!
         * \brief The stack of game screens.
         */
        std::stack<std::unique_ptr<AGameScreen>> _gameScreens;
        /*!
         * \brief If `true`, the game executes itself frame by frame.
         * \details This mode is activated my keeping the F2 key pressed. On release, the mode is disabled. One frame can be passed by pressing the key registered in `fbfType`.
         */
        bool frameByFrame = false;
        /*!
         * \brief The key to press in frame by frame mode to pass one frame.
         */
        sf::Keyboard::Key fbfType = sf::Keyboard::F3;
        /*!
         * \brief Checks in the `fbfType` key has been released before passing one more frame.
         */
        bool hasBeenReleased = true;
        /*!
         * \brief Counts the number of times a frame has been skipped because of an exception.
         */
        int frameskips = 0;
    };

} // namespace OpMon
