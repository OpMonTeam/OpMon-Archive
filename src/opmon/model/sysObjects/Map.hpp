/*
Map.hpp
Author : Cyrielle
Contributors : BAKFR
File under GNU GPL v3.0 license
*/

#ifndef MAP_HPP
#define MAP_HPP

#include "../../../nlohmann/json.hpp"
#include "Events.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

namespace OpMon::Model {

        class Event;

        class OverworldData;

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
            Map(std::vector<int> const &layer1, std::vector<int> const &layer2, std::vector<int> const &layer3, int w, int h, bool indoor, std::string bg, std::vector<std::string> animatedElements = std::vector<std::string>());
            explicit Map(nlohmann::json jsonData);
            ~Map();
            [[nodiscard]] int getH() const {
                return h;
            }
            [[nodiscard]] int getW() const {
                return w;
            }
            [[nodiscard]] bool isIndoor() const {
                return indoor;
            }
            [[nodiscard]] bool isLoaded() const {
                return loaded;
            }
            [[nodiscard]] sf::Vector2i getDimensions() const {
                return sf::Vector2i(w, h);
            }
            [[nodiscard]] const int *getLayer1() const {
                return layer1;
            }
            [[nodiscard]] const int *getLayer2() const {
                return layer2;
            }
            [[nodiscard]] const int *getLayer3() const {
                return layer3;
            }
            [[nodiscard]] std::string getBg() const {
                return bg;
            }
            [[nodiscard]] const std::vector<std::string> &getAnimatedElements() const {
                return animatedElements;
            }
            void addEvent(Event *event) {
                events.push_back(event);
            }
            [[nodiscard]] std::vector<Event *> getEvent(sf::Vector2i position) const;
            std::vector<Event *> &getEvents() {
                return events;
            }
            void updateElements(sf::RenderTexture &frame); // TODO

            [[nodiscard]] int getCurrentTileCode(sf::Vector2i const &pos, int layer) const;

            [[nodiscard]] int getTileCollision(int tile) const;

            [[nodiscard]] int getCollision(sf::Vector2i const &pos) const;

            Map *loadMap(OverworldData &data);

            std::string toDebugString();
        };
    } // namespace OpMon

#endif // MAP_HPP
