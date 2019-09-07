/**
GameMenuCtrl.hpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#pragma once

#include "../../utils/CycleCounter.hpp"
#include "../model/storage/GameMenuData.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../view/GameMenu.hpp"
#include "AGameScreen.hpp"

namespace OpMon::Controller {

    class GameMenuCtrl : public AGameScreen {
      private:
        Model::GameMenuData &data;

        View::GameMenu view;
        Model::Player &player;

        int loadNext = 0;

        Utils::CycleCounter curPos = Utils::CycleCounter(6);

      public:
        ~GameMenuCtrl() override;

        GameMenuCtrl(Model::GameMenuData &data, Model::Player &player);

        GameStatus checkEvent(sf::Event const &event) override;
        GameStatus update(sf::RenderTexture &frame) override;

        void loadNextScreen() override;
        void suspend() override;
        void resume() override;
    };

} // namespace OpMon::Controller
