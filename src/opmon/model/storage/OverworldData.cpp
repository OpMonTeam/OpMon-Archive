/*
  Overworld.cpp
  Author : Cyriel
  File under GNU GPL v3.0 license
*/
#include "OverworldData.hpp"
#include "../../../nlohmann/json.hpp"
#include "../../../utils/OpString.hpp"
#include "../../../utils/log.hpp"
#include "../../../utils/path.hpp"
#include "../objects/Attacks.hpp"
#include "InternalFiles.hpp"
#include "ResourceLoader.hpp"
#include <fstream>

namespace OpMon {
    namespace Model {

        OverworldData::OverworldData(UiData *uidata, Player *player)
          : uidata(uidata)
          , player(player) {

            using namespace Utils;

            Attack::initAttacks(Utils::Path::getResourcePath() + "data/attacks.json");

            player->addOpToOpTeam(new Model::OpMon("", uidata->getOp(4), 5, {Model::Attack::newAtk("Tackle"), Model::Attack::newAtk("Growl"), nullptr, nullptr}, Model::Nature::QUIET));

            //PP texture and rect loading
            ResourceLoader::load(texturePP, "sprites/chara/pp/pp_anim.png");
            texturePPRect[(unsigned int)Side::TO_DOWN] = sf::IntRect(0, 64, 32, 32);
            texturePPRect[(unsigned int)Side::TO_RIGHT] = sf::IntRect(32, 64, 32, 32);
            texturePPRect[(unsigned int)Side::TO_LEFT] = sf::IntRect(64, 64, 32, 32);
            texturePPRect[(unsigned int)Side::TO_UP] = sf::IntRect(96, 64, 32, 32);
            walkingPPRect[(unsigned int)Side::TO_DOWN] = sf::IntRect(0, 0, 32, 32);
            walkingPPRect[(unsigned int)Side::TO_RIGHT] = sf::IntRect(32, 0, 32, 32);
            walkingPPRect[(unsigned int)Side::TO_LEFT] = sf::IntRect(64, 0, 32, 32);
            walkingPPRect[(unsigned int)Side::TO_UP] = sf::IntRect(96, 0, 32, 32);
            walkingPP2Rect[(unsigned int)Side::TO_DOWN] = sf::IntRect(0, 32, 32, 32);
            walkingPP2Rect[(unsigned int)Side::TO_RIGHT] = sf::IntRect(32, 32, 32, 32);
            walkingPP2Rect[(unsigned int)Side::TO_LEFT] = sf::IntRect(64, 32, 32, 32);
            walkingPP2Rect[(unsigned int)Side::TO_UP] = sf::IntRect(96, 32, 32, 32);

            //Characters' textures initialization
            ResourceLoader::loadTextureArray(charaTextures["kid"], "sprites/chara/kid/kid%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["fisherman"], "sprites/chara/fisherman/fisherman%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["kiwai"], "sprites/chara/prof/prof%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["playermom"], "sprites/chara/mom/mom%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["sk"], "sprites/chara/rival/sk%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["inferm"], "sprites/chara/inferm/inferm%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["|_| -|- |-| |= |_| N"], "sprites/chara/beta/alphabeta/otheon%d.png", 12);
            ResourceLoader::loadTextureArray(charaTextures["beta"], "sprites/chara/beta/beta%d.png", 12);

            //Doors' textures initialization
            ResourceLoader::loadTextureArray(doorsTextures["shop"], "animations/shopdoor/shop_door%d.png", 4, 1);
            ResourceLoader::loadTextureArray(doorsTextures["normal"], "animations/basicdoor/basic_door%d.png", 4, 1);

            eventsTextures.emplace("alpha", alphaTab);

            //Elements initialization
            elementsCounter["windturbine"] = 0;
            elementsPos["windturbine"] = sf::Vector2f(8 * 32 + 25 * 32 - 7, 3 * 32 + 15);

            ResourceLoader::loadTextureArray(elementsTextures["windturbine"], "animations/windturbine/blade_%d.png", 16, 1);

            elementsCounter["smoke"] = 0;
            elementsPos["smoke"] = sf::Vector2f(8 * 32 + 18 * 32, 11 * 32);

            ResourceLoader::loadTextureArray(elementsTextures["smoke"], "animations/chimneysmoke/chimneysmoke_%d.png", 32, 1);

<<<<<<< HEAD
=======
            ResourceLoader::load(menuTexture, "backgrounds/menu.png");

>>>>>>> Reformated cod
            //Items initialisation

            nlohmann::json itemsJson;

            std::ifstream itemsJsonFile(Utils::Path::getResourcePath() + "data/items.json");

            if(!itemsJsonFile) {
                handleError("Can't open items data. (items.json)", true);
            }

            itemsJsonFile >> itemsJson;

            for(auto itor = itemsJson.begin(); itor != itemsJson.end(); ++itor) {
                std::vector<std::unique_ptr<ItemEffect>> effects; //0 is opmon, 1 is player, 2 is held
                for(auto eitor = itor->at("effects").begin(); eitor != itor->at("effects").end(); ++eitor) {
                    if(eitor->at("type") == "HpHealEffect") {
                        effects.push_back(std::make_unique<Items::HpHealEffect>(eitor->at("healed")));
                    } else {
                        effects.push_back(nullptr);
                    }
                }
                std::string itemId = itor->at("id");
                itemsList.emplace(itemId, std::make_unique<Item>(Utils::OpString("items." + itemId + ".name"), itor->at("usable"), itor->at("onOpMon"), std::move(effects[0]), std::move(effects[1]), std::move(effects[2])));
            }

            //Maps initialisation

            std::ifstream mapsJsonFile(Utils::Path::getResourcePath() + "data/maps.json");
            std::ifstream trainersJsonFile(Utils::Path::getResourcePath() + "data/trainers.json");

            if(!mapsJsonFile || !trainersJsonFile) {
                handleError("Can't open maps or trainers data. (maps.json, trainers.json)", true);
            }

            nlohmann::json mapsJson;
            nlohmann::json trainersJson;

            mapsJsonFile >> mapsJson;
            trainersJsonFile >> trainersJson;

            for(auto itor = trainersJson.begin(); itor != trainersJson.end(); ++itor) {
                OpTeam *team = new Model::OpTeam(itor->at("name"));
                for(auto opmonItor = itor->at("team").begin(); opmonItor != itor->at("team").end(); ++opmonItor) {
                    team->addOpMon(new OpMon(opmonItor->at("nickname"),
                                             uidata->getOp(opmonItor->at("species")),
                                             opmonItor->at("level"),
                                             {Model::Attack::newAtk(opmonItor->at("attacks")[0]),
                                              Model::Attack::newAtk(opmonItor->at("attacks")[1]),
                                              Model::Attack::newAtk(opmonItor->at("attacks")[2]),
                                              Model::Attack::newAtk(opmonItor->at("attacks")[3])},
                                             opmonItor->at("nature")));
                }
                trainers.emplace(itor->at("name"), team);
            }

            std::map<std::string, sf::String *> completions;
            completions.emplace("playername", player->getNameP());

            for(auto itor = mapsJson.begin(); itor != mapsJson.end(); ++itor) {
                Map *currentMap = maps.emplace(itor->at("id"), new Map(itor->at("layers")[0],
                                                                       itor->at("layers")[1],
                                                                       itor->at("layers")[2],
                                                                       itor->at("size")[0],
                                                                       itor->at("size")[1],
                                                                       itor->at("indoor"),
                                                                       itor->at("music"),
                                                                       itor->value("animations", std::vector<std::string>())))
<<<<<<< HEAD
		    .first->second;
=======
                                    .first->second;
>>>>>>> Reformated cod
                for(auto eitor = itor->at("events").begin(); eitor != itor->at("events").end(); ++eitor) {
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
            }

	    ResourceLoader::load(menuTexture, "backgrounds/menu.png");
	    mapsItor = maps.begin();
        }

        OverworldData::~OverworldData() {
            for(auto &map : maps) {
                delete(map.second);
            }
            delete(player);
        }

    } // namespace Model
} // namespace OpMon
