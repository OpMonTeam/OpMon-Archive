/*
  GameData.cpp
  Author : Cyrielle
  Contributors : BAKFR, Navet56
  File under GNU GPL v3.0 license
 */
#include "GameData.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <utility>

#include "../../nlohmann/json.hpp"
#include "../../utils/OpString.hpp"
#include "../../utils/log.hpp"
#include "Jukebox.hpp"
#include "path.hpp"
#include "src/utils/KeyData.hpp"
#include "src/utils/OptionsSave.hpp"
#include "src/utils/ResourceLoader.hpp"
#include "src/utils/i18n/Translator.hpp"

namespace OpMon {
    class Evolution;

    GameData::GameData(Ui::Window &win): window(win) {
        Utils::Log::oplog("Loading options");

        options =
            new Utils::OptionsSave(Path::getSavePath() + "/optSave.oparams");
        if(!options->checkParam("lang")) { // If the "lang" setting don't exist
            options->addParam("lang", "eng");
        }

        // Initializaing keys
        Utils::Log::oplog("Loading strings");
        std::string lang = options->getParam("lang").getValue();
        auto &tr = Utils::I18n::Translator::getInstance();
        tr.setAvailableLanguages({{"en", "keys/english.rkeys"},
                                  {"es", "keys/espanol.rkeys"},
                                  {"fr", "keys/francais.rkeys"},
                                  {"it", "keys/italian.rkeys"},
                                  {"de", "keys/deutsch.rkeys"}});

        if(!tr.getAvailableLanguages().count(lang)) {
            lang = "en"; // The lang isn't available. Default to english.
        }
        tr.setLang(lang);

        Utils::Log::oplog("Initializating GameData");

        // Loading musics and sounds
        for(std::filesystem::directory_entry const &file :
            std::filesystem::directory_iterator(Path::getResourcePath() +
                                                "data/resourcelist")) {
            if(file.is_regular_file()) {
                Utils::Log::oplog("Found resource list file " +
                                  file.path().generic_string());
                std::ifstream resourcelistFile(file.path());
                if(!resourcelistFile) {
                    throw Utils::LoadingException(file.path().generic_string(),
                                                  true);
                }
                nlohmann::json listJson;
                resourcelistFile >> listJson;
                for(auto itor = listJson.at("musics").begin();
                    itor != listJson.at("musics").end(); ++itor) {
                    jukebox.addMusic(itor->at("id"), itor->at("path"));
                }
                for(auto itor = listJson.at("sounds").begin();
                    itor != listJson.at("sounds").end(); ++itor) {
                    jukebox.addSound(itor->at("id"), itor->at("path"));
                }
            }
        }

        Utils::ResourceLoader::load(font, "fonts/Default.ttf", true);

        // Loading dialogs
        Utils::ResourceLoader::load(menuFrame, "backgrounds/menuframe.png");
        Utils::ResourceLoader::load(dialogArrow, "sprites/misc/arrDial.png");

        // Loading volume
        if(!options->checkParam("volume")) {
            options->addParam("volume", "100");
        }

        int volume = std::stoi(options->getParam("volume").getValue());
        jukebox.setGlobalVolume(volume);

        std::string keyUp = options->getParam("control.up").getValue();
        if(keyUp == "NULL") {
            options->addParam("control.up", "Up");
            up = sf::Keyboard::Up;
        } else {
            up = Utils::KeyData::keysMap.at(keyUp);
        }
        std::string keyDown = options->getParam("control.down").getValue();
        if(keyDown == "NULL") {
            options->addParam("control.down", "Down");
            down = sf::Keyboard::Down;
        } else {
            down = Utils::KeyData::keysMap.at(keyDown);
        }
        std::string keyLeft = options->getParam("control.left").getValue();
        if(keyLeft == "NULL") {
            options->addParam("control.left", "Left");
            left = sf::Keyboard::Left;
        } else {
            left = Utils::KeyData::keysMap.at(keyLeft);
        }
        std::string keyRight = options->getParam("control.right").getValue();
        if(keyRight == "NULL") {
            options->addParam("control.right", "Right");
            right = sf::Keyboard::Right;
        } else {
            right = Utils::KeyData::keysMap.at(keyRight);
        }
        std::string keyTalk = options->getParam("control.talk").getValue();
        if(keyTalk == "NULL") {
            options->addParam("control.talk", "Space");
            talk = sf::Keyboard::Space;
        } else {
            talk = Utils::KeyData::keysMap.at(keyTalk);
        }
        std::string keyInteract =
            options->getParam("control.interact").getValue();
        if(keyInteract == "NULL") {
            options->addParam("control.interact", "Return");
            interact = sf::Keyboard::Return;
        } else {
            interact = Utils::KeyData::keysMap.at(keyInteract);
        }
    }

    GameData::~GameData() {
        delete(options);
        Utils::Log::oplog("Deleted GameData");
    }
} // namespace OpMon
