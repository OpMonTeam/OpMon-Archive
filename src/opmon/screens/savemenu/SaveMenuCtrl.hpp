#pragma once

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Event.hpp>

#include "SaveMenu.hpp"
#include "src/opmon/core/AGameScreen.hpp"
#include "src/opmon/core/GameData.hpp"
#include "src/opmon/core/GameStatus.hpp"
#include "src/opmon/screens/savemenu/SaveMenuData.hpp"

namespace sf {
    class Event;
    class RenderTexture;
} // namespace sf

namespace OpMon {

    class GameData;

    class SaveMenuCtrl : public AGameScreen {
      public:
        SaveMenuCtrl(GameData *data, SaveMenuContext context);

        GameStatus checkEvent(sf::Event const &event) override;

        GameStatus update(sf::RenderTexture &frame) override;

      private:
        SaveMenuData data;

        SaveMenu view;
    };

} // namespace OpMon
