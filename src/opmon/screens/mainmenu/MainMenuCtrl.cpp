/*
  MainMenuCtrl.cpp
  Author : BAKFR
  Contributors : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "MainMenuCtrl.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

#include "MainMenu.hpp"
#include "MainMenuData.hpp"
#include "src/opmon/core/GameData.hpp"
#include "src/opmon/screens/base/AGameScreen.hpp"
#include "src/opmon/screens/introscene/IntroSceneCtrl.hpp"
#include "src/opmon/screens/optionsmenu/OptionsMenuCtrl.hpp"
#include "src/opmon/screens/savemenu/SaveMenu.hpp"
#include "src/opmon/screens/savemenu/SaveMenuCtrl.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"
#include "src/utils/CycleCounter.hpp"

namespace OpMon {

    MainMenuCtrl::MainMenuCtrl(GameData *data)
      : data(data)
      , view(this->data) {
    }

    GameStatus MainMenuCtrl::checkEvent(sf::Event const &event) {
        if(event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
                //Activates the player's selection
            case sf::Keyboard::Return:
                switch(curPosI.getValue()) {
                case 0:
                    selectedOption = MainMenuOption::START_GAME;
                    data.getGameDataPtr()->getJukebox().playSound("push");
                    return GameStatus::NEXT;
                case 1:
                    selectedOption = MainMenuOption::GO_TO_LOAD_MENU;
                    data.getGameDataPtr()->getJukebox().playSound("push");
                    return GameStatus::NEXT_NLS;
                case 2:
                    selectedOption = MainMenuOption::GO_TO_SETTINGS_MENU;
                    data.getGameDataPtr()->getJukebox().playSound("push");
                    return GameStatus::NEXT_NLS;
                case 3:
                    data.getGameDataPtr()->getJukebox().playSound("push");
                    return GameStatus::STOP;
                }
                break;
                //Moves the cursor
            case sf::Keyboard::Up:
                curPosI--;
                data.getGameDataPtr()->getJukebox().playSound("arrow");
                break;
            case sf::Keyboard::Down:
                curPosI++;
                data.getGameDataPtr()->getJukebox().playSound("arrow");
                break;
            default:
                break;
            }
        }
        return GameStatus::CONTINUE;
    }

    GameStatus MainMenuCtrl::update(sf::RenderTexture &frame) {
        view.update(curPosI.getValue());
        frame.draw(view);
        return GameStatus::CONTINUE;
    }

    void MainMenuCtrl::loadNextScreen() {
        switch(selectedOption) {
        case MainMenuOption::START_GAME:
            _next_gs = std::make_unique<IntroSceneCtrl>(data.getGameDataPtr());
            break;
        case MainMenuOption::GO_TO_LOAD_MENU:
            _next_gs = std::make_unique<SaveMenuCtrl>(data.getGameDataPtr(), SaveMenuContext::LOADING);
            break;
        case MainMenuOption::GO_TO_SETTINGS_MENU:
            _next_gs = std::make_unique<OptionsMenuCtrl>(data.getGameDataPtr());
            break;
        default:
            throw Utils::UnexpectedValueException(std::to_string(selectedOption), "a view to load in MainMenuCtrl::selectedOptionScreen()");
        }
    }

    void MainMenuCtrl::suspend() {
        view.pause();
    }

    void MainMenuCtrl::resume() {
        view.play();
    }

} // namespace OpMon
