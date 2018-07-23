#include "OptionsMenuData.hpp"
#include "ResourceLoader.hpp"

namespace OpMon {
    namespace Model {
        OptionsMenuData::OptionsMenuData(UiData *data)
          : uidata(data) {
            Model::ResourceLoader::load(background, "backgrounds/options.png");
            Model::ResourceLoader::load(selectBar, "sprites/misc/selectBar.png");
            Model::ResourceLoader::load(langBg, "backgrounds/lang.png");
            Model::ResourceLoader::load(yesTx, "sprites/misc/yes.png");
            Model::ResourceLoader::load(creditsBg, "backgrounds/credits.png");
        }
    } // namespace Model
} // namespace OpMon
