/*
  IntroSceneData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/

#include "IntroSceneData.hpp"

#include <memory>

#include "src/opmon/model/Player.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/view/elements/Position.hpp"
#include "src/utils/ResourceLoader.hpp"

namespace OpMon {
    class GameData;

    IntroSceneData::IntroSceneData(GameData *data)
        : gamedata(data), player(new Player()) {
        Utils::ResourceLoader::load(background,
                                    "backgrounds/start/introscene.png");
        Utils::ResourceLoader::load(prof, "sprites/chara/prof/profkiwai.png");
        Utils::ResourceLoader::load(nameBg, "backgrounds/start/nameEntry.png");
    }

} // namespace OpMon
