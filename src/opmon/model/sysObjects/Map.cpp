
#include "Map.hpp"
#include "../../start/Core.hpp"
#include "../storage/Data.hpp"
#include "../storage/InternalFiles.hpp"
#include "Events.hpp"

namespace OpMon {
	namespace Model {

		Map::Map(const int layer1[], const int layer2[], const int layer3[], int w, int h, std::string const &bg, std::vector<std::string> const &animatedElements)
		  : layer1(layer1)
		  , layer2(layer2)
		  , layer3(layer3)
		  , bg(bg)
		  , animatedElements(animatedElements) {

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
				//cout << "Event coordinates : " << event->getPosition().x
				if(event->getPositionMap().getPosition().x == position.x && event->getPositionMap().getPosition().y == position.y) {
					toReturn.push_back(event);
				}
			}
			return toReturn;
		}

		int Map::getCurrentTileCode(sf::Vector2i const &pos, int layer) const {
			switch(layer) {
			case 1:
				return layer1[pos.x + pos.y * w] - 1;
			case 2:
				return layer2[pos.x + pos.y * w] - 1;
			case 3:
				return layer3[pos.x + pos.y * w] - 1;
			default:
				//TODO: Log error
				return 0;
			}
		}

		int Map::getTileCollision(int tile) const {
			return Collisions::colTile[tile];
		}

		int Map::getCollision(sf::Vector2i const &pos) const {
			int collisionLayer1 = getTileCollision(getCurrentTileCode(pos, 1));
			int collisionLayer2 = getTileCollision(getCurrentTileCode(pos, 2));

			if(collisionLayer1 == 0) {
				return collisionLayer2;
			}
			if(collisionLayer2 == 0) {
				return collisionLayer1;
			}
			if(collisionLayer1 == 1 || collisionLayer2 == 1) {
				return 1;
			}
			// TODO: it may have a conflict between collisions from layer1 and layer2.
			return collisionLayer1;
		}
	} // namespace Model
} // namespace OpMon
