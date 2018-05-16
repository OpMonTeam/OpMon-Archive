#include "OptionsMenuCtrl.hpp"
#include "../view/Window.hpp"

#include "../../utils/defines.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"
#include "../start/i18n/Translator.hpp"
#include "../view/Overworld.hpp"
#include "../view/StartScene.hpp"

#include <math.h>

using namespace std;

enum MenuOption {BACK = 0, FULLSCREEN = 1, LANGUAGE = 2, CONTROLS = 3, VOLUME = 4, CREDITS = 5};

namespace OpMon {
    namespace Controller {

        OptionsMenuCtrl::OptionsMenuCtrl()
          : view() {
            nope.setBuffer(Model::Data::Sounds::nope);
            arrow.setBuffer(Model::Data::Sounds::arrow);
            push.setBuffer(Model::Data::Sounds::push);
        }

        GameStatus OptionsMenuCtrl::checkEvent(sf::Event const &event) {
            auto &menu = view;
            switch(event.type) {
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Return) {
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        switch(menu.cursorPosition()) {
                        case BACK:
                            push.play();
                            return GameStatus::PREVIOUS;
                        case FULLSCREEN:
                            push.play();
                            if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
                                Model::OptionsSave::addOrModifParam("fullscreen", "false");
                                reboot = true;
                            } else {
                                Model::OptionsSave::addOrModifParam("fullscreen", "true");
                                reboot = true;
                            }
                            return GameStatus::STOP;
                            break;
                        case LANGUAGE:
                            push.play();
                            menu.setCurrentOption(View::OptionType::LANG);
                            return GameStatus::CONTINUE;
                            break;
                        case CONTROLS:
                            break;
                        case VOLUME:
                            push.play();
                            toggleVolume();
                            break;
                        case CREDITS:
                            push.play();
                            menu.setCurrentOption(View::OptionType::CREDITS);
                            return GameStatus::CONTINUE;
                            break;
                        }
                    } else if(menu.getCurrentOption() == View::OptionType::LANG) {

                        auto &tr = OpMon::I18n::Translator::getInstance();
                        switch(menu.cursorPosition()) {
                        case 0:
                            push.play();
                            menu.setCurrentOption(View::OptionType::ALL);
                            return GameStatus::CONTINUE;
                        case 1:
                            push.play();
                            Model::OptionsSave::modifyParam("lang", "en");
                            tr.setLang("en");
                            break;
                        case 2:
                            push.play();
                            Model::OptionsSave::modifyParam("lang", "es");
                            tr.setLang("es");
                            break;
                        case 3:
                            push.play();
                            Model::OptionsSave::modifyParam("lang", "fr");
                            tr.setLang("fr");
                            break;
                        }
                    } else if(menu.getCurrentOption() == View::OptionType::CREDITS) {
                        push.play();
                        menu.setCurrentOption(View::OptionType::ALL);
                        return GameStatus::CONTINUE;
                    } else {
                        return GameStatus::CONTINUE;
                    }
                    break;
                default:
                    break;
                }
                if(event.key.code == sf::Keyboard::Up) {
                    menu.moveArrow(true);
                    arrow.play();
                } else if(event.key.code == sf::Keyboard::Down) {
                    menu.moveArrow(false);
                    arrow.play();
                } else if(event.key.code == sf::Keyboard::BackSpace) {
                    push.play();
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        return GameStatus::PREVIOUS;
                    } else {
                        menu.setCurrentOption(View::OptionType::ALL);
                        return GameStatus::CONTINUE;
                    }
                } else if (event.key.code == sf::Keyboard::Left) {
                    lowerVolume();
                } else if (event.key.code == sf::Keyboard::Right) {
                    raiseVolume();
                }
            }
            return GameStatus::CONTINUE;
        }

        void OptionsMenuCtrl::suspend() {
            view.pause();
        }

        void OptionsMenuCtrl::resume() {
            view.play();
        }

        GameStatus OptionsMenuCtrl::update() {
            view.draw(View::frame);
            return GameStatus::CONTINUE;
        }

        void OptionsMenuCtrl::toggleVolume() {
            if (View::jukebox.getGlobalVolume() > 1) {
                View::jukebox.setGlobalVolume(1);
            } else {
                View::jukebox.setGlobalVolume(100);
            }
        }

        void OptionsMenuCtrl::raiseVolume() {
            const int newVolume = min(100, View::jukebox.getGlobalVolume() + 10);
            View::jukebox.setGlobalVolume(newVolume);
        }

        void OptionsMenuCtrl::lowerVolume() {
            const int newVolume = max(1, View::jukebox.getGlobalVolume() - 10);
            View::jukebox.setGlobalVolume(newVolume);
        }

    } // namespace Controller
} // namespace OpMon
