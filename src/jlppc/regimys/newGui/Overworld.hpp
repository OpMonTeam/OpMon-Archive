/*
Overworld.hpp
Auteur : Jlppc
Fichier sous license GPL-3.0
http://opmon-game.ga
Contient le namespace Overworld
*/
#ifndef OVERWORLD_HPP
#define OVERWORLD_HPP
#include "MainFrame.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace MainFrame {
/**
Contient les éléments fonctionnels de l'overworld
*/
namespace Overworld {
void initVars();
int overworld();
int boucle();

void up();
void down();
void right();
void left();


extern Plan *actuel;
extern sf::Sprite personnage;
extern sf::View camera;
extern sf::Sprite* plans[3];
extern sf::Music* music;


}
}

#endif // OVERWORLD_HPP
