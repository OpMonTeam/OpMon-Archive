
#include "Map.hpp"
#include "Events.hpp"
#include "../../start/Core.hpp"
#include "../storage/Data.hpp"
#include "../storage/InternalFiles.hpp"

namespace OpMon{
  namespace Model{

    Map::Map(const int layer1[], const int layer2[], const int layer3[], int w, int h, std::string const &bg, std::vector<std::string > const& animatedElements)
      : layer1(layer1), layer2(layer2), layer3(layer3), bg(bg), animatedElements(animatedElements){


      this->w = w;
      this->h = h;

    }

    Map::~Map() {
      /*
      NOTE: layers are (for now) static objects in Data

      delete(layer1);
      delete(layer2);
      delete(layer3);
       */
      for(Event *event : events) {
        delete(event);
      }
    }

    std::vector<Event *> Map::getEvent(sf::Vector2i position) const {
      std::vector<Event *> toReturn;

      for(Event *event : events) {
        if(event->getPosition().x SQUARES == position.x && event->getPosition().y SQUARES == position.y) {
          toReturn.push_back(event);
        }
      }
      return toReturn;
    }

    int Map::getCurrentTileCode(sf::Vector2i const& pos, int layer){
      switch(layer){
      case 1:
        return layer1[pos.x + pos.y * w];
	break;
      case 2:
	return layer2[pos.x + pos.y * w];
	break;
      case 3:
	return layer3[pos.x + pos.y * w];
	break;
      default:
	return 0;
      }

      return 0;
      
    }

    int Map::getTileCollision(int tile){
      return Collisions::colTile[tile];
    }
    
  }
}
