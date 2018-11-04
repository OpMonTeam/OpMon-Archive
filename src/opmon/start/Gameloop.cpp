/*
Gameloop.cpp
Author : Cyrion
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "./Gameloop.hpp"
#include "../controller/MainMenuCtrl.hpp"
#include "../model/sysObjects/Player.hpp"
#include <SFML/Window/Event.hpp>

namespace OpMon {

    GameLoop::GameLoop()
        : uidata(std::make_unique<Model::UiData>()) {
        std::unique_ptr<Controller::AGameScreen> firstCtrl = std::make_unique<Controller::MainMenuCtrl>(uidata.get());
        _gameScreens.push(std::move(firstCtrl));
    }

    GameStatus GameLoop::operator()() {

        std::unique_ptr<View::Window, std::function<void(View::Window*)>> window(new View::Window(), [](View::Window* w) {
            w->close();
        });
        window->open();

        GameStatus status{GameStatus::CONTINUE};

        while(status != GameStatus::STOP) {
            status = GameStatus::CONTINUE;

            //Gets the current game screen's controller
            auto* ctrl = _gameScreens.top().get();
            sf::Event event;

            //process all pending SFML events
            while(status == GameStatus::CONTINUE) {
                bool isEvent = window->getWindow().pollEvent(event);
                if(isEvent == false)
                    event.type = sf::Event::SensorChanged;
                status = _checkQuit(event);
                if(status == GameStatus::STOP)
                    break;
                status = ctrl->checkEvent(event);
                if(isEvent == false) {
                    break;
                }
            }

            if(status == GameStatus::CONTINUE) {
                // frame update & draw
                status = ctrl->update(window->getFrame());
            }

            switch(status) {
            case GameStatus::NEXT: //Pauses the current screen and passes to the next
                ctrl->suspend();
                _gameScreens.push(std::move(ctrl->getNextGameScreen()));
                break;
            case GameStatus::PREVIOUS: //Deletes the current screen and returns to the previous one
                _gameScreens.pop();
                _gameScreens.top()->resume();
                break;
            case GameStatus::CONTINUE:
                window->refresh();
                break;
            default:
                break;
            }
        }

        return GameStatus::STOP;
    }

    GameStatus GameLoop::_checkQuit(const sf::Event &event) {
        if(event.type == sf::Event::Closed
           || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return GameStatus::STOP;
        }

        return GameStatus::CONTINUE;
    }

} // namespace OpMon
