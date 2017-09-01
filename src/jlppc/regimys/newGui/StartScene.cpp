#include "StartScene.hpp"
#include "../start/main.hpp"
#include "Animations.hpp"
#include "MainFrame.hpp"
#include "../start/OpString.hpp"

#define SIZE_P0 18
#define SIZE_P1 15

UNS



void StartScene::initStrings() {
    unsigned int it = 0;
    for(it = 0; it < 18; it++) {
        string actual;
        actual << string("prof.dialog.start.") << it+1;
        txtP0[it] = kget(actual);
    }
    int ite = 1;
    it++;
    strName = OpString("prof.dialog.start.19", Main::player.getNameP());
    txtP1[0] = strName.getString();
    for(it = it; it < 27; it++) {
        string actual;
        actual << string("prof.dialog.start.") << it+1;
        txtP1[ite] = kget(actual);
        ite++;
    }

    textDescs[0].setString(kget("nameEntry.med"));
    textDescs[1].setString(kget("nameEntry.top"));
    textDescs[2].setString(kget("nameEntry.indic.1"));
    textDescs[3].setString(kget("nameEntry.indic.2"));
}

void StartScene::initVars() {
    initStrings();
    rlog << PRINT_TICKS << "Initializating start scene's variables." << endl;
    Main::mainframe.dialog.setPosition(0, 362);
    textDescs[1].setPosition(85, 25);
    textDescs[0].setPosition(155, 200);
    textDescs[2].setPosition(95, 375);
    textDescs[3].setPosition(95, 405);


    txtEnCours[0] = sf::String(" ");
    txtEnCours[1] = sf::String(" ");
    txtEnCours[2] = sf::String(" ");
    sizeOfTxt = 18;

    rlog << PRINT_TICKS << "Initialization of the sprites" << endl;
#ifdef _WIN32
    textures[0].loadFromFile("ressources\\backgrounds\\start\\startscene.png");
    textures[1].loadFromFile("ressources\\sprites\\chara\\jlppc\\profkiwai.png");
    textures[2].loadFromFile("ressources\\backgrounds\\dialog\\dialog.png");
    textures[3].loadFromFile("ressources\\sprites\\misc\\arrDial.png");
    textures[4].loadFromFile("ressources\\backgrounds\\start\\nameEntry.png");
    bgMus.openFromFile("ressources\\audio\\music\\intro.ogg");
#else
    textures[0].loadFromFile(RESSOURCES_PATH + "backgrounds/start/startscene.png");
    textures[1].loadFromFile(RESSOURCES_PATH + "sprites/chara/jlppc/profkiwai.png");
    textures[2].loadFromFile(RESSOURCES_PATH + "backgrounds/dialog/dialog.png");
    textures[3].loadFromFile(RESSOURCES_PATH + "sprites/misc/arrDial.png");
    textures[4].loadFromFile(RESSOURCES_PATH + "backgrounds/start/nameEntry.png");
    bgMus.openFromFile(RESSOURCES_PATH + "audio/music/intro.ogg");
#endif
    bg.setTexture(textures[0]);
    prof.setTexture(textures[1]);
    Main::mainframe.dialog.setTexture(textures[2]);
    Main::mainframe.arrDial.setTexture(textures[3]);
    bgName.setTexture(textures[4]);
    bgName.setPosition(0, 0);
    bgMus.setLoop(true);

    bg.setPosition(0, 0);
    prof.setPosition(205, 120);
    prof.setScale(1.5, 1.5);

    rlog << PRINT_TICKS << "End of start scene initializations" << endl;
    for(sf::Text &cellTxt : textDescs) {
        cellTxt.setCharacterSize(FONT_SIZE_DEFAULT);
        cellTxt.setColor(sf::Color::Black);
        cellTxt.setFont(Main::mainframe.font);
    }

    nameField.setFont(Main::mainframe.font);
    nameField.setPosition(120, 300);

    Main::mainframe.arrDial.setPosition(437, 482);

}

