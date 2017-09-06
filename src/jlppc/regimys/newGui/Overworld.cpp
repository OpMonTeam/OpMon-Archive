#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define FPS_TICKS 33
#include <cmath>
//#define ppPosY ((character.getPosition().y / CASE_SIZE) - 8)
//#define ppPosX (((character.getPosition().x - 16) / CASE_SIZE) - 8)
#include "Events.hpp"

#ifndef _WIN32

//#define DEBUG_REPORT

#endif

UNS

using namespace Side;



void Overworld::initVars() {
    actual =  Initializer::maps[0];
    character = Main::player.getSprite();
    character.setTexture(Initializer::texturePP[TO_DOWN]);
    character.setPosition(8 CASES + 20 CASES - 16, 8 CASES + 19 CASES);
    ppPosX = 19;
    ppPosY = 19;
    camera.setCenter(character.getPosition());
    camera.setSize(sf::Vector2f(16 CASES, 16 CASES));
    ppDir = TO_UP;
    Main::player.setppDirPointer(&ppDir);

    /*  maps[0] = actual->getLayer1();
        maps[1] = actual->getLayer2();
        maps[2] = actual->getLayer3();*/
    music = actual->getBg();
    music->setLoop(true);
    layer1 = actual->getLayer1();
    layer2 = actual->getLayer2();
    layer3 = actual->getLayer3();
    character.setScale(2, 2);
    character.setOrigin(16, 16);
}

int Overworld::tp(int toTp, sf::Vector2i pos, bool scroll) {
    if(moving != -1|| anim != -1) {
        moving = -1;
        anim = -1;
    }
    actual = Initializer::maps[toTp];
    if(actual == NULL) {
        handleError("Error changing map : actual == NULL", true);
    }
    scrolling = scroll;
    character.setPosition(8 CASES + pos.x CASES - 16, 8 CASES + pos.y CASES);
    ppPosX = pos.x - 1;
    ppPosY = pos.y;
    if(scrolling) {
        camera.setCenter(character.getPosition());
    } else {
        camera.setCenter((actual->getW() CASES) / 2, (actual->getH() CASES) / 2);
    }
    if(music != actual->getBg()) {
        music->stop();
        music = actual->getBg();
        music->play();
    }

    layer1 = actual->getLayer1();
    layer2 = actual->getLayer2();
    layer3 = actual->getLayer3();
    // layer1->move(32, 32);
    // layer2->move(32, 32);
    // layer3->move(32, 32);
    tpCount = 0;
    justTp = true;
    return 0;
}
#define UNLOCK_TP  Events::justTP = false;
void Overworld::up() {
    if(anim == -1 && !movementLock) {
        if(ppDir != TO_UP) {
            ppDir = TO_UP;
            return;
        }
        startFrames = frames;
        anim = TO_UP;

        if(debugMode) {
            UNLOCK_TP
            moving = TO_UP;
            ppPosY--;
            std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i(ppPosX CASES, (ppPosY - 1) CASES));
            if(nextEvents.size() > 0) {
                for(Event *nextEvent : nextEvents) {
                    if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN) {
                        nextEvent->action(Main::player);
                    }
                }
            }
            return;
        }
        if(ppPosY - 1 >= 0) {
            if(actual->getPassArr()[(int)(ppPosY -1)][(int)ppPosX] == 0) {
                std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i(ppPosX CASES, (ppPosY - 1) CASES));
                for(Event *nextEvent : nextEvents) {
                    if(!nextEvent->isPassable()) {
                        return;
                    }
                }
                UNLOCK_TP
                moving = TO_UP;
                ppPosY--;

                if(nextEvents.size() > 0) {
                    for(Event *nextEvent : nextEvents) {
                        if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN && ((nextEvent->getSide() & SIDE_UP) == SIDE_UP)) {
                            nextEvent->action(Main::player);
                        }
                    }
                }
            }

        }
    }
}

