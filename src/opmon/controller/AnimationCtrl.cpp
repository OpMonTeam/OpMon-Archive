/*
AnimationCtrl.cpp
Author : Cyrion
File under GNU GPL 3.0 license
*/
#include "AnimationCtrl.hpp"
#include "../view/Window.hpp"

namespace OpMon {
    namespace Controller {
        AnimationCtrl::AnimationCtrl(View::Animations::Animation *view)
          : view(view) {}

        AnimationCtrl::~AnimationCtrl() {
            delete(view);
        }

        GameStatus AnimationCtrl::update(sf::RenderTexture &frame) {
            return (*view)(frame);
        }
    } // namespace Controller
} // namespace OpMon
