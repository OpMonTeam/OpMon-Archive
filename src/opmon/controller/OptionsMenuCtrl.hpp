
#pragma once

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "../view/OptionsMenu.hpp"
#include "AGameScreen.hpp"
#include "../model/storage/OptionsMenuData.hpp"

namespace OpMon {
    namespace Controller {

        class OptionsMenuCtrl : public AGameScreen {
          private:
	  Model::OptionsMenuData data;

            View::OptionsMenu view;
            void toggleVolume();
            void raiseVolume();
            void lowerVolume();

	  
          public:
            OptionsMenuCtrl(Model::UiData* data);
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderTexture& frame) override;

            void resume();
            void suspend();
        };

    } // namespace Controller
} // namespace OpMon
