/*
Animations.hpp
Author : Cyrion
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

              public:
                Animation(sf::Texture bgTxt);
                virtual ~Animation() = default;
                virtual GameStatus operator()(sf::RenderTexture &frame) = 0;
            };

            class WinAnim : public Animation {
              private:
                int frames = 5;
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

        } // namespace Animations

    } // namespace View
} // namespace OpMon
#endif // ANIMATIONS_HPP
