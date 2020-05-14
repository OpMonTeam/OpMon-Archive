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
#include "src/opmon/core/GameData.hpp"
#include "src/utils/KeyData.hpp"
#include "OptionsMenu.hpp"
#include "OptionsMenuData.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"

enum MenuOption { FULLSCREEN = 0,
                  LANGUAGE = 1,
                  CONTROLS = 2,
                  VOLUME = 3,
                  CREDITS = 4 };

namespace OpMon {

    OptionsMenuCtrl::OptionsMenuCtrl(GameData *data)
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
                        data.getGameDataPtr()->getOptions().addParam(std::string("control.") + controlsName[currentKeyChange], keyCode.c_str());
                    }
                    ++currentKeyChange;
                    view.setCurrentKeyChange(currentKeyChange + 1);
                }

                if(currentKeyChange >= controlsName.size()) {
                    currentKeyChange = 0;
                    keyChangeActive = false;
                    view.setCurrentKeyChange(currentKeyChange);
                    data.getGameDataPtr()->getOptions().saveParams();

                    data.getGameDataPtr()->setKeyUp(data.getGameDataPtr()->getOptions().getParam("control.up").getValue());
                    data.getGameDataPtr()->setKeyDown(data.getGameDataPtr()->getOptions().getParam("control.down").getValue());
                    data.getGameDataPtr()->setKeyLeft(data.getGameDataPtr()->getOptions().getParam("control.left").getValue());
                    data.getGameDataPtr()->setKeyRight(data.getGameDataPtr()->getOptions().getParam("control.right").getValue());
                    data.getGameDataPtr()->setKeyTalk(data.getGameDataPtr()->getOptions().getParam("control.talk").getValue());
                    data.getGameDataPtr()->setKeyInteract(data.getGameDataPtr()->getOptions().getParam("control.interact").getValue());
                }

                return GameStatus::CONTINUE;
            }
            if(event.key.code == sf::Keyboard::Return) {
                //If present on the options' main menu, checks what to do
                if(menu.getCurrentOption() == OptionType::ALL) {
                    switch(menu.cursorPosition()) {
                    case FULLSCREEN:
                        data.getGameDataPtr()->getJukebox().playSound("push");
                        if(data.getGameDataPtr()->getOptions().getParam("fullscreen").getValue() == "true") {
                            data.getGameDataPtr()->getOptions().addOrModifParam("fullscreen", "false");
                        } else {
                            data.getGameDataPtr()->getOptions().addOrModifParam("fullscreen", "true");
                        }
                        view.initOptionsMenuItemsValue();
                        return GameStatus::WIN_REBOOT;
                    case LANGUAGE:
                        data.getGameDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::LANG);
                        return GameStatus::CONTINUE;
                        break;
                    case CONTROLS:
                        data.getGameDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::CONTROLS);
                        return GameStatus::CONTINUE;
                        break;
                    case VOLUME:
                        data.getGameDataPtr()->getJukebox().playSound("push");
                        toggleVolume();
                        break;
                    case CREDITS:
                        data.getGameDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::CREDITS);
                        return GameStatus::CONTINUE;
                        break;
                    }
                } else if(menu.getCurrentOption() == OptionType::LANG) { //Chooses language to print

                    auto &tr = Utils::I18n::Translator::getInstance();
                    data.getGameDataPtr()->getJukebox().playSound("push");
                    switch(menu.cursorPosition()) {
                    case 0:
                        menu.setCurrentOption(OptionType::ALL);
                        return GameStatus::CONTINUE;
                    case 1:
                        data.getGameDataPtr()->getOptions().editParam("lang", "en");
                        tr.setLang("en");
                        break;
                    case 2:
                        data.getGameDataPtr()->getOptions().editParam("lang", "es");
                        tr.setLang("es");
                        break;
                    case 3:
                        data.getGameDataPtr()->getOptions().editParam("lang", "fr");
                        tr.setLang("fr");
                        break;
                    case 4:
                        data.getGameDataPtr()->getOptions().editParam("lang", "de");
                        tr.setLang("de");
                        break;
                    case 5:
                        data.getGameDataPtr()->getOptions().editParam("lang", "it");
                        tr.setLang("it");
                        break;
                    }
                    // Refresh the content of the menu items to change the language
                    view.initLanguagesMenuItemsName();
                    view.initOptionsMenuItemsName();
                } else if(menu.getCurrentOption() == OptionType::CREDITS) {
                    //Only one choice is avilable on the credits : back.
                    data.getGameDataPtr()->getJukebox().playSound("push");
                    menu.setCurrentOption(OptionType::ALL);
                    return GameStatus::CONTINUE;
                } else if(menu.getCurrentOption() == OptionType::CONTROLS) {
                    switch(menu.cursorPosition()) {
                    case 0: //Back
                        data.getGameDataPtr()->getJukebox().playSound("push");
                        menu.setCurrentOption(OptionType::ALL);
                        return GameStatus::CONTINUE;
                    case 1: //Set controls
                        data.getGameDataPtr()->getJukebox().playSound("push");
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
                data.getGameDataPtr()->getJukebox().playSound("arrow");
            } else if(event.key.code == sf::Keyboard::Down) {
                menu.moveArrow(false);
                data.getGameDataPtr()->getJukebox().playSound("arrow");
            } else if(event.key.code == sf::Keyboard::BackSpace) {
                data.getGameDataPtr()->getJukebox().playSound("push");
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
        if(data.getGameDataPtr()->getJukebox().getGlobalVolume() > 0) {
            data.getGameDataPtr()->getJukebox().setGlobalVolume(0);
            data.getGameDataPtr()->getOptions().editParam("volume", "0");
        } else {
            data.getGameDataPtr()->getJukebox().setGlobalVolume(100);
            data.getGameDataPtr()->getOptions().editParam("volume", "100");
        }
        view.initOptionsMenuItemsValue();
    }

    void OptionsMenuCtrl::raiseVolume() {
        const int newVolume = std::min(100, data.getGameDataPtr()->getJukebox().getGlobalVolume() + 10);
        data.getGameDataPtr()->getJukebox().setGlobalVolume(newVolume);
        data.getGameDataPtr()->getOptions().editParam("volume", std::to_string(newVolume));
        view.initOptionsMenuItemsValue();
    }

    void OptionsMenuCtrl::lowerVolume() {
        const int newVolume = std::max(0, data.getGameDataPtr()->getJukebox().getGlobalVolume() - 10);
        data.getGameDataPtr()->getJukebox().setGlobalVolume(newVolume);
        data.getGameDataPtr()->getOptions().editParam("volume", std::to_string(newVolume));
        view.initOptionsMenuItemsValue();
    }

} // namespace OpMon
