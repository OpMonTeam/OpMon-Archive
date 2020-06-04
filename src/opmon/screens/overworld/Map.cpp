/*
Map.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
 */
#include "Map.hpp"

#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <cstdlib>
#include <sstream>

#include "Position.hpp"
#include "events/AnimationEvent.hpp"
#include "events/DialogEvent.hpp"
#include "events/SoundEvent.hpp"
#include "events/TPEvent.hpp"
#include "events/metaevents.hpp"
#include "src/nlohmann/json.hpp"
#include "src/opmon/screens/overworld/OverworldData.hpp"
#include "src/utils/log.hpp"
#include "src/opmon/screens/overworld/events/AbstractEvent.hpp"
#include "src/opmon/screens/overworld/events/BattleEvent.hpp"
#include "src/opmon/screens/overworld/events/CharacterEvent.hpp"
#include "src/opmon/screens/overworld/events/LinearMetaEvent.hpp"
#include "src/utils/exceptions.hpp"

namespace OpMon {

    MapLayer::MapLayer(sf::Vector2i size, const int tilesCodes[],
                       sf::Texture &tileset)
        : tileset(tileset) {
        tiles.setPrimitiveType(sf::Quads);
        tiles.resize(size.x * size.y * 4);

        for(int i = 0; i < size.y; i++) {
            for(int j = 0; j < size.x; j++) {
                // The software we use (Tiled map editor) starts the first
                // tile at 1, and leaves 0 for void. This line substracts one
                // to every square.

                int tileNumber = tilesCodes[(i * size.x) + j] - 1;

                // Now that every void (0) became -1, this replaces every -1
                // by the "official" void tile.
                if(tileNumber == -1) {
                    tileNumber = 257; // official void tile
                }

                int tx = tileNumber % (tileset.getSize().x / 32);
                int ty = tileNumber / (tileset.getSize().x / 32);

                sf::Vertex *quad = &tiles[((i * size.x) + j) * 4];

                quad[0].position = sf::Vector2f(j * 32, i * 32);
                quad[1].position = sf::Vector2f((j + 1) * 32, i * 32);
                quad[2].position = sf::Vector2f((j + 1) * 32, (i + 1) * 32);
                quad[3].position = sf::Vector2f(j * 32, (i + 1) * 32);

                quad[0].texCoords = sf::Vector2f(tx * 32, ty * 32);
                quad[1].texCoords = sf::Vector2f((tx + 1) * 32, ty * 32);
                quad[2].texCoords = sf::Vector2f((tx + 1) * 32, (ty + 1) * 32);
                quad[3].texCoords = sf::Vector2f(tx * 32, (ty + 1) * 32);
            }
        }
    }

    void MapLayer::draw(sf::RenderTarget &target,
                        sf::RenderStates states) const {
        states.transform *= getTransform();

        states.texture = &tileset;

        target.draw(tiles, states);
    }

    Map::Map(std::vector<int> const &layer1, std::vector<int> const &layer2,
             std::vector<int> const &layer3, int w, int h, bool indoor,
             std::string const &tileset, int *tilesetCol, std::string const &bg,
             std::vector<std::string> const &animatedElements)
        : indoor(indoor),
          bg(bg),
          animatedElements(animatedElements),
          tileset(tileset),
          tilesetCol(tilesetCol) {
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
        for(AbstractEvent *event : events) {
            delete(event);
        }
        free(layer1);
        free(layer2);
        free(layer3);
    }

    Map::Map(nlohmann::json jsonData, OverworldData &data) {
        Utils::Log::oplog("Loading " + (std::string)jsonData.at("id"));

        w = jsonData.at("size")[0];
        h = jsonData.at("size")[1];

        this->layer1 = (int *)malloc(sizeof(int) * w * h);
        this->layer2 = (int *)malloc(sizeof(int) * w * h);
        this->layer3 = (int *)malloc(sizeof(int) * w * h);

        for(unsigned int i = 0; i < ((unsigned int)w * h); i++) {
            this->layer1[i] = jsonData.at("layers")[0][i];
            this->layer2[i] = jsonData.at("layers")[1][i];
            this->layer3[i] = jsonData.at("layers")[2][i];
        }

        indoor = jsonData.at("indoor");
        tileset = jsonData.at("tileset");
        tilesetCol = data.getTilesetCol(tileset);
        bg = jsonData.at("music");
        animatedElements =
            jsonData.value("animations", std::vector<std::string>());

        for(nlohmann::json event : jsonData.at("events")) {
            std::string type = event.at("type");
            if(type == "TP")
                events.push_back(new TPEvent(data, event));
            else if(type == "Animation")
                events.push_back(new AnimationEvent(data, event));
            else if(type == "Character")
                events.push_back(new CharacterEvent(data, event));
            else if(type == "Dialog")
                events.push_back(new DialogEvent(data, event));
            else if(type == "Sound")
                events.push_back(new SoundEvent(data, event));
            else if(type == "Battle")
                events.push_back(new BattleEvent(data, event));
            else if(type == "Trainer")
                events.push_back(new TrainerEvent(data, event));
            else if(type == "TalkingCharacter")
                events.push_back(new TalkingCharaEvent(data, event));
            else if(type == "Door")
                events.push_back(new DoorEvent(data, event));
            else if(type == "LinearMeta")
                events.push_back(new LinearMetaEvent(data, event));
        }
    }

    std::list<AbstractEvent *> Map::getEvent(sf::Vector2i position) const {
        std::list<AbstractEvent *> toReturn;

        for(AbstractEvent *event : events) {
            if(event->getPositionMap().getPosition().x == position.x &&
               event->getPositionMap().getPosition().y == position.y) {
                toReturn.push_back(event);
            }
        }
        return toReturn;
    }

    int Map::getCurrentTileCode(sf::Vector2i const &pos, int layer) const {
        switch(layer) {
            case 1:
                return layer1[pos.x + pos.y * w] == 0 ?
                           257 /*"official" void tile*/ :
                           layer1[pos.x + pos.y * w] - 1;
            case 2:
                return layer2[pos.x + pos.y * w] == 0 ?
                           257 /*"official" void tile*/ :
                           layer2[pos.x + pos.y * w] - 1;
            case 3:
                return layer3[pos.x + pos.y * w] == 0 ?
                           257 /*"official" void tile*/ :
                           layer3[pos.x + pos.y * w] - 1;
            default:
                throw Utils::UnexpectedValueException(
                    std::to_string(layer),
                    "a layer between 1 and 3 in Map::getCurrentTileCode",
                    false);
                return 0;
        }
    }

    int Map::getTileCollision(int tile) const { return tilesetCol[tile]; }

    int Map::getCollision(sf::Vector2i const &pos) const {
        int collisionLayer1 = getTileCollision(getCurrentTileCode(pos, 1));
        int collisionLayer2 = getTileCollision(getCurrentTileCode(pos, 2));

        return (collisionLayer1 == 0) ? collisionLayer2 : collisionLayer1;
    }

    std::string Map::toDebugString() {
        std::ostringstream out;
        out << "[class Map]" << std::endl;
        out << "size : " << w << " ; " << h << std::endl;
        out << "bg = " << bg << std::endl;
        out << "indoor = " << indoor << std::endl;
        out << "layer1 size : " << sizeof(layer1) / 4 << std::endl;
        out << "layer2 size : " << sizeof(layer2) / 4 << std::endl;
        out << "layer3 size : " << sizeof(layer3) / 4 << std::endl;
        out << "event count : " << events.size() << std::endl;
        out << "animated elements count : " << animatedElements.size()
            << std::endl;
        return out.str();
    }

} // namespace OpMon
