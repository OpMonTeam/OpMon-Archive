
#pragma once

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/MainMenu.hpp"
#include "../view/OptionsMenu.hpp"
#include "AGameScreen.hpp"


namespace OpMon{
  namespace Controller{

    class OptionsMenuCtrl : public AGameScreen{
    private:
      View::OptionsMenu view;
    public:
      OptionsMenuCtrl();
      virtual GameStatus checkEvent(sf::Event& event);
      virtual GameStatus update();
    };

  }
}
