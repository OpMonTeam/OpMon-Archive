/*
 * OpMonData.cpp
 *
 *  Created on: 3 juin 2020
 *      Author: cyrielle
 */

#include "OpMonData.hpp"

#include <filesystem>

#include "evolutions.hpp"
#include "src/nlohmann/json.hpp"
#include "src/opmon/core/system/path.hpp"
#include "src/utils/exceptions.hpp"

namespace OpMon {

    OpMonData::OpMonData(GameData *gamedata) {
        for(std::filesystem::directory_entry const &file :
            std::filesystem::directory_iterator(Path::getResourcePath() +
                                                "data/species")) {
            if(file.is_regular_file()) {
                Utils::Log::oplog("Found opmon file " +
                                  file.path().generic_string());
                std::ifstream opmonJsonFile(file.path());
                if(!opmonJsonFile) {
                    throw Utils::LoadingException(file.path().generic_string(),
                                                  true);
                }
                nlohmann::json opmonJson;
                opmonJsonFile >> opmonJson;

                for(auto itor = opmonJson.begin(); itor != opmonJson.end();
                    ++itor) {
                    int opDexNumber = itor->at("opDex");
                    std::string opDexNumberStr = std::to_string(opDexNumber);

                    Evolution *evol = nullptr;
                    if(itor->at("evolution").at("type") == "level") {
                        evol = new Evolutions::E_Level(
                            itor->at("evolution").at("species"),
                            itor->at("evolution").at("level"));
                    } else if(itor->at("evolution").at("type") == "no") {
                        evol = nullptr;
                    }
                    std::vector<Stats> evs;
                    for(unsigned int i = 0; i < itor->at("evs").size(); ++i) {
                        evs.push_back(itor->at("evs")[i]);
                    }

                    listOp.emplace(
                        opDexNumber,
                        new Species(itor->at("atk"), itor->at("def"),
                                    itor->at("atkSpe"), itor->at("defSpe"),
                                    itor->at("spe"), itor->at("HP"),
                                    gamedata->getStringKeys().getStd(
                                        "opmon.name." + opDexNumberStr),
                                    itor->at("types")[0], itor->at("types")[1],
                                    evol, evs, itor->at("height"),
                                    itor->at("weight"),
                                    gamedata->getStringKeys().getStd(
                                        "opmon.desc." + opDexNumberStr),
                                    itor->at("expGiven"), itor->at("curve"),
                                    itor->at("captureRate"), opDexNumber));
                    Utils::Log::oplog("Loaded OpMon n°" + opDexNumberStr +
                                      " : " + listOp[opDexNumber]->getName());
                }
            }
        }

        // Initializating OpMon Sprites

        // I will use a "for" loop later, I don't use it now to avoid loading
        // errors. I will use it when every sprite will be loaded.
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[1],
                                                "sprites/opmons/1-%d.png", 2);
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[2],
                                                "sprites/opmons/2-%d.png", 2);
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[4],
                                                "sprites/opmons/4-%d.png", 2);
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[7],
                                                "sprites/opmons/7-%d.png", 2);

        // Intializing types sprites
#define LOAD_TYPE(type)                                                        \
    Utils::ResourceLoader::load(                                               \
        tempTx,                                                                \
        (std::string("sprites/battle/types/") + #type + ".png").c_str());      \
    typesTextures.emplace(Type::type, sf::Texture(tempTx))

        sf::Texture tempTx;
        LOAD_TYPE(BAD);
        LOAD_TYPE(BUG);
        LOAD_TYPE(BURNING);
        LOAD_TYPE(COLD);
        LOAD_TYPE(DRAGON);
        LOAD_TYPE(ELECTRON);
        LOAD_TYPE(FIGHT);
        LOAD_TYPE(GHOST);
        LOAD_TYPE(GROUND);
        LOAD_TYPE(LIQUID);
        LOAD_TYPE(MAGIC);
        LOAD_TYPE(MENTAL);
        LOAD_TYPE(METAL);
        LOAD_TYPE(MINERAL);
        LOAD_TYPE(NEUTRAL);
        LOAD_TYPE(SKY);
        LOAD_TYPE(TOXIC);
        LOAD_TYPE(VEGETAL);

#undef LOAD_TYPE
    }

    OpMonData::~OpMonData() {
        for(std::pair<unsigned int, Species *> spe : listOp) {
            delete(spe.second);
        }
    }

} /* namespace OpMon */
