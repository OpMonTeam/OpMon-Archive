/*
Map.cpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Map.hpp"
#include "../../start/Core.hpp"
#include "../storage/InternalFiles.hpp"
#include "Events.hpp"
#include <cstdlib>

namespace OpMon {
    namespace Model {

        Map::Map(std::vector<int> const &layer1, std::vector<int> const &layer2, std::vector<int> const &layer3, int w, int h, bool indoor, std::string const &bg, std::vector<std::string> const &animatedElements)
          : indoor(indoor)
          , bg(bg)
          , animatedElements(animatedElements) {

            this->layer1 = (int *)malloc(sizeof(int) * w * h);
            this->layer2 = (int *)malloc(sizeof(int) * w * h);
            this->layer3 = (int *)malloc(sizeof(int) * w * h);

            for(unsigned int i = 0; i < ((unsigned int)w * h); i++) {
                this->layer1[i] = layer1[i];
                this->layer2[i] = layer2[i];
                this->layer3[i] = layer3[i];
            }

            this->w = w;
            this->h = h;
        }

        Map::~Map() {
            for(Event *event : events) {
                delete(event);
            }
            free(layer1);
            free(layer2);
            free(layer3);
        }

        std::vector<Event *> Map::getEvent(sf::Vector2i position) const {
            std::vector<Event *> toReturn;

            for(Event *event : events) {
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
            // TODO: it may have a conflict between collisions from layer1 and layer2. (Priority to layer1) TODO : Inform the programmer in the logs
            return collisionLayer1;
        }
    } // namespace Model
} // namespace OpMon
