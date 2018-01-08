/*
StartScene.hpp
Author : Jlppc
File under the GPL-3.0 license
http://opmon-game.ga
*/
#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../../utils/OpString.hpp"

#include "../start/Core.hpp"
#include "./Dialog.hpp"
#include "./Interface.hpp"


namespace OpMon{
  namespace View{
   
    class StartScene : public Interface {
    public:
      GameStatus operator()();

      ~StartScene();

      void play();
      void pause();
      
      void initStrings();

      void init();
      
      GameStatus loop0();
      GameStatus loop1();
      GameStatus loop2();

      Dialog* getDialog(){
	return actualDialog;
      }

      int getPart(){
	return part;
      }

      sf::String& getpName(){
	return pName;
      }

      void delLoop1();
      
    private:
      sf::Sprite bg;
      sf::Sprite prof;
      sf::Music bgMus;

      int part = 0;
      
      sf::String txtP1[15];
      sf::String txtP0[18];
      Utils::OpString strName;

      int sizeOfTxt;

      Dialog *actualDialog;
      
      sf::Texture textures[5];
  
      sf::Text textDescs[4];
      sf::Sprite bgName;
      sf::Text nameField;
  
      sf::String txtEnCours[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};
  
      sf::String pName;
  
      long ancientTick = 0;

      bool loop0init = false;
      bool loop1init = false;
      bool loop2init = false;

    };

  }
}

#endif // STARTSCENE_H
