/*
  Animations.cpp
  Author : Cyrielle
  Contributors : BAKFR, Navet56
  File under GNU GPL v3.0 license
*/
#include "Animations.hpp"

#include <cstddef>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "ResourceLoader.hpp"
#include "GameStatus.hpp"

namespace OpMon {

    namespace Animations {

        //While false, the "WinAnim" animation's sprites are not loaded
        bool WinAnim::winInit = false;
        //Array used by "WinAnim"
        sf::Texture WinAnim::fen[6];

        Animation::Animation(sf::Texture bgTxt, sf::Texture after)
            : bgTxt(bgTxt)
            , afterTx(after) {
        }

        WinAnim::WinAnim(sf::Texture const& bgTxt, bool order)
            : Animation(bgTxt)
            , order(order) {
            if(!winInit) {
                winInit = true;
                Utils::ResourceLoader::loadTextureArray(fen, "animations/winChange/animWindowFrame%d.png", 6, 1);
            }
        }

        GameStatus WinAnim::update(){
            bgSpr.setTexture(bgTxt);
            anim.setTexture(fen[(order ? counter : (frames - counter))]);
            counter++;
            return (counter > frames) ? GameStatus::PREVIOUS_NLS : GameStatus::CONTINUE;
        }

        void WinAnim::draw(sf::RenderTarget &frame, sf::RenderStates states) const {
            frame.draw(bgSpr);
            frame.draw(anim);
        }

        WooshAnim::WooshAnim(sf::Texture const& before, sf::Texture const& after, WooshDir dir, int duration, bool outToIn)
            : Animation(before, after)
            , dir(dir)
            , duration(duration)
            , outToIn(outToIn) {
            counter = duration;
            if(outToIn) {
                initialPos[(int)WooshDir::DOWN] = sf::Vector2f(0, -512);
                initialPos[(int)WooshDir::UP] = sf::Vector2f(0, 512);
                initialPos[(int)WooshDir::RIGHT] = sf::Vector2f(-512, 0);
                initialPos[(int)WooshDir::LEFT] = sf::Vector2f(512, 0);
            } else {
                for(size_t i = 0; i < 4; i++)
                    initialPos[i] = sf::Vector2f(0, 0);
            }
            mvDir[(int)WooshDir::DOWN] = sf::Vector2f(0, 1);
            mvDir[(int)WooshDir::UP] = sf::Vector2f(0, -1);
            mvDir[(int)WooshDir::RIGHT] = sf::Vector2f(1, 0);
            mvDir[(int)WooshDir::LEFT] = sf::Vector2f(-1, 0);

            this->bgSpr.setPosition(0, 0);
            this->bgSpr.setTexture(before);

            this->anim.setTexture(after);
            this->anim.setPosition(initialPos[(int)dir]);
        }

        GameStatus WooshAnim::update(){
            anim.move((counter == 0) ? sf::Vector2f(0, 0) : (mvDir[(int)dir] * (512.0f / duration)));
            counter--;
            return (counter < 0) ? GameStatus::PREVIOUS_NLS : GameStatus::CONTINUE;
        }

        void WooshAnim::draw(sf::RenderTarget &frame, sf::RenderStates state) const {
            frame.clear(sf::Color::Black);
            frame.draw(bgSpr);
            frame.draw(anim);
        }

    } // namespace Animations
} // namespace OpMon
