/**
GameMenuCtrl.hpp
Author : Cyriel
File under GNU GPL v3.0 license
*/
#pragma once

#include "../../utils/CycleCounter.hpp"
#include "../model/storage/GameMenuData.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../view/GameMenu.hpp"
#include "AGameScreen.hpp"

namespace OpMon {
    namespace Controller {

        class GameMenuCtrl : public AGameScreen {
          private:
            Model::GameMenuData &data;

            View::GameMenu view;
            Model::Player &player;

            int loadNext = 0;

            Utils::CycleCounter curPos = Utils::CycleCounter(6);

          public:
            ~GameMenuCtrl();

            GameMenuCtrl(Model::GameMenuData &data, Model::Player &player);

            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderWindow &frame) override;

            virtual void loadNextScreen();
            virtual void suspend();
            virtual void resume();
        };

    } // namespace Controller
} // namespace OpMon
