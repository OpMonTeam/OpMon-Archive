/*
OptionsMenu.cpp
Author : Cyrielle
Contributors : torq, Navet56, BAKFR
File under GNU GPL v3.0 license
*/
#include "OptionsMenu.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "Window.hpp"

namespace OpMon {
    namespace View {

        void OptionsMenu::initStrings() {
            auto kget = Utils::StringKeys::get;

            langFr.setString(L"Français");
            langFr.setFont(data.getUiDataPtr()->getFont());
            langFr.setCharacterSize(FONT_SIZE_DEFAULT);
            langEng.setString("English");
            langEng.setFont(data.getUiDataPtr()->getFont());
            langEng.setCharacterSize(FONT_SIZE_DEFAULT);
            langEsp.setString(L"Espa\u00F1ol");
            langEsp.setFont(data.getUiDataPtr()->getFont());
            langEsp.setCharacterSize(FONT_SIZE_DEFAULT);
            langDe.setString("Deutsch");
            langDe.setFont(data.getUiDataPtr()->getFont());
            langDe.setCharacterSize(FONT_SIZE_DEFAULT);
	    langIt.setString("Italiano");
	    langIt.setFont(data.getUiDataPtr()->getFont());
	    langIt.setCharacterSize(FONT_SIZE_DEFAULT);
            txtRetour.setString(kget("options.retour"));
            txtRetour.setFont(data.getUiDataPtr()->getFont());
            txtRetour.setCharacterSize(FONT_SIZE_DEFAULT);
            txtOptions.setString(kget("options.title"));
            txtOptions.setFont(data.getUiDataPtr()->getFont());
            txtOptions.setCharacterSize(FONT_SIZE_DEFAULT);
            txtOpt1.setString(kget("options.ecran"));
            txtOpt1.setFont(data.getUiDataPtr()->getFont());
            txtOpt1.setCharacterSize(FONT_SIZE_DEFAULT);
            txtOpt2.setString(kget("options.lang"));
            txtOpt2.setFont(data.getUiDataPtr()->getFont());
            txtOpt2.setCharacterSize(FONT_SIZE_DEFAULT);
            txtOpt3.setString(kget("options.vol"));
            txtOpt3.setFont(data.getUiDataPtr()->getFont());
            txtOpt3.setCharacterSize(FONT_SIZE_DEFAULT);
            txtOpt3.setSfmlColor(sf::Color::White);
            txtOpt4.setString(kget("options.control"));
            txtOpt4.setFont(data.getUiDataPtr()->getFont());
            txtOpt4.setCharacterSize(FONT_SIZE_DEFAULT);
            txtOpt4.setSfmlColor(sf::Color::White);
            txtOpt5.setString(kget("options.credit"));
            txtOpt5.setFont(data.getUiDataPtr()->getFont());
            txtOpt5.setCharacterSize(FONT_SIZE_DEFAULT);
            txtOpt5.setSfmlColor(sf::Color::White);

            txtLang.setString(kget("options.lang.title"));
            txtLang.setFont(data.getUiDataPtr()->getFont());
            txtLang.setCharacterSize(FONT_SIZE_DEFAULT);

            txtCred.setString(kget("options.cred.title"));
            txtCred.setFont(data.getUiDataPtr()->getFont());
            txtCred.setCharacterSize(FONT_SIZE_DEFAULT);

            txtCtrl.setString(kget("options.vol"));
            txtCtrl.setFont(data.getUiDataPtr()->getFont());
            txtCtrl.setCharacterSize(FONT_SIZE_DEFAULT);

            txtCre1.setString(kget("options.credit.1"));
            txtCre1.setFont(data.getUiDataPtr()->getFont());
            txtCre1.setCharacterSize(14);
            txtCre1.setSfmlColor(sf::Color::Black);
            txtCre2.setString(kget("options.credit.2"));
            txtCre2.setFont(data.getUiDataPtr()->getFont());
            txtCre2.setCharacterSize(14);
            txtCre2.setSfmlColor(sf::Color::Black);
            txtCre3.setString(kget("options.credit.3"));
            txtCre3.setFont(data.getUiDataPtr()->getFont());
            txtCre3.setCharacterSize(14);
            txtCre3.setSfmlColor(sf::Color::Black);
            txtCre4.setString(kget("options.credit.4"));
            txtCre4.setFont(data.getUiDataPtr()->getFont());
            txtCre4.setCharacterSize(14);
            txtCre4.setSfmlColor(sf::Color::Black);
            txtCre5.setString(kget("options.credit.5"));
            txtCre5.setFont(data.getUiDataPtr()->getFont());
            txtCre5.setCharacterSize(14);
            txtCre5.setSfmlColor(sf::Color::Black);
            txtCre6.setString(kget("options.credit.6"));
            txtCre6.setFont(data.getUiDataPtr()->getFont());
            txtCre6.setCharacterSize(22);
            txtCre6.setSfmlColor(sf::Color::Black);
            txtCre7.setString(kget("options.credit.7"));
            txtCre7.setFont(data.getUiDataPtr()->getFont());
            txtCre7.setCharacterSize(18);
            txtCre7.setSfmlColor(sf::Color::Black);
            txtCre8.setString(kget("options.credit.8"));
            txtCre8.setFont(data.getUiDataPtr()->getFont());
            txtCre8.setCharacterSize(15);
            txtCre81.setString(kget("options.credit.81"));
            txtCre81.setFont(data.getUiDataPtr()->getFont());
            txtCre81.setCharacterSize(15);
            txtCre82.setString(kget("options.credit.82"));
            txtCre82.setFont(data.getUiDataPtr()->getFont());
            txtCre82.setCharacterSize(15);
            txtCre83.setString(kget("options.credit.83"));
            txtCre83.setFont(data.getUiDataPtr()->getFont());
            txtCre83.setCharacterSize(15);
            txtCre84.setString(kget("options.credit.84"));
            txtCre84.setFont(data.getUiDataPtr()->getFont());
            txtCre84.setCharacterSize(15);
            txtCre9.setString(kget("options.credit.9"));
            txtCre9.setFont(data.getUiDataPtr()->getFont());
            txtCre9.setCharacterSize(13);
            txtCre10.setString(kget("options.credit.10"));
            txtCre10.setFont(data.getUiDataPtr()->getFont());
            txtCre10.setCharacterSize(20);
            txtCre10.setSfmlColor(sf::Color::Blue);

            txtCtrlChange.setString(kget("options.ctrl.change"));
            txtCtrlChange.setFont(data.getUiDataPtr()->getFont());
            txtCtrlChange.setCharacterSize(FONT_SIZE_DEFAULT);
        }

