/*
  Map.hpp
  Author : Jlppc
  File under the license GPL-3.0
  http://opmon-game.ga
  Contains the Map class
*/

#ifndef MAP_HPP
#define MAP_HPP

#include "Events.hpp"

namespace OpMon {
    namespace Model {

        class Event;

        /**
       Class defining a specific place
    */
        class Map {
          private:
            const int *layer1;
            const int *layer2;
            const int *layer3;

            std::string bg;
            //Event events;
            int w;
            int h;

            /**The copy constructor must not be used.*/
            Map(Map const &toCopy) = delete;

            std::vector<Event *> events;

            std::vector<std::string> animatedElements;

          public:
            Map(const int layer1[], const int layer2[], const int layer3[], int w, int h, std::string const &bg, std::vector<std::string> const &animatedElements = std::vector<std::string>());
            ~Map();
            int getH() const {
                return h;
            }
            int getW() const {
                return w;
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
            };
            void debugInfo();
            void updateElements(sf::RenderTexture &frame);

            int getCurrentTileCode(sf::Vector2i const &pos, int layer) const;

            int getTileCollision(int tile) const;

            int getCollision(sf::Vector2i const &pos) const;
        };
    } // namespace Model
} // namespace OpMon

#endif // MAP_HPP