void Overworld::down() {
    if(anim == -1 && !movementLock) {//Si une animation n'est pas dÃ©jÃ  en cours
        if(ppDir != TO_DOWN) {
            ppDir = TO_DOWN;
            return;
        }
        startFrames = frames;
        anim = TO_DOWN;
        if(debugMode) {
            UNLOCK_TP
            moving = TO_DOWN;
            ppPosY++;
            std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i(ppPosX CASES, (ppPosY + 1) CASES));
            if(nextEvents.size() > 0) {
                for(Event *nextEvent : nextEvents) {
                    if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN) {
                        nextEvent->action(Main::player);
                    }
                }
            }
            return;
        }
        if(ppPosY + 1 < actual->getH()) {
            if(actual->getPassArr()[(int)(ppPosY + 1)][(int)ppPosX] == 0) {//VÃ©rification des boites de collisions
                std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i(ppPosX CASES, (ppPosY + 1) CASES));
                for(Event *nextEvent : nextEvents) {
                    if(!nextEvent->isPassable()) {
                        return;
                    }
                }
                UNLOCK_TP
                moving = TO_DOWN;
                ppPosY++;
                if(nextEvents.size() > 0) {
                    for(Event *nextEvent : nextEvents) {
                        if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN && ((nextEvent->getSide() & SIDE_DOWN) == SIDE_DOWN)) {
                            nextEvent->action(Main::player);
                        }
                    }
                }
            }

        }
    }
}

void Overworld::right() {
    if(anim == -1 && !movementLock) {
        if(ppDir != TO_RIGHT) {
            ppDir = TO_RIGHT;
            return;
        }
        startFrames = frames;
        anim = TO_RIGHT;
        if(debugMode) {
            UNLOCK_TP
            moving = TO_RIGHT;
            ppPosX++;
            std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i((ppPosX + 1) CASES, ppPosY CASES));
            if(nextEvents.size() > 0) {
                for(Event *nextEvent : nextEvents) {
                    if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN) {
                        nextEvent->action(Main::player);
                    }
                }
            }
            return;
        }
        if(ppPosX + 1 < actual->getW()) {
            if(actual->getPassArr()[(int)(ppPosY)][(int)(ppPosX + 1)] == 0 || actual->getPassArr()[(int)(ppPosY)][(int)(ppPosX + 1)] == 5) {
                std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i((ppPosX + 1) CASES, ppPosY CASES));
                for(Event *nextEvent : nextEvents) {
                    if(!nextEvent->isPassable()) {
                        return;
                    }
                }
                UNLOCK_TP
                moving = TO_RIGHT;
                ppPosX++;
                if(nextEvents.size() > 0) {
                    for(Event *nextEvent : nextEvents) {
                        if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN && ((nextEvent->getSide() & SIDE_RIGHT) == SIDE_RIGHT)) {
                            nextEvent->action(Main::player);
                        }
                    }
                }
            }
        }
    }
}


void Overworld::left() {
    if(anim == -1 && !movementLock) {
        if(ppDir != TO_LEFT) {
            ppDir = TO_LEFT;
            return;
        }
        startFrames = frames;
        anim = TO_LEFT;
        if(debugMode) {
            UNLOCK_TP
            moving = TO_LEFT;
            ppPosX--;
            std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i((ppPosX - 1) CASES, ppPosY CASES));
            if(nextEvents.size() > 0) {
                for(Event *nextEvent : nextEvents) {
                    if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN) {
                        nextEvent->action(Main::player);
                    }
                }
            }
            return;
        }
        if(ppPosX - 1 >= 0) {
            if(actual->getPassArr()[(int)(ppPosY)][(int)(ppPosX - 1)] == 0) {
                std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i((ppPosX - 1) CASES, ppPosY CASES));
                for(Event *nextEvent : nextEvents) {
                    if(!nextEvent->isPassable()) {
                        return;
                    }
                }
                UNLOCK_TP
                moving = TO_LEFT;
                ppPosX--;
                if(nextEvents.size() > 0) {
                    for(Event *nextEvent : nextEvents) {
                        if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN && ((nextEvent->getSide() & SIDE_LEFT) == SIDE_LEFT)) {
                            nextEvent->action(Main::player);
                        }
                    }
                }
            }

        }
    }
}

