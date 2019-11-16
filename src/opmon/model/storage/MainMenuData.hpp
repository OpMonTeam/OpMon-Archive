/*!
 * \file MainMenuData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
*/
#pragma once

#include "UiData.hpp"

namespace OpMon {
    namespace Model {
        /*!
         * \brief Contains the data for the main menu of the game.
         * \details Used by View::MainMenu and Controller:MainMenuCtrl
         */
        class MainMenuData {
          private:
            sf::Texture titlescreen;
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
            /*!
             * \brief Gets the background.
             */
            sf::Texture const &getTitlescreen() const { return titlescreen; }
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
    } // namespace Model
} // namespace OpMon
