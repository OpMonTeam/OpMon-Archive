#include "OptionsMenuCtrl.hpp"
#include "../view/Window.hpp"

#include "../../utils/defines.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../start/i18n/Translator.hpp"
#include "../view/Overworld.hpp"
#include "../view/StartScene.hpp"

#include <math.h>

enum MenuOption { BACK = 0,
                  FULLSCREEN = 1,
                  LANGUAGE = 2,
                  CONTROLS = 3,
                  VOLUME = 4,
                  CREDITS = 5 };

namespace OpMon {
    namespace Controller {

        OptionsMenuCtrl::OptionsMenuCtrl(Model::UiData *data)
          : data(data)
          , view(this->data) {
        }

        GameStatus OptionsMenuCtrl::checkEvent(sf::Event const &event) {
            auto &menu = view;
            switch(event.type) {
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Return) {
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        switch(menu.cursorPosition()) {
                        case BACK:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            return GameStatus::PREVIOUS;
                        case FULLSCREEN:
                            data.getUiDataPtr()->getJukebox().playSound("push");
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
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            menu.setCurrentOption(View::OptionType::LANG);
                            return GameStatus::CONTINUE;
                            break;
                        case CONTROLS:
                            break;
                        case VOLUME:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            toggleVolume();
                            break;
                        case CREDITS:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            menu.setCurrentOption(View::OptionType::CREDITS);
                            return GameStatus::CONTINUE;
                            break;
                        }
                    } else if(menu.getCurrentOption() == View::OptionType::LANG) {

                        auto &tr = OpMon::I18n::Translator::getInstance();
                        switch(menu.cursorPosition()) {
                        case 0:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            menu.setCurrentOption(View::OptionType::ALL);
                            return GameStatus::CONTINUE;
                        case 1:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            Model::OptionsSave::modifyParam("lang", "en");
                            tr.setLang("en");
                            break;
                        case 2:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            Model::OptionsSave::modifyParam("lang", "es");
                            tr.setLang("es");
                            break;
                        case 3:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            Model::OptionsSave::modifyParam("lang", "fr");
                            tr.setLang("fr");
                            break;
                        case 4:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            Model::OptionsSave::modifyParam("lang", "de");
                            tr.setLang("de");
                            break;
                        }
                    } else if(menu.getCurrentOption() == View::OptionType::CREDITS) {
                        data.getUiDataPtr()->getJukebox().playSound("push");
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
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                } else if(event.key.code == sf::Keyboard::Down) {
                    menu.moveArrow(false);
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                } else if(event.key.code == sf::Keyboard::BackSpace) {
                    data.getUiDataPtr()->getJukebox().playSound("push");
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        return GameStatus::PREVIOUS;
                    } else {
                        menu.setCurrentOption(View::OptionType::ALL);
                        return GameStatus::CONTINUE;
                    }
                } else if(event.key.code == sf::Keyboard::Left && menu.cursorPosition() == VOLUME) {
                    lowerVolume();
                } else if(event.key.code == sf::Keyboard::Right && menu.cursorPosition() == VOLUME) {
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

        GameStatus OptionsMenuCtrl::update(sf::RenderTexture &frame) {
            view.draw(frame);
            return GameStatus::CONTINUE;
        }

        void OptionsMenuCtrl::toggleVolume() {
            if(data.getUiDataPtr()->getJukebox().getGlobalVolume() > 0) {
                data.getUiDataPtr()->getJukebox().setGlobalVolume(0);
		Model::OptionsSave::modifyParam("volume", "0");
            } else {
                data.getUiDataPtr()->getJukebox().setGlobalVolume(100);
		Model::OptionsSave::modifyParam("volume", "100");
            }

        }

        void OptionsMenuCtrl::raiseVolume() {
            const int newVolume = std::min(100, data.getUiDataPtr()->getJukebox().getGlobalVolume() + 10);
            data.getUiDataPtr()->getJukebox().setGlobalVolume(newVolume);
	    Model::OptionsSave::modifyParam("volume", std::to_string(newVolume));
        }

        void OptionsMenuCtrl::lowerVolume() {
            const int newVolume = std::max(0, data.getUiDataPtr()->getJukebox().getGlobalVolume() - 10);
            data.getUiDataPtr()->getJukebox().setGlobalVolume(newVolume);
	    Model::OptionsSave::modifyParam("volume", std::to_string(newVolume));
        }

    } // namespace Controller
} // namespace OpMon
