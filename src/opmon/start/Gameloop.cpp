
#include "./Gameloop.hpp"
#include "../controller/MainMenuCtrl.hpp"
#include "../model/storage/Data.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../view/Window.hpp"
#include <SFML/Window/Event.hpp>

namespace OpMon {

    GameLoop::GameLoop()
      : frames(0) {
    }

    GameLoop::~GameLoop() {
        while(!_gameScreens.empty()) {
            delete(_gameScreens.top());
            _gameScreens.pop();
        }
    }

    int *GameLoop::getFrames() {
        return &this->frames;
    }

    GameStatus GameLoop::operator()() {

        // TODO: add first item outside of the Gameloop.
        Controller::AGameScreen *first_ctrl = new Controller::MainMenuCtrl();

        _gameScreens.push(first_ctrl);

        GameStatus status = GameStatus::CONTINUE;
        Model::Data::player.getPosition().setPosition(1, 4);
        while(status != GameStatus::STOP) {
            status = GameStatus::CONTINUE;

            frames++;

            auto ctrl = _gameScreens.top();
            sf::Event event;

            //process all pending SFML events
            while(status == GameStatus::CONTINUE) {
                bool isEvent = View::window.pollEvent(event);
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
                status = ctrl->update();
            }

            switch(status) {
            case GameStatus::NEXT:
                ctrl->suspend();
                _gameScreens.push(ctrl->getNextGameScreen());
                break;
            case GameStatus::PREVIOUS:
                delete(ctrl);
                _gameScreens.pop();
                _gameScreens.top()->resume();
            case GameStatus::CONTINUE:
                View::frame.display();
                View::winRefresh();
            default:
                break;
            }
        }

        return GameStatus::STOP;
    }

    GameStatus GameLoop::_checkQuit(const sf::Event &event) {
        switch(event.type) {
        case sf::Event::Closed:
            return GameStatus::STOP;
        default:
            break;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return GameStatus::STOP;
        }

        return GameStatus::CONTINUE;
    }

} // namespace OpMon
