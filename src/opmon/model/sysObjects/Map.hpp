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

namespace OpMon{
  namespace Model{
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

      char **passArr;
      /**The copy constructor must not be used.*/
      Map(Map const &toCopy) = delete;

      std::vector<Event *> events;

      std::vector<std::string> animatedElements;
      std::vector<sf::Vector2f> elementsPos;
      std::vector<sf::Sprite> elementsSprites;
      std::vector<int> elementsCount;

    public:
      Map(const int layer1[], const int layer2[], const int layer3[], int w, int h, const char* const* collisions, std::string const& bg, std::vector<std::string > const& animatedElements = std::vector<std::string >());
      ~Map();
      int getH() const {
	return h;
      }
      int getW() const {
	return w;
      }
      char **getPassArr() const {
	return passArr;
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
      void addEvent(Event *event) {
        events.push_back(event);
      }
      std::vector<Event *>& getEvent(sf::Vector2i position) const;
      std::vector<Event *>& getEvents() {
        return events;
      };
      void debugInfo();
      void updateElements(sf::RenderTexture &frame);
    };
  }
}

#endif // MAP_HPP