#undef UNLOCK_TP


int Overworld::overworld() {
  Main::mainframe.mapsInit.wait();
    for(Map *map : Initializer::maps) {
        for(Event *event : map->getEvents()) {
            Events::TalkingEvent *te = dynamic_cast<Events::TalkingEvent *>(event);
            if(te != nullptr) {
                te->reloadKeys();
            }
        }
    }

    music->play();
    Main::mainframe.frame.setView(camera);
    int returned = boucle();
    music->stop();
    return returned;
}

int Overworld::boucle() {
    bool continuer = true;
    while(continuer) {
        if((GET_TICKS - ancientTick >= FPS_TICKS)) {
            fpsCounter++;
            if(GET_TICKS - oldTicksFps >= 1000) {
                fps = "";
                fps << fpsCounter;
                fpsPrint.setString(fps);
                fpsCounter = 0;
            }
            frames++;
#define DEBUG_REPORT
#ifdef DEBUG_REPORT
            cout << "[FRAME N°" << frames << "]" << endl;
            cout << "Boucle : Normal" << endl;
            cout << "Tick: " << ticks.getElapsedTime().asMilliseconds() << "ms" << endl;
            cout << "PlayerPosition: " << ppPosX << " - " << ppPosY << endl;
            cout << "PlayerPositionPx: " << character.getPosition().x << " - " << character.getPosition().y << endl;
            cout << "Moving: " << moving << endl;
            cout << "Anim: " << anim << endl;
            cout << "PlayerDirection: " << ppDir << endl;
            cout << "DebugMode: " << debugMode << endl;
            cout << "MapPos: " << layer1->getPosition().x << " - " << layer1->getPosition().y << endl;
#endif

            //cout << "Position perso : P(" << ppPosX << ";" << ppPosY << ")" << endl;
            if(justTp) {
                tpCount++;
                justTp = tpCount < 0;
            }

            ancientTick = GET_TICKS;
	    Main::mainframe.window.pollEvent(Main::mainframe.events);

            switch(Main::mainframe.events.type) {
                QUIT

            case sf::Event::KeyPressed:
                if(Main::mainframe.events.key.code == sf::Keyboard::Equal) {
                    debugMode = !debugMode;
                }
                if(debugMode) {
                    if(Main::mainframe.events.key.code == sf::Keyboard::F10) {
                        printlayer[0] = !printlayer[0];
                    }
                    if(Main::mainframe.events.key.code == sf::Keyboard::F11) {
                        printlayer[1] = !printlayer[1];
                    }
                    if(Main::mainframe.events.key.code == sf::Keyboard::F12) {
                        printlayer[2] = !printlayer[2];
                    }

                    if(Main::mainframe.events.key.code == sf::Keyboard::F5) {
                        tp(4, sf::Vector2i(0, 1), true);
                    } else if(Main::mainframe.events.key.code == sf::Keyboard::F6) {
                        tp(5, sf::Vector2i(0, 0), true);
                    } else if(Main::mainframe.events.key.code == sf::Keyboard::F1) {
                        tp(0, sf::Vector2i(25, 28), true);
                    } else if(Main::mainframe.events.key.code == sf::Keyboard::F2) {
                        tp(1, sf::Vector2i(8, 14), true);
                    } else if(Main::mainframe.events.key.code == sf::Keyboard::F3) {
                        tp(2, sf::Vector2i(15, 14), true);
                    } else if(Main::mainframe.events.key.code == sf::Keyboard::F4) {
                        tp(3, sf::Vector2i(8, 14), true);
                    }
                }
            default:
                break;
            }
            ECHAP
            if(Main::player.gameIsOver) {
                return -1;
            }
            if(!justTp) {
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
            if(debugMode) {
                if(isKeyPressed(sf::Keyboard::Numpad2)) {
                    camera.move(0, 4);
                }
                if(isKeyPressed(sf::Keyboard::Numpad4)) {
                    camera.move(-4, 0);
                }
                if(isKeyPressed(sf::Keyboard::Numpad8)) {
                    camera.move(0, -4);
                }
                if(isKeyPressed(sf::Keyboard::Numpad6)) {
                    camera.move(4, 0);
                }
                debugText.setString("Debug mode");
                debugText.setPosition(Main::mainframe.frame.mapPixelToCoords(sf::Vector2i(0, 0)));
                debugText.setFont(Main::mainframe.font);
                debugText.setColor(sf::Color(127, 127, 127));
                debugText.setCharacterSize(40);
                fpsPrint.setPosition(Main::mainframe.frame.mapPixelToCoords(sf::Vector2i(0, 50)));
                fpsPrint.setFont(Main::mainframe.font);
                fpsPrint.setCharacterSize(48);
            }

            Main::mainframe.frame.clear(sf::Color::Black);
            if((debugMode ? printlayer[0] : true)) {
                Main::mainframe.frame.draw(*layer1);
            }
            if((debugMode ? printlayer[1] : true)) {
                Main::mainframe.frame.draw(*layer2);
            }
            actual->updateEvents(Main::player);
            for(Event *event : actual->getEvents()) {
                if(event->getPosition().y <= ppPosY) {
                    Main::mainframe.frame.draw(*event->getSprite());
                }
            }
            if(anim != -1 && !anims) {
                character.setTexture(Initializer::walkingPP[anim]);
                animsCounter++;
                anims = animsCounter > 8;

            } else if(anim != -1 && anims) {
                character.setTexture(Initializer::walkingPP2[anim]);
                animsCounter++;
                if(animsCounter > 16) {
                    anims = false;
                    animsCounter = 0;
                }
            } else if(anim == -1) {
                character.setTexture(Initializer::texturePP[ppDir]);
            }
            Main::mainframe.frame.draw(character);
            for(Event *event : actual->getEvents()) {
                if(event->getPosition().y > ppPosY) {
                    Main::mainframe.frame.draw(*event->getSprite());
                }
            }
            if((debugMode ? printlayer[2] : true)) {
                Main::mainframe.frame.draw(*layer3);
            }
            if(moving == -1) {
                std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i(ppPosX CASES, ppPosY CASES));
                if(nextEvents.size() > 0) {
                    for(Event *nextEvent : nextEvents) {
                        if(nextEvent->getEventTrigger() == Events::EventTrigger::BE_IN) {
                            bool go = false;
                            if(((nextEvent->getSide() & SIDE_UP) == SIDE_UP) && ppDir == TO_UP) {
                                go = true;
                            } else if(((nextEvent->getSide() & SIDE_DOWN) == SIDE_DOWN) && ppDir == TO_DOWN) {
                                go = true;
                            } else if(((nextEvent->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && ppDir == TO_RIGHT) {
                                go = true;
                            } else if(((nextEvent->getSide() & SIDE_LEFT) == SIDE_LEFT) && ppDir == TO_LEFT) {
                                go = true;
                            }
                            if(go) {
                                nextEvent->action(Main::player);
                            }
                        }
                    }
                }
            }
            actual->updateElements(Main::mainframe.frame);
            if(scrolling && !debugMode) {
                camera.setCenter(character.getPosition().x + 16, character.getPosition().y + 16);
            }
            Main::mainframe.frame.setView(camera);
            if(debugMode) {
                Main::mainframe.frame.draw(debugText);
                Main::mainframe.frame.draw(fpsPrint);
            }
            Main::mainframe.frame.display();
            Main::mainframe.winRefresh();
            if(anim == -1) {
                if(isKeyPressed(sf::Keyboard::Return)) {
                    int lx = ppPosX;
                    int ly = ppPosY;
                    switch(ppDir) {
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
                    vector<Event *> events = actual->getEvent(sf::Vector2i(lx CASES, ly CASES));
                    /*if(events.size() == 0){
                      events = actual->getEvent(sf::Vector2i(ppPosX CASES, ppPosY CASES));
                      }*/

                    if(events.size() > 0) {
                        for(unsigned int i = 0; i < events.size(); i++) {
                            if(events[i]->getEventTrigger() == Events::EventTrigger::PRESS) {
                                bool go = false;
                                if(((events[i]->getSide() & SIDE_UP) == SIDE_UP) && ppDir == TO_UP) {
                                    go = true;
                                } else if(((events[i]->getSide() & SIDE_DOWN) == SIDE_DOWN) && ppDir == TO_DOWN) {
                                    go = true;
                                } else if(((events[i]->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && ppDir == TO_RIGHT) {
                                    go = true;
                                } else if(((events[i]->getSide() & SIDE_LEFT) == SIDE_LEFT) && ppDir == TO_LEFT) {
                                    go = true;
                                }
                                if(go) {
                                    events[i]->action(Main::player);
                                }
                            }
                        }
                    }
                }
            }
            if(anim == TO_UP) {
                if(frames - startFrames >= 7) {
                    if(moving == TO_UP) {
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
                    if(moving == TO_DOWN) {
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
                    if(moving == TO_LEFT) {
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
                    if(moving == TO_RIGHT) {
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
    return 0;
}

int Overworld::boucleDialog(vector<sf::String> const& dialogs) {
    int sizeOfTxt = dialogs.size();
    sf::String txtEnCours[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};
    bool continuer = true;
    unsigned int dialog = 0;
    bool changeDialog = false;
    unsigned int i = 0;
    unsigned int line = 0;

    int phase = 0;
    sf::Vector2f posArrow = Main::mainframe.frame.mapPixelToCoords(sf::Vector2i(512-75, 512-30));
    Main::mainframe.arrDial.setPosition(posArrow);


    while(continuer && phase == 0) {
        if((GET_TICKS - ancientTick >= FPS_TICKS)) {
            frames++;
            if(justTp) {
                tpCount++;
                justTp = tpCount < 0;
            }

            ancientTick = GET_TICKS;
            Main::mainframe.window.pollEvent(Main::mainframe.events);

            switch(Main::mainframe.events.type) {
                QUIT

            case sf::Event::KeyPressed:
                if(Main::mainframe.events.key.code == sf::Keyboard::Space) {
                    DIALOG_PASS(dialogs)
                }
                break;
            default:
                break;
            }
            if(isKeyPressed(sf::Keyboard::Escape)) {
                Main::player.gameIsOver = true;
                return -1;
            }
            Main::mainframe.frame.draw(*layer1);
            Main::mainframe.frame.draw(*layer2);
            for(Event *event : actual->getEvents()) {
                if(event->getPosition().y <= ppPosY) {
                    Main::mainframe.frame.draw(*event->getSprite());
                }
            }
            if(anim != -1 && !anims) {
                character.setTexture(Initializer::walkingPP[anim]);
                animsCounter++;
            } else if(anim != -1 && anims) {
                character.setTexture(Initializer::walkingPP2[anim]);
                animsCounter++;
            } else if(anim == -1) {
                character.setTexture(Initializer::texturePP[ppDir]);
            }
            Main::mainframe.frame.draw(character);
            for(Event *event : actual->getEvents()) {
                if(event->getPosition().y > ppPosY) {
                    Main::mainframe.frame.draw(*event->getSprite());
                }
            }
            Main::mainframe.frame.draw(*layer3);
            if(scrolling) {
                camera.setCenter(character.getPosition().x + 16, character.getPosition().y + 16);
            }
            Main::mainframe.frame.setView(Main::mainframe.frame.getDefaultView());
            Main::mainframe.frame.setView(camera);
            actual->updateElements(Main::mainframe.frame);
            if(!changeDialog) {
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
            Main::mainframe.printText(Main::mainframe.frame, txtEnCours);
            ANIM_ARROW
            Main::mainframe.frame.display();
            Main::mainframe.winRefresh();



        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }


    }
    return 0;
}


