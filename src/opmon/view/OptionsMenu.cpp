#include "OptionsMenu.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"
#include "../save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"

UNS

void OptionsMenu::initStrings() {
  langFr.setString("Français");
  langFr.setFont(Model::Data::Ui::font);
  langFr.setCharacterSize(FONT_SIZE_DEFAULT);
  langEng.setString("English");
  langEng.setFont(Model::Data::Ui::font);
  langEng.setCharacterSize(FONT_SIZE_DEFAULT);
  langEsp.setString("Espa\u00F1ol");
  langEsp.setFont(Model::Data::Ui::font);
  langEsp.setCharacterSize(FONT_SIZE_DEFAULT);
  txtRetour.setString(kget("options.retour"));
  txtRetour.setFont(Model::Data::Ui::font);
  txtRetour.setCharacterSize(FONT_SIZE_DEFAULT);
  txtOptions.setString(kget("options.title"));
  txtOptions.setFont(Model::Data::Ui::font);
  txtOptions.setCharacterSize(FONT_SIZE_DEFAULT);
  txtOpt1.setString(kget("options.ecran"));
  txtOpt1.setFont(Model::Data::Ui::font);
  txtOpt1.setCharacterSize(FONT_SIZE_DEFAULT);
  txtOpt2.setString(kget("options.lang"));
  txtOpt2.setFont(Model::Data::Ui::font);
  txtOpt2.setCharacterSize(FONT_SIZE_DEFAULT);
  txtOpt3.setString(kget("options.vol"));
  txtOpt3.setFont(Model::Data::Ui::font);
  txtOpt3.setCharacterSize(FONT_SIZE_DEFAULT);
  txtOpt3.setColor(sf::Color::Red);
  txtOpt4.setString( kget("options.control"));
  txtOpt4.setFont(Model::Data::Ui::font);
  txtOpt4.setCharacterSize(FONT_SIZE_DEFAULT);
  txtOpt4.setColor(sf::Color::White);
  txtOpt5.setString(kget("options.credit"));
  txtOpt5.setFont(Model::Data::Ui::font);
  txtOpt5.setCharacterSize(FONT_SIZE_DEFAULT);
  txtOpt5.setColor(sf::Color::White);

  txtLang.setString(kget("options.lang.title"));
  txtLang.setFont(Model::Data::Ui::font);
  txtLang.setCharacterSize(FONT_SIZE_DEFAULT);

  txtCred.setString(kget("options.cred.title"));
  txtCred.setFont(Model::Data::Ui::font);
  txtCred.setCharacterSize(FONT_SIZE_DEFAULT);


  txtCre1.setString(kget("options.credit.1"));
  txtCre1.setFont(Model::Data::Ui::font);
  txtCre1.setCharacterSize(14);
  txtCre1.setColor(sf::Color::Black);
  txtCre2.setString(kget("options.credit.2"));
  txtCre2.setFont(Model::Data::Ui::font);
  txtCre2.setCharacterSize(14);
  txtCre2.setColor(sf::Color::Black);
  txtCre3.setString(kget("options.credit.3"));
  txtCre3.setFont(Model::Data::Ui::font);
  txtCre3.setCharacterSize(14);
  txtCre3.setColor(sf::Color::Black);
  txtCre4.setString(kget("options.credit.4"));
  txtCre4.setFont(Model::Data::Ui::font);
  txtCre4.setCharacterSize(12);
  txtCre5.setString(kget("options.credit.5"));
  txtCre5.setFont(Model::Data::Ui::font);
  txtCre5.setCharacterSize(12);
  txtCre6.setString(kget("options.credit.6"));
  txtCre6.setFont(Model::Data::Ui::font);
  txtCre6.setCharacterSize(12);
  txtCre7.setString(kget("options.credit.7"));
  txtCre7.setFont(Model::Data::Ui::font);
  txtCre7.setCharacterSize(12);
  txtCre8.setString(kget("options.credit.8"));
  txtCre8.setFont(Model::Data::Ui::font);
  txtCre8.setCharacterSize(12);
  txtCre9.setString(kget("options.credit.9"));
  txtCre9.setFont(Model::Data::Ui::font);
  txtCre9.setCharacterSize(13);
}

OptionsMenu::OptionsMenu(){
  wait = true;
  init();
}

void OptionsMenu::init() {

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

  lauched = true;
  
}


~OptionsMenu(){
  
}

GameStatus operator()(){
  switch(currentOptions){
  case ALL:
    return loop();
    break;
  case LANG:
    return langLoop();
    break;
  case CREDITS:
    return langCredits();
    break;
  }
}

void moveArrow(bool move){
  Model::Data::Sounds::arrow.play();
  switch(currentOptions){
  case ALL:
    if(move){
      curPosOptI++;
    }else{
      curPosOptI--;
    }
    if(curPosOptI >= 6){
      curPosOptI = 0;
    }else if(curPosOptI < 0){
      curPosOptI = 5;
    }
    break;
  case LANG:
    if(move){
      curPosLangI++;
    }else{
      curPosLangI--;
    }
    if(curPosLangI >= 4){
      curPosLangI = 0;
    }else if(curPosLangI < 0){
      curPosLangI = 3;
    }
  }
}

