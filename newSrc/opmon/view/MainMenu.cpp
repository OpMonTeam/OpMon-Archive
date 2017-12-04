#include "MainMenu.hpp"
#include "../start/main.hpp"
#include <iostream>
#include "OptionsMenu.hpp"
#include "MainFrame.hpp"

UNS

namespace OpMon{
  namespace View{

    void MainMenu::initStrings() {
      play.setString(kget("title.1"));
      charge.setString(kget("title.2"));
      options.setString(kget("title.3"));
      exit.setString(kget("title.4"));
    }

    void MainMenu::initVars() {
      sf::Text *textPos[4] = {&play, &charge, &options, &exit};
      for(int i = 0, j = 175; i < 4; i++) {
        curPos[i].x = 10;
        curPos[i].y = j;
        textPos[i]->setPosition(sf::Vector2f(60, j));
        j+=85;
      }
      // bool ok = true;
      textures[0].loadFromFile(getPath(RESSOURCES_PATH + "backgrounds/titlescreen.png"));
      textures[1].loadFromFile(getPath(RESSOURCES_PATH + "sprites/misc/arrChoice.png"));
      bgMusTitle.openFromFile(getPath(RESSOURCES_PATH + "audio/music/title.ogg"));
      sounds[0].loadFromFile(getPath(RESSOURCES_PATH + "audio/sounds/select.ogg"));
      sounds[1].loadFromFile(getPath(RESSOURCES_PATH + "audio/sounds/selectbuttons.ogg"));
      sounds[2].loadFromFile(getPath(RESSOURCES_PATH + "audio/sounds/nope.ogg"));
      bg.setTexture(textures[0]);
      cursor.setTexture(textures[1]);
      bruitArr.setBuffer(sounds[0]);
      bruitPush.setBuffer(sounds[1]);
      bruitNope.setBuffer(sounds[2]);
      cursor.setScale(3, 3);
      initStrings();
      play.setColor(sf::Color::White);
      charge.setColor(sf::Color::White);
      options.setColor(sf::Color::White);
      exit.setColor(sf::Color::White);
      play.setFont(Main::mainframe.font);
      charge.setFont(Main::mainframe.font);
      options.setFont(Main::mainframe.font);
      exit.setFont(Main::mainframe.font);
      play.setCharacterSize(FONT_SIZE_DEFAULT);
      charge.setCharacterSize(FONT_SIZE_DEFAULT);
      options.setCharacterSize(FONT_SIZE_DEFAULT);
      exit.setCharacterSize(FONT_SIZE_DEFAULT);
      //Mix_Volume(2, MIX_MAX_VOLUME / 4);
      //Mix_Volume(1, MIX_MAX_VOLUME);
      //Mix_Volume(0, MIX_MAX_VOLUME / 2);
      Main::mainframe.optionsmenu.initVars();



      bgMusTitle.setLoop(true);
    }

    void MainMenu::verifVars() {
      if(bg.getTexture() == NULL) {
        handleError("Missing menu bottom texture", true);
      }
      if(cursor.getTexture() == NULL) {
        handleError("Missing cursor texture", true);
      }
    }

    void MainMenu::deleteVars() {

    }
    int MainMenu::boucle0() {

      oplog("Entering the menu");
      //Actualisation des éléments
      Main::mainframe.frame.draw(bg);
      Main::mainframe.frame.draw(play),
	Main::mainframe.frame.draw(charge);
      Main::mainframe.frame.draw(options);
      Main::mainframe.frame.draw(exit);
      cursor.setPosition(curPos[curPosI]);
      Main::mainframe.frame.draw(cursor);

      Main::mainframe.frame.display();
      Main::mainframe.winRefresh();
      while(continuer) {
        Main::mainframe.window.waitEvent(Main::mainframe.events);
        switch(Main::mainframe.events.type) {
	  RETURN_ON_CLOSE_EVENT

        case sf::Event::KeyPressed:
	  if(Main::mainframe.events.key.code == sf::Keyboard::Return) {
	    switch(curPosI) {
	      //Traitement de l'action en fonction de la position du curseur
	    case 0:
	      bgMusTitle.stop();
	      return 0;
	    case 3:
	      bgMusTitle.stop();
	      return -1;
	    case 2:
	      if(Main::mainframe.optionsmenu.optionsMenu() == -1) {
		return -1;
	      }
	      break;
	    case 1:
	      bruitNope.play();
	      break;
	    }
	  }
	  break;
        default:
	  break;

        }
        if(isKeyPressed(sf::Keyboard::Up)) {
	  bruitArr.play();
	  curPosI--;
	  //Si en haut, retourne en bas
	  if(curPosI >= 4) {
	    curPosI = 0;
	  } else if(curPosI < 0) {
	    curPosI = 3;
	  }
        } else if(isKeyPressed(sf::Keyboard::Down)) {
	  bruitArr.play();
	  curPosI++;
	  //Si en bas, retourne en haut
	  if(curPosI >= 4) {
	    curPosI = 0;
	  } else if(curPosI < 0) {
	    curPosI = 3;
	  }
        } else if(isKeyPressed(sf::Keyboard::Escape)) {
	  bgMusTitle.stop();
	  return -1;
        }
        Main::mainframe.frame.clear(sf::Color::Black);

        //Actualisation des éléments
        Main::mainframe.frame.draw(bg);
        Main::mainframe.frame.draw(play),
	  Main::mainframe.frame.draw(charge);
        Main::mainframe.frame.draw(options);
        Main::mainframe.frame.draw(exit);
        cursor.setPosition(curPos[curPosI]);
        Main::mainframe.frame.draw(cursor);

        Main::mainframe.frame.display();
        Main::mainframe.winRefresh();
      }
      bgMusTitle.stop();
      return 0;
    }

    int MainMenu::mainMenu() {
      initVars();
      verifVars();
      //Début de la musique
      bgMusTitle.setVolume(50);
      bgMusTitle.play();
      //Lancement de la boucle
      return boucle0();
    }
  }
}
