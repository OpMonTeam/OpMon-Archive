/*
Animations.hpp
Author : Cyrielle
Contributors : BAKFR, Navet56
File under GNU GPL v3.0 license
*/
#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../start/GameStatus.hpp"

namespace OpMon {
    namespace View {
        /**
	   Contains the functions used for the majors animations
	*/
        namespace Animations {

            class Animation {
              protected:
                int counter = 0;
                sf::Sprite anim;
                sf::Sprite bgSpr;
                sf::Texture bgTxt;
                sf::Texture afterTx;

              public:
                /* For classic animations, "before" is enough. "After" is used for transitions */
                Animation(sf::Texture before, sf::Texture after = sf::Texture());
                virtual ~Animation() = default;
                virtual GameStatus operator()(sf::RenderTexture &frame) = 0;
            };

            class WinAnim : public Animation {
              private:
                int frames{5};
                /*
		  If true : Opening movement | If false : Closing movement
		*/
                bool order;
                static bool winInit;
                static sf::Texture fen[6];

              public:
                WinAnim(sf::Texture bgTxt, bool order);
                GameStatus operator()(sf::RenderTexture &frame) override;
            };

            enum class WooshSide : int {
                UP = 0,
                DOWN = 1,
                LEFT = 2,
                RIGHT = 3
            };

            class WooshAnim : public Animation {
              private:
                WooshSide side;
                int duration = 15;
                int counter = 0;
                sf::Sprite &before = this->bgSpr;
                sf::Sprite &after = this->anim;
                sf::Vector2f initialPos[4];
                sf::Vector2f mvDir[4];
                bool outToIn;

              public:
                WooshAnim(sf::Texture &before, sf::Texture &after, WooshSide side, int duration = 15, bool outToIn = true);
                GameStatus operator()(sf::RenderTexture &frame) override;
            };

        } // namespace Animations

    } // namespace View
} // namespace OpMon
#endif // ANIMATIONS_HPP
