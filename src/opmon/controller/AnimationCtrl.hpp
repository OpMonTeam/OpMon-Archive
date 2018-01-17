#pragma once

#include "AGameScreen.hpp"
#include "../view/Animations.hpp"


namespace OpMon{
  namespace Controller{
    class AnimationCtrl : public AGameScreen{
    private:
      View::Animations::Animation* view;
    public:
      AnimationCtrl(View::Animations::Animation* view);
      ~AnimationCtrl();
      GameStatus update() override;
    };
  }
}
