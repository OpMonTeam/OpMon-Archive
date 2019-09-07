/*
MainMenu.hpp
Author : Cyrielle
Contributors : Navet56, BAKFR
File under GNU GPL v3.0 license
*/
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../model/storage/MainMenuData.hpp"
#include "../start/i18n/ATranslatable.hpp"

namespace OpMon::View {

    /**
         * MainMenu's view (displayed when the game starts).
         */
    class MainMenu : public I18n::ATranslatable {

      public:
        explicit MainMenu(Model::MainMenuData &data, std::size_t totalView = 4);
        ~MainMenu() override = default;

        void initStrings();
        void onLangChanged() override;

        static void pause();
        void play();

        void draw(sf::RenderTexture &frame, int curPosI);

      private:
        Model::MainMenuData &data;
        const std::size_t totalView;
        sf::Sprite bg;

        struct OptionMenu {
            sf::Text text;
            sf::Vector2f pos;
        };
        std::vector<OptionMenu> optionsVec;
        sf::Sprite cursor;
    };
} // namespace OpMon::View

#endif // MAINMENU_HPP