        void OptionsMenu::onLangChanged() {
            initStrings();
        }

        OptionsMenu::OptionsMenu(Model::OptionsMenuData &data)
          : data(data)
          , currentOptions(OptionType::ALL) {

            bgOpt.setTexture(data.getBackground());
            rectSurb.setTexture(data.getSelectBar());
            bgLangues.setTexture(data.getLangBg());
            check.setTexture(data.getYesTx());
            bgCredits.setTexture(data.getCreditsBg());
            bgControls.setTexture(data.getControlsBg());

            volumeCur.setTexture(data.getVolumeCur());
            //Cursor positions :
            //volumeCur.setPosition(165, 290);// = 0
            //volumeCur.setPosition(460, 290);// = 100

            check.setPosition(425, 88);

            initStrings();

            txtOpt1.setPosition(120, 100);
            txtOpt2.setPosition(120, 170);
            txtOpt3.setPosition(120, 240);
            txtOpt5.setPosition(120, 310);
            txtOpt4.setPosition(120, 380);

            langEsp.setPosition(45, 170);
            langEng.setPosition(45, 100);
            langFr.setPosition(45, 240);
            langDe.setPosition(45, 310);
	    langIt.setPosition(45, 380);

            txtRetour.setPosition(55, 25);

            txtLang.setPosition(250, 25);
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

            txtCtrlUp.setFont(data.getUiDataPtr()->getFont());
            txtCtrlUp.setCharacterSize(FONT_SIZE_DEFAULT - 4);
            txtCtrlDown.setFont(data.getUiDataPtr()->getFont());
            txtCtrlDown.setCharacterSize(FONT_SIZE_DEFAULT - 4);
            txtCtrlLeft.setFont(data.getUiDataPtr()->getFont());
            txtCtrlLeft.setCharacterSize(FONT_SIZE_DEFAULT - 4);
            txtCtrlRight.setFont(data.getUiDataPtr()->getFont());
            txtCtrlRight.setCharacterSize(FONT_SIZE_DEFAULT - 4);
            txtCtrlTalk.setFont(data.getUiDataPtr()->getFont());
            txtCtrlTalk.setCharacterSize(FONT_SIZE_DEFAULT - 4);
            txtCtrlInteract.setFont(data.getUiDataPtr()->getFont());
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

        void OptionsMenu::draw(sf::RenderTarget &frame) {
            switch(currentOptions) {
            case OptionType::ALL:
                return loop(frame);
            case OptionType::LANG:
                return langLoop(frame);
            case OptionType::CONTROLS:
                return controlsLoop(frame);
            case OptionType::CREDITS:
                return creditsLoop(frame);
            }
        }

        void OptionsMenu::moveArrow(bool move) {
            switch(currentOptions) {
            case OptionType::ALL:
                Controller::Helper::moveArrow(move, curPosOptI, 6);
                break;
            case OptionType::CONTROLS:
                Controller::Helper::moveArrow(move, curPosCtrlI, 2);
                break;
            case OptionType::LANG:
                Controller::Helper::moveArrow(move, curPosLangI, 6);
                break;
            default:
              break;
            }
        }

        void OptionsMenu::loop(sf::RenderTarget &frame) {
            frame.clear(sf::Color::White);

            frame.draw(bgOpt);
            frame.draw(txtOpt1);
            frame.draw(txtOpt2);
            frame.draw(txtOpt3);
            frame.draw(txtOpt4);
            frame.draw(txtOpt5);
            frame.draw(txtRetour);
            frame.draw(txtOptions);

            volumeCur.setPosition(166 + (295 * data.getUiDataPtr()->getJukebox().getGlobalVolume() / 100), 298);

            frame.draw(volumeCur);
            if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
                frame.draw(check);
            }
            rectSurb.setPosition(curPosOpt[curPosOptI]);
            rectSurb.setScale(curSizeOpt[curPosOptI]);
            frame.draw(rectSurb);
        }

