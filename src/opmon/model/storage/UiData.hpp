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
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <vector>

namespace OpMon {
    namespace Model {

        class UiData {
          private:
            std::vector<std::vector<sf::Texture>> opSprites;
            std::map<unsigned int, Species *> listOp;
            std::vector<std::map<int, std::string>> atkOpLvl;
            std::map<Type, sf::Texture> typesTextures;

            sf::Texture dialogArrow;
            sf::Texture dialogBackground;

            View::Jukebox jukebox;
            sf::Font font;

            //Loading controls compile time
#define ADDMAP(key) {(#key), sf::Keyboard::key}
            const std::map<std::string, sf::Keyboard::Key> keysMap = {
                ADDMAP(Unknown),
                ADDMAP(A), ADDMAP(Z), ADDMAP(E), ADDMAP(R), ADDMAP(T),
                ADDMAP(Y), ADDMAP(U), ADDMAP(I), ADDMAP(O), ADDMAP(P),
                ADDMAP(Q), ADDMAP(S), ADDMAP(D), ADDMAP(F), ADDMAP(G),
                ADDMAP(H), ADDMAP(J), ADDMAP(K), ADDMAP(L), ADDMAP(M),
                ADDMAP(W), ADDMAP(X), ADDMAP(C), ADDMAP(V), ADDMAP(B),
                ADDMAP(N),
                ADDMAP(Num1), ADDMAP(Num2), ADDMAP(Num3), ADDMAP(Num4), ADDMAP(Num5),
                ADDMAP(Num6), ADDMAP(Num7), ADDMAP(Num8), ADDMAP(Num9), ADDMAP(Num0),
                ADDMAP(LControl), ADDMAP(RControl), ADDMAP(LShift), ADDMAP(RShift), ADDMAP(LAlt),
                ADDMAP(RAlt), ADDMAP(Space), ADDMAP(Return), ADDMAP(BackSpace), ADDMAP(Tab),
                ADDMAP(Up), ADDMAP(Left), ADDMAP(Right), ADDMAP(Down),
                ADDMAP(Numpad1), ADDMAP(Numpad2), ADDMAP(Numpad3), ADDMAP(Numpad4), ADDMAP(Numpad5),
                ADDMAP(Numpad6), ADDMAP(Numpad7), ADDMAP(Numpad8), ADDMAP(Numpad9), ADDMAP(Numpad0)
            };
#undef ADDMAP

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
            const std::map<std::string, sf::Keyboard::Key> &getKeysMap() { return keysMap; }

            sf::Keyboard::Key getKeyUp() const { return up; }
            sf::Keyboard::Key getKeyDown() const { return down; }
            sf::Keyboard::Key getKeyLeft() const { return left; }
            sf::Keyboard::Key getKeyRight() const { return right; }
            sf::Keyboard::Key getKeyInteract() const { return interact; }
            sf::Keyboard::Key getKeyTalk() const { return talk; }

            void setKeyUp(const std::string upName) { up = keysMap.at(upName); }
            void setKeyDown(const std::string  downName){ down = keysMap.at(downName); }
            void setKeyLeft(const std::string  leftName) { left = keysMap.at(leftName); }
            void setKeyRight(const std::string  rightName) { right = keysMap.at(rightName); }
            void setKeyInteract(const std::string  interactName) { interact = keysMap.at(interactName); }
            void setKeyTalk(const std::string  talkName) { talk = keysMap.at(talkName); }
        };

    } // namespace Model
} // namespace OpMon
