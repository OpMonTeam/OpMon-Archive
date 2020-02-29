/*
  UiData.cpp
  Author : Cyrielle
  Contributors : BAKFR, Navet56
  File under GNU GPL v3.0 license
*/
#include "UiData.hpp"

#include <fstream>
#include <algorithm>
#include <utility>

#include "../../utils/OpString.hpp"
#include "../../nlohmann/json.hpp"
#include "../../utils/log.hpp"
#include "system/path.hpp"
#include "../model/evolutions.hpp"
#include "src/utils/OptionsSave.hpp"
#include "src/utils/ResourceLoader.hpp"
#include "src/opmon/core/Core.hpp"
#include "src/utils/KeyData.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/model/Species.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"
#include "src/utils/StringKeys.hpp"

namespace OpMon {
class Evolution;

    UiData::UiData() {

        Utils::Log::oplog("Initializating UiData");

        jukebox.addMusic("Title", "audio/music/title.ogg", 50);
        jukebox.addMusic("Start", "audio/music/intro.ogg");
        jukebox.addMusic("Fauxbourg", "audio/music/faubourgeuvi.ogg");
        jukebox.addMusic("Road 14", "audio/music/route14.ogg");
        //jukebox.addMusic("OpCenter", "audio/music/opcenter.ogg");
        jukebox.addMusic("Ms", "audio/music/mysterioucity.ogg");
        jukebox.addMusic("Labo", "audio/music/labo.ogg");
        jukebox.addMusic("Wild Battle", "audio/music/wildbattle.ogg");

        //Loading sounds
        jukebox.addSound("door sound", "audio/sounds/door.ogg");
        jukebox.addSound("shop door sound", "audio/sounds/shopdoor.ogg");
        jukebox.addSound("dialog pass", "audio/sounds/dialogChange.ogg");
        jukebox.addSound("nope", "audio/sounds/nope.ogg");
        jukebox.addSound("arrow", "audio/sounds/select.ogg");
        jukebox.addSound("push", "audio/sounds/selectbuttons.ogg");
        jukebox.addSound("hit", "audio/sounds/hit.ogg");

        Utils::ResourceLoader::load(font, "fonts/Default.ttf", true);

        std::ifstream opmonJsonFile(Path::getResourcePath() + "data/opmon.json");
        if(!opmonJsonFile) {
            handleError("Can't open opmon data.", true);
        }
        nlohmann::json opmonJson;
        opmonJsonFile >> opmonJson;

        for(auto itor = opmonJson.begin(); itor != opmonJson.end(); ++itor) {
            int opDexNumber = itor->at("opDex");
            std::string opDexNumberStr = std::to_string(opDexNumber);

            Evolution *evol = nullptr;
            if(itor->at("evolution").at("type") == "level") {
                evol = new E_Level(itor->at("evolution").at("species"), itor->at("evolution").at("level"));
            } else if(itor->at("evolution").at("type") == "no") {
                evol = nullptr;
            }
            std::vector<Stats> evs;
            for(unsigned int i = 0; i < itor->at("evs").size(); ++i) {
                evs.push_back(itor->at("evs")[i]);
            }

            listOp.emplace(opDexNumber, new Species(itor->at("atk"),
                                                    itor->at("def"),
                                                    itor->at("atkSpe"),
                                                    itor->at("defSpe"),
                                                    itor->at("spe"),
                                                    itor->at("HP"),
                                                    Utils::StringKeys::getStd("opmon.name." + opDexNumberStr),
                                                    itor->at("types")[0],
                                                    itor->at("types")[1],
                                                    evol,
                                                    evs,
                                                    itor->at("height"),
                                                    itor->at("weight"),
                                                    Utils::StringKeys::getStd("opmon.desc." + opDexNumberStr),
                                                    itor->at("expGiven"),
                                                    itor->at("curve"),
                                                    itor->at("captureRate"),
                                                    opDexNumber));
            Utils::Log::oplog("Loaded OpMon n°" + opDexNumberStr + " : " + listOp[opDexNumber]->getName());
        }

        //Initializating OpMon Sprites

        //I will use a "for" loop later, I don't use it now to avoid loading errors. I will use it when every sprite will be loaded.
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[1], "sprites/opmons/1-%d.png", 2);
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[2], "sprites/opmons/2-%d.png", 2);
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[4], "sprites/opmons/4-%d.png", 2);
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        opSprites.push_back(std::vector<sf::Texture>());
        Utils::ResourceLoader::loadTextureArray(opSprites[7], "sprites/opmons/7-%d.png", 2);

        //Intializing types sprites
#define LOAD_TYPE(type)                                                 \
        Utils::ResourceLoader::load(tempTx, (std::string("sprites/battle/types/") + #type + ".png").c_str()); \
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

        //Loading dialogs
        Utils::ResourceLoader::load(menuFrame, "backgrounds/menuframe.png");
        Utils::ResourceLoader::load(dialogArrow, "sprites/misc/arrDial.png");

        //Loading volume
        if(!Utils::OptionsSave::checkParam("volume")) {
            Utils::OptionsSave::addParam("volume", "100");
        }

        int volume = std::stoi(Utils::OptionsSave::getParam("volume").getValue());
        jukebox.setGlobalVolume(volume);

        std::string keyUp = Utils::OptionsSave::getParam("control.up").getValue();
        if(keyUp == "NULL") {
            Utils::OptionsSave::addParam("control.up", "Up");
            up = sf::Keyboard::Up;
        } else {
            up = Utils::KeyData::keysMap.at(keyUp);
        }
        std::string keyDown = Utils::OptionsSave::getParam("control.down").getValue();
        if(keyDown == "NULL") {
            Utils::OptionsSave::addParam("control.down", "Down");
            down = sf::Keyboard::Down;
        } else {
            down = Utils::KeyData::keysMap.at(keyDown);
        }
        std::string keyLeft = Utils::OptionsSave::getParam("control.left").getValue();
        if(keyLeft == "NULL") {
            Utils::OptionsSave::addParam("control.left", "Left");
            left = sf::Keyboard::Left;
        } else {
            left = Utils::KeyData::keysMap.at(keyLeft);
        }
        std::string keyRight = Utils::OptionsSave::getParam("control.right").getValue();
        if(keyRight == "NULL") {
            Utils::OptionsSave::addParam("control.right", "Right");
            right = sf::Keyboard::Right;
        } else {
            right = Utils::KeyData::keysMap.at(keyRight);
        }
        std::string keyTalk = Utils::OptionsSave::getParam("control.talk").getValue();
        if(keyTalk == "NULL") {
            Utils::OptionsSave::addParam("control.talk", "Space");
            talk = sf::Keyboard::Space;
        } else {
            talk = Utils::KeyData::keysMap.at(keyTalk);
        }
        std::string keyInteract = Utils::OptionsSave::getParam("control.interact").getValue();
        if(keyInteract == "NULL") {
            Utils::OptionsSave::addParam("control.interact", "Return");
            interact = sf::Keyboard::Return;
        } else {
            interact = Utils::KeyData::keysMap.at(keyInteract);
        }
    }

    UiData::~UiData() {
        for(auto spe : listOp) {
            delete(spe.second);
        }
        Utils::Log::oplog("Deleted UiData");
    }
} // namespace OpMon
