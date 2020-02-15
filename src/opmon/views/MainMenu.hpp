/*!
 * \file MainMenu.hpp
 * \authors Cyrielle
 * \authors Navet56
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 */
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

#include "MainMenuData.hpp"
#include "../core/i18n/ATranslatable.hpp"
#include "ui/TextBox.hpp"

namespace sf {
class RenderTarget;
}  // namespace sf

namespace OpMon {
class MainMenuData;

    /*!
     * \brief The view printing the main menu showing at the start of the game.
     */
    class MainMenu : public I18n::ATranslatable, public sf::Drawable {

    public:
        MainMenu(MainMenuData &data);
        ~MainMenu() override = default;

        /*!
         * \brief Loads the strings used in the menu.
         */
        void initMainMenuItemsName();

        void onLangChanged() override;

        /*!
         * \brief Pauses the screen.
         */
        void pause();
        /*!
         * \brief Unpauses the screen.
         */
        void play();

        /*!
         * \brief Updates the screen.
         */
        void update(int curPosI);

        /*!
         * \brief Draws the screen.
         */
        void draw(sf::RenderTarget &frame, sf::RenderStates states) const;

    private:
        MainMenuData &data;
        /*!
         * \brief The background of the menu.
         */
        sf::Sprite background;

        /*!
         * \brief Stucture representing an option in the menu.
         */
        struct OptionMenu {
            sf::Text text;
            sf::Vector2f pos;
        };
        /*!
         * \brief Contains the different options of the main menu.
         */
        std::vector<TextBox> mainMenuItems;
        sf::Sprite cursor;
    };
} // namespace OpMon

#endif // MAINMENU_HPP
