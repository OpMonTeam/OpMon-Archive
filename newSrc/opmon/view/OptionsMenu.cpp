#include "OptionsMenu.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"
#include "../save/OptionsSave.hpp"
#include "MainFrame.hpp"

UNS

void OptionsMenu::initStrings() {
    langFr.setString("Français");
    langFr.setFont(Main::mainframe.font);
    langFr.setCharacterSize(FONT_SIZE_DEFAULT);
    langEng.setString("English");
    langEng.setFont(Main::mainframe.font);
    langEng.setCharacterSize(FONT_SIZE_DEFAULT);
    langEsp.setString("Espa\u00F1ol");
    langEsp.setFont(Main::mainframe.font);
    langEsp.setCharacterSize(FONT_SIZE_DEFAULT);
    txtRetour.setString(kget("options.retour"));
    txtRetour.setFont(Main::mainframe.font);
    txtRetour.setCharacterSize(FONT_SIZE_DEFAULT);
    txtOptions.setString(kget("options.title"));
    txtOptions.setFont(Main::mainframe.font);
    txtOptions.setCharacterSize(FONT_SIZE_DEFAULT);
    txtOpt1.setString(kget("options.ecran"));
    txtOpt1.setFont(Main::mainframe.font);
    txtOpt1.setCharacterSize(FONT_SIZE_DEFAULT);
    txtOpt2.setString(kget("options.lang"));
    txtOpt2.setFont(Main::mainframe.font);
    txtOpt2.setCharacterSize(FONT_SIZE_DEFAULT);
    txtOpt3.setString(kget("options.vol"));
    txtOpt3.setFont(Main::mainframe.font);
    txtOpt3.setCharacterSize(FONT_SIZE_DEFAULT);
    txtOpt3.setColor(sf::Color::Red);
    txtOpt4.setString( kget("options.control"));
    txtOpt4.setFont(Main::mainframe.font);
    txtOpt4.setCharacterSize(FONT_SIZE_DEFAULT);
    txtOpt4.setColor(sf::Color::White);
    txtOpt5.setString(kget("options.credit"));
    txtOpt5.setFont(Main::mainframe.font);
    txtOpt5.setCharacterSize(FONT_SIZE_DEFAULT);
    txtOpt5.setColor(sf::Color::White);

    txtLang.setString(kget("options.lang.title"));
    txtLang.setFont(Main::mainframe.font);
    txtLang.setCharacterSize(FONT_SIZE_DEFAULT);

    txtCred.setString(kget("options.cred.title"));
    txtCred.setFont(Main::mainframe.font);
    txtCred.setCharacterSize(FONT_SIZE_DEFAULT);


    txtCre1.setString(kget("options.credit.1"));
    txtCre1.setFont(Main::mainframe.font);
    txtCre1.setCharacterSize(14);
    txtCre1.setColor(sf::Color::Black);
    txtCre2.setString(kget("options.credit.2"));
    txtCre2.setFont(Main::mainframe.font);
    txtCre2.setCharacterSize(14);
    txtCre2.setColor(sf::Color::Black);
    txtCre3.setString(kget("options.credit.3"));
    txtCre3.setFont(Main::mainframe.font);
    txtCre3.setCharacterSize(14);
    txtCre3.setColor(sf::Color::Black);
    txtCre4.setString(kget("options.credit.4"));
    txtCre4.setFont(Main::mainframe.font);
    txtCre4.setCharacterSize(12);
    txtCre5.setString(kget("options.credit.5"));
    txtCre5.setFont(Main::mainframe.font);
    txtCre5.setCharacterSize(12);
    txtCre6.setString(kget("options.credit.6"));
    txtCre6.setFont(Main::mainframe.font);
    txtCre6.setCharacterSize(12);
    txtCre7.setString(kget("options.credit.7"));
    txtCre7.setFont(Main::mainframe.font);
    txtCre7.setCharacterSize(12);
    txtCre8.setString(kget("options.credit.8"));
    txtCre8.setFont(Main::mainframe.font);
    txtCre8.setCharacterSize(12);
    txtCre9.setString(kget("options.credit.9"));
    txtCre9.setFont(Main::mainframe.font);
    txtCre9.setCharacterSize(13);
}

