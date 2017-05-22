#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define CASES * 32
#define CASE_SIZE 32
#define FPS_TICKS 33
#include <cmath>
#define ppPosY (personnage.getPosition().y / CASE_SIZE)
#define ppPosX (personnage.getPosition().x / CASE_SIZE)
UNS
namespace MainFrame {
namespace Overworld {
using namespace Side;

Plan *actuel;
sf::Sprite personnage;
sf::View camera;
sf::Sprite* plans[3];
sf::Music* music;

sf::Sprite *couche1;
sf::Sprite *couche2;
sf::Sprite *couche3;

int anim = -1;
int moving = -1;
bool anims = false;
int ancientTick = 0;

int frames = 0;
int startFrames = 0;
int animsCounter = 0;

bool scrollock[2] = {false, false};
int ppDir = FACE;

void up() {
    if(anim == -1) {
        startFrames = frames;
        anim = DOS;
        ppDir = DOS;
        if(actuel->getPassTab()[(int)((personnage.getPosition().y / CASE_SIZE) + 1) - (((personnage.getPosition().y / CASE_SIZE) + 1 <= 0) ? 0 : 1)][(int)(personnage.getPosition().x / CASE_SIZE) + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events
            moving = DOS;
        }
    }
}

void down() {
    if(anim == -1) {//Si une animation n'est pas déjà en cours
        startFrames = frames;
        anim = FACE;
        ppDir = FACE;
        if(actuel->getPassTab()[(int)(ppPosY + 1) + 1][(int)ppPosX + 1] == 0) {//Vérification des boites de collisions
            //TODO : Ensuite faudra faire la verif du passages des events
            moving = FACE;
        }
    }
}

void right() {
    if(anim == -1) {
        startFrames = frames;
        anim = DROITE;
        ppDir = DROITE;
        if(actuel->getPassTab()[(int)(ppPosY + 1)][(int)(ppPosX + 1) + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events
            moving = DROITE;
        }
    }
}


void left() {
    if(anim == -1) {
        startFrames = frames;
        anim = GAUCHE;
        ppDir = GAUCHE;
        if(actuel->getPassTab()[(int)(ppPosY + 1)][(int)(ppPosX + 1) - ((ppPosX + 1 <= 0) ? 0 : 1)] == 0) {
            //Ensuite faudra faire la verif du passages des events
            moving = GAUCHE;

        }
    }
}

void initVars() {
    actuel =  Initializer::faubourgEuvi;
    personnage.setTexture(Initializer::texturePP[FACE]);
    personnage.setPosition(21 CASES - 8, 14 CASES + 8);
    camera.setCenter(21 CASES, 14 CASES);
    camera.setSize(sf::Vector2f(16 CASES, 16 CASES));

    plans[0] = actuel->getCouche1();
    plans[1] = actuel->getCouche2();
    plans[2] = actuel->getCouche3();
    music = actuel->getFond();
    couche1 = actuel->getCouche1();
    couche2 = actuel->getCouche2();
    couche3 = actuel->getCouche3();
}

int overworld() {
    music->play();
    frame.setView(camera);
    int returned = boucle();
    music->stop();
    return returned;
}

int boucle() {
    bool continuer = true;
    while(continuer) {
        if((GET_TICKS - ancientTick >= FPS_TICKS)) {
            frames++;
            ancientTick = GET_TICKS;
            frame.pollEvent(events);

            switch(events.type) {
                QUIT
            }
            ECHAP
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
            if(isKeyPressed(sf::Keyboard::M)) {
                return 2;
            }
            frame.clear(sf::Color::Black);
            frame.draw(*couche1);
            frame.draw(*couche2);
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
            } else {
                personnage.setTexture(Initializer::texturePP[ppDir]);
            }
            frame.draw(personnage);
            frame.draw(*couche3);
            frame.setView(camera);
            frame.display();

            if(anim == DOS) {
                if(frames - startFrames >= 8) {
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == DOS) {
                        personnage.move(0, -4);
                        if(!scrollock[0] && camera.getCenter().y - 256 <= 0) {
                            scrollock[0] = true;
                        } else if(scrollock[0] && camera.getCenter().y + 256 <= actuel->getH() CASES) {
                            scrollock[0] = false;
                        }

                        if(!scrollock[0]) {
                            camera.move(0, -4);
                        }

                    }
                }
            }
            if(anim == FACE) {
                if(frames - startFrames >= 8) {
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == FACE) {
                        personnage.move(0, 4);
                        if(scrollock[0] && camera.getCenter().y - 256 >= 0) {
                            scrollock[0] = false;
                        } else if(!scrollock[0] && camera.getCenter().y + 256 >= actuel->getH() CASES) {
                            scrollock[0] = true;
                        }

                        if(!scrollock[0]) {
                            camera.move(0, 4);
                        }

                    }
                }
            }

            if(anim == GAUCHE) {
                if(frames - startFrames >= 8) {
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == GAUCHE) {
                        personnage.move(-4, 0);
                        if(!scrollock[1] && camera.getCenter().x - 256 <= 0) {
                            scrollock[1] = true;
                        } else if(scrollock[0] && camera.getCenter().x + 256 <= actuel->getW() CASES) {
                            scrollock[1] = false;
                        }

                        if(!scrollock[1]) {
                            camera.move(-4, 0);
                        }

                    }
                }
            }

            if(anim == DROITE) {
                if(frames - startFrames >= 8) {
                    anim = -1;
                    moving = -1;
                } else {
                    if(moving == DROITE) {
                        personnage.move(4, 0);
                        if(scrollock[1] && camera.getCenter().x - 256 >= 0) {
                            scrollock[1] = false;
                        } else if(!scrollock[0] && camera.getCenter().x + 256 >= actuel->getW() CASES) {
                            scrollock[1] = true;
                        }

                        if(!scrollock[1]) {
                            camera.move(4, 0);
                        }

                    }
                }
            }


        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }


    }
}
}
}
