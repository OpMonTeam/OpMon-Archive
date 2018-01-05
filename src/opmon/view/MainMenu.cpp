#include "MainMenu.hpp"
#include "../start/main.hpp"
#include <iostream>
#include "OptionsMenu.hpp"
#include "./Window.hpp"
#include "../model/storage/Data.hpp"

UNS

namespace OpMon{
  namespace View{

    void MainMenu::initStrings() {
      playtx.setString(kget("title.1"));
      charge.setString(kget("title.2"));
      options.setString(kget("title.3"));
      exit.setString(kget("title.4"));
    }

    void MainMenu::MainMenu() {
            sf::Text *textPos[4] = {&playtx, &charge, &options, &exit};
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
      playtx.setColor(sf::Color::White);
      charge.setColor(sf::Color::White);
      options.setColor(sf::Color::White);
      exit.setColor(sf::Color::White);

      playtx.setFont(Model::Data::Ui::font);
      charge.setFont(Model::Data::Ui::font);
      options.setFont(Model::Data::Ui::font);
      exit.setFont(Model::Data::Ui::font);
      playtx.setCharacterSize(FONT_SIZE_DEFAULT);
      charge.setCharacterSize(FONT_SIZE_DEFAULT);
      options.setCharacterSize(FONT_SIZE_DEFAULT);
      exit.setCharacterSize(FONT_SIZE_DEFAULT);
      //Mix_Volume(2, MIX_MAX_VOLUME / 4);
      //Mix_Volume(1, MIX_MAX_VOLUME);
      //Mix_Volume(0, MIX_MAX_VOLUME / 2);



      bgMusTitle.setLoop(true);

      wait = true;
      
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

      frame.clear(sf::Color::lack);

      //Actualisation des éléments
      frame.draw(bg);
      frame.draw(playtx),
	frame.draw(charge);
      frame.draw(options);
      frame.draw(exit);
      cursor.setPosition(curPos[curPosI]);
      frame.draw(cursor);

      frame.display();
      winRefresh();
	
      return GameStatus::CONTINUE;
    }

    void MainMenu::init() {
      bgMusTitle.setVolume(50);
      bgMusTitle.play();
      
      oplog("Initialisating the menu");
      //Actualisation des éléments
      frame.draw(bg);
      frame.draw(playtx),
	frame.draw(charge);
      frame.draw(options);
      frame.draw(exit);
      cursor.setPosition(curPos[curPosI]);
      frame.draw(cursor);

      frame.display();
      winRefresh();
      launched = true;
    }
  }
}