void OptionsMenu::initVars() {

#ifdef _WIN32
    textures2[0].loadFromFile("ressources\\backgrounds\\options.png");
    textures2[1].loadFromFile("ressources\\sprites\\misc\\selectBar.png");
    textures2[2].loadFromFile("ressources\\backgrounds\\lang.png");
    textures2[3].loadFromFile(RESSOURCES_PATH + "sprites\\misc\\yes.png");
    textures2[4].loadFromFile(RESSOURCES_PATH + "backgrounds\\credits.png");

#else
    textures2[0].loadFromFile(RESSOURCES_PATH + "backgrounds/options.png");
    textures2[1].loadFromFile(RESSOURCES_PATH + "sprites/misc/selectBar.png");
    textures2[2].loadFromFile(RESSOURCES_PATH + "backgrounds/lang.png");
    textures2[3].loadFromFile(RESSOURCES_PATH + "sprites/misc/yes.png");
    textures2[4].loadFromFile(RESSOURCES_PATH + "backgrounds/credits.png");


#endif // _WIN32
    bgOpt.setTexture(textures2[0]);
    rectSurb.setTexture(textures2[1]);
    bgLangues.setTexture(textures2[2]);
    coche.setTexture(textures2[3]);
    bgCredits.setTexture(textures2[4]);

    coche.setPosition(425, 88);


    initStrings();

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
    txtCred.setPosition(250, 25);

    txtCre1.setPosition(105, 220);
    txtCre2.setPosition(283, 220);
    txtCre3.setPosition(283, 280);
    txtCre4.setPosition(172, 347);
    txtCre5.setPosition(140, 372);
    txtCre6.setPosition(165, 395);
    txtCre7.setPosition(172, 422);
    txtCre8.setPosition(60, 457);
    txtCre9.setPosition(385, 488);

    curPosOpt[0].x = 23;
    curPosOpt[0].y = 17;
    curSizeOpt[0].x = 134 / rectSurb.getGlobalBounds().width;
    curSizeOpt[0].y = 49 / rectSurb.getGlobalBounds().height;

    curPosLang[0].x = 23;
    curPosLang[0].y = 17;
    curSizeLang[0].x = 134 / rectSurb.getGlobalBounds().width;
    curSizeLang[0].y = 49 / rectSurb.getGlobalBounds().height;

    for(int i = 1, j = 86; i < 6; i++) {
        curPosOpt[i].x = 23;
        curPosOpt[i].y = j;
        curSizeOpt[i].x = 464 / rectSurb.getGlobalBounds().width;
        curSizeOpt[i].y = 57 / rectSurb.getGlobalBounds().height;
        j+=69;
    }

    for(int i = 1, j = 86; i < 4; i++) {
        curPosLang[i].x = 23;
        curPosLang[i].y = j;
        curSizeLang[i].x = 464 / rectSurb.getGlobalBounds().width;
        curSizeLang[i].y = 57 / rectSurb.getGlobalBounds().height;
        j+=69;
    }


}

void OptionsMenu::verifVars() {

}

void OptionsMenu::deleteVars() {

}
int OptionsMenu::optionsMenu() {

    verifVars();
    //Lancement du menu
    return boucle();
}

int OptionsMenu::boucle() {
    while(continuer) {
        Main::mainframe.window.waitEvent(Main::mainframe.events);
        switch(Main::mainframe.events.type) {
            RETURN_ON_CLOSE_EVENT
        case sf::Event::KeyPressed:
            if(Main::mainframe.events.key.code == sf::Keyboard::Return) {
                switch(curPosOptI) {
                case 0:
                    return 0;
                case 1:
                    if(OptionsSave::getParam("fullscreen").getValue() == "true") {
                        OptionsSave::addOrModifParam("fullscreen", "false");
                    } else {
                        OptionsSave::addOrModifParam("fullscreen", "true");
                    }

                    break;
                case 2:
                    boucleLang();
                    break;
                case 3:
                    Main::mainframe.mainmenu.bruitNope.play();//Non disponible
                    break;
                case 4:
                    boucleCredits();
                    break;
                }
            }
            break;

        default:
            break;
        }

        RETURN_ON_ECHAP_EVENT
        if(isKeyPressed(sf::Keyboard::Return)) {

        } else if(isKeyPressed(sf::Keyboard::Up)) {
            Main::mainframe.mainmenu.bruitArr.play();
            curPosOptI--;
            if(curPosOptI >= 6) {
                curPosOptI = 0;
            } else if(curPosOptI < 0) {
                curPosOptI = 5;
            }
        } else if(isKeyPressed(sf::Keyboard::Down)) {
            Main::mainframe.mainmenu.bruitArr.play();
            curPosOptI++;
            if(curPosOptI >= 6) {
                curPosOptI = 0;
            } else if(curPosOptI < 0) {
                curPosOptI = 5;
            }
        } else if(isKeyPressed(sf::Keyboard::BackSpace)) {
            return 0;
        }


        Main::mainframe.frame.clear(sf::Color::White);

        Main::mainframe.frame.draw(bgOpt);
        Main::mainframe.frame.draw(txtOpt1);
        Main::mainframe.frame.draw(txtOpt2);
        Main::mainframe.frame.draw(txtOpt3);
        Main::mainframe.frame.draw(txtOpt4);
        Main::mainframe.frame.draw(txtOpt5);
        Main::mainframe.frame.draw(txtRetour);
        Main::mainframe.frame.draw(txtOptions);
        if(OptionsSave::getParam("fullscreen").getValue() == "true") {
            Main::mainframe.frame.draw(coche);
        }
        rectSurb.setPosition(curPosOpt[curPosOptI]);
        rectSurb.setScale(curSizeOpt[curPosOptI]);
        Main::mainframe.frame.draw(rectSurb);

        Main::mainframe.frame.display();
        Main::mainframe.winRefresh();

    }

    return 0;

}

