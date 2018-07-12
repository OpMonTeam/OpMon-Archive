#include "StartSceneData.hpp"
#include "ResourceLoader.hpp"

namespace OpMon {
  namespace Model {

    StartSceneData::StartSceneData(UiData* data)
      : uidata(data), player(new Player()) {
      ResourceLoader::load(background, "backgrounds/start/startscene.png");
      ResourceLoader::load(prof, "sprites/chara/prof/profkiwai.png");
      ResourceLoader::load(nameBg, "backgrounds/start/nameEntry.png");

      //Player initalization
      player->setMapID("Player's room");
      player->getPosition().setDir(Side::TO_UP);
    }
    
  }
}
