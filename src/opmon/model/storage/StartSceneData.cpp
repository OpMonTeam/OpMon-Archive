#include "StartSceneData.hpp"

namespace OpMon {
  namespace Model {

    StartSceneData::StartSceneData(UiData* data)
      : uidata(data){
      ResourceLoader::load(background, "backgrounds/start/startscene.png");
      ResourceLoader::load(prof, "sprites/chara/prof/profkiwai.png");
      ResourceLoader::load(nameBg, "backgrounds/start/nameEntry.png");
    }
    
  }
}
