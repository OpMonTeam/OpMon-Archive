/*
  AnimationCtrl.cpp
  Author : Cyrielle
  File under GNU GPL 3.0 license
*/
#include "AnimationCtrl.hpp"
#include "ui/Window.hpp"

namespace OpMon {
    AnimationCtrl::AnimationCtrl(std::unique_ptr<Animations::Animation> view)
        : view(std::move(view)) {}

    GameStatus AnimationCtrl::update(sf::RenderTexture &frame) {
        return (*view)(frame);
    }
} // namespace OpMon
