#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define FPS_TICKS 33
#include <cmath>
#define ppPosY ((character.getPosition().y / CASE_SIZE) - 8)
#define ppPosX (((character.getPosition().x - 16) / CASE_SIZE) - 8)
UNS
namespace MainFrame {
namespace Overworld {
using namespace Side;

Map *actual;
sf::View camera;
sf::Sprite* maps[3];
sf::Music* music;

sf::Sprite *layer1;
sf::Sprite *layer2;
sf::Sprite *layer3;

bool justTp = false;
int tpCount = 0;

int anim = -1;
int moving = -1;
bool anims = false;

int ancientTick = 0;

int frames = 0;
int startFrames = 0;
int animsCounter = 0;

bool scrollock[2] = {false, false};
int ppDir = TO_DOWN;

bool scrolling = true;

bool debugMode = false;
bool printlayer[3] = {true, true, true};

sf::Sprite &character = Main::player.persSprite;

void initVars() {
    actual =  Initializer::maps[0];
    character = Main::player.getSprite();
    character.setTexture(Initializer::texturePP[TO_DOWN]);
    character.setPosition(8 CASES + 21 CASES - 16, 8 CASES + 14 CASES);
    camera.setCenter(21 CASES, 14 CASES);
    camera.setSize(sf::Vector2f(16 CASES, 16 CASES));

/*  maps[0] = actual->getLayer1();
    maps[1] = actual->getLayer2();
    maps[2] = actual->getLayer3();*/
    music = actual->getFond();
    music->setLoop(true);
    layer1 = new sf::Sprite();
    layer2 = new sf::Sprite();
    layer3 = new sf::Sprite();
    layer1->setTexture(*actual->getLayer1());
    layer2->setTexture(*actual->getLayer2());
    layer3->setTexture(*actual->getLayer3());
    character.setScale(2, 2);


}

int tp(int toTp, sf::Vector2i pos, bool scroll){
    if(moving != -1|| anim != -1){
        moving = -1;
        anim = -1;
    }
    actual = Initializer::maps[toTp];
    if(actual == NULL){
        gererErreur("Erreur lors du changement de map : actual == NULL", true);
    }
    scrolling = scroll;
    character.setPosition(8 CASES + pos.x CASES - 16, 8 CASES + pos.y CASES);
    if(scrolling){
        camera.setCenter(character.getPosition());
    }else{
        camera.setCenter((actual->getW() CASES) / 2, (actual->getH() CASES) / 2);
    }
    if(music != actual->getFond()){
        music->stop();
        music = actual->getFond();
        music->play();
    }
    delete(layer1);
    delete(layer2);
    delete(layer3);
    layer1 = new sf::Sprite();
    layer2 = new sf::Sprite();
    layer3 = new sf::Sprite();
    layer1->setTexture(*actual->getLayer1());
    layer2->setTexture(*actual->getLayer2());
    layer3->setTexture(*actual->getLayer3());
    tpCount = 0;
    justTp = true;
    return 0;
}

void up() {
    if(anim == -1) {
        startFrames = frames;
        anim = TO_UP;
        ppDir = TO_UP;
        if(ppPosY - 1 >= -1){
        if(actual->getPassTab()[(int)(ppPosY + 1) - ((ppPosY + 1 <= 0) ? 0 : 1)][(int)ppPosX + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events

                moving = TO_UP;
            }

        }
    }
}

void down() {
    if(anim == -1) {//Si une animation n'est pas déjà en cours
        startFrames = frames;
        anim = TO_DOWN;
        ppDir = TO_DOWN;
        if(ppPosY + 1 < actual->getH() - 1){
        if(actual->getPassTab()[(int)(ppPosY + 1) + 1][(int)ppPosX + 1] == 0) {//Vérification des boites de collisions
            //TODO : Ensuite faudra faire la verif du passages des events

                moving = TO_DOWN;
            }

        }
    }
}

void right() {
    if(anim == -1) {
        startFrames = frames;
        anim = TO_RIGHT;
        ppDir = TO_RIGHT;
        if(ppPosX + 1 < actual->getW() - 1){
        if(actual->getPassTab()[(int)(ppPosY + 1)][(int)(ppPosX + 1) + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events

                moving = TO_RIGHT;
            }
        }
    }
}


void left() {
    if(anim == -1) {
        startFrames = frames;
        anim = TO_LEFT;
        ppDir = TO_LEFT;
        if(ppPosX - 1 >= -1){
        if(actual->getPassTab()[(int)(ppPosY + 1)][(int)(ppPosX + 1) - ((ppPosX + 1 <= 0) ? 0 : 1)] == 0) {
            //Ensuite faudra faire la verif du passages des events

                moving = TO_LEFT;
            }

        }
    }
}



int overworld() {
    music->play();
    frame.setView(camera);
    int returned = boucle();
    music->stop();
    delete(layer1);
    delete(layer2);
    delete(layer3);
    return returned;
}

int boucle() {
    bool continuer = true;
    while(continuer) {
        if((GET_TICKS - ancientTick >= FPS_TICKS)) {
            frames++;
            //cout << "Position perso : P(" << ppPosX << ";" << ppPosY << ")" << endl;
            if(justTp){
                tpCount++;
                justTp = tpCount < 0;
            }

            ancientTick = GET_TICKS;
            window.pollEvent(events);

            switch(events.type) {
                QUIT

                case sf::Event::KeyPressed:
                    if(events.key.code == sf::Keyboard::F1){
                        tp(0, sf::Vector2i(25, 28), true);
                    }else if(events.key.code == sf::Keyboard::F2){
                        tp(1, sf::Vector2i(8, 14), true);
                    }else if(events.key.code == sf::Keyboard::F3){
                        tp(2, sf::Vector2i(15, 14), true);
                    }else if(events.key.code == sf::Keyboard::F4){
                        tp(3, sf::Vector2i(8, 14), true);
                    }else if(events.key.code == sf::Keyboard::Equal){
                        debugMode = !debugMode;
                    }else if(events.key.code == sf::Keyboard::F5){
                        tp(4, sf::Vector2i(0, 1), true);
                    }else if(events.key.code == sf::Keyboard::F6){
                        tp(5, sf::Vector2i(0, 0), true);
                    }
                    if(debugMode){
                        if(events.key.code == sf::Keyboard::F10){
                            printlayer[0] = !printlayer[0];
                        }
                        if(events.key.code == sf::Keyboard::F11){
                            printlayer[1] = !printlayer[1];
                        }
                        if(events.key.code == sf::Keyboard::F12){
                            printlayer[2] = !printlayer[2];
                        }
                    }
            }
            ECHAP
            if(Main::player.gameIsOver){return -1;}
            if(!justTp){
                if(isKeyPressed(sf::Keyboard::Up)) {
                    up();
                }
                if(isKeyPressed(sf::Keyboard::Down)) {
                    down();
                }
                if(isKeyPressed(sf::Keyboard::Left)) {
                    left();
                }
                if(isKeyPressed(sf::Keyboard::Right)) {
                    right();
                }
            }
            sf::Text debugText;
            if(debugMode){
                if(isKeyPressed(sf::Keyboard::Numpad2)){
                    camera.move(0, 4);
                }
                if(isKeyPressed(sf::Keyboard::Numpad4)){
                    camera.move(-4, 0);
                }
                if(isKeyPressed(sf::Keyboard::Numpad8)){
                    camera.move(0, -4);
                }
                if(isKeyPressed(sf::Keyboard::Numpad6)){
                    camera.move(4, 0);
                }
                debugText.setString("Debug mode");
                debugText.setPosition(frame.mapPixelToCoords(sf::Vector2i(0, 0)));
                debugText.setFont(font);
                debugText.setColor(sf::Color::Black);
                debugText.setCharacterSize(40);
            }

            frame.clear(sf::Color::Black);
            if((debugMode ? printlayer[0] : true)){
                frame.draw(*layer1);
            }
            if((debugMode ? printlayer[1] : true)){
                frame.draw(*layer2);
            }
            actual->updateEvents(Main::player);
            if(anim != -1 && !anims) {
                character.setTexture(Initializer::marchePP[anim]);
                animsCounter++;
                anims = animsCounter > 8;

            } else if(anim != -1 && anims) {
                character.setTexture(Initializer::marchePP2[anim]);
                animsCounter++;
                if(animsCounter > 16) {
                    anims = false;
                    animsCounter = 0;
                }
            } else if(anim == -1){
               character.setTexture(Initializer::texturePP[ppDir]);
            }
            frame.draw(character);
            if((debugMode ? printlayer[2] : true)){
                frame.draw(*layer3);
            }
            if(scrolling && !debugMode){
                    camera.setCenter(character.getPosition().x + 16, character.getPosition().y + 16);
            }
            frame.setView(camera);
            if(debugMode){
                frame.draw(debugText);
            }

            frame.display();
            winRefresh();
            if(anim == -1){
                if(isKeyPressed(sf::Keyboard::Return)){
                    int lx = ppPosX;
                    int ly = ppPosY;
                    switch(ppDir){
                        case TO_UP:
                            ly--;
                            break;
                        case TO_DOWN:
                            ly++;
                            break;
                        case TO_LEFT:
                            lx--;
                            break;
                        case TO_RIGHT:
                            lx++;
                            break;
                        default:
                            break;
                    }
                    vector<Event*> events = actual->getEvent(sf::Vector2i(lx CASES, ly CASES));
                    if(events.size() == 0){
                        events = actual->getEvent(sf::Vector2i(ppPosX CASES, ppPosY CASES));
                    }
                    if(events.size() > 0){
                        for(unsigned int i = 0; i < events.size(); i++){
                            if(events[i]->getEventTrigger() == Events::EventTrigger::PRESS){
                                events[i]->action(Main::player);
                            }
                        }
                    }
                }
            }
            if(anim == TO_UP) {
                if(frames - startFrames >= 7) {
                        if(moving == TO_UP){
                    character.move(0, -4);
                        }
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == TO_UP) {
                        character.move(0, -4);


                    }
                }
            }
            if(anim == TO_DOWN) {
                if(frames - startFrames >= 7) {
                        if(moving == TO_DOWN){
                        character.move(0, 4);
                }
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == TO_DOWN) {
                        character.move(0, 4);
                    }
                }
            }

            if(anim == TO_LEFT) {
                if(frames - startFrames >= 7) {
                    if(moving == TO_LEFT){
                        character.move(-4, 0);
                    }

                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == TO_LEFT) {
                        character.move(-4, 0);
                    }
                }
            }

            if(anim == TO_RIGHT) {
                if(frames - startFrames >= 7) {
                        if(moving == TO_RIGHT){
                        character.move(4, 0);
                        }
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == TO_RIGHT) {
                        character.move(4, 0);


                    }
                }
            }


        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }


    }
}

