/*
OptionsMenuCtrl.cpp
Author : BAKFR
Contributors : Cyrion, Navet56, torq, Samurai413x
File under GNU GPL v3.0 license
*/
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
                if(menu.getCurrentOption() == View::OptionType::CONTROLES && keyChangeActive) {
                    if(currentKeyChange < controlsName.size())
                    {
                        const std::string& keyCode = Model::KeyData::findNameKeyCode(event.key.code);
                        if(!keyCode.empty())
                        {
                            Model::OptionsSave::addParam(std::string("control.") + controlsName[currentKeyChange], keyCode.c_str());
                        }
                        ++currentKeyChange;
                        view.setCurrentActionsCtrl(currentKeyChange + 1);
                    }

                    if(currentKeyChange >= controlsName.size())
                    {
                        currentKeyChange = 0;
                        keyChangeActive = false;
                        view.setCurrentActionsCtrl(currentKeyChange);
                        Model::OptionsSave::saveParams(std::string(SAVE_PATH + "optSave.oparams"));

                        data.getUiDataPtr()->setKeyUp(Model::OptionsSave::getParam("control.up").getValue());
                        data.getUiDataPtr()->setKeyDown(Model::OptionsSave::getParam("control.down").getValue());
                        data.getUiDataPtr()->setKeyLeft(Model::OptionsSave::getParam("control.left").getValue());
                        data.getUiDataPtr()->setKeyRight(Model::OptionsSave::getParam("control.right").getValue());
                        data.getUiDataPtr()->setKeyTalk(Model::OptionsSave::getParam("control.talk").getValue());
                        data.getUiDataPtr()->setKeyInteract(Model::OptionsSave::getParam("control.interact").getValue());
                    }

                    return GameStatus::CONTINUE;
                }
                if(event.key.code == sf::Keyboard::Return) {
                    //If present on the options' main menu, checks what to do
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        switch(menu.cursorPosition()) {
                        case BACK:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            return GameStatus::PREVIOUS;
                        case FULLSCREEN:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
                                Model::OptionsSave::addOrModifParam("fullscreen", "false");
                            } else {
                                Model::OptionsSave::addOrModifParam("fullscreen", "true");
                            }
                            reboot = true;
                            return GameStatus::STOP;
                        case LANGUAGE:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            menu.setCurrentOption(View::OptionType::LANG);
                            return GameStatus::CONTINUE;
                            break;
                        case CONTROLS:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            menu.setCurrentOption(View::OptionType::CONTROLES);
                            return GameStatus::CONTINUE;
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
                    } else if(menu.getCurrentOption() == View::OptionType::LANG) { //Chooses language to print

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
                        //Only one choice is avilable on the credits : back.
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(View::OptionType::ALL);
                        return GameStatus::CONTINUE;
                    } else if(menu.getCurrentOption() == View::OptionType::CONTROLES) {
                        switch(menu.cursorPosition()) {
                        case 0:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            menu.setCurrentOption(View::OptionType::ALL);
                            return GameStatus::CONTINUE;
                        case 1:
                            data.getUiDataPtr()->getJukebox().playSound("push");
                            keyChangeActive = true;
                            view.setCurrentActionsCtrl(currentKeyChange + 1);
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
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                } else if(event.key.code == sf::Keyboard::Down) {
                    menu.moveArrow(false);
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                } else if(event.key.code == sf::Keyboard::BackSpace) {
                    data.getUiDataPtr()->getJukebox().playSound("push");
                    if(menu.getCurrentOption() == View::OptionType::ALL) {
                        //Returns to the previous game screen if backspace is pressed while in the options' main menu.
                        return GameStatus::PREVIOUS;
                    } else {
                        //Returns to the options' main menu if any of the options sub-menus are currently printed.
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
