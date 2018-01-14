#include "./MainMenuCtrl.hpp"

#include "../view/Overworld.hpp"
#include "../view/StartScene.hpp"
#include "../view/OptionsMenu.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"
#include "../../utils/defines.hpp"


namespace OpMon {
  namespace Controller {

    MainMenuCtrl::MainMenuCtrl() :
            view() {
    }

    GameStatus MainMenuCtrl::checkEvent(sf::Event &event) {
      auto &menu = view;

      switch (event.type) {
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Return) {
            switch (menu.getCursorPosition()) {
              case 0:

                menu.setNextInterface(new View::StartScene());
                return GameStatus::NEXT;
              case 3:
                return GameStatus::STOP;
              case 2:
                menu.setNextInterface(new View::OptionsMenu());
                return GameStatus::NEXT;
                break;
              case 1:
                Model::Data::Sounds::nope.play();
                return GameStatus::CONTINUE;
            }
          } else if (event.key.code == sf::Keyboard::Up) {
            menu.moveArrow(true);
          } else if (event.key.code == sf::Keyboard::Down) {
            menu.moveArrow(false);
          }
          break;
        default:
          break;
      }
      return GameStatus::CONTINUE;
    }

    GameStatus MainMenuCtrl::update() {
      return view();
    }

  }
}
