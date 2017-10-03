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


#define rLog rlog
#define charLineDialog 33
#define kget StringKeys::get
#define QUIT case sf::Event::Closed:\
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
#define ECHAP if(isKeyPressed(sf::Keyboard::Escape)){return -1;}

#define isKeyPressed sf::Keyboard::isKeyPressed

#define POURCENT(nbre, de) (nbre * de) / 100
#define FONT_SIZE_DEFAULT 25
#define loadTextureFromFile(path) setTexture(sf::Texture(path))
#define loadSoundFromFile(path) setBuffer(sf::SoundBuffer(path))

#define FPS_TICKS 33




#define ANIM_ARROW 	\
  sf::Vector2f posArrow = Main::mainframe.frame.mapPixelToCoords(sf::Vector2i(512-75, 512-30)); \
    Main::mainframe.arrDial.move(0, 1);\
    if (Main::mainframe.arrDial.getPosition().y - posArrow.y > 5) {\
            Main::mainframe.arrDial.move(0, -6);\
        }\
    Main::mainframe.frame.draw(Main::mainframe.arrDial);

/*
Contient toutes les methodes permettant de gérer et de faire fonctionner l'interface graphique
 * Contient aussi le déroulement des évenements
 */
class MainFrame {
public:
    sf::RenderTexture frame;
    sf::RenderWindow window;
    sf::Sprite bg;
    sf::Event events;
    sf::Font font;
    sf::Sprite dialog;
    sf::Text dialogText[3];
    bool init = false;
    sf::Sprite arrDial;
    sf::Sprite ppSprite;
    sf::Sprite ppAnim;
    sf::Sound dialogPass;
    sf::Thread mapsInit;

    sf::Thread *windowRefresh = NULL;

    Overworld overworld;
    StartScene startscene;
    MainMenu mainmenu;
    OptionsMenu optionsmenu;

    bool fullScreen = false;

    MainFrame();



    void open();

    void printText(sf::RenderTexture &frame, sf::String text[]);

    void initAll();

    void initAllStrings();

    void destroyAll();

    void winRefresh();

    sf::Vector2i vec2fTo2i(sf::Vector2f const &toTrans);

private:
    MainFrame(MainFrame&&);
};

#endif /* SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_ */
