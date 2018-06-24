#include "MainMenuData.hpp"

namespace OpMon {
  namespace Model {
    MainMenuData::MainMenuData(UiData* ptr)
      : uidata(ptr){
      ResourceLoader::load(titlescreen, "backgrounds/titlescreen.png");
      ResourceLoader::load(arrChoice, "sprites/misc/arrChoice.png");
    }
  }
}
