
#include "StartSceneCtrl.hpp"
#include "../../utils/log.hpp"
#include "../model/storage/Data.hpp"
#include "../view/Window.hpp"
#include "./OverworldCtrl.hpp"
#include "AnimationCtrl.hpp"

namespace OpMon {
    namespace Controller {

        StartSceneCtrl::StartSceneCtrl()
          : view() {}

        GameStatus StartSceneCtrl::checkEvent(sf::Event const &event) {
            auto &startscene = view;

            switch(event.type) {
            case sf::Event::KeyPressed:
                if(event.key.code == Model::Data::Controls::talk && startscene.getDialog() != nullptr) {
                    startscene.getDialog()->pass();
                }
                if(event.key.code == sf::Keyboard::Return && startscene.getPart() == 1) {
                    sf::String &pName = startscene.getpName();
                    if(pName.isEmpty()) {
                        pName = "Player";
                    }
                    Model::Data::player.setName(pName);
                    startscene.delLoop1();
                    view.draw(View::frame);
                    _next_gs = new AnimationCtrl(new View::Animations::WinAnim(View::frame.getTexture(), false));
                    return GameStatus::NEXT;
                }
                if(event.key.code == sf::Keyboard::P && startscene.getPart() != 1) {
                    _next_gs = new OverworldCtrl(Model::Data::player);
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

            if(view.getPart() > 2) {
                _next_gs = new OverworldCtrl(Model::Data::player);
                return GameStatus::NEXT;
            }
            return GameStatus::CONTINUE;
        }

        GameStatus StartSceneCtrl::update() {
            GameStatus toReturn = view();
            if(toReturn == GameStatus::CONTINUE) {
                view.draw(View::frame);
            }

            if(toReturn == GameStatus::NEXT) {
                switch(view.getPart()) {
                case 1:
                    _next_gs = new AnimationCtrl(new View::Animations::WinAnim(View::frame.getTexture(), true));
                    break;
                case 3:
                    _next_gs = new OverworldCtrl(Model::Data::player);
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
