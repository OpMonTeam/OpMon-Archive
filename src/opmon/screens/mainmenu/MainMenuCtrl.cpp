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

#include "OptionsMenuCtrl.hpp"
#include "StartSceneCtrl.hpp"
#include "src/opmon/core/Core.hpp"
#include "src/opmon/core/UiData.hpp"
#include "src/opmon/screens/MainMenu.hpp"
#include "src/opmon/screens/MainMenuData.hpp"
#include "src/opmon/screens/base/AGameScreen.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"
#include "src/utils/CycleCounter.hpp"

//Defines created to make the code easier to read
#define LOAD_STARTSCENE 1
#define LOAD_OPTIONS 2

namespace OpMon {

    MainMenuCtrl::MainMenuCtrl(UiData *data)
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
                    loadNext = LOAD_STARTSCENE;
                    data.getUiDataPtr()->getJukebox().playSound("push");
                    return GameStatus::NEXT;
                case 1:
                    data.getUiDataPtr()->getJukebox().playSound("nope");
                    return GameStatus::CONTINUE;
                case 2:
                    loadNext = LOAD_OPTIONS;
                    data.getUiDataPtr()->getJukebox().playSound("push");
                    return GameStatus::NEXT_NLS;
                case 3:
                    data.getUiDataPtr()->getJukebox().playSound("push");
                    return GameStatus::STOP;
                }
                break;
                //Moves the cursor
            case sf::Keyboard::Up:
                curPosI--;
                data.getUiDataPtr()->getJukebox().playSound("arrow");
                break;
            case sf::Keyboard::Down:
                curPosI++;
                data.getUiDataPtr()->getJukebox().playSound("arrow");
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
        switch(loadNext) {
        case LOAD_STARTSCENE:
            _next_gs = std::make_unique<StartSceneCtrl>(data.getUiDataPtr());
            break;
        case LOAD_OPTIONS:
            _next_gs = std::make_unique<OptionsMenuCtrl>(data.getUiDataPtr());
            break;
        default:
            handleError("Error : Unknown view to load in MainMenuCtrl.", true);
        }
    }

    void MainMenuCtrl::suspend() {
        view.pause();
    }

    void MainMenuCtrl::resume() {
        view.play();
    }

} // namespace OpMon
