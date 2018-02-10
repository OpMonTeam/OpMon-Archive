/*
  OptionsMenu.hpp
  Author : Cyrion
  File under the GPL-3.0  license
  http://opmon-game.ga
  Contains OptionsMenu namespace
*/
#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include "../start/i18n/ATranslatable.hpp"
#include "Elements.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace OpMon {
    namespace View {

        enum class OptionType { ALL,
                                LANG,
                                CREDITS };

        class OptionsMenu : I18n::ATranslatable {
          public:
            OptionsMenu();

            ~OptionsMenu();

            void moveArrow(bool dir);

            void draw(sf::RenderTarget &frame);

            void loop(sf::RenderTarget &frame);
            void langLoop(sf::RenderTarget &frame);
            void creditsLoop(sf::RenderTarget &frame);

            void initStrings();
            void onLangChanged() override;

            OptionType getCurrentOption() { return currentOptions; }
            void setCurrentOption(OptionType newOpt) { currentOptions = newOpt; }
            int cursorPosition() {
                switch(currentOptions) {
                case OptionType::ALL:
                    return curPosOptI;
                case OptionType::LANG:
                    return curPosLangI;
                default:
                    return 0;
                }
            }

            void play();
            void pause();

          private:
            OptionType currentOptions;

            sf::Sprite bgCredits;
            sf::Sprite bgOpt;
            sf::Text langFr;
            sf::Text langEng;
            sf::Text langEsp;
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

            sf::Text txtLang;
            sf::Text txtCred;
            sf::Sprite bgLangues;
            //J_Texture listeLangues[3] = {};
            sf::Vector2f curPosLang[4] = {};
            sf::Vector2f curSizeLang[4];
            sf::Texture textures2[5];
            sf::Sprite coche;

            bool continuer = true;
        };
    } // namespace View
} // namespace OpMon

#endif // OPTIONSMENU_HPP