int StartScene::boucle0() {
    bool continuer = true;
    while(continuer) {
        if((ticks.getElapsedTime().asMilliseconds() - ancientTick) >= FPS_TICKS) {
            ancientTick = ticks.getElapsedTime().asMilliseconds();

	    Main::mainframe.window.pollEvent(Main::mainframe.events);

            switch (Main::mainframe.events.type) {

                QUIT

            case sf::Event::KeyPressed:
                if(Main::mainframe.events.key.code == sf::Keyboard::Space) {
                    DIALOG_PASS(txtP0)
                }
                break;
            default:
                break;
            }

            ECHAP
            else if(isKeyPressed(sf::Keyboard::P))
                return 2;

            if(phase == 0) {
                Main::mainframe.frame.clear(sf::Color::White);
                Main::mainframe.frame.draw(bg);
                Main::mainframe.frame.draw(prof);
                Main::mainframe.frame.draw(Main::mainframe.dialog);
                if(!changeDialog) {
                    total = line + dialog;
                    if (!(i >= txtP0[total].toUtf32().size())) {

                        if (txtEnCours[line] == sf::String(" ")) {
                            txtEnCours[line] = txtP0[total].toUtf32()[i];
                        } else {
                            txtEnCours[line] += txtP0[total].toUtf32()[i];
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

                sf::String arr[3] = {txtEnCours[0], txtEnCours[1], txtEnCours[2]};
                Main::mainframe.printText(Main::mainframe.frame, arr);
                ANIM_ARROW
                Main::mainframe.frame.display();
                Main::mainframe.winRefresh();
            } else {
                continuer = false;
            }
        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }
    }
    return 0;
}

int StartScene::boucle1() {
    Main::mainframe.window.setKeyRepeatEnabled(true);
    Main::mainframe.frame.clear(sf::Color::White);
    Main::mainframe.frame.draw(bgName);
    for(sf::Text desc : textDescs) {
        desc.setColor(sf::Color::White);
        desc.setFont(Main::mainframe.font);
        Main::mainframe.frame.draw(desc);
    }
    Main::mainframe.frame.display();
    Main::mainframe.winRefresh();
    bool continuer = true;
    while(continuer) {
        Main::mainframe.window.waitEvent(Main::mainframe.events);
        switch (Main::mainframe.events.type) {
            QUIT

        case sf::Event::TextEntered:
            if(Main::mainframe.events.text.unicode == 8) { //Backspace
                if(!pName.empty())
                    pName.pop_back();//C++11
            } else if(Main::mainframe.events.text.unicode == '\n' || Main::mainframe.events.text.unicode <= 32) {//Do nothing
            } else {
                if (pName.size() < 14) {//14 = Max name length
                    pName += Main::mainframe.events.text.unicode;
                }
            }
            break;

        case sf::Event::KeyPressed:
            if(Main::mainframe.events.key.code == sf::Keyboard::Return) {
                if (pName.empty()) {
                    pName = "Céchine";
                }
                continuer = false;
            }
            break;
        default:
            break;
        }

        ECHAP

        Main::mainframe.frame.clear(sf::Color::White);
        Main::mainframe.frame.draw(bgName);
        for(sf::Text desc : textDescs) {
            desc.setColor(sf::Color::White);
            desc.setFont(Main::mainframe.font);
            Main::mainframe.frame.draw(desc);
        }
        nameField.setString(pName);
        Main::mainframe.frame.draw(nameField);
        Main::mainframe.frame.display();
        Main::mainframe.winRefresh();


    }
    Main::mainframe.window.setKeyRepeatEnabled(false);
    Main::player.setName(pName);
    txtP1[0] = strName.getString();
    return 0;

}

int StartScene::boucle2() {
    bool continuer = true;
    while(continuer) {
        if((ticks.getElapsedTime().asMilliseconds() - ancientTick) >= FPS_TICKS) {
            ancientTick = ticks.getElapsedTime().asMilliseconds();

            Main::mainframe.window.pollEvent(Main::mainframe.events);

            switch (Main::mainframe.events.type) {

                QUIT

            case sf::Event::KeyPressed:
                if(Main::mainframe.events.key.code == sf::Keyboard::Space) {
                    DIALOG_PASS(txtP1)
                }
                break;

            default:
                break;

            }

            ECHAP

            if(phase == 2) {
                Main::mainframe.frame.clear(sf::Color::White);
                Main::mainframe.frame.draw(bg);
                Main::mainframe.frame.draw(prof);
                Main::mainframe.frame.draw(Main::mainframe.dialog);
                if(!changeDialog) {
                    total = line + dialog;
                    if (!(i >= txtP1[total].toUtf32().size())) {

                        if (txtEnCours[line] == sf::String(" ")) {
                            txtEnCours[line] = txtP1[total].toUtf32()[i];
                        } else {
                            txtEnCours[line] += txtP1[total].toUtf32()[i];
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

                sf::String arr[3] = {txtEnCours[0], txtEnCours[1], txtEnCours[2]};
                Main::mainframe.printText(Main::mainframe.frame, arr);
                ANIM_ARROW
                Main::mainframe.frame.display();
                Main::mainframe.winRefresh();
            } else {
                continuer = false;
            }
        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }
    }
    return 0;
}

int StartScene::startScene() {
    bgMus.play();

    int result = boucle0();
    if(result == -1 || result == 2) {
        return result;
    }
    phase = 1;

    //Animation 1
    Animations::animWinOpen(Main::mainframe.frame, bg);


    if(boucle1() == -1) {
        return -1;
    }

    //Animation 2
    Animations::animWinClose(Main::mainframe.frame, bg);
    phase = 2;
    sizeOfTxt = 27 - 18;
    i = 0;
    line = 0;
    dialog = 0;
    txtEnCours[0] = sf::String(" ");
    txtEnCours[1] = sf::String(" ");
    txtEnCours[2] = sf::String(" ");
    changeDialog = false;

    if(boucle2() == -1) {
        return -1;
    }

    bgMus.stop();

    return 0;


}
