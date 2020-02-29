/*
  OptionsMenuCtrl.cpp
  Author : BAKFR
  Contributors : Cyrielle, Navet56, torq, Samurai413x
  File under GNU GPL v3.0 license
*/
#include "OptionsMenuCtrl.hpp"

#include <ext/alloc_traits.h>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>

#include "src/utils/defines.hpp"
#include "src/utils/OptionsSave.hpp"
#include "src/utils/i18n/Translator.hpp"
#include "src/opmon/core/UiData.hpp"
#include "src/utils/KeyData.hpp"
#include "OptionsMenu.hpp"
#include "OptionsMenuData.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"

enum MenuOption { BACK = 0,
                  FULLSCREEN = 1,
                  LANGUAGE = 2,
                  CONTROLS = 3,
                  VOLUME = 4,
                  CREDITS = 5 };

namespace OpMon {

    OptionsMenuCtrl::OptionsMenuCtrl(UiData *data)
        : data(data)
        , view(this->data) {
    }

    GameStatus OptionsMenuCtrl::checkEvent(sf::Event const &event) {
        auto &menu = view;
        switch(event.type) {
        case sf::Event::KeyPressed:
            if(menu.getCurrentOption() == OptionType::CONTROLS && keyChangeActive) {
                if(currentKeyChange < controlsName.size()) {
                    const std::string &keyCode = Utils::KeyData::findNameKeyCode(event.key.code);
                    if(!keyCode.empty()) {
                        Utils::OptionsSave::addParam(std::string("control.") + controlsName[currentKeyChange], keyCode.c_str());
                    }
                    ++currentKeyChange;
                    view.setCurrentKeyChange(currentKeyChange + 1);
                }

                if(currentKeyChange >= controlsName.size()) {
                    currentKeyChange = 0;
                    keyChangeActive = false;
                    view.setCurrentKeyChange(currentKeyChange);
                    Utils::OptionsSave::saveParams(std::string(Path::getSavePath()) + "optSave.oparams");

                    data.getUiDataPtr()->setKeyUp(Utils::OptionsSave::getParam("control.up").getValue());
                    data.getUiDataPtr()->setKeyDown(Utils::OptionsSave::getParam("control.down").getValue());
                    data.getUiDataPtr()->setKeyLeft(Utils::OptionsSave::getParam("control.left").getValue());
                    data.getUiDataPtr()->setKeyRight(Utils::OptionsSave::getParam("control.right").getValue());
                    data.getUiDataPtr()->setKeyTalk(Utils::OptionsSave::getParam("control.talk").getValue());
                    data.getUiDataPtr()->setKeyInteract(Utils::OptionsSave::getParam("control.interact").getValue());
                }

                return GameStatus::CONTINUE;
            }
            if(event.key.code == sf::Keyboard::Return) {
                //If present on the options' main menu, checks what to do
                if(menu.getCurrentOption() == OptionType::ALL) {
                    switch(menu.cursorPosition()) {
                    case BACK:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        return GameStatus::PREVIOUS;
                    case FULLSCREEN:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        if(Utils::OptionsSave::getParam("fullscreen").getValue() == "true") {
                            Utils::OptionsSave::addOrModifParam("fullscreen", "false");
                        } else {
                            Utils::OptionsSave::addOrModifParam("fullscreen", "true");
                        }
                        view.initOptionsMenuItemsValue();
                        return GameStatus::WIN_REBOOT;
                    case LANGUAGE:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::LANG);
                        return GameStatus::CONTINUE;
                        break;
                    case CONTROLS:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::CONTROLS);
                        return GameStatus::CONTINUE;
                        break;
                    case VOLUME:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        toggleVolume();
                        break;
                    case CREDITS:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::CREDITS);
                        return GameStatus::CONTINUE;
                        break;
                    }
                } else if(menu.getCurrentOption() == OptionType::LANG) { //Chooses language to print

                    auto &tr = Utils::I18n::Translator::getInstance();
                    data.getUiDataPtr()->getJukebox().playSound("push");
                    switch(menu.cursorPosition()) {
                    case 0:
                        menu.setCurrentOption(OptionType::ALL);
                        return GameStatus::CONTINUE;
                    case 1:
                        Utils::OptionsSave::modifyParam("lang", "en");
                        tr.setLang("en");
                        break;
                    case 2:
                        Utils::OptionsSave::modifyParam("lang", "es");
                        tr.setLang("es");
                        break;
                    case 3:
                        Utils::OptionsSave::modifyParam("lang", "fr");
                        tr.setLang("fr");
                        break;
                    case 4:
                        Utils::OptionsSave::modifyParam("lang", "de");
                        tr.setLang("de");
                        break;
                    case 5:
                        Utils::OptionsSave::modifyParam("lang", "it");
                        tr.setLang("it");
                        break;
                    }
                    // Refresh the content of the menu items to change the language
                    view.initLanguagesMenuItemsName();
                    view.initOptionsMenuItemsName();
                } else if(menu.getCurrentOption() == OptionType::CREDITS) {
                    //Only one choice is avilable on the credits : back.
                    data.getUiDataPtr()->getJukebox().playSound("push");
                    menu.setCurrentOption(OptionType::ALL);
                    return GameStatus::CONTINUE;
                } else if(menu.getCurrentOption() == OptionType::CONTROLS) {
                    switch(menu.cursorPosition()) {
                    case 0: //Back
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::ALL);
                        return GameStatus::CONTINUE;
                    case 1: //Set controls
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        keyChangeActive = true;
                        view.setCurrentKeyChange(currentKeyChange + 1);
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
                if(menu.getCurrentOption() == OptionType::ALL) {
                    //Returns to the previous game screen if backspace is pressed while in the options' main menu.
                    return GameStatus::PREVIOUS;
                } else {
                    //Returns to the options' main menu if any of the options sub-menus are currently printed.
                    menu.setCurrentOption(OptionType::ALL);
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
        GameStatus status = view.update();
        frame.draw(view);
        return status;
    }

    void OptionsMenuCtrl::toggleVolume() {
        if(data.getUiDataPtr()->getJukebox().getGlobalVolume() > 0) {
            data.getUiDataPtr()->getJukebox().setGlobalVolume(0);
            Utils::OptionsSave::modifyParam("volume", "0");
        } else {
            data.getUiDataPtr()->getJukebox().setGlobalVolume(100);
            Utils::OptionsSave::modifyParam("volume", "100");
        }
        view.initOptionsMenuItemsValue();
    }

    void OptionsMenuCtrl::raiseVolume() {
        const int newVolume = std::min(100, data.getUiDataPtr()->getJukebox().getGlobalVolume() + 10);
        data.getUiDataPtr()->getJukebox().setGlobalVolume(newVolume);
        Utils::OptionsSave::modifyParam("volume", std::to_string(newVolume));
        view.initOptionsMenuItemsValue();
    }

    void OptionsMenuCtrl::lowerVolume() {
        const int newVolume = std::max(0, data.getUiDataPtr()->getJukebox().getGlobalVolume() - 10);
        data.getUiDataPtr()->getJukebox().setGlobalVolume(newVolume);
        Utils::OptionsSave::modifyParam("volume", std::to_string(newVolume));
        view.initOptionsMenuItemsValue();
    }

} // namespace OpMon
