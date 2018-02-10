#include "OptionsMenuCtrl.hpp"
#include "../view/Window.hpp"

#include "../../utils/defines.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"
#include "../start/i18n/Translator.hpp"
#include "../view/Overworld.hpp"
#include "../view/StartScene.hpp"

namespace OpMon {
    namespace Controller {

        OptionsMenuCtrl::OptionsMenuCtrl()
          : view() {}

        GameStatus OptionsMenuCtrl::checkEvent(sf::Event const &event) {
            auto &menu = view;
            switch(event.type) {
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Return) {
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        switch(menu.cursorPosition()) {
                        case 0:
                            return GameStatus::PREVIOUS;
                        case 1:
                            if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
                                Model::OptionsSave::addOrModifParam("fullscreen", "false");
                            } else {
                                Model::OptionsSave::addOrModifParam("fullscreen", "true");
                            }
                            break;
                        case 2:
                            menu.setCurrentOption(View::OptionType::LANG);
                            return GameStatus::CONTINUE;
                            break;
                        case 3:
                            Model::Data::Sounds::nope.play();
                            break;
                        case 4:
                            menu.setCurrentOption(View::OptionType::CREDITS);
                            return GameStatus::CONTINUE;
                            break;
                        }
                    } else if(menu.getCurrentOption() == View::OptionType::LANG) {

                        auto &tr = OpMon::I18n::Translator::getInstance();
                        switch(menu.cursorPosition()) {
                        case 0:
                            menu.setCurrentOption(View::OptionType::ALL);
                            return GameStatus::CONTINUE;
                        case 1:
                            Model::OptionsSave::modifyParam("lang", "en");
                            tr.setLang("en");
                            break;
                        case 2:
                            Model::OptionsSave::modifyParam("lang", "es");
                            tr.setLang("es");
                            break;
                        case 3:
                            Model::OptionsSave::modifyParam("lang", "fr");
                            tr.setLang("fr");
                            break;
                        }
                    } else {
                        return GameStatus::CONTINUE;
                    }
                    break;
                default:
                    break;
                }
                if(event.key.code == sf::Keyboard::Up) {
                    menu.moveArrow(true);
                } else if(event.key.code == sf::Keyboard::Down) {
                    menu.moveArrow(false);
                } else if(event.key.code == sf::Keyboard::BackSpace) {
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        return GameStatus::PREVIOUS;
                    } else {
                        menu.setCurrentOption(View::OptionType::ALL);
                        return GameStatus::CONTINUE;
                    }
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

    } // namespace Controller
} // namespace OpMon
