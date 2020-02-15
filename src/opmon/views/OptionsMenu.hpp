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

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <vector>

#include "OptionsMenuData.hpp"
#include "../core/i18n/ATranslatable.hpp"
#include "ui/Elements.hpp"
#include "ui/TextBox.hpp"
#include "../../utils/CycleCounter.hpp"
#include "src/opmon/core/GameStatus.hpp"

namespace sf {
class RenderTarget;
}  // namespace sf

namespace OpMon {
class OptionsMenuData;

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
    class OptionsMenu : I18n::ATranslatable, public sf::Drawable{
    public:
        OptionsMenu(OptionsMenuData &data);
        ~OptionsMenu() = default;

        /*!
         * \brief Moves the cursor.
         * \param dir If `true`, the cursor goes up. It goes down otherwise
         */
        void moveArrow(bool dir);

        /*!
         * \brief Draws the menu on the given frame.
         */
        void draw(sf::RenderTarget &frame, sf::RenderStates states) const;

        /*!
         * \brief Updates the current screen shown on the screen.
         */
        GameStatus update();

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
                return curPosOptI.getValue();
            case OptionType::LANG:
                return curPosLangI.getValue();
            case OptionType::CONTROLS:
                return curPosCtrlI.getValue();
            default:
                return curPosOptI.getValue();
            }

            return 0;
        }

        void setCurrentKeyChange(int currentKeyChange_) { currentKeyChange = currentKeyChange_; }

        void play();
        void pause();

        void initOptionsMenuItemsName();
        void initOptionsMenuItemsValue();
        void initLanguagesMenuItemsName();

    private:

        /*!
         * \brief Updates the main settings menu.
         */
        GameStatus loop();
        /*!
         * \brief Updates the language menu.
         */
        GameStatus langLoop();
        /*!
         * \brief Updates the controls menu.
         */
        GameStatus controlsLoop();
        /*!
         * \brief Updates the credit screen.
         */
        GameStatus creditsLoop();


        OptionsMenuData &data;
        OptionType currentOptions;

        sf::Sprite volumeCur;
        sf::Sprite bgCredits;
        sf::Sprite bgOpt;
        sf::Sprite bgControls;

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
        sf::Sprite rectSurb;
        sf::Vector2f curPosOpt[6] = {};
        sf::Vector2f curSizeOpt[6];
        int optionSelect = -1;
        Utils::CycleCounter curPosOptI = Utils::CycleCounter(6);
        Utils::CycleCounter curPosLangI = Utils::CycleCounter(6);
        Utils::CycleCounter curPosCtrlI = Utils::CycleCounter(2);
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

        std::vector<TextBox> optionsMenuItems;
        std::vector<TextBox> languagesMenuItems;
    };
} // namespace OpMon

#endif // OPTIONSMENU_HPP
