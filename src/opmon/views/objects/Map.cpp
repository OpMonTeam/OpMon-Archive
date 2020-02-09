/*
Map.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Map.hpp"
#include "../../../utils/log.hpp"
#include "../../start/Core.hpp"
#include "../storage/OverworldData.hpp"
#include "Events.hpp"
#include <cstdlib>
#include <sstream>

namespace OpMon {
    namespace Model {

        Map::Map(std::vector<int> const &layer1, std::vector<int> const &layer2, std::vector<int> const &layer3, int w, int h, bool indoor, std::string const &bg, std::vector<std::string> const &animatedElements)
          : indoor(indoor)
          , bg(bg)
          , animatedElements(animatedElements)
          , loaded(true) {

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
                for(Event *event : events) {
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
                                          jsonData.at("music"),
                                          jsonData.value("animations", std::vector<std::string>()));

                for(auto eitor = jsonData.at("events").begin(); eitor != jsonData.at("events").end(); ++eitor) {
                    std::string type = eitor->at("type");

                    //Creates dialogs object
                    Utils::OpString dialog;
                    std::vector<std::string> dialogKey = eitor->value("dialog", std::vector<std::string>());
                    if(!dialogKey.empty()) {
                        std::string key = dialogKey[0];
                        std::vector<sf::String *> toAdd;
                        for(unsigned int j = 1; j < dialogKey.size(); j++) {
                            toAdd.push_back(data.getCompletion(dialogKey[j]));
                        }
                        dialog = Utils::OpString(key, toAdd);
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
                        currentMap->addEvent(new Events::TalkingEvent(data.getEventsTexture(eitor->at("textures")),
                                                                      sf::Vector2f(eitor->at("position")[0],
                                                                                   eitor->at("position")[1]),
                                                                      dialog,
                                                                      eitor->value("side", SIDE_ALL),
                                                                      eitor->value("trigger", Events::EventTrigger::PRESS),
                                                                      eitor->value("passable", false)));
                    } else if(type == "DoorEvent") {
                        currentMap->addEvent(new Events::DoorEvent(data.getDoorsTexture(eitor->at("textures")),
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
                        currentMap->addEvent(new Events::TPEvent(data.getEventsTexture(eitor->at("textures")),
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
                        currentMap->addEvent(new Events::TalkingCharaEvent(data.getCharaTexture(eitor->at("textures")),
                                                                           sf::Vector2f(eitor->at("position")[0],
                                                                                        eitor->at("position")[1]),
                                                                           dialog,
                                                                           eitor->value("side", Side::TO_UP),
                                                                           eitor->value("trigger", Events::EventTrigger::PRESS),
                                                                           eitor->value("moveStyle", Events::MoveStyle::NO_MOVE),
                                                                           charaPath,
                                                                           eitor->value("passable", false),
                                                                           eitor->value("interactionSide", SIDE_ALL)));
                    } else if(type == "TrainerEvent") {
                        std::vector<std::string> defeatedKey = eitor->at("dialogAfter");
                        Utils::OpString defeatedDialog;
                        std::string key = defeatedKey[0];
                        std::vector<sf::String *> toAdd;
                        for(unsigned int j = 1; j < defeatedKey.size(); j++) {
                            toAdd.push_back(data.getCompletion(defeatedKey[j]));
                        }
                        defeatedDialog = Utils::OpString(key, toAdd);
                        currentMap->addEvent(new Events::TrainerEvent(data.getCharaTexture(eitor->at("textures")),
                                                                      sf::Vector2f(eitor->at("position")[0],
                                                                                   eitor->at("position")[1]),
                                                                      data.getTrainer(eitor->at("trainer")),
                                                                      dialog,
                                                                      defeatedDialog,
                                                                      eitor->value("side", Side::TO_UP),
                                                                      eitor->value("trigger", Events::EventTrigger::PRESS),
                                                                      eitor->value("moveStyle", Events::MoveStyle::NO_MOVE),
                                                                      charaPath,
                                                                      eitor->value("passable", false),
                                                                      eitor->value("interactionSide", SIDE_ALL)));
                    }
                }
                return currentMap;
            } else {
                handleError("Error : Trying to load an already loaded map.");
                return nullptr;
            }
        }

        std::vector<Event *> Map::getEvent(sf::Vector2i position) const {
            if(loaded) {
                std::vector<Event *> toReturn;

                for(Event *event : events) {
                    if(event->getPositionMap().getPosition().x == position.x && event->getPositionMap().getPosition().y == position.y) {
                        toReturn.push_back(event);
                    }
                }
                return toReturn;
            } else {
                handleError("Error : using an unloaded map (Map::getEvent).", true);
                return std::vector<Event *>();
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
                    handleError("Map::getCurrentTileCode : layer is not 1, 2 or 3. Returning 0.");
                    return 0;
                }
            } else {
                handleError("Error : using an unloaded map (Map::getCurrentTileCode).", true);
                return 0;
            }
        }

        int Map::getTileCollision(int tile) const {
            if(loaded) {
                return colTile[tile];
            } else {
                handleError("Error : using an unloaded map (Map::getTileCollision).", true);
                return 0;
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
                handleError("Error : using an unloaded map (Map::getCollision).", true);
                return 0;
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

                #define FILL_VOID 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

        int Map::colTile[4096] = {
            0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, FILL_VOID, //The last tile of this line allows to make invisible walls
            0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, FILL_VOID, //1
            0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, FILL_VOID,
            2, 2, 2, 2, 2, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 8, 8, 8, 0, 0, 0, FILL_VOID,
            2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 7, 7, 7, 0, 0, 0, FILL_VOID,
            2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 6, 5, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, FILL_VOID,
            0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 6, 0, 0, 0, 1, 0, 0, 1, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, FILL_VOID, //16
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, FILL_VOID,
            1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, FILL_VOID, //32
            1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 1, 0, 1, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, FILL_VOID,
            1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID, //48
            1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, FILL_VOID //63
         //0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 +35

        };

        #undef FILL_VOID

    } // namespace Model
} // namespace OpMon
