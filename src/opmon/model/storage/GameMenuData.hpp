/*!
 * \file GameMenuData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
*/
#pragma once

#include "../sysObjects/Player.hpp"
#include "UiData.hpp"
#include <SFML/Graphics/Texture.hpp>

namespace OpMon {
    namespace Model {
        /*!
         * \brief Contains the data of the in-game menu used by View::GameMenu and Controller::GameMenuCtrl
         */
        class GameMenuData {
          private:
            sf::Texture menuTexture;
            sf::Texture background;

            sf::Texture selectionTexture[6];
            sf::Vector2f selectionPos[6];

            UiData *uidata;
            Player *player;

            /*!
             * \brief The copy constructor. Not defined, must not be used.
             */
            GameMenuData(GameMenuData const &);

          public:
            /*!
             * \brief Initialises all the data.
             * \param data A pointer to the UiData object.
             * \param player A pointer to the Player object.
             */
            GameMenuData(UiData *data, Player *player);

            /*!
             * \brief Gets the background texture of the in-game menu.
             */
            sf::Texture &getMenuTexture() { return menuTexture; }
            /*!
             * \brief Gets the last saved background by GameMenuData::setBackground for the open/close animations.
             */
            sf::Texture &getBackground() { return background; }
            /*!
             * \brief Saves given texture, can be retreived with GameMenuData::getBackground.
             * \details This method is made to be used for the open/close animations of the menu. The texture to be saved here should be the current screen before the menu opens.
             * \param bg The texture to save.
             */
            void setBackground(sf::Texture const &bg) { background = bg; }

            /*!
             * \brief Gets the texture of a currently selected button.
             * \details Each button of the menu has a selected counterpart which is shown when the cursor is currently on the button.
             * \param index The button whose texture has to be returned.
             */
            sf::Texture &getSelectionTexture(int index) { return selectionTexture[index]; }
            /*!
             * \brief Returns the position of each button.
             * \details This position is used to position the textures of the selected buttons.
             * \param index The button whose position has to be returned.
             */
            sf::Vector2f &getSelectionPos(int index) { return selectionPos[index]; }

            /*!
             * \brief Gets a pointer to the UiData object.
             */
            UiData *getUiDataPtr() { return uidata; }
            /*!
             * \brief Gets a pointer to the Player object.
             */
            Player *getPlayerPtr() { return player; }
            /*!
             * \brief Gets a reference to the Player object.
             */
            Player &getPlayer() { return *player; }
        };

    } // namespace Model
} // namespace OpMon
