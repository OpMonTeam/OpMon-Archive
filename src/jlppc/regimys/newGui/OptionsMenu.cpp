#include "OptionsMenu.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"
#include "../save/OptionsSave.hpp"
#include "MainFrame.hpp"

UNS

namespace MainFrame {
    namespace MainMenu {
        namespace OptionsMenu {

            sf::Sprite bgCredits;
            sf::Sprite bgOpt;
            sf::Text langFr;
            sf::Text langEng;
            sf::Text langEsp;
            sf::Text txtRetour;
            sf::Text txtOptions;
            sf::Text txtCre1;
            sf::Text txtCre2;
            sf::Text txtCre3;
            sf::Text txtCre4;
            sf::Text txtCre5;
            sf::Text txtCre6;
            sf::Text txtCre7;
            sf::Text txtCre8;
            sf::Text txtCre9;
            sf::Text txtOpt1;
            sf::Text txtOpt2;
            sf::Text txtOpt3;
            sf::Text txtOpt4;
            sf::Text txtOpt5;
            sf::Sprite rectSurb;
            sf::Vector2f curPosOpt[6] = {};
            sf::Vector2f curSizeOpt[6];
            int optionSelect = -1;
            int curPosOptI = 0;
            int curPosLangI = 0;

            sf::Text txtLang;
            sf::Text txtCred;
            sf::Sprite bgLangues;
//J_Texture listeLangues[3] = {};
            sf::Vector2f curPosLang[4] = {};
            sf::Vector2f curSizeLang[4];
            sf::Texture textures2[5];
            sf::Sprite coche;

            void initStrings() {
                langFr.setString(L"Français");
                langFr.setFont(font);
                langFr.setCharacterSize(FONT_SIZE_DEFAULT);
                langEng.setString("English");
                langEng.setFont(font);
                langEng.setCharacterSize(FONT_SIZE_DEFAULT);
                langEsp.setString(L"Espa\u00F1ol");
                langEsp.setFont(font);
                langEsp.setCharacterSize(FONT_SIZE_DEFAULT);
                txtRetour.setString(kget("options.retour"));
                txtRetour.setFont(font);
                txtRetour.setCharacterSize(FONT_SIZE_DEFAULT);
                txtOptions.setString(kget("options.title"));
                txtOptions.setFont(font);
                txtOptions.setCharacterSize(FONT_SIZE_DEFAULT);
                txtOpt1.setString(kget("options.ecran"));
                txtOpt1.setFont(font);
                txtOpt1.setCharacterSize(FONT_SIZE_DEFAULT);
                txtOpt2.setString(kget("options.lang"));
                txtOpt2.setFont(font);
                txtOpt2.setCharacterSize(FONT_SIZE_DEFAULT);
                txtOpt3.setString(kget("options.vol"));
                txtOpt3.setFont(font);
                txtOpt3.setCharacterSize(FONT_SIZE_DEFAULT);
                txtOpt3.setColor(sf::Color::Red);
                txtOpt4.setString( kget("options.control"));
                txtOpt4.setFont(font);
                txtOpt4.setCharacterSize(FONT_SIZE_DEFAULT);
                txtOpt4.setColor(sf::Color::White);
                txtOpt5.setString(kget("options.credit"));
                txtOpt5.setFont(font);
                txtOpt5.setCharacterSize(FONT_SIZE_DEFAULT);
                txtOpt5.setColor(sf::Color::White);

                txtLang.setString(kget("options.lang.title"));
                txtLang.setFont(font);
                txtLang.setCharacterSize(FONT_SIZE_DEFAULT);

                txtCred.setString(kget("options.cred.title"));
                txtCred.setFont(font);
                txtCred.setCharacterSize(FONT_SIZE_DEFAULT);


                txtCre1.setString(kget("options.credit.1"));
                txtCre1.setFont(font);
                txtCre1.setCharacterSize(14);
                txtCre1.setColor(sf::Color::Black);
                txtCre2.setString(kget("options.credit.2"));
                txtCre2.setFont(font);
                txtCre2.setCharacterSize(14);
                txtCre2.setColor(sf::Color::Black);
                txtCre3.setString(kget("options.credit.3"));
                txtCre3.setFont(font);
                txtCre3.setCharacterSize(14);
                txtCre3.setColor(sf::Color::Black);
                txtCre4.setString(kget("options.credit.4"));
                txtCre4.setFont(font);
                txtCre4.setCharacterSize(12);
                txtCre5.setString(kget("options.credit.5"));
                txtCre5.setFont(font);
                txtCre5.setCharacterSize(12);
                txtCre6.setString(kget("options.credit.6"));
                txtCre6.setFont(font);
                txtCre6.setCharacterSize(12);
                txtCre7.setString(kget("options.credit.7"));
                txtCre7.setFont(font);
                txtCre7.setCharacterSize(12);
                txtCre8.setString(kget("options.credit.8"));
                txtCre8.setFont(font);
                txtCre8.setCharacterSize(12);
                txtCre9.setString(kget("options.credit.9"));
                txtCre9.setFont(font);
                txtCre9.setCharacterSize(13);
            }

