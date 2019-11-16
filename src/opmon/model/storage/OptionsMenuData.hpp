/*!
 * \file OptionsMenuData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
*/
#pragma once

#include "UiData.hpp"

namespace OpMon {
    namespace Model {

        /*!
         * \brief Contains the data used in the options menu.
         */
        class OptionsMenuData {
          private:
            UiData *uidata;
            sf::Texture background;
            sf::Texture selectBar;
            sf::Texture langBg;
            sf::Texture yesTx;
            sf::Texture creditsBg;
            sf::Texture controlsBg;
            sf::Texture volumeCur;
            sf::Texture keyChange;

            /*!
             * \brief The copy constructor. Not defined, must not be used.
             */
            OptionsMenuData(OptionsMenuData const &);

          public:
            /*!
             * \brief Gets the background.
             */
            sf::Texture const &getBackground() const { return background; }
            /*!
             * \brief Gets the cursor.
             */
            sf::Texture const &getSelectBar() const { return selectBar; }
            /*!
             * \brief Gets the background for the language options.
             */
            sf::Texture const &getLangBg() const { return langBg; }
            /*!
             * \brief Gets the texture of the tick.
             */
            sf::Texture const &getYesTx() const { return yesTx; }
            /*!
             * \brief Gets the background for the credits.
             */
            sf::Texture const &getCreditsBg() const { return creditsBg; }
            /*!
             * \brief Gets the background for the controls.
             */
            sf::Texture const &getControlsBg() const { return controlsBg; }
            /*!
             * \brief Gets the texture of the volume cursor.
             */
            sf::Texture const &getVolumeCur() const { return volumeCur; }
            /*!
             * \brief Gets the texture of the cursor used in the controls.
             */
            sf::Texture const &getKeyChange() const { return keyChange; }
            /*!
             * \brief Gets a pointer to the UiData object.
             */
            UiData *getUiDataPtr() { return uidata; }
            /*!
             * \brief Initialises all the data.
             * \param ptr A pointer to the UiData object.
             */
            OptionsMenuData(UiData *data);
        };
    } // namespace Model
} // namespace OpMon
