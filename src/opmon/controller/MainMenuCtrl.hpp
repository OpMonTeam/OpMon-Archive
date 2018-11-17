/*
MainMenuCtrl.hpp
Author : BAKFR
Contributor : Cyrion
File under GNU GPL v3.0
*/
#pragma once

#include <SFML/Window/Event.hpp>

#include "../model/storage/MainMenuData.hpp"
#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "AGameScreen.hpp"
#include "../helper/MenuHelper.hpp"

namespace OpMon {
    namespace Controller {
        class MainMenuCtrl : public AGameScreen {
          private:
            Model::MainMenuData data;
            View::MainMenu view;

			int loadNext = 0;
            int curPosI{0};

          public:
            MainMenuCtrl(Model::UiData *data);

            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderTexture &frame) override;

			void loadNextScreen() override;

            void suspend() override;
            void resume() override;
        };

    } // namespace Controller
} // namespace OpMon
