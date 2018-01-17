#include <src/opmon/view/Window.hpp>
#include "./MainMenuCtrl.hpp"

#include "../model/storage/Data.hpp"
#include "./StartSceneCtrl.hpp"
#include "./OptionsMenuCtrl.hpp"


namespace OpMon{
  namespace Controller{

    MainMenuCtrl::MainMenuCtrl():
      view() {
    }

    GameStatus MainMenuCtrl::checkEvent(sf::Event const& event){
      if(event.type == sf::Event::KeyPressed) {
        switch (event.key.code){
          case sf::Keyboard::Return:
            switch(view.getCursorPosition()) {
              case 0:
                _next_gs = new StartSceneCtrl();
                return GameStatus::NEXT;
              case 1:
                Model::Data::Sounds::nope.play();
                return GameStatus::CONTINUE;
              case 2:
                _next_gs = new OptionsMenuCtrl();
                return GameStatus::NEXT;
              case 3:
                return GameStatus::STOP;
            }
            break;
          case sf::Keyboard::Up:
            view.moveArrow(true);
            break;
          case sf::Keyboard::Down:
            view.moveArrow(false);
            break;
          default:
            break;
        }
      }
      return GameStatus::CONTINUE;
    }

    GameStatus MainMenuCtrl::update(){
      view.draw(OpMon::View::frame);
      return GameStatus::CONTINUE;
    }

    void MainMenuCtrl::suspend(){
      view.pause();
    }

    void MainMenuCtrl::resume(){
      view.play();
    }

  }
}
