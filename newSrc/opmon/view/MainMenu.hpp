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
      MainMenu();
      void verifVars();
      void del();
      
      void init();

      GameStatus operator()();
      void initStrings();

      
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
