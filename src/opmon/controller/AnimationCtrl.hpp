/*
AnimationCtrl.hpp
Author : Cyrielle
File under GNU GPL 3.0 license.
*/
#pragma once

#include "../view/Animations.hpp"
#include "AGameScreen.hpp"
#include <memory>

namespace OpMon::Controller {
    /**
	   AnimationCtrl is a special game screen which can call all types of animations.
        **/
    class AnimationCtrl : public AGameScreen {
      private:
        std::unique_ptr<View::Animations::Animation> view;

      public:
        explicit AnimationCtrl(std::unique_ptr<View::Animations::Animation> view);
        ~AnimationCtrl() override = default;

        GameStatus update(sf::RenderTexture &frame) override;
    };
} // namespace OpMon::Controller
