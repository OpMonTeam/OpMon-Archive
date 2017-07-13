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
#define CASES * 32
#define CASE_SIZE 32

namespace MainFrame {
/**
Contient les éléments fonctionnels de l'overworld
*/
namespace Overworld {
void initVars();
int overworld();
int boucle();
int boucleDialog(std::vector<sf::String> dialogs);

void up();
void down();
void right();
void left();

int tp(int toTp, sf::Vector2i pos, bool scroll = true);

extern Map *actual;
extern sf::Sprite &character;
extern sf::View camera;
extern sf::Sprite* maps[3];
extern sf::Music* music;
extern int ppDir;


}
}

#endif // OVERWORLD_HPP
