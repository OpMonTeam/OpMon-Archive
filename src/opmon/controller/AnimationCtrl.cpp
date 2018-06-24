#include "AnimationCtrl.hpp"
#include "../view/Window.hpp"

namespace OpMon {
    namespace Controller {
        AnimationCtrl::AnimationCtrl(View::Animations::Animation *view)
          : view(view) {}

        AnimationCtrl::~AnimationCtrl() {
            delete(view);
        }

      GameStatus AnimationCtrl::update(sf::RenderTexture& texture) {
            return (*view)();
        }
    } // namespace Controller
} // namespace OpMon
