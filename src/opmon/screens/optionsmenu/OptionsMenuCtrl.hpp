/*!
 * \file OptionsMenuCtrl.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \authors Samurai413x
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <iosfwd>

#include "src/opmon/core/system/path.hpp"
#include "src/utils/OptionsSave.hpp"
#include "src/opmon/screens/mainmenu/MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "src/opmon/screens/base/AGameScreen.hpp"

namespace sf {
class Event;
class RenderTexture;
}  // namespace sf

namespace OpMon {
class UiData;

    class OptionsMenuCtrl : public AGameScreen {
    private:
        OptionsMenuData data;

        OptionsMenu view;
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
        OptionsMenuCtrl(UiData *data);
        GameStatus checkEvent(sf::Event const &event) override;
        GameStatus update(sf::RenderTexture &frame) override;

        /*!
         * \brief The different names of the controls for the controls menu.
         */
        const std::vector<std::string> controlsName{{"up", "down", "left", "right", "talk", "interact"}};
        void resume();
        void suspend();
    };

} // namespace OpMon