        void OptionsMenu::langLoop(sf::RenderTarget &frame) {
            frame.clear(sf::Color::White);

            frame.draw(bgLangues);
            frame.draw(langEng);
            frame.draw(langEsp);
            frame.draw(langFr);
            frame.draw(langDe);
	    frame.draw(langIt);
            frame.draw(txtRetour);
            frame.draw(txtLang);
            rectSurb.setPosition(curPosOpt[curPosLangI]);
            rectSurb.setScale(curSizeLang[curPosLangI]);
            frame.draw(rectSurb);
        }

        void OptionsMenu::pause() {
        }

        void OptionsMenu::play() {
        }

        void OptionsMenu::controlsLoop(sf::RenderTarget &frame) {
            frame.clear(sf::Color::White);

            frame.draw(bgControls);

            frame.draw(txtCtrlChange);

            rectKeyChange.setPosition(posControls[currentActionsCtrl]);
            frame.draw(rectKeyChange);

            txtCtrlUp.setString(Model::OptionsSave::getParam("control.up").getValue());
            txtCtrlDown.setString(Model::OptionsSave::getParam("control.down").getValue());
            txtCtrlLeft.setString(Model::OptionsSave::getParam("control.left").getValue());
            txtCtrlRight.setString(Model::OptionsSave::getParam("control.right").getValue());
            txtCtrlTalk.setString(Model::OptionsSave::getParam("control.talk").getValue());
            txtCtrlInteract.setString(Model::OptionsSave::getParam("control.interact").getValue());

            frame.draw(txtCtrlUp);
            frame.draw(txtCtrlDown);
            frame.draw(txtCtrlLeft);
            frame.draw(txtCtrlRight);
            frame.draw(txtCtrlTalk);
            frame.draw(txtCtrlInteract);

            rectSurb.setPosition(curPosCtrl[curPosCtrlI]);
            rectSurb.setScale(curSizeCtrl[curPosCtrlI]);
            frame.draw(rectSurb);

            frame.draw(txtRetour);
            frame.draw(txtCtrl);
        }

        void OptionsMenu::creditsLoop(sf::RenderTarget &frame) {
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

            rectSurb.setPosition(curPosOpt[0]);
            rectSurb.setScale(curSizeLang[0]);
            frame.draw(rectSurb);

            frame.draw(txtRetour);
            frame.draw(txtCred);
        }

    } // namespace View
} // namespace OpMon
