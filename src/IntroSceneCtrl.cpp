/*
  IntroSceneCtrl.cpp
  Author : Cyrielle
  Contributor : BAKFR
  File under GNU GPL v3.0 license
*/
#include "IntroSceneCtrl.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include <string>

#include "OverworldCtrl.hpp"
#include "AnimationCtrl.hpp"
#include "Player.hpp"
#include "GameData.hpp"
#include "Animations.hpp"
#include "IntroScene.hpp"
#include "IntroSceneData.hpp"
#include "AGameScreen.hpp"
#include "Dialog.hpp"

//Defines created to make the code easier to understand.
#define LOAD_OVERWORLD 1
#define LOAD_ANIMATION_OPEN 2
#define LOAD_ANIMATION_CLOSE 3

namespace OpMon {

    IntroSceneCtrl::IntroSceneCtrl(GameData *data)
        : data(data)
        , view(this->data) {}

    GameStatus IntroSceneCtrl::checkEvent(sf::Event const &event) {
        auto &introscene = view;

        switch(event.type) {
        case sf::Event::KeyPressed:
            if(event.key.code == data.getGameDataPtr()->getKeyTalk() && introscene.getDialog() != nullptr) {
                introscene.getDialog()->pass();
            }
            //Part 1 is the part where the player enters his/her name
            if(event.key.code == sf::Keyboard::Return && introscene.getPart() == 1) {
                sf::String &pName = introscene.getpName();
                if(pName.isEmpty()) {
                    pName = "Player"; //We will find a default name some day
                }
                data.getPlayer().setName(pName);
                introscene.delLoop1();
                animNext = true;
                return GameStatus::CONTINUE;
            }
            //P is used to skip the introduction, but it must be disabled when entering the name
            if(event.key.code == sf::Keyboard::P && introscene.getPart() != 1) {
                loadNext = LOAD_OVERWORLD;
                return GameStatus::NEXT;
            }
            break;
        case sf::Event::TextEntered:
            if(introscene.getPart() == 1) {
                sf::String &pName = introscene.getpName();
                if(event.text.unicode == 8) { //Backspace
                    if(!pName.isEmpty()) {
                        pName = sf::String::fromUtf32(pName.begin(), pName.end() - 1);
                    }
                } else if(event.text.unicode > 32) {
                    if(pName.toUtf32().size() < 14) { //14 = Max name length
                        pName += event.text.unicode;
                    }
                }
            }
        default:
            break;
        }

        //If it's the end of the introduction, go to the overworld
        if(view.getPart() > 2) {
            loadNext = LOAD_OVERWORLD;
            return GameStatus::NEXT;
        }
        return GameStatus::CONTINUE;
    }

    void IntroSceneCtrl::loadNextScreen() {
        switch(loadNext) {
        case LOAD_OVERWORLD:
            _next_gs = std::make_unique<OverworldCtrl>(data.getPlayer(), data.getGameDataPtr());
            break;
        case LOAD_ANIMATION_OPEN:
            _next_gs = std::make_unique<AnimationCtrl>(std::make_unique<Animations::WinAnim>(screenTexture, true));
            break;
        case LOAD_ANIMATION_CLOSE:
            _next_gs = std::make_unique<AnimationCtrl>(std::make_unique<Animations::WinAnim>(screenTexture, false));
            break;
        default:
            throw Utils::UnexpectedValueException(std::to_string(loadNext), "a view to load in IntroSceneCtrl::loadNextScreen()");
        }
    }

    GameStatus IntroSceneCtrl::update(sf::RenderTexture &frame) {
        //If the player have finished to enter his/her name, animNext must have been set to true. This part will launch the animation.
        if(animNext) {
            animNext = false;
            frame.draw(view);
            loadNext = LOAD_ANIMATION_CLOSE;
            screenTexture = frame.getTexture();
            return GameStatus::NEXT_NLS;
        }
        GameStatus toReturn = view.update();
        if(toReturn == GameStatus::CONTINUE) {
            frame.draw(view);
        }

        if(toReturn == GameStatus::NEXT_NLS || toReturn == GameStatus::NEXT) {
            switch(view.getPart()) {
            case 1:
                loadNext = LOAD_ANIMATION_OPEN;
                screenTexture = frame.getTexture();
                toReturn = GameStatus::NEXT_NLS;
                break;
            case 3:
                loadNext = LOAD_OVERWORLD;
                break;
            default:
                throw Utils::UnexpectedValueException(std::to_string(view.getPart()), "1 or 3 in IntroScene::draw()");
            }
        }

        return toReturn;
    }

    void IntroSceneCtrl::suspend() {
        view.pause();
    }

    void IntroSceneCtrl::resume() {
        view.play();
    }

} // namespace OpMon