int boucleDialog(vector<sf::String> dialogs){
    int sizeOfTxt = dialogs.size();
    sf::String txtEnCours[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};
    bool continuer = true;
    int dialog = 0;
    bool changeDialog = false;
    int i = 0;
    int line = 0;

    int phase = 0;
    sf::Vector2f posArrow = frame.mapPixelToCoords(sf::Vector2i(512-75, 512-30));
    arrDial.setPosition(posArrow);\

    while(continuer && phase == 0) {
        if((GET_TICKS - ancientTick >= FPS_TICKS)) {
            frames++;
            if(justTp){
                tpCount++;
                justTp = tpCount < 0;
            }

            ancientTick = GET_TICKS;
            window.pollEvent(events);

            switch(events.type) {
                QUIT

                case sf::Event::KeyPressed:
                    if(events.key.code == sf::Keyboard::Space){
                        DIALOG_PASS(dialogs)
                    }
                break;
            }
            ECHAP

            frame.draw(*layer1);
            frame.draw(*layer2);
            for(Event* event : actual->getEvents()){
                frame.draw(*event->getSprite());
            }
            if(anim != -1 && !anims) {
                character.setTexture(Initializer::marchePP[anim]);
                animsCounter++;
            } else if(anim != -1 && anims) {
                character.setTexture(Initializer::marchePP2[anim]);
                animsCounter++;
            } else if(anim == -1){
               character.setTexture(Initializer::texturePP[ppDir]);
            }
            frame.draw(character);
            frame.draw(*layer3);
            if(scrolling){
                    camera.setCenter(character.getPosition().x + 16, character.getPosition().y + 16);
            }
            frame.setView(frame.getDefaultView());
            frame.setView(camera);
            if(!changeDialog){
                 if (!(i >= dialogs[line + dialog].toUtf32().size())) {

                        if (txtEnCours[line] == sf::String(" ")) {
                            txtEnCours[line] = dialogs[line + dialog].toUtf32()[i];
                        } else {
                            txtEnCours[line] += dialogs[line + dialog].toUtf32()[i];
                        }

                        i++;
                    } else {
                        if (line == 2) {
                            changeDialog = true;
                        } else {
                            line++;
                            i = 0;
                        }
                    }
            }
            printText(frame, txtEnCours);
            ANIM_ARROW
            frame.display();
            winRefresh();


        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }


    }
}

}



}
