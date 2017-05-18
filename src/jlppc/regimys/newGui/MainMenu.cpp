#include "MainMenu.hpp"
#include "../start/main.hpp"
#include <iostream>
#include "OptionsMenu.hpp"

UNS

namespace MainFrame {
namespace MainMenu {

 sf::Sprite fond;
 sf::Text play;
 sf::Text charge;
 sf::Text options;
 sf::Text exit;
 sf::Sprite cursor;
 sf::Vector2f curPos[4];
 sf::Music fondMusTitle;
 sf::Sound bruitArr;
 sf::Sound bruitPush;
 sf::Sound bruitNope;
int curPosI = 0;

bool continuer = true;

void initVars() {
    sf::Text *textPos[4] = {&play, &charge, &options, &exit};
    for(int i = 0, j = 175; i < 4; i++) {
        curPos[i].x = 10;
        curPos[i].y = j;
        curPos[i].w = 30;
        curPos[i].h = 30;
        textPos[i]->setPosition(sf::Vector2f(60, j));
        j+=85;
    }
#ifdef _WIN32
    fond.loadTextureFromFile("ressources\\backgrounds\\titlescreen.png");
    cursor.loadTextureFromFile("ressources\\sprites\\misc\\arrChoice.png");
    fondMusTitle.openFromFile("ressources\\audio\\music\\title.ogg");
    bruitArr.loadSoundFromFile("ressources\\audio\\sounds\\select.ogg");
    bruitPush.loadSoundFromFile("ressources\\audio\\sounds\\selectbuttons.ogg");
    bruitNope.loadSoundFromFile("ressources\\audio\\sounds\\nope.ogg");
#else
    fond.loadTextureFromFile("ressources/backgrounds/titlescreen.png");
    cursor.loadTextureFromFile("ressources/sprites/misc/arrChoice.png");
    fondMusTitle.openFromFile("ressources/audio/music/title.ogg");
    bruitArr.loadSoundFromFile("ressources/audio/sounds/select.ogg");
    bruitPush.loadSoundFromFile("ressources/audio/sounds/selectbuttons.ogg");
    bruitNope.loadSoundFromFile("ressources/audio/sounds/nope.ogg");
#endif // _WIN32
    play.setString(kget("title.1"));
    charge.setString(kget("title.2"));
    options.setString(kget("title.3"));
    exit.setString(kget("title.4"));
    //Mix_Volume(2, MIX_MAX_VOLUME / 4);
    //Mix_Volume(1, MIX_MAX_VOLUME);
    //Mix_Volume(0, MIX_MAX_VOLUME / 2);
    OptionsMenu::initVars();
}

void verifVars() {

}

void deleteVars() {

}

int boucle0() {
    while(continuer) {
        frame.pollEvent(events);
        switch(events.type) {
            QUIT
        }
        if(isKeyPressed(sf::Keyboard::Up)){
            bruitArr.play();
            curPosI--;
            //Si en haut, retourne en bas
            if(curPosI >= 4) {
                curPosI = 0;
            } else if(curPosI < 0) {
                curPosI = 3;
            }
        }else if(isKeyPressed(sf::Keyboard::Down)){
            bruitArr.play();
            curPosI++;
            //Si en bas, retourne en haut
            if(curPosI >= 4) {
                curPosI = 0;
            } else if(curPosI < 0) {
                curPosI = 3;
            }
        }else ECHAP
        else if(isKeyPressed(sf::Keyboard::Return)){
            switch(curPosI) {
                    //Traitement de l'action en fonction de la position du curseur
                case 0:
                    return 0;
                case 3:
                    return -1;
                case 2:
                    if(OptionsMenu::optionsMenu() == -1){
                        return -1;
                    }
                    break;
                case 1:
                    bruitNope.play();
                    break;
                }
        }

        frame.clear(sf::Color::White);

        //Actualisation des éléments

        frame.draw(fond);
        frame.draw(play),
        frame.draw(charge);
        frame.draw(options);
        frame.draw(exit);
        frame.draw(cursor);

        frame.display();
    }
    return 0;
}

int mainMenu() {

    verifVars();
    //Début de la musique
    fondMusTitle.play();
    //Lancement de la boucle
    return boucle0();
}

}
}
