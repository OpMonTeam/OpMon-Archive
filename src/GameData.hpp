/*!
 * \file GameData.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>

#include "Keyboard.hpp"
#include "OptionsSave.hpp"
#include "Translator.hpp"
#include "Species.hpp"
#include "Jukebox.hpp"
#include "Window.hpp"
#include "StringKeys.hpp"

namespace OpMon {
    class Species;

    /*!
     * \brief Contains the data needed for the game in general.
     * \details One instance of it must be created in GameLoop, and then shared as a pointer in every "Data" classes.
     */
    class GameData {
      private:
        std::vector<std::vector<sf::Texture>> opSprites;
        std::map<unsigned int, Species *> listOp;
        std::vector<std::map<int, std::string>> atkOpLvl;
        std::unordered_map<Type, sf::Texture> typesTextures;

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
        GameData();
        ~GameData();
        /*!
         * \brief Gets a texture of an OpMon.
         * \param id The identifier of the Species of the OpMon.
         * \param face If `true`, returns the face texture, if `false`, the back texture.
         */
        sf::Texture &getOpSprite(unsigned int id, bool face) { return opSprites[id][(unsigned int)face]; }
        /*!
         * \brief Gets a pointer to a Species object.
         */
        Species *getOp(unsigned int id) { return listOp.at(id); }
        /*!
         * \brief Gets the texture of a type.
         */
        sf::Texture &getTypeTexture(Type type) { return typesTextures[type]; }

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
        auto getKeyUp() const { return up; }
        /*!
         * \brief Gets the key for the "down" action.
         */
        auto getKeyDown() const { return down; }
        /*!
         * \brief Gets the key for the "left" action.
         */
        auto getKeyLeft() const { return left; }
        /*!
         * \brief Gets the key for the "right" action.
         */
        auto getKeyRight() const { return right; }
        /*!
         * \brief Gets the key for the "interact" action.
         */
        auto getKeyInteract() const { return interact; }
        /*!
         * \brief Gets the key for the "talk" action.
         */
        auto getKeyTalk() const { return talk; }

        /*!
         * \brief Gets the heigth of the window
         */
        uint32_t getWindowHeight() const { return windowHeight; }

        /*!
         * \brief Gets the width of the window
         */
        uint32_t getWindowWidth() const { return windowWidth; }

        sf::Texture &getMenuFrame() { return menuFrame; }

        /*!
         * \brief Sets the key for the "up" action.
         */
        void setKeyUp(const std::string &upName) {
            up = stringToKey(upName);
        }
        /*!
         * \brief Sets the key for the "down" action.
         */
        void setKeyDown(const std::string downName) {
            down = stringToKey(downName);
        }

        void setKeyLeft(const std::string leftName) {
            left = stringToKey(leftName);
        }
        /*!
         * \brief Sets the key for the "left" action.
         */
        void setKeyRight(const std::string rightName) {
            right = stringToKey(rightName);
        }
        /*!
         * \brief Sets the key for the "interact" action.
         */
        void setKeyInteract(const std::string interactName) {
            interact = stringToKey(interactName);
        }
        /*!
         * \brief Sets the key for the "talk" action.
         */
        void setKeyTalk(const std::string talkName) {
            talk = stringToKey(talkName);
        }

        sf::String getString(std::string key) { return Utils::I18n::Translator::getInstance().getStringKeys().get(key); }

        Utils::StringKeys &getStringKeys() { return Utils::I18n::Translator::getInstance().getStringKeys(); }

        Utils::OptionsSave &getOptions() { return *options; }

        std::vector<sf::Texture> alpha = {sf::Texture()};
    };

} // namespace OpMon
