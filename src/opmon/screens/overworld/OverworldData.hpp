/*!
 * \file OverworldData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Rect.hpp>

#include "src/utils/defines.hpp"
#include "src/opmon/view/elements/Map.hpp"
#include "src/opmon/screens/gamemenu/GameMenuData.hpp"

namespace sf {
class String;
}  // namespace sf

namespace OpMon {
class OpTeam;
class Player;
class GameData;
namespace Elements {
class Map;
}  // namespace Elements

    /*!
     * \brief Contains the data used for the Overworld.
     */
    class OverworldData {
    private:
        sf::Texture alpha = sf::Texture();
        std::vector<sf::Texture> alphaTab = std::vector<sf::Texture>(1);

        std::map<std::string, OpTeam *> trainers;

        /*!
         * \brief Contains the maps.
         *
         * The first element of the pair contains the json used to build the map.
         * The second element contains the built map, or nullptr if the map has not
         * been initialized yet.
         */
        std::map<std::string, std::pair<nlohmann::json, Elements::Map *> > maps;
        std::map<std::string, std::pair<nlohmann::json, Elements::Map *> >::iterator mapsItor;

        sf::Texture texturePP;
        sf::IntRect texturePPRect[4];
        sf::IntRect walkingPPRect[4];
        sf::IntRect walkingPP2Rect[4];

        GameData *gamedata;

        Player *player;

        std::map<std::string, sf::Vector2f> elementsPos;
        std::map<std::string, unsigned int> elementsCounter;
        std::map<std::string, std::vector<sf::Texture>> elementsTextures;

        std::map<std::string, std::vector<sf::Texture>> eventsTextures;

        std::map<std::string, std::unique_ptr<Item>> itemsList;

        std::map<std::string, sf::String *> completions;

        /*!
         * \brief Contains the tilesets.
         *
         * The first element of the pair represents the texture of the tileset, the second represents the array of collisions.
         */
        std::map<std::string, std::pair<sf::Texture, int*>> tilesets;

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
         * \deprecated Use getEventsTexture, charaTextures have been merged with eventsTextures.
         */
        OP_DEPRECATED std::vector<sf::Texture> &getCharaTexture(std::string const &key) { return eventsTextures[key]; }
        /*!
         * \brief Gets the textures of a door.
         * \deprecated Use getEventsTexture, doorsTextures have been merged with eventsTextures.
         */
        OP_DEPRECATED std::vector<sf::Texture> &getDoorsTexture(std::string const &key) { return eventsTextures[key]; }
        /*!
         * \brief Gets the textures of an event.
         */
        std::vector<sf::Texture> &getEventsTexture(std::string const &key);

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
        Elements::Map *getMap(std::string const &map);
        /*!
         * \brief Gets the current map.
         */
        Elements::Map *getCurrentMap();

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
         * \brief Gets a pointer to the GameData object.
         */
        GameData *getGameDataPtr() { return gamedata; }
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
         * \brief Returns a tileset.
         */
        sf::Texture& getTileset(std::string id) {return tilesets[id].first;}

        /*!
         * \brief Returns the collision array for a tileset.
         */
        int* getTilesetCol(std::string id) {return tilesets[id].second;}

        /*!
         * \brief Initialises all the data.
         * \param data A pointer to the GameData object.
         * \param player A pointer to the Player object.
         */
        OverworldData(GameData *gamedata, Player *player);
        ~OverworldData();
    };

} // namespace OpMon