            void initVars() {

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
                        window.waitEvent(events);
                        switch(events.type) {
                                    QUIT
                                case sf::Event::KeyPressed:
                                    if(events.key.code == sf::Keyboard::Return) {
                                            switch(curPosOptI) {
                                                    case 0:
                                                        return 0;
                                                    case 1:
                                                        if(OptionsSave::getParam("fullscreen").getValue() == "true") {
                                                                OptionsSave::addOrModifParam("fullscreen", "false");
                                                            }
                                                        else {
                                                                OptionsSave::addOrModifParam("fullscreen", "true");
                                                            }

                                                        break;
                                                    case 2:
                                                        boucleLang();
                                                        break;
                                                    case 3:
                                                        bruitNope.play();//Non disponible
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

                        ECHAP
                        if(isKeyPressed(sf::Keyboard::Return)) {

                            }
                        else if(isKeyPressed(sf::Keyboard::Up)) {
                                bruitArr.play();
                                curPosOptI--;
                                if(curPosOptI >= 6) {
                                        curPosOptI = 0;
                                    }
                                else if(curPosOptI < 0) {
                                        curPosOptI = 5;
                                    }
                            }
                        else if(isKeyPressed(sf::Keyboard::Down)) {
                                bruitArr.play();
                                curPosOptI++;
                                if(curPosOptI >= 6) {
                                        curPosOptI = 0;
                                    }
                                else if(curPosOptI < 0) {
                                        curPosOptI = 5;
                                    }
                            }
                        else if(isKeyPressed(sf::Keyboard::BackSpace)) {
                                return 0;
                            }


                        frame.clear(sf::Color::White);

                        frame.draw(bgOpt);
                        frame.draw(txtOpt1);
                        frame.draw(txtOpt2);
                        frame.draw(txtOpt3);
                        frame.draw(txtOpt4);
                        frame.draw(txtOpt5);
                        frame.draw(txtRetour);
                        frame.draw(txtOptions);
                        if(OptionsSave::getParam("fullscreen").getValue() == "true") {
                                frame.draw(coche);
                            }
                        rectSurb.setPosition(curPosOpt[curPosOptI]);
                        rectSurb.setScale(curSizeOpt[curPosOptI]);
                        frame.draw(rectSurb);

                        frame.display();
                        winRefresh();

                    }

                return 0;

            }

            int boucleLang() {
                while(continuer) {
                        window.waitEvent(events);
                        switch(events.type) {
                                    QUIT

                                case sf::Event::KeyPressed:
                                    if(events.key.code == sf::Keyboard::Return) {
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
                                                        initAllStrings();
                                                        return 0;
                                                        break;
                                                    case 2:
                                                        OptionsSave::modifyParam("lang", "esp");
#ifdef _WIN32
                                                        StringKeys::initialize("ressources\\keys\\espanol.rkeys");
#else
                                                        StringKeys::initialize(RESSOURCES_PATH + "keys/espanol.rkeys");
#endif // _WIN32
                                                        initAllStrings();
                                                        return 0;
                                                        break;
                                                    case 3:
                                                        OptionsSave::modifyParam("lang", "fr");
#ifdef _WIN32
                                                        StringKeys::initialize("ressources\\keys\\francais.rkeys");
#else
                                                        StringKeys::initialize(RESSOURCES_PATH + "keys/francais.rkeys");
#endif
                                                        initAllStrings();
                                                        return 0;
                                                        break;
                                                }
                                        }
                                    break;
			default:
			  break;

                            }
                        ECHAP
                        if(isKeyPressed(sf::Keyboard::Up)) {
                                bruitArr.play();
                                curPosOptI--;
                                if(curPosOptI >= 4) {
                                        curPosOptI = 0;
                                    }
                                else if(curPosOptI < 0) {
                                        curPosOptI = 3;
                                    }
                            }
                        else if(isKeyPressed(sf::Keyboard::Down)) {
                                bruitArr.play();
                                curPosOptI++;
                                if(curPosOptI >= 4) {
                                        curPosOptI = 0;
                                    }
                                else if(curPosOptI < 0) {
                                        curPosOptI = 3;
                                    }
                            }
                        else if(isKeyPressed(sf::Keyboard::BackSpace)) {
                                return 0;
                            }

                        frame.clear(sf::Color::White);

                        frame.draw(bgLangues);
                        frame.draw(langEng);
                        frame.draw(langEsp);
                        frame.draw(langFr);
                        frame.draw(txtRetour);
                        frame.draw(txtLang);
                        rectSurb.setPosition(curPosOpt[curPosOptI]);
                        rectSurb.setScale(curSizeLang[curPosOptI]);
                        frame.draw(rectSurb);

                        frame.display();
                        winRefresh();

                    }

                return 0;
            }
            int boucleCredits() {
                while(continuer) {
                        window.waitEvent(events);
                        switch(events.type) {
                                    QUIT

                                case sf::Event::KeyPressed:
                                    if(events.key.code == sf::Keyboard::Return) {
                                            switch(curPosOptI) {
                                                    case 0://Bouton Retour
                                                        initAllStrings();
                                                        return 0;

                                                        break;
                                                }
                                        }
                                    break;
			default:
			  break;

                            }
                        ECHAP
                        if(isKeyPressed(sf::Keyboard::Up)) {
                                bruitArr.play();
                                curPosOptI--;
                                if(curPosOptI >= 4) {
                                        curPosOptI = 0;
                                    }
                                else if(curPosOptI < 0) {
                                        curPosOptI = 3;
                                    }
                            }
                        else if(isKeyPressed(sf::Keyboard::Down)) {
                                bruitArr.play();
                                curPosOptI++;
                                if(curPosOptI >= 4) {
                                        curPosOptI = 0;
                                    }
                                else if(curPosOptI < 0) {
                                        curPosOptI = 3;
                                    }
                            }
                        else if(isKeyPressed(sf::Keyboard::BackSpace)) {
                                return 0;
                            }

                        frame.clear(sf::Color::White);

                        frame.draw(bgCredits);
                        frame.draw(txtCre1);
                        frame.draw(txtCre2);
                        frame.draw(txtCre3);
                        frame.draw(txtCre4);
                        frame.draw(txtCre5);
                        frame.draw(txtCre6);
                        frame.draw(txtCre7);
                        frame.draw(txtCre8);
                        frame.draw(txtCre9);
                        frame.draw(txtRetour);
                        frame.draw(txtCred);

                        frame.display();
                        winRefresh();

                    }

                return 0;
            }

        }
    }
}
