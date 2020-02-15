/*
  StartSceneData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/

#include "StartSceneData.hpp"

#include <memory>

#include "../core/system/ResourceLoader.hpp"
#include "src/opmon/core/Player.hpp"
#include "src/opmon/objects/Enums.hpp"
#include "src/opmon/views/objects/Position.hpp"

namespace OpMon {
class UiData;

    StartSceneData::StartSceneData(UiData *data)
        : uidata(data)
        , player(new Player()) {
        System::ResourceLoader::load(background, "backgrounds/start/startscene.png");
        System::ResourceLoader::load(prof, "sprites/chara/prof/profkiwai.png");
        System::ResourceLoader::load(nameBg, "backgrounds/start/nameEntry.png");

        //Player initalization
        player->setMapID("Player's room");
        player->getPosition().setDir(Side::TO_UP);
    }

} // namespace OpMon
