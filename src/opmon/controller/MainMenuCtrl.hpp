
#pragma once

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "AGameScreen.hpp"
#include "../model/storage/MainMenuData.hpp"


namespace OpMon {
    namespace Controller {
	
        class MainMenuCtrl : public AGameScreen {
          private:
            View::MainMenu view;
	    Model::MainMenuData data;
          public:
	    MainMenuCtrl(Model::UiData* data);
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderTexture& frame) override;
            void suspend() override;
            void resume() override;
        };

    } // namespace Controller
} // namespace OpMon
