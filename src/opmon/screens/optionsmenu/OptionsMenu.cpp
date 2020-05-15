/*
  OptionsMenu.cpp
  Author : Cyrielle
  Contributors : torq, Navet56, BAKFR
  File under GNU GPL v3.0 license
*/
#include "OptionsMenu.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <algorithm>
#include <memory>
#include <string>

#include "src/utils/OptionsSave.hpp"
#include "src/opmon/view/ui/TextBox.hpp"
#include "src/opmon/core/GameData.hpp"
#include "OptionsMenuData.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"
#include "src/utils/CycleCounter.hpp"
#include "src/utils/StringKeys.hpp"
#include "src/utils/defines.hpp"

namespace OpMon {

    int OPTIONS_MENU_ITEM_HEIGHT = 64;
    int OPTIONS_MENU_ITEM_WIDTH = 504;
    int OPTIONS_MENU_ITEM_PADDING = 4;

    void OptionsMenu::initStrings() {
        txtRetour.setString(data.getGameDataPtr()->getString("options.retour"));
        txtRetour.setFont(data.getGameDataPtr()->getFont());
        txtRetour.setCharacterSize(FONT_SIZE_DEFAULT);
        txtOptions.setString(data.getGameDataPtr()->getString("options.title"));
        txtOptions.setFont(data.getGameDataPtr()->getFont());
        txtOptions.setCharacterSize(FONT_SIZE_DEFAULT);

        txtCred.setString(data.getGameDataPtr()->getString("options.cred.title"));
        txtCred.setFont(data.getGameDataPtr()->getFont());
        txtCred.setCharacterSize(FONT_SIZE_DEFAULT);

        txtCtrl.setString(data.getGameDataPtr()->getString("options.vol"));
        txtCtrl.setFont(data.getGameDataPtr()->getFont());
        txtCtrl.setCharacterSize(FONT_SIZE_DEFAULT);

        txtCre1.setString(data.getGameDataPtr()->getString("options.credit.1"));
        txtCre1.setFont(data.getGameDataPtr()->getFont());
        txtCre1.setCharacterSize(14);
        txtCre1.setSfmlColor(sf::Color::Black);
        txtCre2.setString(data.getGameDataPtr()->getString("options.credit.2"));
        txtCre2.setFont(data.getGameDataPtr()->getFont());
        txtCre2.setCharacterSize(14);
        txtCre2.setSfmlColor(sf::Color::Black);
        txtCre3.setString(data.getGameDataPtr()->getString("options.credit.3"));
        txtCre3.setFont(data.getGameDataPtr()->getFont());
        txtCre3.setCharacterSize(14);
        txtCre3.setSfmlColor(sf::Color::Black);
        txtCre4.setString(data.getGameDataPtr()->getString("options.credit.4"));
        txtCre4.setFont(data.getGameDataPtr()->getFont());
        txtCre4.setCharacterSize(14);
        txtCre4.setSfmlColor(sf::Color::Black);
        txtCre5.setString(data.getGameDataPtr()->getString("options.credit.5"));
        txtCre5.setFont(data.getGameDataPtr()->getFont());
        txtCre5.setCharacterSize(14);
        txtCre5.setSfmlColor(sf::Color::Black);
        txtCre6.setString(data.getGameDataPtr()->getString("options.credit.6"));
        txtCre6.setFont(data.getGameDataPtr()->getFont());
        txtCre6.setCharacterSize(22);
        txtCre6.setSfmlColor(sf::Color::Black);
        txtCre7.setString(data.getGameDataPtr()->getString("options.credit.7"));
        txtCre7.setFont(data.getGameDataPtr()->getFont());
        txtCre7.setCharacterSize(18);
        txtCre7.setSfmlColor(sf::Color::Black);
        txtCre8.setString(data.getGameDataPtr()->getString("options.credit.8"));
        txtCre8.setFont(data.getGameDataPtr()->getFont());
        txtCre8.setCharacterSize(15);
        txtCre81.setString(data.getGameDataPtr()->getString("options.credit.81"));
        txtCre81.setFont(data.getGameDataPtr()->getFont());
        txtCre81.setCharacterSize(15);
        txtCre82.setString(data.getGameDataPtr()->getString("options.credit.82"));
        txtCre82.setFont(data.getGameDataPtr()->getFont());
        txtCre82.setCharacterSize(15);
        txtCre83.setString(data.getGameDataPtr()->getString("options.credit.83"));
        txtCre83.setFont(data.getGameDataPtr()->getFont());
        txtCre83.setCharacterSize(15);
        txtCre84.setString(data.getGameDataPtr()->getString("options.credit.84"));
        txtCre84.setFont(data.getGameDataPtr()->getFont());
        txtCre84.setCharacterSize(15);
        txtCre9.setString(data.getGameDataPtr()->getString("options.credit.9"));
        txtCre9.setFont(data.getGameDataPtr()->getFont());
        txtCre9.setCharacterSize(13);
        txtCre10.setString(data.getGameDataPtr()->getString("options.credit.10"));
        txtCre10.setFont(data.getGameDataPtr()->getFont());
        txtCre10.setCharacterSize(20);
        txtCre10.setSfmlColor(sf::Color::Blue);

        txtCtrlChange.setString(data.getGameDataPtr()->getString("options.ctrl.change"));
        txtCtrlChange.setFont(data.getGameDataPtr()->getFont());
        txtCtrlChange.setCharacterSize(FONT_SIZE_DEFAULT);
    }

