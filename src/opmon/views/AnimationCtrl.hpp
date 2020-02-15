/*!
 * \file AnimationCtrl.hpp
 * \author Cyrielle
 * \copyright GNU GPL 3.0
 */
#pragma once

#include <memory>

#include "Animations.hpp"
#include "base/AGameScreen.hpp"
#include "src/opmon/core/GameStatus.hpp"

namespace sf {
class RenderTexture;
}  // namespace sf

namespace OpMon {
    /*!
     * \brief A special game screen able to call any type of animation.
     *
     * AnimationCtrl does nothing else than calling the method to update and draw the animation.
     */
    class AnimationCtrl : public AGameScreen {
    private:
        std::unique_ptr<Animations::Animation> view;

    public:
        AnimationCtrl(std::unique_ptr<Animations::Animation> view);
        ~AnimationCtrl() = default;

        GameStatus update(sf::RenderTexture &frame) override;
    };
} // namespace OpMon
