/*
StartSceneCtrl.hpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef STARTSCENECTRL_HPP
#define STARTSCENECTRL_HPP

#include "../model/storage/StartSceneData.hpp"
#include "../start/Core.hpp"
#include "../view/StartScene.hpp"
#include "AGameScreen.hpp"
#include <SFML/Window.hpp>
#include <memory>

namespace OpMon::Controller {

    class StartSceneCtrl : public AGameScreen {
      protected:
        Model::StartSceneData data;

        View::StartScene view;
        bool animNext = false;

        int loadNext = 0;

        sf::Texture screenTexture;

      public:
        explicit StartSceneCtrl(Model::UiData *data);
        GameStatus checkEvent(sf::Event const &event) override;
        GameStatus update(sf::RenderTexture &frame) override;

        void loadNextScreen() override;
        void suspend() override;
        void resume() override;
    };

} // namespace OpMon::Controller

#endif
