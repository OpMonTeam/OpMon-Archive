/*
Gameloop.cpp
Author : Cyriel
Contributor : BAKFR, PyroFlareX
File under GNU GPL v3.0 license
*/
#include "./Gameloop.hpp"
#include "../../utils/StringKeys.hpp"
#include "../controller/MainMenuCtrl.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../model/sysObjects/Player.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

namespace OpMon {

    GameLoop::GameLoop()
      : uidata(std::make_unique<Model::UiData>()) {
        std::unique_ptr<Controller::AGameScreen> firstCtrl = std::make_unique<Controller::MainMenuCtrl>(uidata.get());
        _gameScreens.push(std::move(firstCtrl));
    }

    GameStatus GameLoop::runLoop() {

        std::unique_ptr<View::Window, std::function<void(View::Window *)>> window(new View::Window(), [](View::Window *w) {
            w->close();
        });

        window->open();

        sf::Texture loadTx;
        Model::ResourceLoader::load(loadTx, "backgrounds/loading.png");
        sf::Text loadingTxt;
        loadingTxt.setString(Utils::StringKeys::get("load.txt"));
        loadingTxt.setPosition(250, 440);
        sf::Sprite loadSpr;
        loadSpr.setTexture(loadTx);
        loadingTxt.setFont(uidata->getFont());
        loadingTxt.setCharacterSize(35);

        window->getFrame().draw(loadSpr);
        window->getFrame().draw(loadingTxt);
        window->refresh();

        GameStatus status{GameStatus::CONTINUE};

        while(status != GameStatus::STOP) {
            status = GameStatus::CONTINUE;

            //Gets the current game screen's controller
            auto *ctrl = _gameScreens.top().get();

            sf::Event event;

            //process all pending SFML events
            while(status == GameStatus::CONTINUE) {
                bool isEvent = window->getWindow().pollEvent(event);

                window->handleEvent(&event);

                if(isEvent == false)
                    event.type = sf::Event::SensorChanged;
                status = CheckforClose(event);
                if(status == GameStatus::STOP)
                    break;
                status = ctrl->checkEvent(event);
                if(isEvent == false) {
                    break;
                }
}

	        if(status == GameStatus::WIN_REBOOT){
    		window->reboot();
	    	status = GameStatus::CONTINUE;
	        }
	    
            if(status == GameStatus::CONTINUE) {
                // frame update & draw
                status = ctrl->update(window->getFrame());
            }

            if(status == GameStatus::NEXT || status == GameStatus::PREVIOUS || status == GameStatus::NEXT_NLS || status == GameStatus::PREVIOUS_NLS) {
                if(status == GameStatus::NEXT) {
                    window->getFrame().draw(loadSpr);
                    window->getFrame().draw(loadingTxt);
                    window->refresh();
                } else {
                    status = ((status == GameStatus::NEXT_NLS) ? GameStatus::NEXT : GameStatus::PREVIOUS);
                }
                if(status == GameStatus::NEXT) {
                    ctrl->loadNextScreen();
                }
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

    GameStatus GameLoop::CheckforClose(sf::Event &event) {
        //process all pending SFML events
        if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {;
            return GameStatus::STOP;
        }

        return GameStatus::CONTINUE;
    }

} // namespace OpMon