GameStatus OptionsMenu::loop() {
  
  /*Main::mainframe.window.waitEvent(Main::mainframe.events);
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
  */
	
  Window::frame.frame.clear(sf::Color::White);

  Window::frame.frame.draw(bgOpt);
  Window::frame.frame.draw(txtOpt1);
  Window::frame.frame.draw(txtOpt2);
  Window::frame.frame.draw(txtOpt3);
  Window::frame.frame.draw(txtOpt4);
  Window::frame.frame.draw(txtOpt5);
  Window::frame.frame.draw(txtRetour);
  Window::frame.frame.draw(txtOptions);
  if(OptionsSave::getParam("fullscreen").getValue() == "true") {
    Window::frame.frame.draw(coche);
  }
  rectSurb.setPosition(curPosOpt[curPosOptI]);
  rectSurb.setScale(curSizeOpt[curPosOptI]);
  Window::frame.frame.draw(rectSurb);

  Window::frame.frame.display();
  Window::winRefresh();
  return GameStatus::CONTINUE;

}

void play(){
  
}

void pause(){
  
}

int OptionsMenu::langLoop() {
  /*Window::frame.window.waitEvent(Window::frame.events);
    switch(Window::frame.events.type) {
    RETURN_ON_CLOSE_EVENT

    case sf::Event::KeyPressed:
    if(Window::frame.events.key.code == sf::Keyboard::Return) {
    switch(curPosOptI) {//CLanguage choice
    case 0://Back button
    return 0;
    case 1:
    OptionsSave::modifyParam("lang", "eng");
    #ifdef _WIN32
    Utils::StringKeys::initialize("ressources\\keys\\english.rkeys");
    #else
    Utils::StringKeys::initialize(RESSOURCES_PATH + "keys/english.rkeys");
    #endif
    Window::frame.initAllStrings();
    return 0;
    break;
    case 2:
    OptionsSave::modifyParam("lang", "esp");
    #ifdef _WIN32
    Utils::StringKeys::initialize("ressources\\keys\\espanol.rkeys");
    #else
    Utils::StringKeys::initialize(RESSOURCES_PATH + "keys/espanol.rkeys");
    #endif // _WIN32
    Window::frame.initAllStrings();
    return 0;
    break;
    case 3:
    OptionsSave::modifyParam("lang", "fr");
    #ifdef _WIN32
    Utils::StringKeys::initialize("ressources\\keys\\francais.rkeys");
    #else
    Utils::StringKeys::initialize(RESSOURCES_PATH + "keys/francais.rkeys");
    #endif
    Window::frame.initAllStrings();
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
    Window::frame.mainmenu.bruitArr.play();
    curPosOptI--;
    if(curPosOptI >= 4) {
    curPosOptI = 0;
    } else if(curPosOptI < 0) {
    curPosOptI = 3;
    }
    } else if(isKeyPressed(sf::Keyboard::Down)) {
    Window::frame.mainmenu.bruitArr.play();
    curPosOptI++;
    if(curPosOptI >= 4) {
    curPosOptI = 0;
    } else if(curPosOptI < 0) {
    curPosOptI = 3;
    }
    } else if(isKeyPressed(sf::Keyboard::BackSpace)) {
    return 0;
    }
  */
  Window::frame.frame.clear(sf::Color::White);

  Window::frame.frame.draw(bgLangues);
  Window::frame.frame.draw(langEng);
  Window::frame.frame.draw(langEsp);
  Window::frame.frame.draw(langFr);
  Window::frame.frame.draw(txtRetour);
  Window::frame.frame.draw(txtLang);
  rectSurb.setPosition(curPosOpt[curPosOptI]);
  rectSurb.setScale(curSizeLang[curPosOptI]);
  Window::frame.frame.draw(rectSurb);

  Window::frame.frame.display();
  Window::winRefresh();

  return 0;
}

int OptionsMenu::boucleCredits() {
  /*        Window::frame.window.waitEvent(Window::frame.events);
	    switch(Window::frame.events.type) {
            RETURN_ON_CLOSE_EVENT

	    case sf::Event::KeyPressed:
            if(Window::frame.events.key.code == sf::Keyboard::Return) {
	    switch(curPosOptI) {
	    case 0://Bouton Retour
	    Window::frame.initAllStrings();
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
            Window::frame.mainmenu.bruitArr.play();
            curPosOptI--;
            if(curPosOptI >= 4) {
	    curPosOptI = 0;
            } else if(curPosOptI < 0) {
	    curPosOptI = 3;
            }
	    } else if(isKeyPressed(sf::Keyboard::Down)) {
            Window::frame.mainmenu.bruitArr.play();
            curPosOptI++;
            if(curPosOptI >= 4) {
	    curPosOptI = 0;
            } else if(curPosOptI < 0) {
	    curPosOptI = 3;
            }
	    } else if(isKeyPressed(sf::Keyboard::BackSpace)) {
            return 0;
	    }
  */
  Window::frame.frame.clear(sf::Color::White);

  Window::frame.frame.draw(bgCredits);
  Window::frame.frame.draw(txtCre1);
  Window::frame.frame.draw(txtCre2);
  Window::frame.frame.draw(txtCre3);
  Window::frame.frame.draw(txtCre4);
  Window::frame.frame.draw(txtCre5);
  Window::frame.frame.draw(txtCre6);
  Window::frame.frame.draw(txtCre7);
  Window::frame.frame.draw(txtCre8);
  Window::frame.frame.draw(txtCre9);
  Window::frame.frame.draw(txtRetour);
  Window::frame.frame.draw(txtCred);

  Window::frame.frame.display();
  Window::winRefresh();


  return GameStatus::CONTINUE;
}
