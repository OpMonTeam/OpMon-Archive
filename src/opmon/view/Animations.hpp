/*
Animations.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contains the Animations namespace 
*/
#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace OpMon{
  namespace View{
    /**
       Contains the functions used for the major animations
    */
    namespace Animations {

      /**
	 Initialize the animations
      */
      void initAnims();
      /**
	 Delete the animations's resources
      */
      void deleteAnims();

      GameStatus animWinOpen(sf::RenderTexture &window, sf::Sprite const &bg);
      GameStatus animWinClose(sf::RenderTexture &window, sf::Sprite const &bg);

    }

  }
}
#endif // ANIMATIONS_HPP
