#pragma once

#include "SaveMenu.hpp"
#include "src/opmon/screens/base/AGameScreen.hpp"

namespace sf {
    class Event;
    class RenderTexture;
} // namespace sf

namespace OpMon {

    class GameData;

    class SaveMenuCtrl : public AGameScreen {
      public:
        SaveMenuCtrl(GameData *data);

        GameStatus checkEvent(sf::Event const &event) override;

        GameStatus update(sf::RenderTexture &frame) override;

      private:
        SaveMenuData data;

        SaveMenu view;
    };

} // namespace OpMon
