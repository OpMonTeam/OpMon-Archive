/*
GameMenuCtrl.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/

#include "GameMenuCtrl.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

#include "src/opmon/screens/optionsmenu/OptionsMenuCtrl.hpp"
#include "src/opmon/core/GameData.hpp"
#include "GameMenu.hpp"
#include "GameMenuData.hpp"
#include "src/opmon/screens/base/AGameScreen.hpp"
#include "src/opmon/screens/savemenu/SaveMenuCtrl.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"
#include "src/utils/CycleCounter.hpp"

namespace OpMon {
class Player;
}  // namespace OpMon

#define LOAD_OPTIONS 1

namespace OpMon {

        GameMenuCtrl::~GameMenuCtrl() {
        }

        GameMenuCtrl::GameMenuCtrl(GameMenuData &data, Player &player)
          : data(data)
          , view(data)
          , player(player) {
        }

        GameStatus GameMenuCtrl::checkEvent(sf::Event const &event) {
            switch(event.type) {
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::M) {
                    return GameStatus::PREVIOUS_NLS;
                }
                if(event.key.code == sf::Keyboard::Up) {
                    data.getGameDataPtr()->getJukebox().playSound("arrow");
                    curPos -= 2;
                }
                if(event.key.code == sf::Keyboard::Down) {
                    data.getGameDataPtr()->getJukebox().playSound("arrow");
                    curPos += 2;
                }
                if(event.key.code == sf::Keyboard::Left) {
                    data.getGameDataPtr()->getJukebox().playSound("arrow");
                    curPos--;
                }
                if(event.key.code == sf::Keyboard::Right) {
                    data.getGameDataPtr()->getJukebox().playSound("arrow");
                    curPos++;
                }
                if(event.key.code == sf::Keyboard::Return) {
                    switch(curPos.getValue()) {
                    case 0:
                        submenuToLoadNext = SubMenu::SAVE_MENU;
                        return GameStatus::NEXT_NLS;
                    case 5:
                        submenuToLoadNext = SubMenu::SETTINGS_MENU;
                        return GameStatus::NEXT_NLS;
                    default:
                        data.getGameDataPtr()->getJukebox().playSound("nope");
                        break;
                    }
                }
                view.setCurPos(curPos.getValue());
            default:
                break;
            }

            return GameStatus::CONTINUE;
        }

        GameStatus GameMenuCtrl::update(sf::RenderTexture &frame) {
            frame.draw(view);
            return GameStatus::CONTINUE;
        }

        void GameMenuCtrl::loadNextScreen() {
            switch(submenuToLoadNext) {
            case SubMenu::SAVE_MENU:
                _next_gs = std::make_unique<SaveMenuCtrl>(data.getGameDataPtr());
                break;
            case SubMenu::SETTINGS_MENU:
                _next_gs = std::make_unique<OptionsMenuCtrl>(data.getGameDataPtr());
                break;
            default:
                throw Utils::UnexpectedValueException(std::to_string(submenuToLoadNext), "a view to load in GameMenuCtrl::loadNextScreen()");
            }
        }

        void GameMenuCtrl::suspend() {
        }

        void GameMenuCtrl::resume() {
        }

} // namespace OpMon
