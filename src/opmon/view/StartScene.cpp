#include "StartScene.hpp"
#include "Animations.hpp"
#include "Dialog.hpp"
#include "../model/storage/Data.hpp"
#include "../../utils/fs.hpp"
#include "../../utils/OpString.hpp"
#include "../../utils/defines.hpp"
#include "./Window.hpp"


#define SIZE_P0 18
#define SIZE_P1 15

UNS

namespace OpMon{
  namespace View{

    void StartScene::initStrings() {
      unsigned int it = 0;
      for(it = 0; it < 18; it++) {
        string actual;
        actual << string("prof.dialog.start.") << it+1;
        txtP0[it] = kget(actual);
      }
      int ite = 1;
      it++;
      strName = Utils::OpString("prof.dialog.start.19", Main::player.getNameP());
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

    void StartScene::StartScene() {
      initStrings();
      Dialog::dialog.setPosition(0, 362);
      textDescs[1].setPosition(85, 25);
      textDescs[0].setPosition(155, 200);
      textDescs[2].setPosition(95, 375);
      textDescs[3].setPosition(95, 405);


      txtEnCours[0] = sf::String(" ");
      txtEnCours[1] = sf::String(" ");
      txtEnCours[2] = sf::String(" ");

      textures[0].loadFromFile(Utils::Fs::getPath(RESSOURCES_PATH + "backgrounds/start/startscene.png"));
      textures[1].loadFromFile(Utils::Fs::getPath(RESSOURCES_PATH + "sprites/chara/jlppc/profkiwai.png"));
      textures[2].loadFromFile(Utils::Fs::getPath(RESSOURCES_PATH + "backgrounds/dialog/dialog.png"));
      textures[3].loadFromFile(Utils::Fs::getPath(RESSOURCES_PATH + "sprites/misc/arrDial.png"));
      textures[4].loadFromFile(Utils::Fs::getPath(RESSOURCES_PATH + "backgrounds/start/nameEntry.png"));
      bgMus.openFromFile(Utils::Fs::getPath(RESSOURCES_PATH + "audio/music/intro.ogg"));
      bg.setTexture(textures[0]);
      prof.setTexture(textures[1]);
      Dialog::dialog.setTexture(textures[2]);
      Dialog::arrDial.setTexture(textures[3]);
      bgName.setTexture(textures[4]);
      bgName.setPosition(0, 0);
      bgMus.setLoop(true);

      bg.setPosition(0, 0);
      prof.setPosition(205, 120);
      prof.setScale(1.5, 1.5);

      for(sf::Text &cellTxt : textDescs) {
        cellTxt.setCharacterSize(FONT_SIZE_DEFAULT);
        cellTxt.setColor(sf::Color::Black);
        cellTxt.setFont(Model::Data::Ui::font);
      }

      nameField.setFont(Model::Data::Ui::font);
      nameField.setPosition(120, 300);

      Dialog::arrDial.setPosition(437, 482);
    }

    void StartScene::onLangChanged(){
      initStrings();
    }

    GameStatus StartScene::operator()(){
      if(!launched){
	init();
      }
      switch(part){
      case 0:
	return loop0();
      case 1:
	return loop1();
      case 2:
	return loop2();
	
      }
      nextPanel = new Overworld();
      return GameStatus::NEXT;
    }

    void initLoop0(){
      sizeOfTxt = 18;
      if(dialog != nullptr){
	    delete(dialog);
      }
      dialog = new Dialog(txtP0, sizeOfTxt);
      loop0init = true;
      loop1init = false;
      loop2init = false;
    }

    void initLoop1(){
      wait = true;
      Window::window.setKeyRepeatEnabled(true);
      Window::frame.clear(sf::Color::White);
      Window::frame.draw(bgName);
      for(sf::Text desc : textDescs) {
        desc.setColor(sf::Color::White);
        desc.setFont(Model::Data::Ui::font);
        Window::frame.draw(desc);
      }
      Window::frame.display();
      Window::winRefresh();
      loop0init = false;
      loop1init = true;
      loop2init = false;
    }

    void delLoop1(){
      wait = false;
      Window::window.setKeyRepeatEnable(false);
      Data::player.setName(pName);
      txtP1[0] = strName.getString();
      loop0init = false;
      loop1init = false;
      loop2init = false;
      part++;
    }

    void initLoop2(){
      int sizeOfTxt = 27 - 18;
      if(dialog != nullptr){
	delete(dialog);
      }
      dialog = new Dialog(txtP1, sizeOfTxt);
      loop0init = false;
      loop1init = false;
      loop2init = true;
    }
    
    GameStatus StartScene::loop0() {
      if(!loop0init){
	initLoop0();
      }

      if(!dialog->isDialogOver()) {
	Window::frame.clear(sf::Color::White);
	Window::frame.draw(bg);
	Window::frame.draw(prof);

	dialog->updateTextAnimation();

	dialog->draw(Window::frame);
	Window::frame.display();
	Window::winRefresh();
	
      } else {
	part++;
      }

      return GameStatus::CONTINUE;

    }

    GameStatus StartScene::loop1() {

      if(!loop1init){
	initLoop1();
      }
      
      Window::frame.clear(sf::Color::White);
        Window::frame.draw(bgName);
        for(sf::Text desc : textDescs) {
	  desc.setColor(sf::Color::White);
	  desc.setFont(Model::Data::Ui::font);
	  Window::frame.draw(desc);
        }
        nameField.setString(pName);
        Window::frame.draw(nameField);
        Window::frame.display();
        Window::winRefresh();


	return GameStatus::CONTINUE;
    }

    GameStatus StartScene::loop2() {

      /*
	switch (Main::mainframe.events.type) {

	RETURN_ON_CLOSE_EVENT

	case sf::Event::KeyPressed:
	//if(Main::mainframe.events.key.code == sf::Keyboard::Space) {
	//dialog->pass();
	}
	break;

	default:
	break;

	}

	RETURN_ON_ECHAP_EVENT
      */
      if(!dialog->isDialogOver()) {
	Window::frame.clear(sf::Color::White);
	Window::frame.draw(bg);
	Window::frame.draw(prof);

	dialog->updateTextAnimation();

	dialog->draw(Window::frame);
	Window::frame.display();
	Window::winRefresh();
	return GameStatus::CONTINUE;
      } else {
	nextPanel = new Overworld();
	return GameStatus::NEXT;
      }
        
    }

    void StartScene::init() {
      bgMus.play();
      
      //Animations::animWinOpen(Window::frame, bg);

      //Animations::animWinClose(Window::frame, bg);

      launched = true;


    }

    void StartScene::play(){
      bgMus.play();
    }

    void StartScene::pause(){
      bgMus.pause();
    }

    StartScene::~StartScene(){
      bgMus.stop();
    }
  }
}
