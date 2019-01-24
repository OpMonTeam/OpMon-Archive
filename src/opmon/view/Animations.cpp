/*
Animations.cpp
Author : Cyriel
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

            Animation::Animation(sf::Texture bgTxt, sf::Texture after)
              : bgTxt(bgTxt),
				afterTx(after){
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
                return (counter > frames) ? GameStatus::PREVIOUS_NLS : GameStatus::CONTINUE;
            }
			
			WooshAnim::WooshAnim(sf::Texture before, sf::Texture after, WooshSide side, int duration)
			 : Animation(before, after),
			   side(side),
			   duration(duration),
			   counter(duration){
				   initialPos[WooshSide::UP] = sf::Vector2f(0, 0 - after.getSize().y);
				   initialPos[WooshSide::DOWN] = sf::Vector2f(0, 512 + after.getSize().y);
				   initialPos[WooshSide::LEFT] = sf::Vector2f(0 - after.getSize().x, 0);
				   initialPos[WooshSide::RIGHT] = sf::Vector2f(512 + after.getSize.x, 0);
				   mvDir[WooshSide::UP] = sf::Vector2f(0, 1);
				   mvDir[WooshSide::DOWN] = sf::Vector2f(0, -1);
				   mvDir[WooshSide::LEFT] = sf::Vector2f(1, 0);
				   mvDir[WooshSide::RIGHT] = sf::Vector2f(-1, 0);
				   
				   this->before.setPosition(0, 0);
				   this->before.setTexture(bgTxt);
				   
				   this->after.setTexture(afterTx);
				   this->after.setPosition(initialPos[side]);
			}
			
			GameStatus WooshAnim::operator()(sf::RenderTexture &frame){
				after.move((counter == 0) ? sf::Vector2f(0, 0) : (mvDir[side] * (512.0f/duration)));
				
				frame.draw(before);
				frame.draw(after);
				
				counter--;
				
				return (counter < 0) ? GameStatus::PREVIOUS_NLS : GameStatus::CONTINUE;
			}

        } // namespace Animations
    }     // namespace View
} // namespace OpMon
