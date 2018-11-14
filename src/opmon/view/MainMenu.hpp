/*
MainMenu.hpp
Author : Cyrion
Contributors : Navet56, BAKFR
File under GNU GPL v3.0 license
*/
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../model/storage/MainMenuData.hpp"
#include "../start/i18n/ATranslatable.hpp"

namespace OpMon {
    namespace View {

        /**
         * MainMenu's view (displayed when the game starts).
         */
        class MainMenu : public I18n::ATranslatable {

          public:
            MainMenu(Model::MainMenuData &data);
            ~MainMenu() override = default;

            void initStrings();
            void onLangChanged() override;

            void pause();
            void play();

            void draw(sf::RenderTexture &frame, int curPosI);

          private:
            sf::Sprite bg;
            sf::Text playtx;
            sf::Text charge;
            sf::Text options;
            sf::Text exit;
            sf::Vector2f curPos[4];
            sf::Sprite cursor;
            Model::MainMenuData &data;
        };
    } // namespace View
} // namespace OpMon

#endif // MAINMENU_HPP
