/*!
 * \file UiData.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
*/
#pragma once

#include "../../../utils/defines.hpp"
#include "../../view/Jukebox.hpp"
#include "../../view/Window.hpp"
#include "../objects/Enums.hpp"
#include "../objects/Species.hpp"
#include "KeyData.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <unordered_map>
#include <vector>

namespace OpMon {
    namespace Model {

        /*!
         * \brief Contains the data needed for the user interface and the game in general.
         * \details One instance of it must be created in GameLoop, and then shared as a pointer in every "Data" classes.
         */
        class UiData {
          private:
            std::vector<std::vector<sf::Texture>> opSprites;
            std::map<unsigned int, Species *> listOp;
            std::vector<std::map<int, std::string>> atkOpLvl;
            std::unordered_map<Type, sf::Texture> typesTextures;

            sf::Texture dialogArrow;
            sf::Texture dialogBackground;

            View::Jukebox jukebox;
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

            /*!
             * \brief The copy constructor. Not defined, must not be used.
             */
            UiData(UiData const &data);

          public:
            /*!
             * \brief Gets a reference to the Jukebox object.
             */
            View::Jukebox &getJukebox() { return jukebox; }
            /*!
             * \brief Gets a reference to the game's font.
             */
            sf::Font const &getFont() const { return font; }
            UiData();
            ~UiData();
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

            sf::Texture &getMenuFrame() { return menuFrame; }

            /*!
             * \brief Sets the key for the "up" action.
             */
            void setKeyUp(const std::string upName) { up = KeyData::keysMap.at(upName); }
            /*!
             * \brief Sets the key for the "down" action.
             */
            void setKeyDown(const std::string downName) { down = KeyData::keysMap.at(downName); }
            void setKeyLeft(const std::string leftName) { left = KeyData::keysMap.at(leftName); }
            /*!
             * \brief Sets the key for the "left" action.
             */
            void setKeyRight(const std::string rightName) { right = KeyData::keysMap.at(rightName); }
            /*!
             * \brief Sets the key for the "interact" action.
             */
            void setKeyInteract(const std::string interactName) { interact = KeyData::keysMap.at(interactName); }
            /*!
             * \brief Sets the key for the "talk" action.
             */
            void setKeyTalk(const std::string talkName) { talk = KeyData::keysMap.at(talkName); }
        };

    } // namespace Model
} // namespace OpMon
