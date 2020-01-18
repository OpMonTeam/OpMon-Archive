/*!
 * \file MainMenu.hpp
 * \authors Cyrielle
 * \authors Navet56
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 */
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../model/storage/MainMenuData.hpp"
#include "../start/i18n/ATranslatable.hpp"

namespace OpMon {
    namespace View {

        /*!
         * \brief The view printing the main menu showing at the start of the game.
         */
        class MainMenu : public I18n::ATranslatable {

          public:
            MainMenu(Model::MainMenuData &data);
            ~MainMenu() override = default;

            /*!
             * \brief Loads the strings used in the menu.
             */
            void initMainMenuItemsName();
          
            void onLangChanged() override;

            /*!
             * \brief Pauses the screen.
             */
            void pause();
            /*!
             * \brief Unpauses the screen.
             */
            void play();

            /*!
             * \brief Updates and draws the screen.
             */
            void draw(sf::RenderTexture &frame, int curPosI);

          private:
            Model::MainMenuData &data;
            const std::size_t totalView;
            /*!
             * \brief The background of the menu.
             */
            sf::Sprite background;

            /*!
             * \brief Stucture representing an option in the menu.
             */
            struct OptionMenu {
                sf::Text text;
                sf::Vector2f pos;
            };
            /*!
             * \brief Contains the different options of the main menu.
             */
            std::vector<OptionMenu> mainMenuItems;
            sf::Sprite cursor;
        };
    } // namespace View
} // namespace OpMon

#endif // MAINMENU_HPP
