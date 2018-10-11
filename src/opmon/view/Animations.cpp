/*
Animations.cpp
Author : Cyrion
Contributors : BAKFR, Navet56
File under GNU GPL v3.0 license
*/
#include "Animations.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/time.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../start/Core.hpp"
#include "../view/Window.hpp"

namespace OpMon {
    namespace View {

        namespace Animations {
	  
	  //While false, the "WinAnim" animation's sprites are not loaded
            bool WinAnim::winInit = false;
	  //Array used by "WinAnim"
            sf::Texture WinAnim::fen[6];

            Animation::Animation(sf::Texture bgTxt)
              : bgTxt(bgTxt) {
            }

            WinAnim::WinAnim(sf::Texture bgTxt, bool order)
              : Animation(bgTxt)
              , order(order) {
                if(!winInit) {
                    winInit = true;
                    Model::ResourceLoader::loadTextureArray(fen, "animations/winChange/animWindowFrame%d.png", 6, 1);
                }
            }

            GameStatus WinAnim::operator()(sf::RenderTexture &frame) {
                bgSpr.setTexture(bgTxt);
                anim.setTexture(fen[(order ? counter : (frames - counter))]);

                frame.draw(bgSpr);
                frame.draw(anim);

                counter++;
                return (counter > frames) ? GameStatus::PREVIOUS : GameStatus::CONTINUE;
            }

        } // namespace Animations
    }     // namespace View
} // namespace OpMon
