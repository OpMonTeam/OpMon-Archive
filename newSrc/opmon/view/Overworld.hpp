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


namespace Main{
  extern Player player;
}

/**
Contient les Ã©lÃ©ments fonctionnels de l'overworld
*/
class Overworld {
public:

  sf::View& getCamera(){
    return camera;
  }
    sf::Sprite *maps[3];

    std::string fps;
    int fpsCounter;
    sf::Text fpsPrint;
    int oldTicksFps;

    int &ppPosX = Main::player.getPosX();
    int &ppPosY = Main::player.getPosY();

    bool justTp = false;
    int tpCount = 0;

  Side anim = Side::NO_MOVE;
  Side moving = Side::NO_MOVE;
    bool anims = false;

    int ancientTick = 0;

    int frames = 0;
    int startFrames = 0;
    int animsCounter = 0;

    bool movementLock = false;

    bool scrollock[2] = {false, false};

    bool scrolling = true;

    bool debugMode = false;
    bool printlayer[3] = {true, true, true};

  sf::Sprite& getCharacter(){
    return character;
  }
  
    void initVars();
    GameStatus overworld();
    int boucle();
    int boucleDialog(std::vector<sf::String> const& dialogs);

  GameStatus operator()(bool dialog);

  void move(Side direction);
  bool checkPass(Side direction);
  
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
  
private:
  sf::View camera;
  sf::Sprite character;
  Map* actual;
  sf::Music *music;
  MapLayer *layer1;
  MapLayer *layer2;
  MapLayer *layer3;
};

#endif // OVERWORLD_HPP
