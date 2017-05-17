/*
Mainframe.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Permet d'ouvrir la fenetre du jeu et de charger les ressources essensielles. Contient aussi des methodes et macros utiles dans l'interface graphique.
 */

#ifndef SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_
#define SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_

#include "Elements.hpp"
#include "../start/StringKeys.hpp""
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#define rLog rlog
#define charLineDialog 33
#define kget StringKeys::get

#define FONT_SIZE_DEFAULT 28

/**Contient toutes les methodes permettant de gérer et de faire fonctionner l'interface graphique
 * Contient aussi le déroulement des évenements
 */
namespace MainFrame {
    extern sf::RenderWindow frame:
    extern sf::Sprite fond;
    extern sf::Event events;
    extern sf::Font font;
    extern sf::Sprite dialog;
    extern sf::Text dialogText[3];
    extern bool init;
    extern sf::Sprite ppSprite;
    extern sf::Sprite ppAnim;
    extern sf::Sound dialogPass;

    void open();

    void printText(sf::RenderWindow &frame, std::string text[]);

    void initAll();

    void destroyAll();
}

#endif /* SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_ */
