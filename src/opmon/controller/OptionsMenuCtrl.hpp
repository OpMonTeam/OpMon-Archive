/*!
 * \file OptionsMenuCtrl.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \authors Samurai413x
 * \copyright GNU GPL v3.0
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

namespace OpMon {
    namespace Controller {

        class OptionsMenuCtrl : public AGameScreen {
          private:
            Model::OptionsMenuData data;

            View::OptionsMenu view;
            void toggleVolume();
            void raiseVolume();
            void lowerVolume();

            /*!
             * \brief The currently selected key to change in the controls menu.
             */
            std::size_t currentKeyChange{0};
            /*!
             * \brief If the controls edition mode is on or off.
             */
            bool keyChangeActive{false};

          public:
            OptionsMenuCtrl(Model::UiData *data);
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderTexture &frame) override;

            /*!
             * \brief The different names of the controls for the controls menu.
             */
            const std::vector<std::string> controlsName{{"up", "down", "left", "right", "talk", "interact"}};
            void resume();
            void suspend();
        };

    } // namespace Controller
} // namespace OpMon
