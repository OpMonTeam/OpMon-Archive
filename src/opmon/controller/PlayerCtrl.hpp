/*!
 * \file PlayerCtrl.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors Navet56
 * \copyright GNU GPL v3.0
*/
#ifndef PLAYERCTRL_HPP
#define PLAYERCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Events.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../view/Overworld.hpp"

namespace OpMon {
    namespace Controller {
        /*!
         * \brief Contains functions used for the player's movements.
         * \todo Make this a class or put this in the Player object.
         */
        namespace PlayerCtrl {
            /*!
             * \brief Checks the key pressed on the keyboard to see if the player wants to move.
             * \details Does not check if Overworld::justTp is `true`, if the player is currently animated or if their movement is locked (Position::moveLock). If a direction key is pressed and the player is able to move, calls PlayerCtrl::move.
             */
            void checkMove(Model::Player &player, View::Overworld &overworld);
            /*!
             * \brief Moves the player, and then triggers the events activated when the player is moving towards them.
             * \details Calls Position::move and EventsCtrl::actionEvents with Model::Events::EventTrigger::GO_IN.
             */
            void move(Model::Side direction, Model::Player &player, View::Overworld &overworld);
        } // namespace PlayerCtrl
    }     // namespace Controller
} // namespace OpMon

#endif
