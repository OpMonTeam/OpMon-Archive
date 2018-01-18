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

#include "../start/GameStatus.hpp"

namespace OpMon{
  namespace View{
    /**
       Contains the functions used for the major animations
    */
    namespace Animations {

      class Animation {
      protected:
	int counter = 0;
	sf::Sprite anim;
	sf::Sprite bgSpr;
	sf::Texture bgTxt;
      public:
	Animation(sf::Texture bgTxt);
	virtual GameStatus operator()() = 0;
      };

      class WinAnim : public Animation {
      private:
	int frames = 5;
	/*
	  If true : Open | If false : Close
	*/
	bool order;
      public:
	WinAnim(sf::Texture bgTxt, bool order);
	GameStatus operator()();
      };

      
      /*
      
      /**
	 Initialize the animations
      *
      void initAnims();
      /**
	 Delete the animations's resources
      *
      void deleteAnims();

      GameStatus animWinOpen(sf::RenderTexture &window, sf::Sprite const &bg);
      GameStatus animWinClose(sf::RenderTexture &window, sf::Sprite const &bg);

      */

    }

  }
}
#endif // ANIMATIONS_HPP
