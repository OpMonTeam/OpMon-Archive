/*
  UiData.cpp
  Author : Cyrion
  Contributors : BAKFR, Navet56
  File under GNU GPL v3.0 license
*/
#include "UiData.hpp"
#include "../../../utils/log.hpp"
#include "../../../utils/path.hpp"
#include "../../../nlohmann/json.hpp"
#include "../objects/evolution/evolutions.hpp"
#include "../save/OptionsSave.hpp"
#include "ResourceLoader.hpp"
#include <fstream>

namespace OpMon {
    namespace Model {

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

            ResourceLoader::load(font, "fonts/Default.ttf", true);

	    std::ifstream opmonJsonFile(Utils::Path::getResourcePath() + "data/opmon.json");
	    if(!opmonJsonFile){
	      handleError("Can't open opmon data.", true);
	    }
	    nlohmann::json opmonJson;
	    opmonJsonFile >> opmonJson;

	    for(auto itor = opmonJson.begin(); itor != opmonJson.end(); ++itor){
	      int opDexNumber = itor->at("opDex");
	      std::string opDexNumberStr = std::to_string(opDexNumber);

	      Evolution* evol = nullptr;
	      if(itor->at("evolution").at("type") == "level"){
		evol = new E_Level(itor->at("evolution").at("species"), itor->at("evolution").at("level"));
	      }else if(itor->at("evolution").at("type") == "no"){
		evol = nullptr;
	      }
	      std::vector<Stats> evs;
	      for(unsigned int i = 0; i < itor->at("evs").size(); ++i){
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

	    }

	    /*nlohmann::json toWrite;

	    for(auto itor = listOp.begin(); itor != listOp.end(); ++itor){
	      Species* species = itor->second;
	      nlohmann::json cS;
	      cS["opDex"] = itor->first;
	      cS["atk"] = species->getBaseAtk();
	      cS["def"] = species->getBaseDef();
	      cS["atkSpe"] =  species->getBaseAtkSpe();
	      cS["defSpe"] = species->getBaseDefSpe();
	      cS["spe"] = species->getBaseSpe();
	      cS["HP"] = species->getBaseHP();
	      cS["types"] =  {species->getType1(), species->getType2()};
	      cS["evolution"] = {
		{"type", ((species->getEvolType() == nullptr) ? "no" : "level")},
		{"level", species->getNiveauEvolution()},
		{"species", ((species->getEvolType() == nullptr) ?  species->getEvolType()->getEvolution()->getOpdexNumber() : -1)}
	      };
	      cS["evs"] = species->getEv();
	      cS["height"] =  species->getHeight();
	      cS["weight"] = species->getWeight();
	      cS["expGiven"] = species->getExp();
	      cS["curve"] = species->getExpMax();
	      cS["captureRate"] = species->getCaptureRate();
	      toWrite.push_back(cS);

	      }

	    std::ofstream out("opmons.json");
	    out << toWrite;*/

            //Initializating OpMon Sprites
            //I will use a "for" loop later, I don't use it now to avoid loading errors. I will use it when every sprite will be loaded.
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[1], "sprites/opmons/1-%d.png", 2);
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[2], "sprites/opmons/2-%d.png", 2);
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[4], "sprites/opmons/4-%d.png", 2);
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            opSprites.push_back(std::vector<sf::Texture>());
            ResourceLoader::loadTextureArray(opSprites[7], "sprites/opmons/7-%d.png", 2);

            //Intializing types sprites
#define LOAD_TYPE(type)                                                                            \
    ResourceLoader::load(tempTx, (std::string("sprites/battle/types/") + #type + ".png").c_str()); \
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
            ResourceLoader::load(dialogBackground, "backgrounds/dialog/dialog.png");
            ResourceLoader::load(dialogArrow, "sprites/misc/arrDial.png");

            //Loading volume
            if(!OptionsSave::checkParam("volume")) {
                OptionsSave::addParam("volume", "100");
            }

            int volume = std::stoi(OptionsSave::getParam("volume").getValue());
            jukebox.setGlobalVolume(volume);


            std::string keyUp = OptionsSave::getParam("control.up").getValue();
            if(keyUp == "NULL") {
                OptionsSave::addParam("control.up", "Up");
                up = sf::Keyboard::Up;
            } else {
                up = KeyData::keysMap.at(keyUp);
            }
            std::string keyDown = OptionsSave::getParam("control.down").getValue();
            if(keyDown == "NULL") {
                OptionsSave::addParam("control.down", "Down");
                down = sf::Keyboard::Down;
            } else {
                down = KeyData::keysMap.at(keyDown);
            }
            std::string keyLeft = OptionsSave::getParam("control.left").getValue();
            if(keyLeft == "NULL") {
                OptionsSave::addParam("control.left", "Left");
                left = sf::Keyboard::Left;
            } else {
                left = KeyData::keysMap.at(keyLeft);
            }
            std::string keyRight = OptionsSave::getParam("control.right").getValue();
            if(keyRight == "NULL") {
                OptionsSave::addParam("control.right", "Right");
                right = sf::Keyboard::Right;
            } else {
                right = KeyData::keysMap.at(keyRight);
            }
            std::string keyTalk = OptionsSave::getParam("control.talk").getValue();
            if(keyTalk == "NULL") {
                OptionsSave::addParam("control.talk", "Space");
                talk = sf::Keyboard::Space;
            } else {
                talk = KeyData::keysMap.at(keyTalk);
            }
            std::string keyInteract = OptionsSave::getParam("control.interact").getValue();
            if(keyInteract == "NULL") {
                OptionsSave::addParam("control.interact", "Return");
                interact = sf::Keyboard::Return;
            } else {
                interact = KeyData::keysMap.at(keyInteract);
            }
        }

        UiData::~UiData() {
            for(auto spe : listOp) {
                delete(spe.second);
            }
            Utils::Log::oplog("Deleted UiData");
        }
    } // namespace Model
} // namespace OpMon
