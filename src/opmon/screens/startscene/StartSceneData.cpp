/*
  StartSceneData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/

#include "StartSceneData.hpp"

#include <memory>

#include "src/utils/ResourceLoader.hpp"
#include "src/opmon/core/Player.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/view/elements/Position.hpp"

namespace OpMon {
class GameData;

    StartSceneData::StartSceneData(GameData *data)
        : gamedata(data)
        , player(new Player()) {
        Utils::ResourceLoader::load(background, "backgrounds/start/startscene.png");
        Utils::ResourceLoader::load(prof, "sprites/chara/prof/profkiwai.png");
        Utils::ResourceLoader::load(nameBg, "backgrounds/start/nameEntry.png");

        //Player initalization
        player->setMapID("Player's room");
        player->getPosition().setDir(Side::TO_UP);
    }

} // namespace OpMon
