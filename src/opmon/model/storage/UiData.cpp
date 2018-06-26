#include "UiData.hpp"

namespace OpMon {
  namespace Model {

    UiData::UiData(){
      jukebox.addMusic("Title", "audio/music/title.ogg", 50);
      jukebox.addMusic("Start", "audio/music/intro.ogg");
      jukebox.addMusic("Fauxbourg", "audio/music/faubourgeuvi.ogg");
      jukebox.addMusic("Route 14", "audio/music/route14.ogg");
      //jukebox.addMusic("OpCenter", "audio/music/opcenter.ogg");
      jukebox.addMusic("Ms", "audio/music/mysterioucity.ogg");
      jukebox.addMusic("Labo", "audio/music/labo.ogg");
      jukebox.addMusic("Wild Battle", "audio/music/wildbattle.ogg");

      ResourceLoader::load(font, "fonts/Default.ttf", true);
    }
  }
}
