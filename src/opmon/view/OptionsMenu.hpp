/*!
 * \file OptionsMenu.hpp
 * \authors Cyrielle
 * \authors torq
 * \authors Navet56
 * \authors BAKFR
 * \copyright GNU GPL v3.0
*/
#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include "../controller/MenuHelper.hpp"
#include "../model/storage/OptionsMenuData.hpp"
#include "../start/i18n/ATranslatable.hpp"
#include "Elements.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace OpMon {
    namespace View {

        /*!
         * \brief The different screens of the settings.
         */
        enum class OptionType { ALL,/*!< The main menu of the settings.*/
                                LANG,/*!< The language menu.*/
                                CONTROLS,/*!< The controls menu.*/
                                CREDITS/*!< The credits screen.*/ };

        /*!
         * \brief The screen of the settings.
         * \todo Change OptionsMenu to SettingsMenu
         * \todo Make the addition of a language easier.
         * \todo Put some variables in arrays.
         */
        class OptionsMenu : I18n::ATranslatable {
          public:
            OptionsMenu(Model::OptionsMenuData &data);
            ~OptionsMenu() = default;

            /*!
             * \brief Moves the cursor.
             * \param dir If `true`, the cursor goes up. It goes down otherwise
             */
            void moveArrow(bool dir);

            /*!
             * \brief Draws the menu on the given frame.
             */
            void draw(sf::RenderTarget &frame);

            /*!
             * \brief Updates the main settings menu.
             */
            void loop(sf::RenderTarget &frame);
            /*!
             * \brief Updates the language menu.
             */
            void langLoop(sf::RenderTarget &frame);
            /*!
             * \brief Updates the controls menu.
             */
            void controlsLoop(sf::RenderTarget &frame);
            /*!
             * \brief Updates the credit screen.
             */
            void creditsLoop(sf::RenderTarget &frame);

            /*!
             * \brief Initialises the strings used in the setting
             */
            void initStrings();
            void onLangChanged() override;

            OptionType getCurrentOption() { return currentOptions; }
            void setCurrentOption(OptionType newOpt) { currentOptions = newOpt; }
            /*!
             * \brief Returns the cursor position of the current menu.
             */
            int cursorPosition() const {
                switch(currentOptions) {
                case OptionType::ALL:
                    return curPosOptI;
                case OptionType::LANG:
                    return curPosLangI;
                case OptionType::CONTROLS:
                    return curPosCtrlI;
                default:
                    return curPosOptI;
                }

                return 0;
            }

            void setCurrentKeyChange(int currentKeyChange_) { currentKeyChange = currentKeyChange_; }

            void play();
            void pause();

          private:
            Model::OptionsMenuData &data;
            OptionType currentOptions;

            sf::Sprite volumeCur;
            sf::Sprite bgCredits;
            sf::Sprite bgOpt;
            sf::Sprite bgControls;

            //TODO : Make the addition of a language easier.
            sf::Text langFr;
            sf::Text langEng;
            sf::Text langEsp;
            sf::Text langDe;
            sf::Text langIt;

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
            sf::Text txtCre10;
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
            /*!
             * \brief The currently selected key to change in the controls menu.
             */
            int currentKeyChange{0};
            sf::Text txtCtrlChange;
            sf::Text txtCtrlUp;
            sf::Text txtCtrlDown;
            sf::Text txtCtrlLeft;
            sf::Text txtCtrlRight;
            sf::Text txtCtrlTalk;
            sf::Text txtCtrlInteract;
            sf::Sprite rectKeyChange;
            const sf::Vector2f posControls[7] = {
              {-500.0, -500.0}, {150.0, 175.0}, {148.0, 450.0}, {9.0, 311.0}, {298.0, 310.0}, {412.0, 211.0}, {412.0, 334.0}};

            sf::Text txtLang;
            sf::Text txtCred;
            sf::Text txtCtrl;
            /*!
             * \brief The background for the language screen.
             * \todo Change to bgLang
             */
            sf::Sprite bgLangues;
            sf::Vector2f curPosLang[6] = {};
            sf::Vector2f curSizeLang[6];
            sf::Vector2f curPosCtrl[5] = {};
            sf::Vector2f curSizeCtrl[5];
            /*!
             * \brief The sprite of the check for the fullscreen option.
             */
            sf::Sprite check;
        };
    } // namespace View
} // namespace OpMon

#endif // OPTIONSMENU_HPP
