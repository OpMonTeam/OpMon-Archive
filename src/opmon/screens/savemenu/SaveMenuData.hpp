#pragma once

#include "src/opmon/core/GameData.hpp"

namespace OpMon {

    class GameData;

    /*!
     * \brief Contains the data used in the save menu.
     */
    class SaveMenuData {
      private:
        GameData *gamedata;

      public:
        /*!
         * \brief Gets a pointer to the GameData object.
         */
        GameData *getGameDataPtr() { return gamedata; }

        /*!
         * \brief Initialises all the data.
         * \param ptr A pointer to the UiData object.
         */
        SaveMenuData(GameData *data);
    };

} // namespace OpMon
