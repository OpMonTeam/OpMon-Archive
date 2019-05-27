/*
StartSceneCtrl.hpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef STARTSCENECTRL_HPP
#define STARTSCENECTRL_HPP

#include "../model/storage/StartSceneData.hpp"
#include "../start/Core.hpp"
#include "../view/StartScene.hpp"
#include "AGameScreen.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace OpMon {
    namespace Controller {

        class StartSceneCtrl : public AGameScreen {
          protected:
            Model::StartSceneData data;

            View::StartScene view;
            bool animNext = false;

            int loadNext = 0;

            sf::Texture screenTexture;

          public:
            StartSceneCtrl(Model::UiData *data);
            GameStatus checkEvent(sf::Event const &event) override;
            GameStatus update(sf::RenderWindow &frame) override;

            void loadNextScreen() override;
            void suspend() override;
            void resume() override;
        };

    } // namespace Controller
} // namespace OpMon

#endif
