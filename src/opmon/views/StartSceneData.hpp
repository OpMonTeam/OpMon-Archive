/**!
 * \file StartSceneData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0 license
 */
#pragma once

#include <SFML/Graphics/Texture.hpp>

#include "../core/Player.hpp"
#include "../core/UiData.hpp"

namespace OpMon {
class Player;
class UiData;

    /*!
     * \brief Contains the data used by View::StartScene and Controller::StartSceneCtrl
     */
    class StartSceneData {
    private:
        sf::Texture background;
        sf::Texture prof;
        sf::Texture nameBg;

        UiData *uidata;

        Player *player;

        /*!
         * \brief The copy constructor. Not defined, must not be used.
         */
        StartSceneData(StartSceneData const &);

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
         * \brief Returns a pointer to the UiData object.
         */
        UiData *getUiDataPtr() { return uidata; }
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
         * \param ptr A pointer to the UiData object.
         */
        StartSceneData(UiData *data);
    };

} // namespace OpMon
