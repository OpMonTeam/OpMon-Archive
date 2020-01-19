/*!
 * \file BattleData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
*/
#pragma once

#include "../sysObjects/Player.hpp"
#include "UiData.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <list>
#include <map>
#include <string>
#include <vector>

namespace OpMon {
    namespace Model {

        /*!
         * \brief Contains the data used by View::Battle and Controller::BattleCtrl
         */
        class BattleData {
          private:
            std::map<std::string, sf::Texture> backgrounds;
            sf::Texture dialog;
            sf::Texture attackDialog;
            sf::Texture cursor;
            //std::vector<sf::Texture> choices;
            std::map<std::string, std::vector<sf::Texture>> charaBattleTextures;
            std::list<sf::Texture> battlePlayerAnim;
            sf::Texture infoboxPlayer;
            sf::Texture infoboxTrainer;
            sf::Texture shadowPlayer;
            sf::Texture shadowTrainer;
            sf::Texture healthbar1;
            sf::Texture healthbar2;

            UiData *uidata;
            Player *player;

            /*!
             * \brief The copy constructor. Not defined, must not be used.
             */
            BattleData(BattleData const &);

          public:
            /*!
             * \brief A pointer to the Player object.
             */
            Player *getPlayerPtr() { return player; }
            /*!
             * \brief A reference to the Player object.
             */
            Player &getPlayer() { return *player; }

            /*!
             * \brief A pointer to the UiData object.
             */
            UiData *getUiDataPtr() { return uidata; }

            /*!
             * \brief Initialises all the data.
             * \param data A pointer to the UiData object.
             * \param player A pointer to the Player object.
             */
            BattleData(UiData *data, Player *player);

            /*!
             * \brief Gets one battle background.
             * \param id The identifier of the wanted background.
             * \returns The background associated to the identifier, an empty sf::Texture if not found.
             */
            sf::Texture &getBackground(std::string id) { return backgrounds[id]; }
            /*!
             * \brief Gets the texture of the action choice dialog.
             */
            sf::Texture &getDialog() { return dialog; }
            /*!
             * \brief Gets the texture of the attack choice dialog.
             */
            sf::Texture &getAttackDialog() { return attackDialog; }
            /*!
             * \brief Gets the texture of the cursor.
             */
            sf::Texture &getCursor() { return cursor; }
            /*!
             * \brief Gets the character's battle textures.
             * \param id The identifier of the character's textures.
             */
            std::vector<sf::Texture> &getCharaBattleTextures(std::string id) { return charaBattleTextures[id]; }
            /*!
             * \brief Gets the iterator to the first element of the list of textures for the player's sprite animation at the start of a battle.
             */
            std::list<sf::Texture>::iterator getBattlePlayerAnimBegin() { return battlePlayerAnim.begin(); }
            /*!
             * \brief Gets the texture of the infobox for the player's OpMon.
             */
            sf::Texture &getInfoboxPlayer() { return infoboxPlayer; }
            /*!
             * \brief Gets the texture of the infobox for the opponent's OpMon.
             */
            sf::Texture &getInfoboxTrainer() { return infoboxTrainer; }
            /*!
             * \brief Gets the player's sprite shadow.
             */
            sf::Texture &getShadowPlayer() { return shadowPlayer; }
            /*!
             * \brief Gets the opponent's sprite shadow.
             */
            sf::Texture &getShadowTrainer() { return shadowTrainer; }
            /*!
             * \brief Gets the gray healthbar.
             */
            sf::Texture &getHealthbar1() { return healthbar1; }
            /*!
             * \brief Gets the colored healthbar.
             */
            sf::Texture &getHealthbar2() { return healthbar2; }
        };

    } // namespace Model
} // namespace OpMon
