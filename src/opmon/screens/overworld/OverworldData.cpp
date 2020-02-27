/*
  Overworld.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "OverworldData.hpp"

#include <fstream>
#include <algorithm>

#include "src/nlohmann/json.hpp"
#include "src/utils/OpString.hpp"
#include "src/utils/log.hpp"
#include "src/utils/path.hpp"
#include "src/opmon/core/system/ResourceLoader.hpp"
#include "src/opmon/core/Core.hpp"
#include "src/opmon/core/Player.hpp"
#include "src/opmon/core/UiData.hpp"
#include "src/opmon/model/Attack.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/model/Nature.hpp"
#include "src/opmon/model/OpMon.hpp"
#include "src/opmon/model/OpTeam.hpp"
#include "src/opmon/view/elements/Map.hpp"

namespace OpMon {

    OverworldData::OverworldData(UiData *uidata, Player *player)
        : uidata(uidata)
        , player(player)
        , gameMenuData(uidata, player) {

        using namespace Utils;

        Attack::initAttacks(Utils::Path::getResourcePath() + "data/attacks.json");

        player->addOpToOpTeam(new OpMon("", uidata->getOp(4), 5, {Attack::newAtk("Tackle"), Attack::newAtk("Growl"), nullptr, nullptr}, Nature::QUIET));

        //PP texture and rect loading
        System::ResourceLoader::load(texturePP, "sprites/chara/pp/pp_anim.png");
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
        System::ResourceLoader::loadTextureArray(charaTextures["kid"], "sprites/chara/kid/kid%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["fisherman"], "sprites/chara/fisherman/fisherman%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["kiwai"], "sprites/chara/prof/prof%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["playermom"], "sprites/chara/mom/mom%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["sk"], "sprites/chara/rival/sk%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["inferm"], "sprites/chara/inferm/inferm%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["|_| -|- |-| |= |_| N"], "sprites/chara/beta/alphabeta/otheon%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["beta"], "sprites/chara/beta/beta%d.png", 12);
        System::ResourceLoader::loadTextureArray(charaTextures["albd"], "sprites/chara/albd/albd%d.png", 12);

        //Doors' textures initialization
        System::ResourceLoader::loadTextureArray(doorsTextures["shop"], "animations/shopdoor/shop_door%d.png", 4, 1);
        System::ResourceLoader::loadTextureArray(doorsTextures["normal"], "animations/basicdoor/basic_door%d.png", 4, 1);

        eventsTextures.emplace("alpha", alphaTab);

        //Elements initialization
        elementsCounter["windturbine"] = 0;
        elementsPos["windturbine"] = sf::Vector2f(8 * 32 + 25 * 32 - 7, 3 * 32 + 15);

        System::ResourceLoader::loadTextureArray(elementsTextures["windturbine"], "animations/windturbine/blade_%d.png", 16, 1);

        elementsCounter["smoke"] = 0;
        elementsPos["smoke"] = sf::Vector2f(8 * 32 + 18 * 32, 11 * 32);

        System::ResourceLoader::loadTextureArray(elementsTextures["smoke"], "animations/chimneysmoke/chimneysmoke_%d.png", 32, 1);

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

        //The maps and the trainers' data are stored in two separate files
        std::ifstream mapsJsonFile(Utils::Path::getResourcePath() + "data/maps.json");
        std::ifstream trainersJsonFile(Utils::Path::getResourcePath() + "data/trainers.json");

        if(!mapsJsonFile || !trainersJsonFile) {
            handleError("Can't open maps or trainers data. (maps.json, trainers.json)", true);
        }

        nlohmann::json mapsJson;
        nlohmann::json trainersJson;

        mapsJsonFile >> mapsJson;
        trainersJsonFile >> trainersJson;

        /* Trainers loading */
        for(auto itor = trainersJson.begin(); itor != trainersJson.end(); ++itor) {
            OpTeam *team = new OpTeam(itor->at("name"));
            for(auto opmonItor = itor->at("team").begin(); opmonItor != itor->at("team").end(); ++opmonItor) {
                team->addOpMon(new OpMon(opmonItor->at("nickname"),
                                         uidata->getOp(opmonItor->at("species")),
                                         opmonItor->at("level"),
                                         {Attack::newAtk(opmonItor->at("attacks")[0]),
                                          Attack::newAtk(opmonItor->at("attacks")[1]),
                                          Attack::newAtk(opmonItor->at("attacks")[2]),
                                          Attack::newAtk(opmonItor->at("attacks")[3])},
                                         opmonItor->at("nature")));
            }
            trainers.emplace(itor->at("name"), team);
            std::string strName = itor->at("name");
            Utils::Log::oplog("Loaded trainer " + strName);
        }

        completions.emplace("playername", player->getNameP());

        /* Maps loading */
        for(auto itor = mapsJson.begin(); itor != mapsJson.end(); ++itor) {
            maps.emplace(itor->at("id"), new Elements::Map(*itor));
        }

        mapsItor = maps.begin();
    }

    OverworldData::~OverworldData() {
        for(auto &map : maps) {
            delete(map.second);
        }
        delete(player);
    }

    Elements::Map *OverworldData::getMap(std::string const &map) {
        if(!maps[map]->isLoaded()) {
            Elements::Map *newMap = maps[map]->loadMap(*this);
            delete(maps[map]);
            maps[map] = newMap;
        }
        return maps[map];
    }

    Elements::Map *OverworldData::getCurrentMap() {
        return getMap(player->getMapId());
    }

} // namespace OpMon
