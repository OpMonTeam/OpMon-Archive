/*
Map.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
 */
#include "Map.hpp"

#include <cstdlib>
#include <sstream>

#include "../../../utils/log.hpp"
#include "src/opmon/screens/overworld/OverworldData.hpp"
#include "src/nlohmann/json.hpp"
#include "events/metaevents.hpp"
#include "events/DialogEvent.hpp"
#include "events/TPEvent.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/view/elements/Position.hpp"
#include "src/utils/OpString.hpp"
#include "events/AnimationEvent.hpp"
#include "events/SoundEvent.hpp"

namespace sf {
	class String;
}  // namespace sf

namespace OpMon {
	namespace Elements {

		Map::Map(std::vector<int> const &layer1, std::vector<int> const &layer2, std::vector<int> const &layer3, int w, int h, bool indoor, std::string const& tileset, int* tilesetCol, std::string const &bg, std::vector<std::string> const &animatedElements)
		: indoor(indoor)
		, bg(bg)
		, animatedElements(animatedElements)
		, loaded(true)
		, tileset(tileset)
		, tilesetCol(tilesetCol){

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
			if(loaded) {
				for(AbstractEvent *event : events) {
					delete(event);
				}
				free(layer1);
				free(layer2);
				free(layer3);
			}
		}

		Map::Map(nlohmann::json jsonData)
		: jsonData(jsonData)
		, loaded(false) {
		}

		Map *Map::loadMap(OverworldData &data) {
			if(!loaded) {
				std::string mapName = jsonData.at("id");
				Utils::Log::oplog("Loading " + mapName);
				Map *currentMap = new Map(jsonData.at("layers")[0],
						jsonData.at("layers")[1],
						jsonData.at("layers")[2],
						jsonData.at("size")[0],
						jsonData.at("size")[1],
						jsonData.at("indoor"),
						jsonData.at("tileset"),
						data.getTilesetCol(jsonData.at("tileset")),
						jsonData.at("music"),
						jsonData.value("animations", std::vector<std::string>()));

				for(nlohmann::json event : jsonData.at("events")){
					std::string type = event.at("type");
					if(type == "TP") currentMap->addEvent(new TPEvent(data, event));
					else if(type == "Animation") currentMap->addEvent(new AnimationEvent(data, event));
					else if(type == "Character") currentMap->addEvent(new CharacterEvent(data, event));
					else if(type == "Dialog") currentMap->addEvent(new DialogEvent(data, event));
					else if(type == "Sound") currentMap->addEvent(new SoundEvent(data, event));
					else if(type == "Battle") currentMap->addEvent(new BattleEvent(data, event));
					else if(type == "Trainer") currentMap->addEvent(new TrainerEvent(data, event));
					else if(type == "TalkingCharacter") currentMap->addEvent(new TalkingCharaEvent(data, event));
					else if(type == "Door") currentMap->addEvent(new DoorEvent(data, event));
					else if(type == "LinearMeta") currentMap->addEvent(new LinearMetaEvent(data, event));
				}
				return currentMap;
			} else {
				Utils::Log::warn("Trying to load an already loaded map.");
				return nullptr;
			}
		}

		std::list<AbstractEvent *> Map::getEvent(sf::Vector2i position) const {
			if(loaded) {
				std::list<AbstractEvent *> toReturn;

				for(AbstractEvent *event : events) {
					if(event->getPositionMap().getPosition().x == position.x && event->getPositionMap().getPosition().y == position.y) {
						toReturn.push_back(event);
					}
				}
				return toReturn;
			} else {
				throw Utils::UnloadedResourceException("Map", "Map::getEvent");
			}
		}

		int Map::getCurrentTileCode(sf::Vector2i const &pos, int layer) const {
			if(loaded) {
				switch(layer) {
				case 1:
					return layer1[pos.x + pos.y * w] == 0 ? 257 /*"official" void tile*/ : layer1[pos.x + pos.y * w] - 1;
				case 2:
					return layer2[pos.x + pos.y * w] == 0 ? 257 /*"official" void tile*/ : layer2[pos.x + pos.y * w] - 1;
				case 3:
					return layer3[pos.x + pos.y * w] == 0 ? 257 /*"official" void tile*/ : layer3[pos.x + pos.y * w] - 1;
				default:
					throw Utils::UnexpectedValueException(std::to_string(layer), "a layer between 1 and 3 in Map::getCurrentTileCode", false);
					return 0;
				}
			} else {
				throw Utils::UnloadedResourceException("Map", "Map::getCurrentTileCode");
			}
		}

		int Map::getTileCollision(int tile) const {
			if(loaded) {
				return tilesetCol[tile];
			} else {
				throw Utils::UnloadedResourceException("Map", "Map::getTileCollision");
			}
		}

		int Map::getCollision(sf::Vector2i const &pos) const {
			if(loaded) {
				int collisionLayer1 = getTileCollision(getCurrentTileCode(pos, 1));
				int collisionLayer2 = getTileCollision(getCurrentTileCode(pos, 2));

				//TODO : factorise if possible (I don't like all these return statements)
				if(collisionLayer1 == 0) {
					return collisionLayer2;
				}
				if(collisionLayer2 == 0) {
					return collisionLayer1;
				}
				if(collisionLayer1 == 1 || collisionLayer2 == 1) {
					return 1;
				}
				return collisionLayer1;
			} else {
				throw Utils::UnloadedResourceException("Map", "Map::getCollision");
			}
		}

		std::string Map::toDebugString() {
			std::ostringstream out;
			out << "[class Map]" << std::endl;
			out << "loaded = " << loaded << std::endl;
			if(loaded) {
				out << "size : " << w << " ; " << h << std::endl;
				out << "bg = " << bg << std::endl;
				out << "indoor = " << indoor << std::endl;
				out << "layer1 size : " << sizeof(layer1) / 4 << std::endl;
				out << "layer2 size : " << sizeof(layer2) / 4 << std::endl;
				out << "layer3 size : " << sizeof(layer3) / 4 << std::endl;
				out << "event count : " << events.size() << std::endl;
				out << "animated elements count : " << animatedElements.size() << std::endl;
			} else {
				out << "Json object : " << std::endl;
				out << jsonData << std::endl;
			}
			return out.str();
		}

	} // namespace Elements
} // namespace OpMon
