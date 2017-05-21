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
 sf::Texture textures[2];
 sf::SoundBuffer sounds[3];
int curPosI = 0;

bool continuer = true;

void initStrings(){
    play.setString(kget("title.1"));
    charge.setString(kget("title.2"));
    options.setString(kget("title.3"));
    exit.setString(kget("title.4"));
}

void initVars() {
    sf::Text *textPos[4] = {&play, &charge, &options, &exit};
    for(int i = 0, j = 175; i < 4; i++) {
        curPos[i].x = 10;
        curPos[i].y = j;
        textPos[i]->setPosition(sf::Vector2f(60, j));
        j+=85;
    }
    bool ok = true;
#ifdef _WIN32
    textures[0].loadFromFile("ressources\\backgrounds\\titlescreen.png");
    textures[1].loadFromFile("ressources\\sprites\\misc\\arrChoice.png");
    fondMusTitle.openFromFile("ressources\\audio\\music\\title.ogg");
    sounds[0].loadFromFile("ressources\\audio\\sounds\\select.ogg");
    sounds[1].loadFromFile("ressources\\audio\\sounds\\selectbuttons.ogg");
    sounds[2].loadFromFile("ressources\\audio\\sounds\\nope.ogg");
#else
    textures[0].loadFromFile("ressources/backgrounds/titlescreen.png");
    textures[1].loadFromFile("ressources/sprites/misc/arrChoice.png");
    fondMusTitle.openFromFile("ressources/audio/music/title.ogg");
    sounds[0].loadFromFile("ressources/audio/sounds/select.ogg");
    sounds[1].loadFromFile("ressources/audio/sounds/selectbuttons.ogg");
    sounds[2].loadFromFile("ressources/audio/sounds/nope.ogg");
#endif // _WIN32
    fond.setTexture(textures[0]);
    cursor.setTexture(textures[1]);
    bruitArr.setBuffer(sounds[0]);
    bruitPush.setBuffer(sounds[1]);
    bruitNope.setBuffer(sounds[2]);
    cursor.setScale(3, 3);
    initStrings();
    play.setColor(sf::Color::Black);
    charge.setColor(sf::Color::Black);
    options.setColor(sf::Color::Black);
    exit.setColor(sf::Color::Black);
    play.setFont(font);
    charge.setFont(font);
    options.setFont(font);
    exit.setFont(font);
    play.setCharacterSize(FONT_SIZE_DEFAULT);
    charge.setCharacterSize(FONT_SIZE_DEFAULT);
    options.setCharacterSize(FONT_SIZE_DEFAULT);
    exit.setCharacterSize(FONT_SIZE_DEFAULT);
    string toTell =  exit.getString();
    cout << toTell << endl;
    //Mix_Volume(2, MIX_MAX_VOLUME / 4);
    //Mix_Volume(1, MIX_MAX_VOLUME);
    //Mix_Volume(0, MIX_MAX_VOLUME / 2);
    OptionsMenu::initVars();
        frame.clear(sf::Color::White);

        //Actualisation des éléments
        frame.draw(fond);
        frame.draw(play),
        frame.draw(charge);
        frame.draw(options);
        frame.draw(exit);
        cursor.setPosition(curPos[curPosI]);
        frame.draw(cursor);

        frame.display();
}

void verifVars() {
    if(fond.getTexture() == NULL){
        gererErreur("Texture du fond du menu manquante", true);
    }
    if(cursor.getTexture() == NULL){
        gererErreur("Texture du curseur manquant", true);
    }
}

void deleteVars() {

}
int boucle0() {

    rlog << PRINT_TICKS << "Entrée dans le menu" << endl;
    while(continuer) {
        frame.waitEvent(events);
        switch(events.type) {
            QUIT

            case sf::Event::KeyPressed:
                if(events.key.code == sf::Keyboard::Return){
                     switch(curPosI) {
                    //Traitement de l'action en fonction de la position du curseur
                    case 0:
                        fondMusTitle.stop();
                        return 0;
                    case 3:
                        fondMusTitle.stop();
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
                break;

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
        }else if(isKeyPressed(sf::Keyboard::Escape)){
            fondMusTitle.stop();
            return -1;
        }
        frame.clear(sf::Color::Black);

        //Actualisation des éléments
        frame.draw(fond);
        frame.draw(play),
        frame.draw(charge);
        frame.draw(options);
        frame.draw(exit);
        cursor.setPosition(curPos[curPosI]);
        frame.draw(cursor);

        frame.display();
    }
    fondMusTitle.stop();
    return 0;
}

int mainMenu() {
    initVars();
    verifVars();
    //Début de la musique
    fondMusTitle.setVolume(50);
    fondMusTitle.play();
    //Lancement de la boucle
    return boucle0();
}

}
}
