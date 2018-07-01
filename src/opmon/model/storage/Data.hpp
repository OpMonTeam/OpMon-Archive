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
#include <list>
#include <map>
#include <vector>

namespace OpMon {
    namespace Model {

        class Species;
        class Map;
        class Player;

        namespace Data {


            namespace OpMons {
                
            } // namespace OpMons

            namespace World {
                extern sf::Texture tileset;
            } // namespace World

            namespace Battle {

            } // namespace Battle

            namespace Elements {

            } // namespace Elements

            namespace Ui {
	      //extern std::vector<sf::Music *> townMusics;

	      //extern sf::Texture backPP; //Not init yet

                extern 
                //Battle
                //extern sf::Texture bActButtons[4];
                //extern sf::Texture bHpBar;
                //extern sf::Texture bHpBg;
                //extern std::vector<sf::Texture> battleBackgrounds;

                //extern std::vector<sf::Texture> charaFront;

                //std::string backgrounds[];
            } // namespace Ui

            namespace Sounds {
            } // namespace Sounds

            namespace Animations {
                extern sf::Texture fen[6];
            }

            namespace Controls {
            } // namespace Controls
        }     // namespace Data
    }         // namespace Model
} // namespace OpMon

#endif
