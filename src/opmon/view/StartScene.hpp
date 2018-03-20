/*
StartScene.hpp
Author : Jlppc
File under the GPL-3.0 license
http://opmon-game.ga
Contains StartScene class
*/
#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "../../utils/OpString.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../start/Core.hpp"
#include "../start/i18n/ATranslatable.hpp"
#include "./Dialog.hpp"

namespace OpMon {
    namespace View {

        class StartScene : public I18n::ATranslatable {
          public:
            StartScene();
            ~StartScene() override;

            GameStatus operator()();
            void draw(sf::RenderTarget &frame);

            void play();
            void pause();

            void initStrings();
            void onLangChanged() override;

            Dialog *getDialog() {
                return dialog;
            }

            int getPart() {
                return part;
            }

            sf::String &getpName() {
                return pName;
            }

            void delLoop1();

          private:
            sf::Sprite bg;
            sf::Sprite prof;

            int part = 0;

            sf::String txtP1[15];
            sf::String txtP0[18];
            Utils::OpString strName;

            Dialog *dialog;

            sf::Texture textures[5];

            sf::Text textDescs[4];
            sf::Sprite bgName;
            sf::Text nameField;

            sf::String txtEnCours[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};

            sf::String pName;
        };

    } // namespace View
} // namespace OpMon

#endif // STARTSCENE_H
