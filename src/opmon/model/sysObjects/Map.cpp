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
#include "../../
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
		
		Map(nlohmann::json jsonData) 
		: jsonData(jsonData)
		, loaded(false){
	
		}
		
		bool Map::loadMap(OverworldData &data){
			if(!loaded){
				Map *currentMap = new Map(jsonData->at("layers")[0],
                                          jsonData->at("layers")[1],
                                          jsonData->at("layers")[2],
                                          jsonData->at("size")[0],
                                          jsonData->at("size")[1],
                                          jsonData->at("indoor"),
                                          jsonData->at("music"),
                                          jsonData->value("animations", std::vector<std::string>()));
										  
                for(auto eitor = jsonData->at("events").begin(); eitor != jsonData->at("events").end(); ++eitor) {
                    std::string type = eitor->at("type");

                    //Creates dialogs object
                    std::vector<Utils::OpString> dialogs;
                    std::vector<std::vector<std::string>> dialogsKeys = eitor->value("dialog", std::vector<std::vector<std::string>>());
                    if(!dialogsKeys.empty()) {
                        for(unsigned int i = 0; i < dialogsKeys.size(); i++) {
                            std::string key = dialogsKeys[i][0];
                            std::vector<sf::String *> toAdd;
                            for(unsigned int j = 1; j < dialogsKeys[i].size(); j++) {
                                toAdd.push_back(completions[dialogsKeys[i][j]]);
                            }
                            dialogs.push_back(OpString(key, toAdd));
                        }
                    }

                    //Creates path objects for npcs
                    std::vector<std::vector<int>> prePath = eitor->value("path", std::vector<std::vector<int>>());
                    std::vector<Side> charaPath;
                    if(!prePath.empty()) {
                        nlohmann::json prePathJson = eitor->at("path");
                        for(auto pitor = prePathJson.begin(); pitor != prePathJson.end(); ++pitor) {
                            for(unsigned int r = 0; r < pitor->at(1); r++) {
                                charaPath.push_back(pitor->at(0));
                            }
                        }
                    }

                    if(type == "TalkingEvent") {
                        currentMap->addEvent(new Events::TalkingEvent(eventsTextures[eitor->at("textures")],
                                                                      sf::Vector2f(eitor->at("position")[0],
                                                                                   eitor->at("position")[1]),
                                                                      dialogs,
                                                                      eitor->value("side", SIDE_ALL),
                                                                      eitor->value("trigger", Events::EventTrigger::PRESS),
                                                                      eitor->value("passable", false)));
                    } else if(type == "DoorEvent") {
                        currentMap->addEvent(new Events::DoorEvent(doorsTextures[eitor->at("textures")],
                                                                   eitor->at("doorType"),
                                                                   sf::Vector2f(eitor->at("position")[0],
                                                                                eitor->at("position")[1]),
                                                                   sf::Vector2i(eitor->at("tp").at("position")[0],
                                                                                eitor->at("tp").at("position")[1]),
                                                                   eitor->at("tp").at("map"),
                                                                   eitor->value("trigger", Events::EventTrigger::GO_IN),
                                                                   eitor->at("tp").value("side", Side::NO_MOVE),
                                                                   eitor->value("sides", SIDE_ALL),
                                                                   eitor->value("passable", true)));
                    } else if(type == "TPEvent") {
                        currentMap->addEvent(new Events::TPEvent(eventsTextures[eitor->at("textures")],
                                                                 eitor->at("trigger"),
                                                                 sf::Vector2f(eitor->at("position")[0],
                                                                              eitor->at("position")[1]),
                                                                 sf::Vector2i(eitor->at("tp").at("position")[0],
                                                                              eitor->at("tp").at("position")[1]),
                                                                 eitor->at("tp").at("map"),
                                                                 eitor->at("tp").value("side", Side::NO_MOVE),
                                                                 eitor->value("side", SIDE_ALL),
                                                                 eitor->value("passable", true)));
                    } else if(type == "TalkingCharaEvent") {
                        currentMap->addEvent(new Events::TalkingCharaEvent(charaTextures[eitor->at("textures")],
                                                                           sf::Vector2f(eitor->at("position")[0],
                                                                                        eitor->at("position")[1]),
                                                                           dialogs,
                                                                           eitor->value("side", Side::TO_UP),
                                                                           eitor->value("trigger", Events::EventTrigger::PRESS),
                                                                           eitor->value("moveStyle", Events::MoveStyle::NO_MOVE),
                                                                           charaPath,
                                                                           eitor->value("passable", false),
                                                                           eitor->value("interactionSide", SIDE_ALL)));
                    } else if(type == "TrainerEvent") {
                        std::vector<std::vector<std::string>> defeatedKeys = eitor->at("dialogAfter");
                        std::vector<OpString> defeatedDialog;
                        for(unsigned int i = 0; i < defeatedKeys.size(); i++) {
                            std::string key = defeatedKeys[i][0];
                            std::vector<sf::String *> toAdd;
                            for(unsigned int j = 1; j < defeatedKeys[i].size(); j++) {
                                toAdd.push_back(completions[defeatedKeys[i][j]]);
                            }
                            defeatedDialog.push_back(OpString(key, toAdd));
                        }
                        currentMap->addEvent(new Events::TrainerEvent(charaTextures[eitor->at("textures")],
                                                                      sf::Vector2f(eitor->at("position")[0],
                                                                                   eitor->at("position")[1]),
                                                                      trainers[eitor->at("trainer")],
                                                                      dialogs,
                                                                      defeatedDialog,
                                                                      eitor->value("side", Side::TO_UP),
                                                                      eitor->value("trigger", Events::EventTrigger::PRESS),
                                                                      eitor->value("moveStyle", Events::MoveStyle::NO_MOVE),
                                                                      charaPath,
                                                                      eitor->value("passable", false),
                                                                      eitor->value("interactionSide", SIDE_ALL)));
                    }
                }
				
				
				
				loaded = true;
			}else{
				
			}
		}

        std::vector<Event *> Map::getEvent(sf::Vector2i position) const {
			if(loaded){
				std::vector<Event *> toReturn;

				for(Event *event : events) {
					if(event->getPositionMap().getPosition().x == position.x && event->getPositionMap().getPosition().y == position.y) {
						toReturn.push_back(event);
					}
				}
				return toReturn;
			}else{
				handleError("Error : using an unloaded map (Map::getEvent).", true);
				return std::vector<Event *>();
			}
        }

        int Map::getCurrentTileCode(sf::Vector2i const &pos, int layer) const {
			if(loaded){
				switch(layer) {
				case 1:
					return layer1[pos.x + pos.y * w] == 0 ? 257 /*"official" void tile*/ : layer1[pos.x + pos.y * w] - 1;
				case 2:
					return layer2[pos.x + pos.y * w] == 0 ? 257 /*"official" void tile*/ : layer2[pos.x + pos.y * w] - 1;
				case 3:
					return layer3[pos.x + pos.y * w] == 0 ? 257 /*"official" void tile*/ : layer3[pos.x + pos.y * w] - 1;
				default:
					//TODO: Log error
					return 0;
				}
			}else{
				handleError("Error : using an unloaded map (Map::getCurrentTileCode).", true);
				return 0;
			}
        }

        int Map::getTileCollision(int tile) const {
			if(loaded){
				return Collisions::colTile[tile];
			}else{
				handleError("Error : using an unloaded map (Map::getTileCollision).", true);
				return 0;
			}
        }

        int Map::getCollision(sf::Vector2i const &pos) const {
			if(loaded){
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
			}else{
				handleError("Error : using an unloaded map (Map::getCollision).", true);
				return 0;
			}
        }
    } // namespace Model
} // namespace OpMon
