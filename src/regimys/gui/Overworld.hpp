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
#define CASES * 32
#define CASE_SIZE 32

/**
Contient les Ã©lÃ©ments fonctionnels de l'overworld
*/
class Overworld {
public:

    Map *actual;
    sf::View camera;
    sf::Sprite *maps[3];
    sf::Music *music;

    std::string fps;
    int fpsCounter;
    sf::Text fpsPrint;
    int oldTicksFps;

    sf::Sprite *layer1;
    sf::Sprite *layer2;
    sf::Sprite *layer3;

    int &ppPosX = Main::player.getPosX();
    int &ppPosY = Main::player.getPosY();

    bool justTp = false;
    int tpCount = 0;

    int anim = -1;
    int moving = -1;
    bool anims = false;

    int ancientTick = 0;

    int frames = 0;
    int startFrames = 0;
    int animsCounter = 0;

    bool movementLock = false;

    bool scrollock[2] = {false, false};
    int ppDir = Side::TO_DOWN;

    bool scrolling = true;

    bool debugMode = false;
    bool printlayer[3] = {true, true, true};

    sf::Sprite &character = Main::player.getSprite();

    void initVars();
    int overworld();
    int boucle();
    int boucleDialog(std::vector<sf::String> const& dialogs);

  void move(int direction);
  bool checkPass(int direction);
  
    OP_DEPRECATED void up();
    OP_DEPRECATED void down();
    OP_DEPRECATED void right();
    OP_DEPRECATED void left();

    int tp(int toTp, sf::Vector2i pos, bool scroll = true);



};

#endif // OVERWORLD_HPP
