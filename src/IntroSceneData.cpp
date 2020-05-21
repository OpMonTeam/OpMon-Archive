/*
  IntroSceneData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/

#include "IntroSceneData.hpp"

#include <memory>

#include "ResourceLoader.hpp"
#include "Player.hpp"
#include "Enums.hpp"
#include "Position.hpp"

namespace OpMon {
class GameData;

    IntroSceneData::IntroSceneData(GameData *data)
        : gamedata(data)
        , player(new Player()) {
        Utils::ResourceLoader::load(background, "backgrounds/start/introscene.png");
        Utils::ResourceLoader::load(prof, "sprites/chara/prof/profkiwai.png");
        Utils::ResourceLoader::load(nameBg, "backgrounds/start/nameEntry.png");

        //Player initalization
        player->setMapID("Player's room");
        player->getPosition().setDir(Side::TO_UP);
    }

} // namespace OpMon
