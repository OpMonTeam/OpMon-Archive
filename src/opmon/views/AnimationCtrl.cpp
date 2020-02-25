/*
  AnimationCtrl.cpp
  Author : Cyrielle
  File under GNU GPL 3.0 license
*/
#include "AnimationCtrl.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <utility>

#include "src/opmon/views/Animations.hpp"

namespace OpMon {
    AnimationCtrl::AnimationCtrl(std::unique_ptr<Animations::Animation> view)
        : view(std::move(view)) {}

    GameStatus AnimationCtrl::update(sf::RenderTexture &frame) {
        GameStatus status = view->update();
        frame.draw(*view);
        return status;
    }
} // namespace OpMon
