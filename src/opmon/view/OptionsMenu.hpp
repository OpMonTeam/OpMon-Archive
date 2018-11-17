/*
  OptionsMenu.hpp
  Author : Cyrion
  Contributors : torq, Navet56, BAKFR
  File under GNU GPL v3.0 license
*/
#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include "../model/storage/OptionsMenuData.hpp"
#include "../start/i18n/ATranslatable.hpp"
#include "../helper/MenuHelper.hpp"
#include "Elements.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace OpMon {
    namespace View {

        enum class OptionType { ALL,
                                LANG,
                                CONTROLES,
                                CREDITS };

        class OptionsMenu : I18n::ATranslatable {
          public:
            OptionsMenu(Model::OptionsMenuData &data);
            ~OptionsMenu() = default;

            void moveArrow(bool dir);

            void draw(sf::RenderTarget &frame);

            void loop(sf::RenderTarget &frame);
            void langLoop(sf::RenderTarget &frame);
            void controlesLoop(sf::RenderTarget &frame);
            void creditsLoop(sf::RenderTarget &frame);

            void initStrings();
            void onLangChanged() override;

            OptionType getCurrentOption() { return currentOptions; }
            void setCurrentOption(OptionType newOpt) { currentOptions = newOpt; }
            int cursorPosition() const {
                switch(currentOptions) {
                case OptionType::ALL:
                    return curPosOptI;
                case OptionType::LANG:
                    return curPosLangI;
                case OptionType::CONTROLES:
                    return curPosCtrlI;
                }

                return 0;
            }

            void setCurrentActionsCtrl(int currentActionsCtrl_) { currentActionsCtrl = currentActionsCtrl_; }

            void play();
            void pause();

          private:
            Model::OptionsMenuData &data;
            OptionType currentOptions;

            sf::Sprite volumeCur;
            sf::Sprite bgCredits;
            sf::Sprite bgOpt;
            sf::Sprite bgControles;

            sf::Text langFr;
            sf::Text langEng;
            sf::Text langEsp;
            sf::Text langDe;

            sf::Text txtRetour;
            sf::Text txtOptions;
            sf::Text txtCre1;
            sf::Text txtCre2;
            sf::Text txtCre3;
            sf::Text txtCre4;
            sf::Text txtCre5;
            sf::Text txtCre6;
            sf::Text txtCre7;
            sf::Text txtCre8;
            sf::Text txtCre81;
            sf::Text txtCre82;
            sf::Text txtCre83;
            sf::Text txtCre84;
            sf::Text txtCre9;
            sf::Text txtOpt1;
            sf::Text txtOpt2;
            sf::Text txtOpt3;
            sf::Text txtOpt4;
            sf::Text txtOpt5;
            sf::Sprite rectSurb;
            sf::Vector2f curPosOpt[6] = {};
            sf::Vector2f curSizeOpt[6];
            int optionSelect = -1;
            int curPosOptI = 0;
            int curPosLangI = 0;
            int curPosCtrlI = 0;
            int currentActionsCtrl{0};
            sf::Text txtCtrlChange;
            sf::Text txtCtrlUp;
            sf::Text txtCtrlDown;
            sf::Text txtCtrlLeft;
            sf::Text txtCtrlRight;
            sf::Text txtCtrlTalk;
            sf::Text txtCtrlInteract;
            sf::Sprite rectKeyChange;
            const sf::Vector2f posControls[7] = {
                {-500.0, -500.0}, {108.0, 215.0}, {98.0, 348.0}, {5.0, 280.0}, {175.0, 280.0}, {255.0, 440.0}, {350.0, 395.0}
            };

            sf::Text txtLang;
            sf::Text txtCred;
            sf::Text txtCtrl;
            sf::Sprite bgLangues;
            sf::Vector2f curPosLang[5] = {};
            sf::Vector2f curSizeLang[5];
            sf::Vector2f curPosCtrl[5] = {};
            sf::Vector2f curSizeCtrl[5];
            sf::Sprite check;
        };
    } // namespace View
} // namespace OpMon

#endif // OPTIONSMENU_HPP
