/*
OptionsMenuCtrl.hpp
Author : BAKFR
Contributors : Cyrielle, Samurai413x
File under GNU GPL v3.0 license
*/
#pragma once

#include <SFML/Window/Event.hpp>
#include <string>

#include "../../utils/defines.hpp"
#include "../../utils/path.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/KeyData.hpp"
#include "../model/storage/OptionsMenuData.hpp"
#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "../view/OptionsMenu.hpp"
#include "AGameScreen.hpp"

namespace OpMon::Controller {

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
        explicit OptionsMenuCtrl(Model::UiData *data);
        GameStatus checkEvent(sf::Event const &event) override;
        GameStatus update(sf::RenderTexture &frame) override;

        const std::vector<std::string> controlsName{{"up", "down", "left", "right", "talk", "interact"}};
        void resume() override;
        void suspend() override;
    };

} // namespace OpMon::Controller
