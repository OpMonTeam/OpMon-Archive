#pragma once

#include "../view/Animations.hpp"
#include "AGameScreen.hpp"

namespace OpMon {
    namespace Controller {
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
