
#pragma once

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "AGameScreen.hpp"


namespace OpMon {
  namespace Controller {

    class MainMenuCtrl : public AGameScreen {
    private:
      View::MainMenu view;
    public:
      MainMenuCtrl();

      virtual GameStatus checkEvent(sf::Event &event);

      virtual GameStatus update();
    };

  }
}
