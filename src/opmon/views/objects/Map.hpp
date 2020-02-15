/*!
  \file Map.hpp
  \authors Cyrielle
  \authors BAKFR
  \copyright GNU GPL v3.0
*/

#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>
#include <algorithm>

#include "../../../nlohmann/json.hpp"
#include "Events.hpp"

namespace sf {
class RenderTexture;
}  // namespace sf

namespace OpMon {

    class OverworldData;

    namespace Elements {

        class Event;

        /*!
         * \brief Defines a specific place in a game, containing the event, the animated objects and the map layers.
         * \details To lower the loading time, a map object can be created without initialisation. The data of the map is stored in Map::jsonData, and the map can then be loaded by calling Map::loadMap. Using an unloaded map will crash the game.
         * \todo Separate the class into MapBuilder (The unloaded map) and Map.
         */
        class Map {
          private:
            int *layer1;
            int *layer2;
            int *layer3;

            /*!
             * \brief If `true`, the map is an indoor map.
             */
            bool indoor;

            /*!
             * \brief The ID of the background music.
             */
            std::string bg;

            /*!
             * \brief Width of the map.
             */
            int w;
            /*!
             * \brief Height of the map.
             */
            int h;

            Map(Map const &toCopy) = delete;

            std::vector<Event *> events;
            /*!
             * \brief Contains the animated elements of the map.
             * \details An animated element is an animation put on the top of the map. For exemple, the wind turbine of Fauxbourg Euvi.
             */
            std::vector<std::string> animatedElements;

            /*!
             * \brief The map in json for the initialisation.
             */
            nlohmann::json jsonData;
            /*!
             * \brief If the map has been loaded or not.
             */
            bool loaded = false;


            /*!
             * \brief The collisions for each tile.
             *
             * \todo Add description of each number/collision type.
             * \todo Move this in a json file and add multiple tileset support.
             */
            static int colTile[4096];


          public:
            /*!
             * \brief Creates a map and loads it at the same time, with all the information needed.
             */
            Map(std::vector<int> const &layer1, std::vector<int> const &layer2, std::vector<int> const &layer3, int w, int h, bool indoor, std::string const &bg, std::vector<std::string> const &animatedElements = std::vector<std::string>());
            /*!
             * \brief Creates a map without loading it.
             * \details If you want to use the map, please call Map::loadMap before calling any other method.
             */
            Map(nlohmann::json jsonData);
            ~Map();
            int getH() const {
                return h;
            }
            int getW() const {
                return w;
            }
            bool isIndoor() const {
                return indoor;
            }
            bool isLoaded() const {
                return loaded;
            }
            sf::Vector2i getDimensions() const {
                return sf::Vector2i(w, h);
            }
            const int *getLayer1() const {
                return layer1;
            }
            const int *getLayer2() const {
                return layer2;
            }
            const int *getLayer3() const {
                return layer3;
            }
            std::string getBg() const {
                return bg;
            }
            const std::vector<std::string> &getAnimatedElements() const {
                return animatedElements;
            }
            /*!
             * \brief Adds an event to the events of the map.
             * \param event A pointer to an event.
             * \warning The given event will be deleted at the destruction of the map.
             */
            void addEvent(Event *event) {
                events.push_back(event);
            }
            /*!
             * \brief Returns all the events in the given position.
             * \param position The position in which to search for event.
             */
            std::vector<Event *> getEvent(sf::Vector2i position) const;
            /*!
             * \brief Returns all the events of the map.
             */
            std::vector<Event *> &getEvents() {
                return events;
            }
            /*!
             * \brief Updates the animated elements by incrementing the animation.
             * \param frame A reference to the frame of the game.
             */
            void updateElements(sf::RenderTexture &frame);

            /*!
             * \brief Returns the tile code at the given position and layer.
             * \param pos The position of the tile.
             * \param layer The layer of the tile.
             */
            int getCurrentTileCode(sf::Vector2i const &pos, int layer) const;

            /*!
             * \brief Returns the collision associated with a tile.
             * \param tile The tile code.
             */
            int getTileCollision(int tile) const;

            /*!
             * \brief Returns the collision box of the given position.
             * \details The method searches in the two first layers at this position. If one blocks the player, it's prioritary.
             * \param pos The position of the collision to return.
             */
            int getCollision(sf::Vector2i const &pos) const;

            /*!
             * \brief Loads the map and returns it.
             * \warning This method doesn't load the map in this object! It returns a new Map object loaded with the data contained in the current Map object.
             * \returns A pointer to the loaded Map.
             */
            Map *loadMap(OverworldData &data);

            /*!
             * \brief Returns a string containing information on the Map.
             */
            std::string toDebugString();
        };
    } // namespace Elements
} // namespace OpMon

#endif // MAP_HPP
