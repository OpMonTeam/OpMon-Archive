#include "./MainMenuCtrl.hpp"
#include "../view/Window.hpp"

#include "./OptionsMenuCtrl.hpp"
#include "./StartSceneCtrl.hpp"

namespace OpMon {
    namespace Controller {

      MainMenuCtrl::MainMenuCtrl(Model::UiData* data)
          : data(data), view(this->data) {

        }

        GameStatus MainMenuCtrl::checkEvent(sf::Event const &event) {
            if(event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                case sf::Keyboard::Return:
                    switch(view.getCursorPosition()) {
                    case 0:
		      _next_gs = new StartSceneCtrl(data.getUiDataPtr());
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        return GameStatus::NEXT;
                    case 1:
		      data.getUiDataPtr()->getJukebox().playSound("nope");
                        return GameStatus::CONTINUE;
                    case 2:
		      _next_gs = new OptionsMenuCtrl(data.getUiDataPtr());
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        return GameStatus::NEXT;
                    case 3:
                        data.getUiDataPtr()->getJukebox().playSound("push");
                        return GameStatus::STOP;
                    }
                    break;
                case sf::Keyboard::Up:
                    view.moveArrow(true);
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                    break;
                case sf::Keyboard::Down:
                    view.moveArrow(false);
                    data.getUiDataPtr()->getJukebox().playSound("arrow");
                    break;

                default:
                    break;
                }
            }
            return GameStatus::CONTINUE;
        }

      GameStatus MainMenuCtrl::update(sf::RenderTexture& frame) {
            view.draw(frame);
            return GameStatus::CONTINUE;
        }

        void MainMenuCtrl::suspend() {
            view.pause();
        }

        void MainMenuCtrl::resume() {
            view.play();
        }

    } // namespace Controller
} // namespace OpMon
