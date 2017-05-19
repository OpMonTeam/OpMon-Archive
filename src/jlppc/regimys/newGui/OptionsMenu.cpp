#include "OptionsMenu.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"
#include "../save/OptionsSave.hpp"
#include "MainFrame.hpp"

UNS

namespace MainFrame {
namespace MainMenu {
namespace OptionsMenu {

sf::Sprite fondOpt;
sf::Text langFr;
sf::Text langEng;
sf::Text langEsp;
sf::Text txtRetour;
sf::Text txtOptions;
sf::Text txtOpt1;
sf::Text txtOpt2;
sf::Text txtOpt3;
sf::Text txtOpt4;
sf::Text txtOpt5;
sf::Sprite rectSurb;
sf::Vector2f curPosOpt[6] = {};
int optionSelect = -1;
int curPosOptI = 0;
int curPosLangI = 0;

sf::Text txtLang;
sf::Sprite fondLangues;
//J_Texture listeLangues[3] = {};
sf::Vector2f curPosLang[4] = {};

void initVars() {

#ifdef _WIN32
    fondOpt.loadTextureFromFile("ressources\\backgrounds\\options.png");
    rectSurb.loadTextureFromFile("ressources\\sprites\\misc\\selectBar.png");
    fondLangues.loadTextureFromFile("ressources\\backgrounds\\lang.png");

#else
    fondOpt.loadTextureFromFile("ressources/backgrounds/options.png");
    rectSurb.loadTextureFromFile("ressources/sprites/misc/selectBar.png");
    fondLangues.loadTextureFromFile("ressources/backgrounds/lang.png");


#endif // _WIN32
    langFr.setString(L"Français");
    langEng.setString("English");
    langEsp.setString(L"Espa\u00F1ol");
    txtRetour.setString(kget("options.retour"));
    txtOptions.setString(kget("options.title"));
    txtOpt1.setString(kget("options.ecran"));
    txtOpt1.setColor(sf::Color::Red);
    txtOpt2.setString(kget("options.lang"));
    txtOpt3.setString(kget("options.vol"));
    txtOpt3.setColor(sf::Color::Red);
    txtOpt4.setString( kget("options.control"));
    txtOpt4.setColor(sf::Color::Red);
    txtOpt5.setString(kget("options.credit"));
    txtOpt5.setColor(sf::Color::Red);

    txtLang.setString(kget("options.lang.title"));


    txtOpt1.setPosition(120, 100);
    txtOpt2.setPosition(120, 170);
    txtOpt3.setPosition(120, 240);
    txtOpt4.setPosition(120, 310);
    txtOpt5.setPosition(120, 380);

    langEsp.setPosition(45, 170);
    langEng.setPosition(45, 100);
    langFr.setPosition(45, 240);

    txtRetour.setPosition(55, 25);

    txtLang.setPosition(250, 25);
    txtOptions.setPosition(230, 25);

    curPosOpt[0].x = 23;
    curPosOpt[0].y = 17;

    curPosLang[0].x = 23;
    curPosLang[0].y = 17;

    for(int i = 1, j = 86; i < 6; i++) {
        curPosOpt[i].x = 23;
        curPosOpt[i].y = j;
        j+=69;
    }

    for(int i = 1, j = 86; i < 4; i++){
        curPosLang[i].x = 23;
        curPosLang[i].y = j;
        j+=69;
    }


}

void verifVars() {

}

void deleteVars() {

}

int optionsMenu() {
    verifVars();
    //Lancement du menu
    return boucle();
}

int boucle() {
    while(continuer) {
        frame.waitEvent(events);
        switch(events.type) {
            QUIT
        }

        ECHAP
        if(isKeyPressed(sf::Keyboard::Return)){
            switch(curPosOptI) {
                case 0:
                    return 0;
                case 1:
                    bruitNope.play();
                    break;
                case 2:
                    boucleLang();
                    break;
                case 3:
                    bruitNope.play();//Non disponible
                    break;
                case 4:
                    bruitNope.play();//Non disponible
                    break;
                case 5:
                    bruitNope.play();//Non disponible
                    break;
            }
        }else if(isKeyPressed(sf::Keyboard::Up)){
                bruitArr.play();
                curPosOptI--;
                if(curPosOptI >= 6) {
                    curPosOptI = 0;
                } else if(curPosOptI < 0) {
                    curPosOptI = 5;
                }
        }else if(isKeyPressed(sf::Keyboard::Down)){
                bruitArr.play();
                curPosOptI++;
                if(curPosOptI >= 6) {
                    curPosOptI = 0;
                } else if(curPosOptI < 0) {
                    curPosOptI = 5;
                }
        }else if(isKeyPressed(sf::Keyboard::BackSpace)){
            return 0;
        }


        frame.clear(sf::Color::White);

        frame.draw(fondOpt);
        frame.draw(txtOpt1);
        frame.draw(txtOpt2);
        frame.draw(txtOpt3);
        frame.draw(txtOpt4);
        frame.draw(txtOpt5);
        frame.draw(txtRetour);
        frame.draw(txtOptions);
        rectSurb.setPosition(curPosOpt[curPosOptI]);
        frame.draw(rectSurb);

        frame.display();

    }

    return 0;

}

int boucleLang(){
    while(continuer) {
        frame.waitEvent(events);
        switch(events.type) {
            QUIT
        }

        ECHAP
        if(isKeyPressed(sf::Keyboard::Return)){
            switch(curPosOptI) {//Choix de la langue
                case 0://Bouton Retour
                    return 0;
                case 1:
                    OptionsSave::modifyParam("lang", "eng");
                    OptionsSave::saveParams(optSave);
                #ifdef _WIN32
                    StringKeys::initialize("ressources\\keys\\english.rkeys");
                #else
                    StringKeys::initialize("ressources/keys/english.rkeys");
                #endif
                    initAll();
                    return 0;
                    break;
                case 2:
                    OptionsSave::modifyParam("lang", "esp");
                    OptionsSave::saveParams(optSave);
                    #ifdef _WIN32
                        StringKeys::initialize("ressources\\keys\\espanol.rkeys");
                    #else
                        StringKeys::initialize("ressources/keys/espanol.rkeys");
                    #endif // _WIN32
                    initAll();
                    return 0;
                    break;
                case 3:
                    OptionsSave::modifyParam("lang", "fr");
                    OptionsSave::saveParams(optSave);
                    #ifdef _WIN32
                        StringKeys::initialize("ressources\\keys\\francais.rkeys");
                    #else
                        StringKeys::initialize("ressources/keys/francais.rkeys");
                    #endif
                    initAll();
                    return 0;
                    break;
                }
        }else if(isKeyPressed(sf::Keyboard::Up)){
                bruitArr.play();
                curPosOptI--;
                if(curPosOptI >= 4) {
                    curPosOptI = 0;
                } else if(curPosOptI < 0) {
                    curPosOptI = 3;
                }
        }else if(isKeyPressed(sf::Keyboard::Down)){
                bruitArr.play();
                curPosOptI++;
                if(curPosOptI >= 4) {
                    curPosOptI = 0;
                } else if(curPosOptI < 0) {
                    curPosOptI = 3;
                }
        }else if(isKeyPressed(sf::Keyboard::BackSpace)){
            return 0;
        }

        frame.clear(sf::Color::White);

        frame.draw(fondLangues);
        frame.draw(langEng);
        frame.draw(langEsp);
        frame.draw(langFr);
        frame.draw(txtRetour);
        frame.draw(txtLang);
        rectSurb.setPosition(curPosOpt[curPosOptI]);
        frame.draw(rectSurb);

        frame.display();

    }

    return 0;
}

}
}
}
