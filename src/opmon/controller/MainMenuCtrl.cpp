/*
MainMenuCtrl.cpp
Author : BAKFR
Contributors : Cyrion
File under GNU GPL v3.0 license
*/
#include "./MainMenuCtrl.hpp"
#include "../view/Window.hpp"

#include "./OptionsMenuCtrl.hpp"
#include "./StartSceneCtrl.hpp"

//Defines created to make the code easier to read
#define LOAD_STARTSCENE 1
#define LOAD_OPTIONS 2

namespace OpMon {
    namespace Controller {

        MainMenuCtrl::MainMenuCtrl(Model::UiData *data)
          : data(data)
          , view(this->data) {
        }

        GameStatus MainMenuCtrl::checkEvent(sf::Event const &event) {
            if(event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    //Activates the player's selection
                case sf::Keyboard::Return:
                    switch(curPosI) {
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
                        return GameStatus::NEXT;
                    case 3:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        return GameStatus::STOP;
                    }
                    break;
                    //Moves the cursor
                case sf::Keyboard::Up:
                    Helper::moveArrow(true, curPosI);
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                    break;
                case sf::Keyboard::Down:
                    Helper::moveArrow(false, curPosI);
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                    break;
                }
            }
            return GameStatus::CONTINUE;
        }

        GameStatus MainMenuCtrl::update(sf::RenderTexture &frame) {
            view.draw(frame, curPosI);
            return GameStatus::CONTINUE;
        }

		void MainMenuCtrl::loadNextScreen(){
			switch(loadNext){
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

    } // namespace Controller
} // namespace OpMon
