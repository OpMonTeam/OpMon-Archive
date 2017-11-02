/*
Mainframe.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Permet d'ouvrir la fenetre du jeu et de charger les ressources essensielles. Contient aussi des methodes et macros utiles dans l'interface graphique.
 */

#ifndef SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_
#define SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_

#include "Elements.hpp"
#include "../start/StringKeys.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../start/Initializer.hpp"
#include "Overworld.hpp"
#include "StartScene.hpp"
#include "MainMenu.hpp"
#include "OptionsMenu.hpp"


#define charLineDialog 33
#define kget StringKeys::get
#define RETURN_ON_CLOSE_EVENT case sf::Event::Closed:\
    return -1;

#define FULLSCREEN if(events.key.code == sf::Keyboard::F){\
            if(MainFrame::fullScreen){\
                    MainFrame::window.create(sf::VideoMode::getDesktopMode(), "OpMon Lazuli", sf::Style::Fullscreen);\
                    MainFrame::fullScreen = true;\
                }else{\
                    MainFrame::fullScreen = false;\
                    window.create(sf::VideoMode(512, 512), "OpMon Lazuli", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);\
                }\
        }


#define FULLSCREEN_FULL case sf::Event::KeyPressed:\
    FULLSCREEN\
    break;
#define RETURN_ON_ECHAP_EVENT if(isKeyPressed(sf::Keyboard::Escape)){return -1;}

#define isKeyPressed sf::Keyboard::isKeyPressed

#define POURCENT(nbre, de) (nbre * de) / 100
#define FONT_SIZE_DEFAULT 25
#define loadTextureFromFile(path) setTexture(sf::Texture(path))
#define loadSoundFromFile(path) setBuffer(sf::SoundBuffer(path))

#define FPS_TICKS 33




#define ANIM_ARROW 	\

/*
Contient toutes les methodes permettant de gérer et de faire fonctionner l'interface graphique
 * Contient aussi le déroulement des évenements
 */
class MainFrame {
public:
    sf::Sprite bg;
    bool init = false;

    sf::Thread *windowRefresh = nullptr;



    bool fullScreen = false;

  bool initEnd = false;

    MainFrame();



    void open();


    void initAll();

    void initAllStrings();

    void destroyAll();

    void winRefresh();


private:
    MainFrame(MainFrame&&);
};

#endif /* SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_ */
