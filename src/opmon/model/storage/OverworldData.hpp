/*!
 * \file OverworldData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
*/
#pragma once

#include "../sysObjects/Map.hpp"
#include "../sysObjects/Player.hpp"
#include "GameMenuData.hpp"
#include "UiData.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>
#include <vector>

namespace OpMon {
    namespace Model {
        /*!
         * \brief Contains the data used for the Overworld.
         */
        class OverworldData {
          private:
            sf::Texture alpha = sf::Texture();
            std::vector<sf::Texture> alphaTab = std::vector<sf::Texture>(1);

            std::map<std::string, OpTeam *> trainers;

            std::map<std::string, Map *> maps;
            std::map<std::string, Map *>::iterator mapsItor;

            sf::Texture texturePP;
            sf::IntRect texturePPRect[4];
            sf::IntRect walkingPPRect[4];
            sf::IntRect walkingPP2Rect[4];

            UiData *uidata;

            Player *player;

            std::map<std::string, sf::Vector2f> elementsPos;
            std::map<std::string, unsigned int> elementsCounter;
            std::map<std::string, std::vector<sf::Texture>> elementsTextures;

            std::map<std::string, std::vector<sf::Texture>> charaTextures;

            std::map<std::string, std::vector<sf::Texture>> eventsTextures;

            std::map<std::string, std::vector<sf::Texture>> doorsTextures;

            std::map<std::string, std::unique_ptr<Item>> itemsList;

            std::map<std::string, sf::String *> completions;

            GameMenuData gameMenuData;

            /*!
             * \brief The copy constructor. Not defined, must not be used.
             */
            OverworldData(OverworldData const &);

          public:
            /*!
             * \brief Increments the animation counter for an element.
             */
            void incrementElementCounter(std::string const &elementId) { elementsCounter[elementId]++; }
            /*!
             * \brief Resets the animation counter for an element.
             */
            void resetElementCounter(std::string const &id) { elementsCounter[id] = 0; }
            /*!
             * \brief Gets the animation counter for an element.
             */
            unsigned int getElementCounter(std::string const &id) { return elementsCounter[id]; }
            /*!
             * \brief Gets the textures of an element.
             */
            std::vector<sf::Texture> &getElementTextures(std::string const &id) { return elementsTextures[id]; }
            /*!
             * \brief Gets the position of an element.
             */
            sf::Vector2f &getElementPos(std::string const &id) { return elementsPos[id]; }
            /*!
             * \brief Gets the current shown texture of an element.
             */
            sf::Texture &getCurrentElementTexture(std::string const &id) { return elementsTextures[id][elementsCounter[id]]; }

            /*!
             * \brief Gets the textures of a character.
             */
            std::vector<sf::Texture> &getCharaTexture(std::string const &key) { return charaTextures[key]; }
            /*!
             * \brief Gets the textures of a door.
             */
            std::vector<sf::Texture> &getDoorsTexture(std::string const &key) { return doorsTextures[key]; }
            /*!
             * \brief Gets the textures of an event.
             */
            std::vector<sf::Texture> &getEventsTexture(std::string const &key) { return eventsTextures[key]; }

            /*!
             * \brief Gets a completion.
             * \details A completion is a pointer to a string which can change during the game (For exemple the player's name, changing when you're playing a new game)
             */
            sf::String *getCompletion(std::string const &key) { return completions.at(key); }

            /*!
             * \brief Gets the team of a trainer.
             */
            OpTeam *getTrainer(std::string const &key) { return trainers.at(key); }

            /*!
             * \brief Gets a reference to the GameMenuData object.
             */
            GameMenuData &getGameMenuData() { return gameMenuData; }

            /*!
             * \brief Gets a map.
             */
            Map *getMap(std::string const &map);
            /*!
             * \brief Gets the current map.
             */
            Map *getCurrentMap();

            /*!
             * \brief Gets the id of the map currently pointer by the map iterator.
             * \details The map iterator is used to go through all the maps in debug mode.
             */
            std::string getCurrentItorMap() { return mapsItor->first; }
            /*!
             * \brief Increments the map iterator.
             * \details See OverworldData::getCurrentItorMap for more information on the map iterator.
             */
            void incrementItorMap() {
                mapsItor++;
                if(mapsItor == maps.end())
                    mapsItor = maps.begin();
            }
            /*!
             * \brief Decrements the map iterator.
             * \details See OverworldData::getCurrentItorMap for more information on the map iterator.
             */
            void decrementItorMap() {
                if(mapsItor != maps.begin())
                    mapsItor--;
                else {
                    mapsItor = maps.end();
                    --mapsItor;
                }
            }

            /*!
             * \brief Gets the texture of the principal character.
             */
            sf::Texture &getTexturePP() { return texturePP; }
            /*!
             * \brief Gets the rect of a character's standing texture.
             * \param id The side to get.
             * \todo Change the type of id for Side
             */
            sf::IntRect &getTexturePPRect(unsigned int id) { return texturePPRect[((id < 4) ? id : 0)]; }
            /*!
             * \brief Gets the rect of a character's moving texture (first frame)
             * \param id The side to get.
             * \todo Change the type of id for side
             */
            sf::IntRect &getWalkingPPRect(unsigned int id) { return walkingPPRect[((id < 4) ? id : 0)]; }
            /*!
             * \brief Gets the rect of a character's moving texture (second frame)
             * \param id The side to get.
             * \todo Change the type of id for side
             */
            sf::IntRect &getWalkingPP2Rect(unsigned int id) { return walkingPP2Rect[((id < 4) ? id : 0)]; }

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

            /*!
             * \brief Gets an item.
             */
            std::unique_ptr<Item> &getItem(std::string const &str) { return itemsList[str]; }

            /*!
             * \brief Initialises all the data.
             * \param data A pointer to the UiData object.
             * \param player A pointer to the Player object.
             */
            OverworldData(UiData *uidata, Player *player);
            ~OverworldData();
        };

    } // namespace Model
} // namespace OpMon
