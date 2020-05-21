/**!
 * \file IntroSceneData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0 license
 */
#pragma once

#include "Player.hpp"
#include "GameData.hpp"

namespace OpMon {
class Player;
class GameData;

    /*!
     * \brief Contains the data used by View::IntroScene and Controller::IntroSceneCtrl
     */
    class IntroSceneData {
    private:
        sf::Texture background;
        sf::Texture prof;
        sf::Texture nameBg;

        GameData *gamedata;

        Player *player;

        /*!
         * \brief The copy constructor. Not defined, must not be used.
         */
        IntroSceneData(IntroSceneData const &);

    public:
        /*!
         * \brief Returns a reference to the Player object.
         */
        Player &getPlayer() { return *player; }
        /*!
         * \brief Returns a pointer to the Player object.
         */
        Player *getPlayerPtr() { return player; }
        /*!
         * \brief Returns a pointer to the GameData object.
         */
        GameData *getGameDataPtr() { return gamedata; }
        /*!
         * \brief Gets the background of the scene.
         */
        sf::Texture &getBackground() { return background; }
        /*!
         * \brief Gets the professor's sprite.
         */
        sf::Texture &getProf() { return prof; }
        /*!
         * \brief Gets the background of the name entry screen.
         */
        sf::Texture &getNameBg() { return nameBg; }
        /*!
         * \brief Initialises all the data.
         * \param ptr A pointer to the GameData object.
         */
        IntroSceneData(GameData *data);
    };

} // namespace OpMon
