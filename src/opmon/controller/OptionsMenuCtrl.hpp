/*
OptionsMenuCtrl.hpp
Author : BAKFR
Contributors : Cyrion, Samurai413x
File under GNU GPL v3.0 license
*/
#pragma once

#include <SFML/Window/Event.hpp>
#include <string>

#include "../model/storage/OptionsMenuData.hpp"
#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "../view/OptionsMenu.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../../utils/path.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/KeyData.hpp"
#include "AGameScreen.hpp"

namespace OpMon {
    namespace Controller {

        class OptionsMenuCtrl : public AGameScreen {
          private:
            Model::OptionsMenuData data;

            View::OptionsMenu view;
            void toggleVolume();
            void raiseVolume();
            void lowerVolume();

            std::size_t currentKeyChange{0};
            bool keyChangeActive{false};

          public:
            OptionsMenuCtrl(Model::UiData *data);
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderTexture &frame) override;

            const std::vector<std::string> controlsName{{"up", "down", "left", "right", "talk", "interact"}};
            void resume();
            void suspend();
        };

    } // namespace Controller
} // namespace OpMon
