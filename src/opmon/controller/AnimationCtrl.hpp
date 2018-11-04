/*
AnimationCtrl.hpp
Author : Cyrion
File under GNU GPL 3.0 license.
*/
#pragma once

#include "../view/Animations.hpp"
#include "AGameScreen.hpp"

namespace OpMon {
    namespace Controller {
        /**
	 AnimationCtrl is a special game screen which can call all types of animations.
      **/
        class AnimationCtrl : public AGameScreen {
          private:
            View::Animations::Animation *view;

          public:
            AnimationCtrl(View::Animations::Animation *view);
            ~AnimationCtrl();
            GameStatus update(sf::RenderTexture &frame) override;
        };
    } // namespace Controller
} // namespace OpMon
