/*!
 * \file GameMenu.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "GameMenuData.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace OpMon {

    /*!
     * \brief View printing the in-game menu.
     */
    class GameMenu {
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

        /*!
         * \brief Updates one frame.
         */
        GameStatus operator()(sf::RenderTexture &frame);

        /*!
         * \brief Changed the position of the cursor.
         */
        void setCurPos(int newCurPos);
    };

} // namespace OpMon
