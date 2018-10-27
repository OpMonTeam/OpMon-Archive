/*
StartSceneCtrl.cpp
Author : Cyrion
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "StartSceneCtrl.hpp"
#include "../../utils/log.hpp"
#include "../view/Window.hpp"
#include "./OverworldCtrl.hpp"
#include "AnimationCtrl.hpp"

namespace OpMon {
    namespace Controller {

        StartSceneCtrl::StartSceneCtrl(Model::UiData *data)
          : data(data)
          , view(this->data) {}

        GameStatus StartSceneCtrl::checkEvent(sf::Event const &event) {
            auto &startscene = view;

            switch(event.type) {
            case sf::Event::KeyPressed:
                if(event.key.code == data.getUiDataPtr()->getKeyTalk() && startscene.getDialog() != nullptr) {
                    startscene.getDialog()->pass();
                }
                //Part 1 is the part where the player enters his/her name
                if(event.key.code == sf::Keyboard::Return && startscene.getPart() == 1) {
                    sf::String &pName = startscene.getpName();
                    if(pName.isEmpty()) {
                        pName = "Player"; //We will find a default name some day
                    }
                    data.getPlayer().setName(pName);
                    startscene.delLoop1();
                    animNext = true;
                    return GameStatus::CONTINUE;
                }
                //P is used to skip the introduction, but it must be not working when entering the name
                if(event.key.code == sf::Keyboard::P && startscene.getPart() != 1) {
                    _next_gs = new OverworldCtrl(data.getPlayer(), data.getUiDataPtr());
                    return GameStatus::NEXT;
                }
                break;
            case sf::Event::TextEntered:
                if(startscene.getPart() == 1) {
                    sf::String &pName = startscene.getpName();
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
                _next_gs = new OverworldCtrl(data.getPlayer(), data.getUiDataPtr());
                return GameStatus::NEXT;
            }
            return GameStatus::CONTINUE;
        }

        GameStatus StartSceneCtrl::update(sf::RenderTexture &frame) {
            //If the player have finished to enter his/her name, animNext must have been set to true. This part will launch the animation.
            if(animNext) {
                animNext = false;
                view.draw(frame);
                _next_gs = new AnimationCtrl(new View::Animations::WinAnim(frame.getTexture(), false));
                return GameStatus::NEXT;
            }
            GameStatus toReturn = view();
            if(toReturn == GameStatus::CONTINUE) {
                view.draw(frame);
            }

            if(toReturn == GameStatus::NEXT) {
                switch(view.getPart()) {
                case 1:
                    _next_gs = new AnimationCtrl(new View::Animations::WinAnim(frame.getTexture(), true));
                    break;
                case 3:
                    _next_gs = new OverworldCtrl(data.getPlayer(), data.getUiDataPtr());
                    break;
                default:
                    handleError("Internal error, unknown part in StartSceneCtrl::update", true);
                    break;
                }
            }

            return toReturn;
        }

        void StartSceneCtrl::suspend() {
            view.pause();
        }

        void StartSceneCtrl::resume() {
            view.play();
        }

    } // namespace Controller
} // namespace OpMon
