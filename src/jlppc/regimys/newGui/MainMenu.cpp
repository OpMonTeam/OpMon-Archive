#include "MainMenu.hpp"
#include "../start/main.hpp"
#include <iostream>
#include "OptionsMenu.hpp"

UNS


void MainMenu::initStrings() {
    play.setString(kget("title.1"));
    charge.setString(kget("title.2"));
    options.setString(kget("title.3"));
    exit.setString(kget("title.4"));
}

void MainMenu::initVars() {
    sf::Text *textPos[4] = {&play, &charge, &options, &exit};
    for(int i = 0, j = 175; i < 4; i++) {
        curPos[i].x = 10;
        curPos[i].y = j;
        textPos[i]->setPosition(sf::Vector2f(60, j));
        j+=85;
    }
    // bool ok = true;
#ifdef _WIN32
    textures[0].loadFromFile("ressources\\backgrounds\\titlescreen.png");
    textures[1].loadFromFile("ressources\\sprites\\misc\\arrChoice.png");
    bgMusTitle.openFromFile("ressources\\audio\\music\\title.ogg");
    sounds[0].loadFromFile("ressources\\audio\\sounds\\select.ogg");
    sounds[1].loadFromFile("ressources\\audio\\sounds\\selectbuttons.ogg");
    sounds[2].loadFromFile("ressources\\audio\\sounds\\nope.ogg");
#else
    textures[0].loadFromFile(RESSOURCES_PATH + "backgrounds/titlescreen.png");
    textures[1].loadFromFile(RESSOURCES_PATH + "sprites/misc/arrChoice.png");
    bgMusTitle.openFromFile(RESSOURCES_PATH + "audio/music/title.ogg");
    sounds[0].loadFromFile(RESSOURCES_PATH + "audio/sounds/select.ogg");
    sounds[1].loadFromFile(RESSOURCES_PATH + "audio/sounds/selectbuttons.ogg");
    sounds[2].loadFromFile(RESSOURCES_PATH + "audio/sounds/nope.ogg");
#endif // _WIN32
    bg.setTexture(textures[0]);
    cursor.setTexture(textures[1]);
    bruitArr.setBuffer(sounds[0]);
    bruitPush.setBuffer(sounds[1]);
    bruitNope.setBuffer(sounds[2]);
    cursor.setScale(3, 3);
    initStrings();
    play.setColor(sf::Color::White);
    charge.setColor(sf::Color::White);
    options.setColor(sf::Color::White);
    exit.setColor(sf::Color::White);
    play.setFont(font);
    charge.setFont(font);
    options.setFont(font);
    exit.setFont(font);
    play.setCharacterSize(FONT_SIZE_DEFAULT);
    charge.setCharacterSize(FONT_SIZE_DEFAULT);
    options.setCharacterSize(FONT_SIZE_DEFAULT);
    exit.setCharacterSize(FONT_SIZE_DEFAULT);
    //Mix_Volume(2, MIX_MAX_VOLUME / 4);
    //Mix_Volume(1, MIX_MAX_VOLUME);
    //Mix_Volume(0, MIX_MAX_VOLUME / 2);
    OptionsMenu::initVars();



    bgMusTitle.setLoop(true);
}

void MainMenu::verifVars() {
    if(bg.getTexture() == NULL) {
        handleError("Missing menu bottom texture", true);
    }
    if(cursor.getTexture() == NULL) {
        handleError("Missing cursor texture", true);
    }
}

void MainMenu::deleteVars() {

}
int MainMenu::boucle0() {

    rlog << PRINT_TICKS << "Entering the menu" << endl;
    //Actualisation des éléments
    frame.draw(bg);
    frame.draw(play),
               frame.draw(charge);
    frame.draw(options);
    frame.draw(exit);
    cursor.setPosition(curPos[curPosI]);
    frame.draw(cursor);

    frame.display();
    winRefresh();
    while(continuer) {
        window.waitEvent(events);
        switch(events.type) {
            QUIT

        case sf::Event::KeyPressed:
            if(events.key.code == sf::Keyboard::Return) {
                switch(curPosI) {
                //Traitement de l'action en fonction de la position du curseur
                case 0:
                    bgMusTitle.stop();
                    return 0;
                case 3:
                    bgMusTitle.stop();
                    return -1;
                case 2:
                    if(OptionsMenu::optionsMenu() == -1) {
                        return -1;
                    }
                    break;
                case 1:
                    bruitNope.play();
                    break;
                }
            }
            break;
        default:
            break;

        }
        if(isKeyPressed(sf::Keyboard::Up)) {
            bruitArr.play();
            curPosI--;
            //Si en haut, retourne en bas
            if(curPosI >= 4) {
                curPosI = 0;
            } else if(curPosI < 0) {
                curPosI = 3;
            }
        } else if(isKeyPressed(sf::Keyboard::Down)) {
            bruitArr.play();
            curPosI++;
            //Si en bas, retourne en haut
            if(curPosI >= 4) {
                curPosI = 0;
            } else if(curPosI < 0) {
                curPosI = 3;
            }
        } else if(isKeyPressed(sf::Keyboard::Escape)) {
            bgMusTitle.stop();
            return -1;
        }
        frame.clear(sf::Color::Black);

        //Actualisation des éléments
        frame.draw(bg);
        frame.draw(play),
                   frame.draw(charge);
        frame.draw(options);
        frame.draw(exit);
        cursor.setPosition(curPos[curPosI]);
        frame.draw(cursor);

        frame.display();
        winRefresh();
    }
    bgMusTitle.stop();
    return 0;
}

int MainMenu::mainMenu() {
    initVars();
    verifVars();
    //Début de la musique
    bgMusTitle.setVolume(50);
    bgMusTitle.play();
    //Lancement de la boucle
    return boucle0();
}
