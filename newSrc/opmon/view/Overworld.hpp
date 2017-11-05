/*
  Overworld.hpp
  Author : Jlppc
  File under the license GPL-3.0
  http://opmon-game.ga
  Contient le namespace Overworld
*/
#ifndef OVERWORLD_HPP
#define OVERWORLD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../start/main.hpp"
#include "Elements.hpp"
#include "../playercore/Player.hpp"
#define SQUARES_SIZE 32
#define SQUARES * SQUARES_SIZE

namespace OpMon{
  namespace View{

    class Overworld {
    public:

      sf::View& getCamera(){
	return camera;
      }
  

      sf::Sprite& getCharacter(){
	return character;
      }
  
      GameStatus operator()(bool dialog, int frame);
  
      void tp(std::string toTp, sf::Vector2i pos);

      sf::Music* getMusic(){
	return music;
      }

      MapLayer* getMapLayer(int number){
	switch(number){
	case 1:
	  return layer1:
	case 2:
	  return layer2;
	case 3:
	  return layer3;
	default:
	  return nullptr;
	}
      }

      Dialog* getDialog(){
	return dialog;
      }

      void moveCamera(Side dir);

      bool printlayer[3] = {true, true, true};

      bool justTp = false;

      bool isLaunched(){
	return launched;
      }

      void del();

      static std::vector<sf::String> actualDialog;
      
    private:
      sf::View camera;
      sf::Sprite character;
      Map* current = nullptr;
      sf::Music *music = nullptr;
      MapLayer *layer1 = nullptr;
      MapLayer *layer2 = nullptr;
      MapLayer *layer3 = nullptr;
      sf::Vector2f posArrow;
      Dialog* dialog = nullptr;
      //Indicate the frame of the walking animation that must be used.
      bool anims = false;

      std::string fps;
      int fpsCounter;
      sf::Text fpsPrint;
      int oldTicksFps;
      
      int tpCount = 0;
      
      int startFrames = 0;
      int animsCounter = 0;

      bool movementLock = false;

      bool scrolling = true;

      bool debugMode = false;

      bool launched = false;
    };

  }
}

#endif // OVERWORLD_HPP
