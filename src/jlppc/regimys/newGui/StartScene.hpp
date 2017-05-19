/*
StartScene.hpp
Auteur : Jlppc
Fichier sous license GPL-3.0
http://opmon-game.ga
Contient le namespace StartScene
*/
#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "../start/bigDefines.hxx"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace MainFrame {
/**Fait se dérouler la scène de début*/
namespace StartScene {
int startScene();
void initVars();
void destroyVars();

extern sf::Sprite fondT;
extern sf::Sprite profT;
extern sf::Sprite arrDial;
extern sf::Music fondMus;
}
}


#endif // STARTSCENE_H
