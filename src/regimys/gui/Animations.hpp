/*
Animations.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contient la dÃ©finition du namespace Animations.
*/
#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <iostream>
#include "../start/main.hpp"
#include <SFML/Graphics.hpp>

/*Define permettant de vÃ©rifier si les animations ont Ã©tÃ© initialisÃ©es*/
#define ANIM_CHECK_INIT \
    if(!init){\
            handleError("Erreur : Animations non initialisÃ©es", true);\
        }

/**
Le namespace Animations contient toutes les animations du jeu. Ces animations doivent etre initialisÃ©es avec initAnims() puis dÃ©truites avec deleteAnims()
*/
namespace Animations {

/**
Initialise les animations
*/
void initAnims();
/**
LibÃ¨re les ressources associÃ©es aux animations
*/
void deleteAnims();

int animWinOpen(sf::RenderTexture &window, sf::Sprite const &bg);
int animWinClose(sf::RenderTexture &window, sf::Sprite const &bg);

}


#endif // ANIMATIONS_HPP
