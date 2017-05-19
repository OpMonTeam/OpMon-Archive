#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define SQUARE 32
#define FPS_TICKS 33
UNS
namespace MainFrame {
namespace Overworld {
using namespace Side;

bool continuer = true;
long ancientTick = 0;
bool joypressed = false;
bool mapChanged = true;
sf::Music *fond;
Plan *actuel = NULL;
sf::Sprite personnage;
sf::Vector2f ppPos;
sf::Vector2f mapPos;
int moving = -1;//Signale le mouvement a la boucle
int anim = -1;//Signale l'animation a la boucle
int ppDir = 0;
int pressed = -1;
int frames = 0;
bool mapMove[] = {true, true, true, true};
int startFrames = 0;
int ppPosX = 17;
int ppPosY = 15;
std::string musicPath;

void down() {
    if(anim == -1) {//Si une animation n'est pas déjà en cours
        startFrames = frames;
        anim = DOS;
        if(actuel->getPassTab()[(ppPosY + 1) + 1][ppPosX + 1] == 0) {//Vérification des boites de collisions
            //TODO : Ensuite faudra faire la verif du passages des events
            moving = DOS;
            ppPosY++;
            if(ppPosY + 8 >= actuel->getH()) {//Vérification du scrolling
                mapMove[DOS] = false;
                mapMove[FACE] = false;
            } else if(ppPosY >= 8) {
                mapMove[FACE] = true;
                mapMove[DOS] = true;
            }
        }
    }


}
//Pour avoir la documentation des methodes up(), right() et left(), se référer a la doc de down()
void up() {
    if(anim == -1) {
        startFrames = frames;
        anim = FACE;
        if(actuel->getPassTab()[(ppPosY + 1) - ((ppPosY + 1 <= 0) ? 0 : 1)][ppPosX + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events
            moving = FACE;
            ppPosY--;
            if(ppPosY - 6 <= 0) {
                mapMove[FACE] = false;
                mapMove[DOS] = false;
            } else if(ppPosY <= actuel->getH() - 10) {
                mapMove[DOS] = true;
                mapMove[FACE] = true;
            }
        }
    }
}
void right() {
    if(anim == -1) {
        startFrames = frames;
        anim = DROITE;
        if(actuel->getPassTab()[(ppPosY + 1)][(ppPosX + 1) + 1] == 0) {
            //Ensuite faudra faire la verif du passages des events
            moving = DROITE;
            ppPosX++;
            if(ppPosX + 6 >= actuel->getW()) {
                mapMove[DROITE] = false;
                mapMove[GAUCHE] = false;
            } else if(ppPosX >= 8) {
                mapMove[DROITE] = true;
                mapMove[GAUCHE] = true;
            }
        }
    }

}

void left() {
    if(anim == -1) {
        startFrames = frames;
        anim = GAUCHE;
        if(actuel->getPassTab()[(ppPosY + 1)][(ppPosX + 1) - ((ppPosX + 1 <= 0) ? 0 : 1)] == 0) {
            //Ensuite faudra faire la verif du passages des events
            moving = GAUCHE;
            ppPosX--;
            if(ppPosX - 8 <= 0) {
                mapMove[GAUCHE] = false;
                mapMove[DROITE] = false;
            } else if(ppPosX <= actuel->getW() - 8) {
                mapMove[GAUCHE] = true;
                mapMove[DROITE] = true;
            }
        }
    }
}

void initVars() {
    rlog << PRINT_TICKS << "Initialisation des variables et des sprites" << endl;
    actuel = Initializer::faubourgEuvi;
    personnage.setTexture(Initializer::texturePP[FACE]);
    fond = actuel->getFond();
    mapPos.x = -(8*SQUARE);
    mapPos.y = -(8*SQUARE);
    ppPos.x = mapPos.x + (ppPosX*SQUARE) + 16;
    ppPos.y = mapPos.y + (ppPosY*SQUARE);

}
void verifVars() {

}

int overworld() {
    rlog << PRINT_TICKS << "Entrée dans l'overworld..." << endl;
    verifVars();
    //Début de la musique
    actuel->getFond()->play();
    return boucle();
}

void deleteVars() {

}

int boucle() {
    rlog << PRINT_TICKS << "Entrée dans la boucle de l'overworld..." << endl;
    bool anims = false;
    int animsCounter = 0;
    while(continuer) {
        while (continuer) {
            if ((ticks.getElapsedTime().asMilliseconds() - ancientTick) >= (FPS_TICKS - 5)) {//Limitation de FPS un peu plus rapide
                frames++;
                /*rerrLog << "Liste vars : (tick n°" << SDL_GetTicks() << ")" << endl;
                rerrLog << "Frames : " << frames << endl;
                rerrLog << "ancientTick : " << ancientTick << endl;
                rerrLog << "anim : " << anim << endl;
                rerrLog << "moving : " << moving << endl;
                rerrLog << "anims : " << anims << endl;
                rerrLog << "pressed : " << pressed << endl;
                rerrLog << "startFrames : " << startFrames << endl;
                rerrLog << "Event : ";*/

                ancientTick = ticks.getElapsedTime().asMilliseconds();

                frame.pollEvent(events);

                switch (events.type) {
                    QUIT
                }
                rerrLog << endl;
                if(actuel->getMusicPath() != musicPath) {
                    actuel->getFond()->play();
                }
                ECHAP
                if(isKeyPressed(sf::Keyboard::Up)){
                    pressed = DOS;
                    down();
                }else if(isKeyPressed(sf::Keyboard::Down)){
                    pressed = FACE;
                    up();
                }else if(isKeyPressed(sf::Keyboard::Right)){
                    pressed = DROITE;
                    right();
                }else if(isKeyPressed(sf::Keyboard::Left)){
                    pressed = GAUCHE;
                    left();
                }else if(isKeyPressed(sf::Keyboard::M)){
                    return 2;
                }
                frame.clear(sf::Color::White);
                actuel->setPos(mapPos);
                frame.draw(actuel->getCouche1());
                frame.draw(actuel->getCouche2());
                //Animations
                if(anim != -1 && !anims) {
                    if(anim == DOS) {
                        personnage.setTexture(Initializer::marchePP[FACE]);
                    } else if(anim == FACE) {
                        personnage.setTexture(Initializer::marchePP[DOS]);
                    } else {
                        personnage.setTexture(Initializer::marchePP[anim]);
                    }
                    animsCounter++;
                    anims = animsCounter > 8;

                } else if(anim != -1 && anims) {
                    if(anim == DOS) {
                        personnage.setTexture(Initializer::marchePP2[FACE]);
                    } else if(anim == FACE) {
                        personnage.setTexture(Initializer::marchePP2[DOS]);
                    } else {
                        personnage.setTexture(Initializer::marchePP2[anim]);
                    }
                    animsCounter++;
                    if(animsCounter > 16) {
                        anims = false;
                        animsCounter = 0;
                    }
                } else {
                    personnage.setTexture(Initializer::texturePP[ppDir]);
                }
                personnage.setPosition(ppPos);
                frame.draw(personnage);

                frame.draw(actuel->getCouche3());
                //Mouvements
                if(anim == DOS) {
                    if(frames - startFrames == 8) {
                        anim = -1;
                        moving = -1;
                        //mapPos.y = mapPos.y - 4;
                    } else {
                        if(moving == DOS) {
                            //ppPos.y = ppPos.y + 1;
                            if(mapMove[DOS]) {
                                mapPos.y = mapPos.y - 4;
                            } else {
                                ppPos.y = ppPos.y + 4;
                            }

                        }
                    }
                    ppDir = FACE;
                } else if(anim == FACE) {
                    if(frames - startFrames == 8) {
                        anim = -1;
                        moving = -1;
                        //mapPos.y = mapPos.y + 4;
                    } else {
                        if(moving == FACE) {
                            //ppPos.y = ppPos.y - 1;
                            if(mapMove[FACE]) {
                                mapPos.y = mapPos.y + 4;
                            } else {
                                ppPos.y = ppPos.y - 4;
                            }
                        }

                    }

                    ppDir = DOS;
                } else if(anim == DROITE) {
                    if(frames - startFrames == 8) {
                        anim = -1;
                        moving = -1;
                        // mapPos.x = mapPos.x - 4;
                    } else {
                        if(moving == DROITE) {
                            //ppPos.x = ppPos.x + 1;
                            if(mapMove[DROITE]) {
                                mapPos.x = mapPos.x - 4;
                            } else {
                                ppPos.x = ppPos.x + 4;
                            }
                        }

                    }

                    ppDir = DROITE;
                } else if(anim == GAUCHE) {
                    if(frames - startFrames == 8) {
                        anim = -1;
                        moving = -1;
                        //mapPos.x = mapPos.x + 4;
                    } else {
                        if(moving == GAUCHE) {
                            //ppPos.x = ppPos.x - 1;
                            if(mapMove[GAUCHE]) {
                                mapPos.x = mapPos.x + 4;
                            } else {
                                ppPos.x = ppPos.x - 4;
                            }
                        }

                    }
                    ppDir = GAUCHE;
                }

                frame.display();

            } else {
                Utils::wait((FPS_TICKS - 5) - (ticks.getElapsedTime().asMilliseconds() - ancientTick));
            }
        }
    }
}
}
}
