/*
Gameloop.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Gameloop.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <functional>
#include <utility>

#include "AGameScreen.hpp"
#include "Window.hpp"
#include "src/opmon/core/GameData.hpp"
#include "src/opmon/core/GameStatus.hpp"
#include "src/utils/ResourceLoader.hpp"
#include "src/utils/exceptions.hpp"
// Only include of another folder of the game by core
// Used to determine the first screen to launch
#include "src/opmon/screens/mainmenu/MainMenuCtrl.hpp"
#include "src/utils/log.hpp"

namespace OpMon {

    GameLoop::GameLoop() {}

    GameStatus GameLoop::operator()() {
        std::unique_ptr<Window, std::function<void(Window *)>> window(
            new Window(), [](Window *w) {
                w->close();
            });
        gamedata = new GameData(*window);
        window->open(gamedata->getOptions());
        std::unique_ptr<AGameScreen> firstCtrl =
            std::make_unique<MainMenuCtrl>(gamedata);
        _gameScreens.push(std::move(firstCtrl));

        sf::Texture loadTx;
        Utils::ResourceLoader::load(loadTx, "backgrounds/loading.png");
        sf::Text loadingTxt;
        loadingTxt.setString(gamedata->getString("load.txt"));
        loadingTxt.setPosition(250, 440);
        loadingTxt.setFont(gamedata->getFont());
        loadingTxt.setCharacterSize(35);

        window->getFrame().clear(sf::Color(74, 81, 148));
        window->getFrame().draw(loadingTxt);
        window->refresh();

        GameStatus status {GameStatus::CONTINUE};

        while(status != GameStatus::STOP && status != GameStatus::REBOOT) {
            try {
                status = GameStatus::CONTINUE;

                // Debug frame by frame
                while(
                    sf::Keyboard::isKeyPressed(sf::Keyboard::F2) &&
                    !(sf::Keyboard::isKeyPressed(fbfType) && hasBeenReleased)) {
                    if(!sf::Keyboard::isKeyPressed(fbfType)) {
                        hasBeenReleased = true;
                    }
                }
                hasBeenReleased = false;

                // Gets the current game screen's controller
                auto *ctrl = _gameScreens.top().get();
                sf::Event event;

                // process all pending SFML events
                while(status == GameStatus::CONTINUE) {
                    bool isEvent = window->getWindow().pollEvent(event);
                    if(isEvent == false)
                        event.type = sf::Event::SensorChanged;
                    _checkWindowResize(event, *window);
                    status = _checkQuit(event);
                    if(status == GameStatus::STOP ||
                       status == GameStatus::REBOOT)
                        break;
                    status = ctrl->checkEvent(event);
                    if(isEvent == false) {
                        break;
                    }
                }

                if(status == GameStatus::WIN_REBOOT) {
                    window->reboot(gamedata->getOptions());
                    status = GameStatus::CONTINUE;
                }

                if(status == GameStatus::CONTINUE) {
                    // frame update & draw
                    status = ctrl->update(window->getFrame());
                }

                if(status == GameStatus::NEXT ||
                   status == GameStatus::PREVIOUS ||
                   status == GameStatus::NEXT_NLS ||
                   status == GameStatus::PREVIOUS_NLS) {
                    if(status == GameStatus::NEXT) {
                        window->getFrame().clear(sf::Color(74, 81, 148));
                        window->getFrame().draw(loadingTxt);
                        window->refresh();
                    } else {
                        status = ((status == GameStatus::NEXT_NLS) ?
                                      GameStatus::NEXT :
                                      GameStatus::PREVIOUS);
                    }
                    if(status == GameStatus::NEXT) {
                        ctrl->loadNextScreen();
                    }
                }

                switch(status) {
                    case GameStatus::NEXT: // Pauses the current screen and
                                           // passes to the next
                        ctrl->suspend();
                        _gameScreens.push(ctrl->getNextGameScreen());
                        break;
                    case GameStatus::PREVIOUS: // Deletes the current screen and
                                               // returns to the previous one
                        _gameScreens.pop();
                        _gameScreens.top()->resume();
                        break;
                    case GameStatus::CONTINUE:
                        window->refresh();
                        break;
                    default:
                        break;
                }
            } catch(Utils::Exception &e) {
                frameskips++;
                Utils::Log::oplog(e.desc(), true);
                if(e.fatal || frameskips >= 100) {
                    Utils::Log::oplog(e.fatal ?
                                          "Fatal error, closing game." :
                                          "Too much frame skips, closing game.",
                                      true);
                    throw;
                } else {
                    Utils::Log::warn("Skipping one frame (Exception caught)");
                }
            }
        }

        delete(gamedata);
        delete(window.release());
        return status;
    }

    GameStatus GameLoop::_checkQuit(const sf::Event &event) {
        if(event.type == sf::Event::Closed ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return GameStatus::STOP;
        }

        return GameStatus::CONTINUE;
    }

    void GameLoop::_checkWindowResize(const sf::Event &event,
                                      Window &window) const {
        if(event.type == sf::Event::Resized) {
            window.updateView();
        }
    }

} // namespace OpMon
