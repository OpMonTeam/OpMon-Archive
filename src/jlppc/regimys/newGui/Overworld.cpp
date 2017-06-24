#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define CASES * 32
#define CASE_SIZE 32
#define FPS_TICKS 33
#include <cmath>
#define ppPosY ((personnage.getPosition().y / CASE_SIZE) - 8)
#define ppPosX (((personnage.getPosition().x - 16) / CASE_SIZE) - 8)
UNS
namespace MainFrame {
namespace Overworld {
using namespace Side;
/**
actuel = actual (easy)
*/
Plan *actuel;
sf::View camera;
sf::Sprite* plans[3];
sf::Music* music;
/**
couche = layer in french
*/
sf::Sprite *couche1;
sf::Sprite *couche2;
sf::Sprite *couche3;

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
int ppDir = FACE;

bool scrolling = true;
/**
personnage = character in french
*/
sf::Sprite &personnage = Main::player.persSprite;

void initVars() {
    actuel =  Initializer::plans[0];
    personnage = Main::player.getSprite();
    personnage.setTexture(Initializer::texturePP[FACE]);
    personnage.setPosition(8 CASES + 21 CASES - 16, 8 CASES + 14 CASES);
    camera.setCenter(21 CASES, 14 CASES);
    camera.setSize(sf::Vector2f(16 CASES, 16 CASES));

/*  plans[0] = actuel->getCouche1();
    plans[1] = actuel->getCouche2();
    plans[2] = actuel->getCouche3();*/
    music = actuel->getFond();
    music->setLoop(true);
    couche1 = new sf::Sprite();
    couche2 = new sf::Sprite();
    couche3 = new sf::Sprite();
    couche1->setTexture(*actuel->getCouche1());
    couche2->setTexture(*actuel->getCouche2());
    couche3->setTexture(*actuel->getCouche3());
    personnage.setScale(2, 2);


}

int tp(int toTp, sf::Vector2i pos, bool scroll){
    if(moving != -1|| anim != -1){
        moving = -1;
        anim = -1;
    }
    actuel = Initializer::plans[toTp];
    if(actuel == NULL){
        gererErreur("Erreur lors du changement de map : actuel == NULL", true);
    }
    scrolling = scroll;
    personnage.setPosition(8 CASES + pos.x CASES - 16, 8 CASES + pos.y CASES);
    if(scrolling){
        camera.setCenter(personnage.getPosition());
    }else{
        camera.setCenter((actuel->getW() CASES) / 2, (actuel->getH() CASES) / 2);
    }
    if(music != actuel->getFond()){
        music->stop();
        music = actuel->getFond();
        music->play();
    }
    delete(couche1);
    delete(couche2);
    delete(couche3);
    couche1 = new sf::Sprite();
    couche2 = new sf::Sprite();
    couche3 = new sf::Sprite();
    couche1->setTexture(*actuel->getCouche1());
    couche2->setTexture(*actuel->getCouche2());
    couche3->setTexture(*actuel->getCouche3());
    tpCount = 0;
    justTp = true;
    return 0;
}

void up() {
    if(anim == -1) {
        startFrames = frames;
        anim = DOS;
        ppDir = DOS;
        if(ppPosY - 1 >= -1){
        if(actuel->getPassTab()[(int)(ppPosY + 1) - ((ppPosY + 1 <= 0) ? 0 : 1)][(int)ppPosX + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events

                moving = DOS;
            }

        }
    }
}

void down() {
    if(anim == -1) {//Si une animation n'est pas déjà en cours
        startFrames = frames;
        anim = FACE;
        ppDir = FACE;
        if(ppPosY + 1 < actuel->getH() - 1){
        if(actuel->getPassTab()[(int)(ppPosY + 1) + 1][(int)ppPosX + 1] == 0) {//Vérification des boites de collisions
            //TODO : Ensuite faudra faire la verif du passages des events

                moving = FACE;
            }

        }
    }
}

void right() {
    if(anim == -1) {
        startFrames = frames;
        anim = DROITE;
        ppDir = DROITE;
        if(ppPosX + 1 < actuel->getW() - 1){
        if(actuel->getPassTab()[(int)(ppPosY + 1)][(int)(ppPosX + 1) + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events

                moving = DROITE;
            }
        }
    }
}


void left() {
    if(anim == -1) {
        startFrames = frames;
        anim = GAUCHE;
        ppDir = GAUCHE;
        if(ppPosX - 1 >= -1){
        if(actuel->getPassTab()[(int)(ppPosY + 1)][(int)(ppPosX + 1) - ((ppPosX + 1 <= 0) ? 0 : 1)] == 0) {
            //Ensuite faudra faire la verif du passages des events

                moving = GAUCHE;
            }

        }
    }
}



int overworld() {
    music->play();
    frame.setView(camera);
    int returned = boucle();
    music->stop();
    delete(couche1);
    delete(couche2);
    delete(couche3);
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
                        std::vector<sf::String> strs;
                        strs.push_back(kget("dialogNope.1"));
                        strs.push_back(kget("dialogNope.2"));
                        strs.push_back(kget("dialogNope.3"));
                        boucleDialog(strs);
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

            frame.clear(sf::Color::Black);
            frame.draw(*couche1);
            frame.draw(*couche2);
            FOR_EACH(Event*, actuel->getEvents(), actuel->getEvents().size(), {)
                (*objActuel)->update(Main::player);
                frame.draw((*objActuel)->getSprite());
            }
            if(anim != -1 && !anims) {
                personnage.setTexture(Initializer::marchePP[anim]);
                animsCounter++;
                anims = animsCounter > 8;

            } else if(anim != -1 && anims) {
                personnage.setTexture(Initializer::marchePP2[anim]);
                animsCounter++;
                if(animsCounter > 16) {
                    anims = false;
                    animsCounter = 0;
                }
            } else if(anim == -1){
               personnage.setTexture(Initializer::texturePP[ppDir]);
            }
            frame.draw(personnage);
            frame.draw(*couche3);
            if(scrolling){
                    camera.setCenter(personnage.getPosition().x + 16, personnage.getPosition().y + 16);
            }
            frame.setView(camera);
            frame.display();
            winRefresh();
            if(anim == -1){
                if(isKeyPressed(sf::Keyboard::Return)){
                    int lx = ppPosX;
                    int ly = ppPosY;
                    switch(ppDir){
                        case DOS:
                            ly--;
                            break;
                        case FACE:
                            ly++;
                            break;
                        case GAUCHE:
                            lx--;
                            break;
                        case DROITE:
                            lx++;
                            break;
                        default:
                            break;
                    }
                    vector<Event*> events = actuel->getEvent(sf::Vector2i(lx CASES, ly CASES));
                    if(events.size() == 0){
                        events = actuel->getEvent(sf::Vector2i(ppPosX CASES, ppPosY CASES));
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
            if(anim == DOS) {
                if(frames - startFrames >= 7) {
                        if(moving == DOS){
                    personnage.move(0, -4);
                        }
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == DOS) {
                        personnage.move(0, -4);


                    }
                }
            }
            if(anim == FACE) {
                if(frames - startFrames >= 7) {
                        if(moving == FACE){
                        personnage.move(0, 4);
                }
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == FACE) {
                        personnage.move(0, 4);
                    }
                }
            }

            if(anim == GAUCHE) {
                if(frames - startFrames >= 7) {
                    if(moving == GAUCHE){
                        personnage.move(-4, 0);
                    }

                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == GAUCHE) {
                        personnage.move(-4, 0);
                    }
                }
            }

            if(anim == DROITE) {
                if(frames - startFrames >= 7) {
                        if(moving == DROITE){
                        personnage.move(4, 0);
                        }
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == DROITE) {
                        personnage.move(4, 0);


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

            frame.draw(*couche1);
            frame.draw(*couche2);
            FOR_EACH(Event*, actuel->getEvents(), actuel->getEvents().size(), {)
                frame.draw((*objActuel)->getSprite());
            }
            if(anim != -1 && !anims) {
                personnage.setTexture(Initializer::marchePP[anim]);
                animsCounter++;
            } else if(anim != -1 && anims) {
                personnage.setTexture(Initializer::marchePP2[anim]);
                animsCounter++;
            } else if(anim == -1){
               personnage.setTexture(Initializer::texturePP[ppDir]);
            }
            frame.draw(personnage);
            frame.draw(*couche3);
            if(scrolling){
                    camera.setCenter(personnage.getPosition().x + 16, personnage.getPosition().y + 16);
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
            frame.display();
            winRefresh();


        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }


    }
}

}



}
