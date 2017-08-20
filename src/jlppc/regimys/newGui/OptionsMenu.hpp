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
#include "MainFrame.hpp"
#include "MainMenu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Elements.hpp"

namespace MainFrame {
    namespace MainMenu {
        /**
        Namespace contenant les éléments du menu des options
        */
        namespace OptionsMenu {

            extern sf::Sprite bgOpt;
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
            extern sf::Text txtCre5;
            extern sf::Text txtCre1;
            extern sf::Text txtCre2;
            extern sf::Text txtCre3;
            extern sf::Text txtCre4;
            extern sf::Text txtCre6;
            extern sf::Text txtCre7;
            extern sf::Text txtCre8;
            extern sf::Text txtCre9;
            extern sf::Sprite rectSurb;

            extern sf::Text txtLang;
            extern sf::Sprite bgLangues;
            //extern sf::Text listeLangues[3];
            extern sf::Vector2f curPosLang[4];

            extern sf::Sprite bgCredits;
            extern sf::Text txtCred;

            int optionsMenu();
            void initVars();
            void verifVars();
            void deleteVars();
            int boucle();
            int boucleLang();
            int boucleCredits();
            void initStrings();

        }
    }
}

#endif // OPTIONSMENU_HPP
