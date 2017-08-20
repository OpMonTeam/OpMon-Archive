/*
MainMenu.hpp
Auteur : Jlppc
Fichier sous license GPL-3.0
http://opmon-game.ga
Contient le namespace MainMenu
*/
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "MainFrame.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace MainFrame {
    /**
    Namespace contenant les éléments du menu principal
    */
    namespace MainMenu {

        extern sf::Sprite bg;
        extern sf::Text play;
        extern sf::Text charge;
        extern sf::Text options;
        extern sf::Text exit;
        extern sf::Sprite cursor;
        extern sf::Vector2f curPos[4];
        extern sf::Music bgMusTitle;
        extern sf::Sound bruitArr;
        extern sf::Sound bruitPush;
        extern sf::Sound bruitNope;

        extern bool continuer;

        void initVars();
        void verifVars();
        void deleteVars();
        int mainMenu();
        int boucle0();
        void initStrings();
    }
}


#endif // MAINMENU_HPP
