/*!
 * \file GameMenu.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Text.hpp>

#include "GameMenuData.hpp"

namespace sf {
class RenderTarget;
}  // namespace sf

namespace OpMon {

/*!
 * \brief Represent one of the submenu that can be accessed from the game menu.
 */
enum SubMenu { SETTINGS_MENU,
               SAVE_MENU };

class GameMenuData;

    /*!
     * \brief View printing the in-game menu.
     */
    class GameMenu : public sf::Drawable {
    private:
        /*!
         * \brief The background displayed behind the menu (Usually a screenshot taken before opening the menu).
         */
        sf::Sprite background;
        /*!
         * \brief The background of the menu.
         */
        sf::Sprite menuBg;
        /*!
         * \brief The sprites for the highlighted textures of the choices.
         */
        sf::Sprite selections[6];
        /*!
         * \brief The names of the different options.
         */
        sf::Text selectxt[6];

        /*!
         * \brief The data used by the view.
         */
        GameMenuData &data;

        /*!
         * \brief The position of the cursor.
         */
        int curPos = 0;

    public:
        GameMenu(GameMenuData &data);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        /*!
         * \brief Changed the position of the cursor.
         */
        void setCurPos(int newCurPos);
    };

} // namespace OpMon