    void OptionsMenu::onLangChanged() {
        initStrings();
    }

    OptionsMenu::OptionsMenu(OptionsMenuData &data)
        : data(data)
        , currentOptions(OptionType::ALL) {
        float optionsMenuItemX = (data.getGameDataPtr()->getWindowWidth() - OPTIONS_MENU_ITEM_WIDTH)/2;

        // Create text boxes for the main screen
        for(int i = 0; i < 5; i++) {
            sf::Vector2f position(optionsMenuItemX, OPTIONS_MENU_ITEM_PADDING + i * (OPTIONS_MENU_ITEM_HEIGHT + OPTIONS_MENU_ITEM_PADDING));
            TextBox optionsMenuItem(data.getGameDataPtr()->getMenuFrame(), position, OPTIONS_MENU_ITEM_WIDTH, OPTIONS_MENU_ITEM_HEIGHT);
            optionsMenuItem.setFont(data.getGameDataPtr()->getFont());
            optionsMenuItems.push_back(optionsMenuItem);
        }
        initOptionsMenuItemsName();
        initOptionsMenuItemsValue();

        // Create text boxes for the language selection screen
        for(int i = 0; i < 6; i++) {
            sf::Vector2f position(optionsMenuItemX, OPTIONS_MENU_ITEM_PADDING + i * (OPTIONS_MENU_ITEM_HEIGHT + OPTIONS_MENU_ITEM_PADDING));
            TextBox languagesMenuItem(data.getGameDataPtr()->getMenuFrame(), position, OPTIONS_MENU_ITEM_WIDTH, OPTIONS_MENU_ITEM_HEIGHT);
            languagesMenuItem.setFont(data.getGameDataPtr()->getFont());
            languagesMenuItems.push_back(languagesMenuItem);
        }
        initLanguagesMenuItemsName();

        bgOpt.setTexture(data.getBackground());
        rectSurb.setTexture(data.getSelectBar());
        bgLangues.setTexture(data.getLangBg());
        bgCredits.setTexture(data.getCreditsBg());
        bgControls.setTexture(data.getControlsBg());

        volumeCur.setTexture(data.getVolumeCur());

        initStrings();

        txtRetour.setPosition(55, 25);

        txtOptions.setPosition(230, 25);
        txtCred.setPosition(250, 25);
        txtCtrl.setPosition(250, 25);

        txtCre1.setPosition(180, 128);
        txtCre2.setPosition(180, 148);
        txtCre3.setPosition(180, 168);
        txtCre4.setPosition(350, 128);
        txtCre5.setPosition(350, 148);
        txtCre6.setPosition(30, 250);
        txtCre7.setPosition(30, 274);
        txtCre8.setPosition(30, 368);
        txtCre81.setPosition(10, 385);
        txtCre82.setPosition(10, 402);
        txtCre83.setPosition(10, 420);
        txtCre84.setPosition(10, 437);
        txtCre9.setPosition(450, 488);
        txtCre10.setPosition(180, 100);

        txtCtrlChange.setPosition(33.0, 91.0);

        txtCtrlUp.setPosition(155.0, 180.0);
        txtCtrlDown.setPosition(153.0, 455.0);
        txtCtrlLeft.setPosition(14.0, 316.0);
        txtCtrlRight.setPosition(303.0, 315.0);
        txtCtrlTalk.setPosition(417.0, 216.0);
        txtCtrlInteract.setPosition(417.0, 339.0);

        txtCtrlUp.setFont(data.getGameDataPtr()->getFont());
        txtCtrlUp.setCharacterSize(FONT_SIZE_DEFAULT - 4);
        txtCtrlDown.setFont(data.getGameDataPtr()->getFont());
        txtCtrlDown.setCharacterSize(FONT_SIZE_DEFAULT - 4);
        txtCtrlLeft.setFont(data.getGameDataPtr()->getFont());
        txtCtrlLeft.setCharacterSize(FONT_SIZE_DEFAULT - 4);
        txtCtrlRight.setFont(data.getGameDataPtr()->getFont());
        txtCtrlRight.setCharacterSize(FONT_SIZE_DEFAULT - 4);
        txtCtrlTalk.setFont(data.getGameDataPtr()->getFont());
        txtCtrlTalk.setCharacterSize(FONT_SIZE_DEFAULT - 4);
        txtCtrlInteract.setFont(data.getGameDataPtr()->getFont());
        txtCtrlInteract.setCharacterSize(FONT_SIZE_DEFAULT - 4);

        rectKeyChange.setTexture(data.getKeyChange());
        rectKeyChange.setScale(70 / rectKeyChange.getGlobalBounds().width, 43 / rectKeyChange.getGlobalBounds().height);

        curPosOpt[0].x = 23;
        curPosOpt[0].y = 17;
        curSizeOpt[0].x = 134 / rectSurb.getGlobalBounds().width;
        curSizeOpt[0].y = 49 / rectSurb.getGlobalBounds().height;

        curPosLang[0].x = 23;
        curPosLang[0].y = 17;
        curSizeLang[0].x = 134 / rectSurb.getGlobalBounds().width;
        curSizeLang[0].y = 49 / rectSurb.getGlobalBounds().height;

        curPosCtrl[0].x = 23;
        curPosCtrl[0].y = 17;
        curSizeCtrl[0].x = 134 / rectSurb.getGlobalBounds().width;
        curSizeCtrl[0].y = 49 / rectSurb.getGlobalBounds().height;

        for(int i = 1, j = 86; i < 6; i++) {
            curPosOpt[i].x = 23;
            curPosOpt[i].y = j;
            curSizeOpt[i].x = 464 / rectSurb.getGlobalBounds().width;
            if(i == 4) {
                curSizeOpt[i].y = 62 / rectSurb.getGlobalBounds().height;
                curPosOpt[i].y -= 5;
            } else {
                curSizeOpt[i].y = 57 / rectSurb.getGlobalBounds().height;
            }
            j += 69;
        }

        for(int i = 1, j = 86; i < 6; i++) {
            curPosLang[i].x = 23;
            curPosLang[i].y = j;
            curSizeLang[i].x = 464 / rectSurb.getGlobalBounds().width;
            curSizeLang[i].y = 57 / rectSurb.getGlobalBounds().height;
            j += 70;
        }

        curPosCtrl[1].x = 23;
        curPosCtrl[1].y = 81;
        curSizeCtrl[1].x = 351 / rectSurb.getGlobalBounds().width;
        curSizeCtrl[1].y = 63 / rectSurb.getGlobalBounds().height;
    }

