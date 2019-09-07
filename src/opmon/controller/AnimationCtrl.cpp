/*
AnimationCtrl.cpp
Author : Cyrielle
File under GNU GPL 3.0 license
*/
#include "AnimationCtrl.hpp"
#include "../view/Window.hpp"

namespace OpMon::Controller {
    AnimationCtrl::AnimationCtrl(std::unique_ptr<View::Animations::Animation> view)
      : view(std::move(view)) {}

    GameStatus AnimationCtrl::update(sf::RenderTexture &frame) {
        return (*view)(frame);
    }
} // namespace OpMon::Controller
