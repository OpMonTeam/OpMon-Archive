/*
OptionsMenu.hpp
Auteur : Jlppc
Fichier sous license GPL-3.0
http://opmon-game.ga
Contient le namespace OptionsMenu
*/
#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include <iostream>
#include "MainFrame.hpp"
#include "MainMenu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Elements.hpp"

namespace MainFrame{
namespace MainMenu{
/**
Namespace contenant les éléments du menu des options
*/
namespace OptionsMenu{

    extern sf::Sprite fondOpt;
    //extern SDL_Rect curseurOpt;
    //extern SDL_Rect curseurSnd;
    extern sf::Text langFr;
    extern sf::Text langEng;
    extern sf::Text langEsp;
    extern sf::Text txtRetour;
    extern sf::Text txtOptions;
    extern sf::Text txtOpt1;
    extern sf::Text txtOpt2;
    extern sf::Text txtOpt3;
    extern sf::Text txtOpt4;
    extern sf::Text txtOpt5;
    extern sf::Sprite rectSurb;

    extern sf::Text txtLang;
    extern sf::Sprite fondLangues;
    //extern sf::Text listeLangues[3];
    extern sf::Vector2f curPosLang[4];

    int optionsMenu();
    void initVars();
    void verifVars();
    void deleteVars();
    int boucle();
    int boucleLang();

}
}
}

#endif // OPTIONSMENU_HPP
