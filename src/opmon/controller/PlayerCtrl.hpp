/*
PlayerCtrl.hpp
Author : Cyrielle
Contributor : BAKFR, Navet56
File under GNU GPL v3.0 license
*/
#ifndef PLAYERCTRL_HPP
#define PLAYERCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Events.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../view/Overworld.hpp"

namespace OpMon {
    namespace Controller {
        namespace PlayerCtrl {
            void checkMove(Model::Player &player, View::Overworld &overworld);
            void move(Model::Side direction, Model::Player &player, View::Overworld &overworld);
        } // namespace PlayerCtrl
    }     // namespace Controller
} // namespace OpMon

#endif
