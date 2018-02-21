/**
  Data.hpp :
  Author : Jlppc
  File under the GPL-3.0 license
  http://opmon-game.ga
  Contains the global variables used in the program.
*/
#ifndef DATA_HPP
#define DATA_HPP

#include "../../../utils/defines.hpp"
#include "../objects/Enums.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <map>
#include <vector>

namespace OpMon {
    namespace Model {

        class Species;
        class Map;
        class Player;

        namespace Data {

            extern Player player;

            namespace OpMons {
                extern std::map<unsigned int, Species> listOp;
                extern std::vector<std::map<int, std::string>> atkOpLvl;
                OP_DEPRECATED extern std::vector<std::vector<Stats>> evs;
            } // namespace OpMons

            namespace World {
                extern std::map<std::string, Map *> maps;
                extern sf::Texture tileset;
            } // namespace World

            namespace Elements {
                extern std::map<std::string, sf::Vector2f> elementsPos;
                extern std::map<std::string, int> elementsCounter;
                extern std::map<std::string, std::vector<sf::Texture>> elementsTextures;
                extern std::map<std::string, sf::Sprite> elementsSprites;
            } // namespace Elements

            namespace Ui {
                extern std::vector<sf::Music *> townMusics;
                extern sf::Texture texturePP[4];
                extern sf::Texture walkingPP[4];
                extern sf::Texture walkingPP2[4];
                extern sf::Texture backPP; //Not init yet

                extern std::map<std::string, std::vector<sf::Texture>> charaTextures;

                //Battle
                extern sf::Texture bActButtons[4];
                extern sf::Texture bHpBar;
                extern sf::Texture bHpBg;
                extern std::vector<sf::Texture> battleBackgrounds;

                extern std::vector<sf::Texture> charaFront;

                extern std::vector<std::vector<sf::Texture>> doorsTextures;
                extern sf::SoundBuffer doorSoundBuffer;
                extern sf::SoundBuffer shopDoorSoundBuffer;
                //std::string backgrounds[];
                extern sf::Font font;
            } // namespace Ui

            namespace Sounds {
                extern sf::SoundBuffer nope;
                extern sf::SoundBuffer arrow;
                extern sf::SoundBuffer dialogPass;
                extern sf::SoundBuffer push;
            } // namespace Sounds

            namespace Animations {
                extern sf::Texture fen[6];
            }

            namespace Controls {
                extern sf::Keyboard::Key up;
                extern sf::Keyboard::Key down;
                extern sf::Keyboard::Key left;
                extern sf::Keyboard::Key right;
                extern sf::Keyboard::Key interact;
                extern sf::Keyboard::Key talk;
            } // namespace Controls
        }     // namespace Data
    }         // namespace Model
} // namespace OpMon

#endif
