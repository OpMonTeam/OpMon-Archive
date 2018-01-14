/*
  Overworld.hpp
  Author : Jlppc
  File under the license GPL-3.0
  http://opmon-game.ga
  Contains Overworld namespace
*/
#ifndef OVERWORLD_HPP
#define OVERWORLD_HPP

#include "Elements.hpp"
#include "Interface.hpp"
#include "Dialog.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../model/sysObjects/Map.hpp"
#include "../model/objects/Enums.hpp"

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
  
      GameStatus operator()(int frame);

	  /**Undefined method because this must not be used*/
      GameStatus operator()();
      
      void tp(std::string toTp, sf::Vector2i pos);
      
      sf::Music* getMusic(){
	return music;
      }

      MapLayer* getMapLayer(int number){
	switch(number){
	case 1:
	  return layer1;
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

      void moveCamera(Model::Side dir);

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

			/**
			 * Events can call this method to start a new dialog with the player.
			 */
			void startDialog(std::vector<sf::String> const& dialogs);
      
      
    private:

      void init();
      
      sf::View camera;
      sf::Sprite character;
      Model::Map* current = nullptr;
      
      sf::Music *music = nullptr;
      std::string musicPath = "";

      std::map<std::vector<sf::Sprite>::iterator, sf::Sprite> eventsSprites;
      
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
