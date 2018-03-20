/*
MainMenu.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contains MainMenu namespace
*/
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../start/i18n/ATranslatable.hpp"

namespace OpMon {
    namespace View {

        /**
     * View of the main menu (displayed when the game starts).
     */
        class MainMenu : public I18n::ATranslatable {

          public:
            MainMenu();
            ~MainMenu() override;

            void initStrings();
            void onLangChanged() override;

            /**
       * Move the cursor to select another menu entry.
       * @param `true` moves the cursor up; `false` moves it down.
       */
            void moveArrow(bool direction);

            void pause();
            void play();

            void draw(sf::RenderTexture &frame);

            int getCursorPosition() {
                return curPosI;
            }

          private:
            sf::Sprite bg;
            sf::Text playtx;
            sf::Text charge;
            sf::Text options;
            sf::Text exit;
            sf::Sprite cursor;
            sf::Vector2f curPos[4];
            sf::Sound bruitArr;
            sf::Sound bruitPush;
            sf::Texture textures[2];
            sf::SoundBuffer sounds[3];
            int curPosI = 0;
        };
    } // namespace View
} // namespace OpMon

#endif // MAINMENU_HPP
