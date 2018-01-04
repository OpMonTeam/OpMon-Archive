#ifndef STARTSCENECTRL_HPP
#define STARTSCENECTRL_HPP

#include <SFML/Window.hpp>
#include "../start/Core.hpp"
#include "../view/StartScene.hpp"


namespace OpMon{
  namespace Controller{
    namespace StartSceneCtrl{
      GameStatus checkEvents(sf::Event& event, OpMon::View::StartScene& startscene);
    }
  }
}

#endif
