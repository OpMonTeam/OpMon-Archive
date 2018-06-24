#ifndef STARTSCENECTRL_HPP
#define STARTSCENECTRL_HPP

#include "../start/Core.hpp"
#include "../view/StartScene.hpp"
#include "AGameScreen.hpp"
#include <SFML/Window.hpp>

namespace OpMon {
    namespace Controller {

        class StartSceneCtrl : public AGameScreen {
          protected:
            View::StartScene view;
	  bool animNext = false;
	  
          public:
            StartSceneCtrl();
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderTexture& frame) override;
            void suspend() override;
	  void resume() override;
        };

    } // namespace Controller
} // namespace OpMon

#endif
