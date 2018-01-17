#ifndef STARTSCENECTRL_HPP
#define STARTSCENECTRL_HPP

#include <SFML/Window.hpp>
#include "../start/Core.hpp"
#include "../view/StartScene.hpp"
#include "AGameScreen.hpp"


namespace OpMon{
  namespace Controller{

    class StartSceneCtrl : public AGameScreen{
    protected:
      View::StartScene view;
    public:
      StartSceneCtrl();
      GameStatus checkEvent(sf::Event const& event) override;
      GameStatus update() override;
      void suspend() override;
      void resume() override;
    };

  }
}

#endif
