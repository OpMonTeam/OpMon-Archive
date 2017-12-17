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

    void MainMenu::MainMenu() {

    }


    void init(){
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



      bgMusTitle.setLoop(true);
    }

    void MainMenu::del() {
      bgMusTitle.stop();
    }

    void MainMenu::pause(){
      bgMusTitle.stop();
    }

    void MainMenu::play(){
      bgMusTitle.play();
    }

    void moveArrow(bool direction){
      Model::Data::Sounds::arrow.play();
      if(direction /* == true*/){
	curPosI--;
      }else{
	curPosI++;
      }
      if(curPosI >= 4) {
	curPosI = 0;
      } else if(curPosI < 0) {
	curPosI = 3;
      }
    }
    
    int MainMenu::operator()() {

      if(!launched){
	init();
      }

      Main::mainframe.frame.clear(sf::Color::lack);

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
	
      return GameStatus::CONTINUE;
    }

    void MainMenu::init() {
      bgMusTitle.setVolume(50);
      bgMusTitle.play();
      
      oplog("Initialisating the menu");
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
      launched = true;
    }
  }
}
