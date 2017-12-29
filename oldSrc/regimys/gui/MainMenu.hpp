/*
MainMenu.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contient le namespace MainMenu
*/
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
Namespace contenant les éléments du menu principal
*/
class MainMenu {

public:

    sf::Sprite bg;
    sf::Text play;
    sf::Text charge;
    sf::Text options;
    sf::Text exit;
    sf::Sprite cursor;
    sf::Vector2f curPos[4];
    sf::Music bgMusTitle;
    sf::Sound bruitArr;
    sf::Sound bruitPush;
    sf::Sound bruitNope;
    sf::Texture textures[2];
    sf::SoundBuffer sounds[3];
    int curPosI = 0;

    bool continuer = true;


    void initVars();
    void verifVars();
    void deleteVars();
    int mainMenu();
    int boucle0();
    void initStrings();
};


#endif // MAINMENU_HPP
