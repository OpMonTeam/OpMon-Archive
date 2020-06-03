/*!
 * \file GameData.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <ext/alloc_traits.h>
#include <map>

#include "../view/ui/Jukebox.hpp"
#include "../view/ui/Window.hpp"
#include "src/utils/KeyData.hpp"
#include "src/utils/OptionsSave.hpp"
#include "src/utils/i18n/Translator.hpp"

namespace OpMon {
    class Species;

    /*!
     * \brief Contains the data needed for the game in general.
     * \details One instance of it must be created in GameLoop, and then shared as a pointer in every "Data" classes.
     */
    class GameData {
      private:
        sf::Texture dialogArrow;
        sf::Texture dialogBackground;

        Ui::Jukebox jukebox;
        sf::Font font;

        sf::Keyboard::Key up;
        sf::Keyboard::Key down;
        sf::Keyboard::Key left;
        sf::Keyboard::Key right;
        sf::Keyboard::Key interact;
        sf::Keyboard::Key talk;

        uint32_t windowHeight = 540;
        uint32_t windowWidth = 960;

        sf::Texture menuFrame;

        Utils::OptionsSave *options;

        /*!
         * \brief The copy constructor. Must not be used.
         */
        GameData(GameData const &data) = delete;

      public:
        /*!
         * \brief Gets a reference to the Jukebox object.
         */
        Ui::Jukebox &getJukebox() { return jukebox; }
        /*!
         * \brief Gets a reference to the game's font.
         */
        sf::Font const &getFont() const { return font; }
        GameData(Ui::Window &win);
        ~GameData();


        /*!
         * \brief Gets the texture of the dialog arrow.
         */
        sf::Texture &getDialogArrow() { return dialogArrow; }
        /*!
         * \brief Gets the background texture of the dialog box.
         */
        sf::Texture &getDialogBackground() { return dialogBackground; }

        /*!
         * \brief Gets the key for the "up" action.
         */
        sf::Keyboard::Key getKeyUp() const { return up; }
        /*!
         * \brief Gets the key for the "down" action.
         */
        sf::Keyboard::Key getKeyDown() const { return down; }
        /*!
         * \brief Gets the key for the "left" action.
         */
        sf::Keyboard::Key getKeyLeft() const { return left; }
        /*!
         * \brief Gets the key for the "right" action.
         */
        sf::Keyboard::Key getKeyRight() const { return right; }
        /*!
         * \brief Gets the key for the "interact" action.
         */
        sf::Keyboard::Key getKeyInteract() const { return interact; }
        /*!
         * \brief Gets the key for the "talk" action.
         */
        sf::Keyboard::Key getKeyTalk() const { return talk; }

        /*!
         * \brief Gets the heigth of the window
         */
        uint32_t getWindowHeight() const { return windowHeight; }

        /*!
         * \brief Gets the width of the window
         */
        uint32_t getWindowWidth() const { return windowWidth; }

        /*!
         * \brief Gets the size of the window
         */
        template <typename T>
        sf::Vector2<T> getWindowSize() const {
            return sf::Vector2<T>(windowWidth, windowHeight);
        }

        sf::Texture &getMenuFrame() { return menuFrame; }

        /*!
         * \brief Sets the key for the "up" action.
         */
        void setKeyUp(const std::string upName) {
            up = Utils::KeyData::keysMap.at(upName);
        }
        /*!
         * \brief Sets the key for the "down" action.
         */
        void setKeyDown(const std::string downName) {
            down = Utils::KeyData::keysMap.at(downName);
        }
        void setKeyLeft(const std::string leftName) {
            left = Utils::KeyData::keysMap.at(leftName);
        }
        /*!
         * \brief Sets the key for the "left" action.
         */
        void setKeyRight(const std::string rightName) {
            right = Utils::KeyData::keysMap.at(rightName);
        }
        /*!
         * \brief Sets the key for the "interact" action.
         */
        void setKeyInteract(const std::string interactName) {
            interact = Utils::KeyData::keysMap.at(interactName);
        }
        /*!
         * \brief Sets the key for the "talk" action.
         */
        void setKeyTalk(const std::string talkName) {
            talk = Utils::KeyData::keysMap.at(talkName);
        }

        /*!
         * \brief Converts pixels to map coords.
         */
        sf::Vector2f mapPixelToCoords(sf::Vector2i in) {
            return window.getFrame().mapPixelToCoords(in);
        }

        sf::String getString(std::string key) {
            return Utils::I18n::Translator::getInstance().getStringKeys().get(
                key);
        }

        Utils::StringKeys &getStringKeys() {
            return Utils::I18n::Translator::getInstance().getStringKeys();
        }

        Utils::OptionsSave &getOptions() { return *options; }

        std::vector<sf::Texture> alpha = {sf::Texture()};

        Ui::Window &window;
    };

} // namespace OpMon
