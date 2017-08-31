/*
StartScene.hpp
Author : Jlppc
File under the GPL-3.0 license
http://opmon-game.ga
*/
#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "../start/bigDefines.hxx"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../start/OpString.hpp"

class StartScene {
    public:
        sf::Sprite bg;
sf::Sprite prof;
sf::Music bgMus;

sf::String txtP1[15];
sf::String txtP0[18];
OpString strName;
int sizeOfTxt = 18;

sf::Texture textures[5];

sf::Text textDescs[4];
sf::Sprite bgName;
sf::Text nameField;

sf::String txtEnCours[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};

unsigned int line = 0, i = 0, dialog = 0, total = 0;

bool changeDialog = false;
int phase = 0;
  std::string pName;

long ancientTick = 0;
int startScene();
void initVars();
void initStrings();

int boucle0();
int boucle1();
int boucle2();

};


#endif // STARTSCENE_H