int OptionsMenu::boucleLang() {
    while(continuer) {
        Main::mainframe.window.waitEvent(Main::mainframe.events);
        switch(Main::mainframe.events.type) {
            RETURN_ON_CLOSE_EVENT

        case sf::Event::KeyPressed:
            if(Main::mainframe.events.key.code == sf::Keyboard::Return) {
                switch(curPosOptI) {//CLanguage choice
                case 0://Back button
                    return 0;
                case 1:
                    OptionsSave::modifyParam("lang", "eng");
#ifdef _WIN32
                    StringKeys::initialize("ressources\\keys\\english.rkeys");
#else
                    StringKeys::initialize(RESSOURCES_PATH + "keys/english.rkeys");
#endif
                    Main::mainframe.initAllStrings();
                    return 0;
                    break;
                case 2:
                    OptionsSave::modifyParam("lang", "esp");
#ifdef _WIN32
                    StringKeys::initialize("ressources\\keys\\espanol.rkeys");
#else
                    StringKeys::initialize(RESSOURCES_PATH + "keys/espanol.rkeys");
#endif // _WIN32
                    Main::mainframe.initAllStrings();
                    return 0;
                    break;
                case 3:
                    OptionsSave::modifyParam("lang", "fr");
#ifdef _WIN32
                    StringKeys::initialize("ressources\\keys\\francais.rkeys");
#else
                    StringKeys::initialize(RESSOURCES_PATH + "keys/francais.rkeys");
#endif
                    Main::mainframe.initAllStrings();
                    return 0;
                    break;
                }
            }
            break;
        default:
            break;

        }
        RETURN_ON_ECHAP_EVENT
        if(isKeyPressed(sf::Keyboard::Up)) {
            Main::mainframe.mainmenu.bruitArr.play();
            curPosOptI--;
            if(curPosOptI >= 4) {
                curPosOptI = 0;
            } else if(curPosOptI < 0) {
                curPosOptI = 3;
            }
        } else if(isKeyPressed(sf::Keyboard::Down)) {
	  Main::mainframe.mainmenu.bruitArr.play();
            curPosOptI++;
            if(curPosOptI >= 4) {
                curPosOptI = 0;
            } else if(curPosOptI < 0) {
                curPosOptI = 3;
            }
        } else if(isKeyPressed(sf::Keyboard::BackSpace)) {
            return 0;
        }

        Main::mainframe.frame.clear(sf::Color::White);

        Main::mainframe.frame.draw(bgLangues);
        Main::mainframe.frame.draw(langEng);
        Main::mainframe.frame.draw(langEsp);
        Main::mainframe.frame.draw(langFr);
        Main::mainframe.frame.draw(txtRetour);
        Main::mainframe.frame.draw(txtLang);
        rectSurb.setPosition(curPosOpt[curPosOptI]);
        rectSurb.setScale(curSizeLang[curPosOptI]);
        Main::mainframe.frame.draw(rectSurb);

        Main::mainframe.frame.display();
        Main::mainframe.winRefresh();

    }

    return 0;
}
int OptionsMenu::boucleCredits() {
    while(continuer) {
        Main::mainframe.window.waitEvent(Main::mainframe.events);
        switch(Main::mainframe.events.type) {
            RETURN_ON_CLOSE_EVENT

        case sf::Event::KeyPressed:
            if(Main::mainframe.events.key.code == sf::Keyboard::Return) {
                switch(curPosOptI) {
                case 0://Bouton Retour
                    Main::mainframe.initAllStrings();
                    return 0;

                    break;
                }
            }
            break;
        default:
            break;

        }
        RETURN_ON_ECHAP_EVENT
        if(isKeyPressed(sf::Keyboard::Up)) {
            Main::mainframe.mainmenu.bruitArr.play();
            curPosOptI--;
            if(curPosOptI >= 4) {
                curPosOptI = 0;
            } else if(curPosOptI < 0) {
                curPosOptI = 3;
            }
        } else if(isKeyPressed(sf::Keyboard::Down)) {
            Main::mainframe.mainmenu.bruitArr.play();
            curPosOptI++;
            if(curPosOptI >= 4) {
                curPosOptI = 0;
            } else if(curPosOptI < 0) {
                curPosOptI = 3;
            }
        } else if(isKeyPressed(sf::Keyboard::BackSpace)) {
            return 0;
        }

        Main::mainframe.frame.clear(sf::Color::White);

        Main::mainframe.frame.draw(bgCredits);
        Main::mainframe.frame.draw(txtCre1);
        Main::mainframe.frame.draw(txtCre2);
        Main::mainframe.frame.draw(txtCre3);
        Main::mainframe.frame.draw(txtCre4);
        Main::mainframe.frame.draw(txtCre5);
        Main::mainframe.frame.draw(txtCre6);
        Main::mainframe.frame.draw(txtCre7);
        Main::mainframe.frame.draw(txtCre8);
        Main::mainframe.frame.draw(txtCre9);
        Main::mainframe.frame.draw(txtRetour);
        Main::mainframe.frame.draw(txtCred);

        Main::mainframe.frame.display();
        Main::mainframe.winRefresh();

    }

    return 0;
}
