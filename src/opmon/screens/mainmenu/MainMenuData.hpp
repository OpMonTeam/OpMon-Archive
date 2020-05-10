/*!
 * \file MainMenuData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Texture.hpp>

#include "src/opmon/core/GameData.hpp"

namespace OpMon {
class GameData;

    /*!
     * \brief Contains the data for the main menu of the game.
     * \details Used by View::MainMenu and Controller:MainMenuCtrl
     */
    class MainMenuData {
    private:
        sf::Texture arrChoice;

        GameData *gamedata;

        /*!
         * \brief The copy constructor. Not defined, must not be used.
         */
        MainMenuData(MainMenuData const &);

    public:
        /*!
         * \brief Returns a pointer to the GameData object.
         */
        GameData *getGameDataPtr() const { return gamedata; }

        /*!
         * \brief Gets the cursor.
         */
        sf::Texture const &getArrChoice() const { return arrChoice; }
        /*!
         * \brief Initialises all the data.
         * \param ptr A pointer to the GameData object.
         */
        MainMenuData(GameData *ptr);
    };
} // namespace OpMon
