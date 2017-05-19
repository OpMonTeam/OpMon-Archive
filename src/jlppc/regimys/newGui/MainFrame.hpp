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

#define QUIT case sf::Event::Closed:\
                return -1;
#define ECHAP if(isKeyPressed(sf::Keyboard::Escape)){return -1;}

#define ESPACE ECHAP

#define isKeyPressed sf::Keyboard::isKeyPressed

#define POURCENT(nbre, de) (nbre * de) / 100
#define FONT_SIZE_DEFAULT 28
#define loadTextureFromFile(path) setTexture(sf::Texture(path))
#define loadSoundFromFile(path) setBuffer(sf::SoundBuffer(path))

#define DIALOG_PASS(varname) if (changeDialog == false) {\
		txtEnCours[0] = varname[dialog];\
		txtEnCours[1] = varname[dialog + 1];\
		txtEnCours[2] = varname[dialog + 2];\
		printText(renderer, txtEnCours[0], txtEnCours[1], txtEnCours[2]);\
		changeDialog = true;\
		Utils::wait(50);\
	} else if (!(dialog + 3 >= sizeOfTxt)) {\
		dialogPass.play()\
		line = 0;\
		dialog++;\
		dialog++;\
		dialog++;\
		i = 0;\
		txtEnCours[0] = string(" ");\
		txtEnCours[1] = string(" ");\
		txtEnCours[2] = string(" ");\
		changeDialog = false;\
	}else{\
		phase++;\
	}\

#define ANIM_ARROW 	arrDialP.y = arrDialP.y + 1;\
	if (arrDialP.getPosition().y - (512 - 30) > 5) {\
        arrDialP.setPosition(arrDialP.getPosition().x, arrDial.getPosition().y - 6);\
	}\
	frame.draw(arrDialP);


/**Contient toutes les methodes permettant de gérer et de faire fonctionner l'interface graphique
 * Contient aussi le déroulement des évenements
 */
namespace MainFrame {
    extern sf::RenderWindow frame;
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