    void OptionsMenu::draw(sf::RenderTarget &frame, sf::RenderStates states) const {
        switch(currentOptions) {
        case OptionType::CREDITS:
            frame.clear(sf::Color::White);
            frame.draw(bgCredits);
            frame.draw(txtCre1);
            frame.draw(txtCre2);
            frame.draw(txtCre3);
            frame.draw(txtCre4);
            frame.draw(txtCre5);
            frame.draw(txtCre6);
            frame.draw(txtCre7);
            frame.draw(txtCre8);
            frame.draw(txtCre81);
            frame.draw(txtCre82);
            frame.draw(txtCre83);
            frame.draw(txtCre84);
            frame.draw(txtCre9);
            frame.draw(txtCre10);
            frame.draw(rectSurb);
            frame.draw(txtRetour);
            frame.draw(txtCred);
            break;

        case OptionType::CONTROLS:
            frame.clear(sf::Color::White);
            frame.draw(bgControls);
            frame.draw(txtCtrlChange);
            frame.draw(rectKeyChange);
            frame.draw(txtCtrlUp);
            frame.draw(txtCtrlDown);
            frame.draw(txtCtrlLeft);
            frame.draw(txtCtrlRight);
            frame.draw(txtCtrlTalk);
            frame.draw(txtCtrlInteract);
            frame.draw(rectSurb);
            frame.draw(txtRetour);
            frame.draw(txtCtrl);
            break;

        case OptionType::LANG:
            frame.clear(sf::Color(74, 81, 148));
            for(auto &languagesMenuItem : languagesMenuItems) {
                frame.draw(languagesMenuItem);
            }
            break;

        case OptionType::ALL:
            frame.clear(sf::Color(74, 81, 148));
            for(auto &optionsMenuItem : optionsMenuItems) {
                frame.draw(optionsMenuItem);
            }
            break;

        }
    }

