/*
Map.hpp
Author : Cyriel
Contributors : BAKFR
File under GNU GPL v3.0 license
*/

#ifndef MAP_HPP
#define MAP_HPP

#include "Events.hpp"
#include "../../../nlohmann/json.hpp"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

namespace OpMon {
    namespace Model {

        class Event;

        /**
	   Class defining a specific place in a game, containing the event, the animated objects and the map layers
	*/
        class Map {
          private:
            int *layer1;
            int *layer2;
            int *layer3;

            bool indoor;

            std::string bg;

            int w;
            int h;

            /**The copy constructor must not be used.*/
            Map(Map const &toCopy) = delete;

            std::vector<Event *> events;

            std::vector<std::string> animatedElements;
			
			nlohmann::json jsonData;
			bool loaded = false;

          public:
            Map(std::vector<int> const &layer1, std::vector<int> const &layer2, std::vector<int> const &layer3, int w, int h, bool indoor, std::string const &bg, std::vector<std::string> const &animatedElements = std::vector<std::string>());
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
            void addEvent(Event *event) {
                events.push_back(event);
            }
            std::vector<Event *> getEvent(sf::Vector2i position) const;
            std::vector<Event *> &getEvents() {
                return events;
            }
            void updateElements(sf::RenderTexture &frame);

            int getCurrentTileCode(sf::Vector2i const &pos, int layer) const;

            int getTileCollision(int tile) const;

            int getCollision(sf::Vector2i const &pos) const;
			
			bool loadMap(OverworldData &data);
        };
    } // namespace Model
} // namespace OpMon

#endif // MAP_HPP
