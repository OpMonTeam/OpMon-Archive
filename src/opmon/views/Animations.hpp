/*!
 * \file Animations.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors Navet56
 * \copyright GNU GPL v3.0
 */
#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../core/GameStatus.hpp"

namespace OpMon {
    /*!
     * \brief Contains the functions used for the majors animations
     */
    namespace Animations {

        /*!
         * \brrief Base class defining an animation on the whole screen.
         */
        class Animation {
        protected:
            int counter = 0;
            /*!
             * \brief The sprite of the animation.
             */
            sf::Sprite anim;
            /*!
             * \brief The background of the animation.
             */
            sf::Sprite bgSpr;
            /*!
             * \brief The texture of the background.
             */
            sf::Texture bgTxt;
            /*!
             * \brief The texture to show after the animation.
             */
            sf::Texture afterTx;

        public:
            /*!
             * \brief Constructs an animation.
             * \param before The texture present before the animation.
             * \param after The texture to show after the animation.
             * \details For classic animations, "before" is enough. "after" is used for transitions.
             */
            Animation(sf::Texture before, sf::Texture after = sf::Texture());
            virtual ~Animation() = default;
            /*!
             * \brief Updates the animation.
             */
            virtual GameStatus operator()(sf::RenderTexture &frame) = 0;
        };

        /*!
         * \brief Animation played as a transition between the professor's dialog and the name input screen.
         */
        class WinAnim : public Animation {
        private:
            int frames{5};
            /*!
             * \brief The order of the animation.
             * \details If `true` : Opening movement, closing movement otherwise.
             */
            bool order;
            /*!
             * \brief If `true`, the textures for the animation has been loaded.
             */
            static bool winInit;
            /*!
             * \brief The textures for the animation.
             */
            static sf::Texture fen[6];

        public:
            WinAnim(sf::Texture const& bgTxt, bool order);
            GameStatus operator()(sf::RenderTexture &frame) override;
        };

        /*!
         * \brief The direction of the movement for WooshAnim.
         */
        enum class WooshDir : int {
            UP = 0,/*!< The movement will be from the bottom to the top.*/
            DOWN = 1,/*!< The movement will be from the top to the bottom.*/
            LEFT = 2,/*!< The movement will be from right to left.*/
            RIGHT = 3/*!< The movement will be from left to right.*/
        };

        /*!
         * \brief A simple sliding transition.
         * \details This animation makes a sprite move by one entire screen (512px), either from the outside of the screen to the screen, or the opposite. In the game, this animation is used for the in-game menu.
         */
        class WooshAnim : public Animation {
        private:
            /*!
             * \brief The direction of the movement.
             */
            WooshDir dir;
            /*!
             * \brief The duration of the animation, in frames.
             */
            int duration = 15;
            /*!
             * \brief The initial position of the sprite to move.
             */
            sf::Vector2f initialPos[4];
            /*!
             * \brief The direction of the movement in a vector.
             * \details The vector is filled according to WooshAnim::dir with 1, 0 or -1.
             * \todo Put this in const static and initilise it only one time.
             */
            sf::Vector2f mvDir[4];
            /*!
             * \brief The initial position of the mobile sprite.
             * \details If `true`, the sprite will be outside the screen at the start, in a different position according to the direction it has to move. Else, the initial position will be 0,0 and the sprite will move outside the screen.
             */
            bool outToIn;

        public:
            /*!
             * \brief Constructs a WooshAnim.
             * \param before The static texture, in the background. It won't move.
             * \param after The mobile texture.
             * \param dir The direction of the movement.
             * \param duraction The duration of the movement, in frames.
             * \param outToIn The initial position of the mobile sprite.
             */
            WooshAnim(sf::Texture const& before, sf::Texture const& after, WooshDir dir, int duration = 15, bool outToIn = true);
            GameStatus operator()(sf::RenderTexture &frame) override;
        };

    } // namespace Animations

} // namespace OpMon
#endif // ANIMATIONS_HPP
