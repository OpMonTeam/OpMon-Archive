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
void verifVars();
int overworld();
void deleteVars();
int boucle();
void up();
void down();
void left();
void right();
extern Plan *actuel;
extern sf::Sprite personnage;
extern Vector2f ppPos;
extern Vector2f mapPos;
extern sf::Music fond;
}
}

#endif // OVERWORLD_HPP
