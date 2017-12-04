/*
MainMenu.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contient le namespace MainMenu
*/
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


namespace OpMon{
  namespace View{
    /**
       Namespace contenant les éléments du menu principal
    */
    class MainMenu : public Interface {

    public:
      void initVars();//Must be moved
      void verifVars();//Must be moved
      void deleteVars();//Must be renamed
      
      int mainMenu();//Must be moved

      void init();//Must be completed
      GameStatus operator()();//New name of boucle0 (Must rename things in the source)
      void initStrings();//Must be moved

      
    private:

      sf::Sprite bg;
      sf::Text play;
      sf::Text charge;
      sf::Text options;
      sf::Text exit;
      sf::Sprite cursor;
      sf::Vector2f curPos[4];
      sf::Music bgMusTitle;
      sf::Sound bruitArr;
      sf::Sound bruitPush;
      sf::Sound bruitNope;
      sf::Texture textures[2];
      sf::SoundBuffer sounds[3];
      int curPosI = 0;

      bool continuer = true;

    };
  }
}

#endif // MAINMENU_HPP