    GameStatus OptionsMenu::update() {
        switch(currentOptions) {
        case OptionType::ALL:
            return loop();
        case OptionType::LANG:
            return langLoop();
        case OptionType::CONTROLS:
            return controlsLoop();
        case OptionType::CREDITS:
            return creditsLoop();
        }
    }

    void OptionsMenu::moveArrow(bool move) {
        switch(currentOptions) {
        case OptionType::ALL:
            curPosOptI += (move ? -1 : 1);
            break;
        case OptionType::CONTROLS:
            curPosCtrlI += (move ? -1 : 1);
            break;
        case OptionType::LANG:
            curPosLangI += (move ? -1 : 1);
            break;
        default:
            break;
        }
    }

    GameStatus OptionsMenu::loop() {
        for(auto &optionsMenuItem : optionsMenuItems) {
            optionsMenuItem.setActive(false);
        }
        optionsMenuItems[curPosOptI.getValue()].setActive(true);
        return GameStatus::CONTINUE;
    }

    GameStatus OptionsMenu::langLoop() {
        for(auto &languagesMenuItem : languagesMenuItems) {
            languagesMenuItem.setActive(false);
        }
        languagesMenuItems[curPosLangI.getValue()].setActive(true);
        return GameStatus::CONTINUE;
    }

    void OptionsMenu::pause() {
    }

    void OptionsMenu::play() {
    }

    GameStatus OptionsMenu::controlsLoop() {
        rectKeyChange.setPosition(posControls[currentKeyChange]);
        txtCtrlUp.setString(data.getGameDataPtr()->getOptions().getParam("control.up").getValue());
        txtCtrlDown.setString(data.getGameDataPtr()->getOptions().getParam("control.down").getValue());
        txtCtrlLeft.setString(data.getGameDataPtr()->getOptions().getParam("control.left").getValue());
        txtCtrlRight.setString(data.getGameDataPtr()->getOptions().getParam("control.right").getValue());
        txtCtrlTalk.setString(data.getGameDataPtr()->getOptions().getParam("control.talk").getValue());
        txtCtrlInteract.setString(data.getGameDataPtr()->getOptions().getParam("control.interact").getValue());
        rectSurb.setPosition(curPosCtrl[curPosCtrlI.getValue()]);
        rectSurb.setScale(curSizeCtrl[curPosCtrlI.getValue()]);
        return GameStatus::CONTINUE;
    }

    GameStatus OptionsMenu::creditsLoop() {
        rectSurb.setPosition(curPosOpt[0]);
        rectSurb.setScale(curSizeLang[0]);
        return GameStatus::CONTINUE;
    }

    void OptionsMenu::initOptionsMenuItemsName() {
        std::string key;
        int i = 0;
        for(auto &optionsMenuItem : optionsMenuItems) {
            switch (i) {
            case 0:
                key = "ecran";
                break;
            case 1:
                key = "lang";
                break;
            case 2:
                key = "controls";
                break;
            case 3:
                key = "volume";
                break;
            case 4:
                key = "credits";
                break;
            }
            optionsMenuItem.setLeftContent(data.getGameDataPtr()->getString("options." + key));
            ++i;
        }
    }

    void OptionsMenu::initOptionsMenuItemsValue() {
        int i = 0;
        int globalVolume = data.getGameDataPtr()->getJukebox().getGlobalVolume();
        for(auto &optionsMenuItem : optionsMenuItems) {
            switch (i) {
            case 1:
                if(data.getGameDataPtr()->getOptions().getParam("fullscreen").getValue() == "true") {
                    optionsMenuItem.setRightContent("On");
                } else {
                    optionsMenuItem.setRightContent("Off");
                }
                break;
            case 3:
                optionsMenuItem.setRightContent(std::to_string(globalVolume) + "%");
                break;
            default:
                break;
            }
            ++i;
        }
    }

    void OptionsMenu::initLanguagesMenuItemsName() {
        int i = 0;
        for(auto &languagesMenuItem : languagesMenuItems) {
            switch (i) {
            case 0:
                languagesMenuItem.setLeftContent(data.getGameDataPtr()->getString("options.retour"));
                break;
            case 1:
                languagesMenuItem.setLeftContent("English");
                break;
            case 2:
                languagesMenuItem.setLeftContent(L"Espa\u00F1ol");
                break;
            case 3:
                languagesMenuItem.setLeftContent(L"Francais");
                break;
            case 4:
                languagesMenuItem.setLeftContent("Deutsch");
                break;
            case 5:
                languagesMenuItem.setLeftContent("Italiano");
                break;

            }
            ++i;
        }
    }

} // namespace OpMon
