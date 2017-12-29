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

#include "Interface.hpp"

namespace OpMon{
  namespace View{

    class Overworld : public Interface{
    public:

      sf::View& getCamera(){
	return camera;
      }
  

      sf::Sprite& getCharacter(){
	return character;
      }

      Model::Map* getCurrent(){
	return current;
      }
  
      GameStatus operator()(bool dialog, int frame);

	  /**Undefined method because this must not be used*/
      GameStatus operator()();
      
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

      virtual ~Overworld();

      virtual void play();
      virtual void pause();

      void setMusic(std::string const& path);
      
      static std::vector<sf::String> actualDialog;

      
      
    private:

      void init();
      
      sf::View camera;
      sf::Sprite character;
      Model::Map* current = nullptr;
      
      sf::Music *music = nullptr;
      std::string musicPath = "";

      std::map<std::vector::iterator, sf::Sprite> eventsSprites;
      
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

    };

  }
}

#endif // OVERWORLD_HPP
