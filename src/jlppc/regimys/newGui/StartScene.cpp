#include "StartScene.hpp"
#include "../start/main.hpp"
#include "Animations.hpp"
#include "MainFrame.hpp"

UNS

namespace MainFrame {
namespace StartScene {
//Déclaration des SDL_Rect et des SDL_Texture secondaires, necessaires a cette scene (a détruire)
sf::Sprite fondT;
sf::Sprite profT;
sf::Sprite arrDial;
sf::Sprite textUre;
sf::Music fondMus;
//Déclaration des variables utilitaires (sera supprimé en cours de travail)
//Part 0
bool continuer = true;
long ancientTick = 0;
sf::String txtP0[18];//Deux cases == Deux lignes. 3 cases == Deux lignes + un nouveau dialogue
int sizeOfTxt = 18;
sf::String txtEnCours[] = {sf::String(" "), sf::String(" "), sf::String(" ")};
//SDL_Surface *sfce = NULL;
int line = 0, i = 0, dialog = 0;
bool changeDialog = false;
int phase = 0;
bool joypressed = false;
//Part 1
char pName[16] = "               ";
int k = 0;
sf::Sprite fondNE;
sf::Text texteDescs[4];//To destroy in part 1
sf::Text nameT;//To destroy in part 1
bool shift = false;
bool caps = false;
//Part 2
sf::String txtP1[15];

sf::Texture textures[5];



void destroyVars() {

}

/**Initialise les variables*/
void initVars() {
    unsigned int it = 0;
    for(it = 0; it < 18; it++) {
        ostringstream oss;
        oss << "prof.dialog.start." << it + 1;
        txtP0[it] = kget(oss.str());
    }
    int ite = 1;
    it++;
    txtP1[0] = kget("prof.dialog.start.19");
    for(it = it; it < 27; it++) {
        ostringstream oss;
        oss << "prof.dialog.start." << it + 1;
        txtP1[ite] = kget(oss.str());
        ite++;
    }
    rlog << PRINT_TICKS << "Initialisation des variables de la scene d'intro" << endl;
    MainFrame::dialog.setPosition(0, 362);
    profT.setPosition((fondT.getGlobalBounds().height / 2) - (profT.getGlobalBounds().width / 2) + 10, ((fondT.getGlobalBounds().height - MainFrame::dialog.getGlobalBounds().height / 2) - (profT.getGlobalBounds().height / 2) + 50));
    texteDescs[1].setPosition(85, 25);
    texteDescs[0].setPosition(155, 200);
    texteDescs[2].setPosition(95, 375);
    texteDescs[4].setPosition(95, 375+30);

    txtEnCours[0] = sf::String(" ");
    txtEnCours[1] = sf::String(" ");
    txtEnCours[2] = sf::String(" ");
    sizeOfTxt = 18;
    changeDialog = false;
    phase = 0;
    joypressed = false;
    line = 0;
    i = 0;
    dialog = 0;
    //Initialisation des images
    rlog << PRINT_TICKS << "Initialisation des sprites..." << endl;
#ifdef _WIN32
    textures[0].loadFromFile("ressources\\backgrounds\\start\\startscene.png");
    textures[1].loadFromFile("ressources\\sprites\\chara\\jlppc\\profkiwai.png");
    textures[2].loadFromFile("ressources\\backgrounds\\dialog\\dialog.png");
    textures[3].loadFromFile("ressources\\sprites\\misc\\arrDial.png");
    textures[4].loadFromFile("ressources\\backgrounds\\start\\nameEntry.png");
#else
    textures[0].loadFromFile("ressources/backgrounds/start/startscene.png");
    textures[1].loadFromFile("ressources/sprites/chara/jlppc/profkiwai.png");
    textures[2].loadFromFile("ressources/backgrounds/dialog/dialog.png");
    textures[3].loadFromFile("ressources/sprites/misc/arrDial.png");
    textures[4].loadFromFile("ressources/backgrounds/start/nameEntry.png");
#endif

    fondT.setTexture(textures[0]);
    profT.setTexture(textures[1]);
    MainFrame::dialog.setTexture(textures[2]);
    arrDial.setTexture(textures[3]);
    fondNE.setTexture(textures[4]);



    rlog << PRINT_TICKS << "Fin des initialisations" << endl;
    for(unsigned int iterator; iterator < 4; iterator++){
        texteDescs[iterator].setCharacterSize(FONT_SIZE_DEFAULT);
        texteDescs[iterator].setColor(sf::Color::Black);
        texteDescs[iterator].setFont(font);
    }
    texteDescs[0].setString(kget("nameEntry.med"));

    texteDescs[1].setString(kget("nameEntry.top"));

    texteDescs[2].setString(kget("nameEntry.indic.1"));

    texteDescs[3].setString(kget("nameEntry.indic.2"));
#ifdef _WIN32
    fondMus.openFromFile("ressources\\audio\\music\\intro.ogg");
#else
    fondMus.openFromFile("ressources/audio/music/intro.ogg");
#endif
    arrDial.setPosition(512-75, 512-30);
}

/**Verifie les erreurs de variables*/
int verifVars() {
}

int boucle0() {
    rlog << PRINT_TICKS << "Début de la boucle n°0" << endl;
    //Boucle n°1
    while (continuer) {
        if ((ticks.getElapsedTime().asMilliseconds() - ancientTick) >= FPS_TICKS) {

            ancientTick = ticks.getElapsedTime().asMilliseconds();

            frame.pollEvent(events);

            switch (events.type) {

                QUIT

            }

            ECHAP
            else if(isKeyPressed(sf::Keyboard::P)){
                return 2;
            }else if(isKeyPressed(sf::Keyboard::Space)){
                DIALOG_PASS(txtP0)
            }

            if (phase == 0) {
                frame.clear(sf::Color::White);
                frame.draw(fondT);
                frame.draw(profT);
                frame.draw(MainFrame::dialog);
                if (!changeDialog) {
                    //Affichage caractère par caractère
                    if (!(i >= txtP0[line + dialog].toUtf32().size())) {

                        if (txtEnCours[line] == sf::String(" ")) {
                            txtEnCours[line] = txtP0[line + dialog].toUtf32()[i];
                        } else {
                            txtEnCours[line] += txtP0[line + dialog].toUtf32()[i];

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
                sf::String tab[3] = {txtEnCours[0], txtEnCours[1], txtEnCours[2]};
                printText(frame, tab);
                ANIM_ARROW
                frame.display();
            } else {
                break;
            }


        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }

    }
    return 0;
}

int boucle1() {
    frame.clear(sf::Color::White);
    frame.draw(fondNE);
    FOR_EACH(sf::Text, texteDescs, 4,{)
        frame.draw(*objActuel);
    }
    frame.display();
    while (continuer) {
        frame.waitEvent(events);
        switch (events.type) {
            QUIT

        case sf::Event::TextEntered:
            if(events.text.unicode == 8){//Backspace
                pName[k] = ' ';
                    if (k != 0) {
                        k--;
                    }
            }else if(events.text.unicode == '\n' || events.text.unicode < 32){
            }else{
                if (k != 14) {
                    k++;
                }
               pName[k] = events.text.unicode;
            }

        }

            frame.clear(sf::Color::White);
        frame.draw(fondNE);
        FOR_EACH(sf::Text, texteDescs, 4,{)
            frame.draw(*objActuel);
        }
        nameT.setString(string(pName));
        frame.display();


    }
    return 0;
}

int boucle2() {

    while (continuer) {
        if ((GET_TICKS - ancientTick) >= FPS_TICKS) {

            ancientTick = GET_TICKS;

            frame.pollEvent(events);

            switch (events.type) {

                QUIT
            }

            if(isKeyPressed(sf::Keyboard::Space)){
                DIALOG_PASS(txtP1);
            }
            if (phase == 2) {
                frame.clear(sf::Color::White);
                frame.draw(fondT);
                frame.draw(profT);
                frame.draw(MainFrame::dialog);
                if (!changeDialog) {

                    if (!(i >= txtP1[line + dialog].toUtf32().size())) {

                        if (txtEnCours[line] == " ") {
                            txtEnCours[line] = txtP1[line + dialog].toUtf32()[i];
                        } else {
                            txtEnCours[line] += txtP1[line + dialog].toUtf32()[i];
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
                sf::String tab[3] = {txtEnCours[0], txtEnCours[1], txtEnCours[2]};
                printText(frame, tab);
                ANIM_ARROW
                frame.display();
            } else {
                return 0;
            }


        } else {
            Utils::wait(FPS_TICKS - (GET_TICKS - ancientTick));
        }
    }
    return 0;
}

int startScene() {
    verifVars();
    //Départ de la musique
    fondMus.play();

    //Initialisation des tailles

    //Vesrification des problèmes possibles

    //Initialisation des variables utiles pour la boucle
    frame.display();
    int result = boucle0();
    if(result == -1) {
        return -1;
    }else if(result == 2){;
        return 2;
    }

    continuer = true;



    phase = 1;
    rlog << PRINT_TICKS << "Chargement de la boucle n°1" << endl;

    //Animation 1
    Animations::animFenOpen(frame, fondT);

    rlog << PRINT_TICKS << "Début de la boucle n°1" << endl;

    if(boucle1() == -1) {

        return -1;
    }

    continuer = true;
    //Animation 2
    Animations::animFenClose(frame, fondT);

    txtP1[0]+=(string(pName) + kget("prof.dialog.start.19.5"));

    phase = 2;

    sizeOfTxt = 27 - 18;
    i = 0;
    line = 0;
    dialog = 0;
    txtEnCours[0] = sf::String(" ");
    txtEnCours[1] = sf::String(" ");
    txtEnCours[2] = sf::String(" ");
    changeDialog = false;
    rlog << PRINT_TICKS << "Début de la boucle n°2" << endl;
    if(boucle2() == -1) {
        return -1;
    }
    phase++;
    return 0;


}
}
}

