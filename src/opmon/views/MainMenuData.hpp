/*!
 * \file MainMenuData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Texture.hpp>

#include "../core/UiData.hpp"

namespace OpMon {
class UiData;

    /*!
     * \brief Contains the data for the main menu of the game.
     * \details Used by View::MainMenu and Controller:MainMenuCtrl
     */
    class MainMenuData {
    private:
        sf::Texture menuframe;
        sf::Texture arrChoice;

        UiData *uidata;

        /*!
         * \brief The copy constructor. Not defined, must not be used.
         */
        MainMenuData(MainMenuData const &);

    public:
        /*!
         * \brief Returns a pointer to the UiData object.
         */
        UiData *getUiDataPtr() const { return uidata; }

        sf::Texture const &getMenuframe() const { return menuframe; }
        /*!
         * \brief Gets the cursor.
         */
        sf::Texture const &getArrChoice() const { return arrChoice; }
        /*!
         * \brief Initialises all the data.
         * \param ptr A pointer to the UiData object.
         */
        MainMenuData(UiData *ptr);
    };
} // namespace OpMon
