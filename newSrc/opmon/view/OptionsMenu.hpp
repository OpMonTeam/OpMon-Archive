/*
OptionsMenu.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contient le namespace OptionsMenu
*/
#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Elements.hpp"

/**
Namespace contenant les éléments du menu des options
*/
class OptionsMenu {
public:
    sf::Sprite bgCredits;
    sf::Sprite bgOpt;
    sf::Text langFr;
    sf::Text langEng;
    sf::Text langEsp;
    sf::Text txtRetour;
    sf::Text txtOptions;
    sf::Text txtCre1;
    sf::Text txtCre2;
    sf::Text txtCre3;
    sf::Text txtCre4;
    sf::Text txtCre5;
    sf::Text txtCre6;
    sf::Text txtCre7;
    sf::Text txtCre8;
    sf::Text txtCre9;
    sf::Text txtOpt1;
    sf::Text txtOpt2;
    sf::Text txtOpt3;
    sf::Text txtOpt4;
    sf::Text txtOpt5;
    sf::Sprite rectSurb;
    sf::Vector2f curPosOpt[6] = {};
    sf::Vector2f curSizeOpt[6];
    int optionSelect = -1;
    int curPosOptI = 0;
    int curPosLangI = 0;

    sf::Text txtLang;
    sf::Text txtCred;
    sf::Sprite bgLangues;
//J_Texture listeLangues[3] = {};
    sf::Vector2f curPosLang[4] = {};
    sf::Vector2f curSizeLang[4];
    sf::Texture textures2[5];
    sf::Sprite coche;

    bool continuer = true;


    int optionsMenu();
    void initVars();
    void verifVars();
    void deleteVars();
    int boucle();
    int boucleLang();
    int boucleCredits();
    void initStrings();

};

#endif // OPTIONSMENU_HPP
