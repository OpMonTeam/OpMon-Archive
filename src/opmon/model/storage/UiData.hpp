/*
  UiData.hpp
  Author : Cyrion
  Contributors : BAKFR
  File under GNU GPL v3.0 license
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

            UiData(UiData const &data);

          public:
            View::Jukebox &getJukebox() { return jukebox; }
            sf::Font const &getFont() const { return font; }
            UiData();
            ~UiData();
            sf::Texture &getOpSprite(unsigned int id, bool face) { return opSprites[id][(unsigned int)face]; }
            Species *getOp(unsigned int id) { return listOp.at(id); }
            sf::Texture &getTypeTexture(Type type) { return typesTextures[type]; }

            sf::Texture &getDialogArrow() { return dialogArrow; }
            sf::Texture &getDialogBackground() { return dialogBackground; }
            //const std::map<std::string, sf::Keyboard::Key> &getKeysMap() { return keysMap; }

            sf::Keyboard::Key getKeyUp() const { return up; }
            sf::Keyboard::Key getKeyDown() const { return down; }
            sf::Keyboard::Key getKeyLeft() const { return left; }
            sf::Keyboard::Key getKeyRight() const { return right; }
            sf::Keyboard::Key getKeyInteract() const { return interact; }
            sf::Keyboard::Key getKeyTalk() const { return talk; }

            void setKeyUp(const std::string upName) { up = KeyData::keysMap.at(upName); }
            void setKeyDown(const std::string  downName){ down = KeyData::keysMap.at(downName); }
            void setKeyLeft(const std::string  leftName) { left = KeyData::keysMap.at(leftName); }
            void setKeyRight(const std::string  rightName) { right = KeyData::keysMap.at(rightName); }
            void setKeyInteract(const std::string  interactName) { interact = KeyData::keysMap.at(interactName); }
            void setKeyTalk(const std::string  talkName) { talk = KeyData::keysMap.at(talkName); }
        };

    } // namespace Model
} // namespace OpMon
