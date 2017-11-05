#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define FPS_TICKS 33
#include <cmath>
//#define ppPosY ((character.getPosition().y / CASE_SIZE) - 8)
//#define ppPosX (((character.getPosition().x - 16) / CASE_SIZE) - 8)
#include "Events.hpp"
#include "Dialog.hpp"
					      
#ifndef _WIN32

//#define DEBUG_REPORT

#endif

UNS

namespace OpMon{
  namespace View{


    void Overworld::moveCamera(Side dir){
      switch(dir){
      case Side::TO_UP:
	camera.move(0, -4);
	break;
      case Side::TO_DOWN:
	camera.move(0, 4);
	break;
      case Side::TO_LEFT:
	camera.move(-4, 0);
	break;
      case Side::TO_RIGHT:
	camera.move(4, 0);
	break;
      }
    }
    
    void Overworld::tp(std::string toTp, sf::Vector2i pos){
      Model::Data::player.tp(toTp, pos);
      current = &Model::Data::World::maps.at(Model::Data::player.getMapId());
      character.setPosition(8 CASES + pos.x CASES - 16, 8 CASES + pos.y CASES);
      if(music != current->getBg()) {
	music->stop();
	music = current->getBg();
	music->play();
      }

      delete(layer1);
      delete(layer2);
      delete(layer3);
  
      layer1 = new MapLayer(current->getLayer1());
      layer2 = new MapLayer(current->getLayer2());
      layer3 = new MapLayer(current->getLayer3());
      tpCount = 0;
    }

    void init(){
      for(auto map = Initializer::maps.cbegin(); map!=Initializer::maps.cend(); ++map) {
	for(Event *event : map->second.getEvents()) {
	  Events::TalkingEvent *te = dynamic_cast<Events::TalkingEvent *>(event);
	  if(te != nullptr) {
	    te->reloadKeys();
	  }
	}
      }
      posArrow = Window::frame.mapPixelToCoords(sf::Vector2i(512-75, 512-30));
      Dialog::arrDial.setPosition(posArrow);

      if(music != nullptr){
	music->play();
      }else{
	handleError("Error : Music = nullptr in Overworld.", false);
      }
      Window::frame.setView(camera);
    }

    void del(){
      music->stop();
      delete(layer1);
      delete(layer2);
      delete(layer3);
    }

    GameStatus Overworld::operator()(bool dialog, int frame, std::vector<sf::String> const& dialogs = actualDialog){
      if(!launched){
	init();
	launched = true;
      }
      if(dialog){
	// `&dialogs[0]` converts the std::vector into a regular array.
	this->dialog = new Dialog(&dialogs[0], dialogs.size());
      }
      fpsCounter++;
      if(GET_TICKS - oldTicksFps >= 1000) {
	fps = "";
	fps << fpsCounter;
	fpsPrint.setString(fps);
	fpsCounter = 0;
	oldTicksFps = GET_TICKS;
      }
      sf::Text debugText;
      /*
	In the bloc, every commented line must be moved in GameLoop
      */
      if(debugMode){
	//cout << "[FRAME Nｰ" << frames << "]" << endl;
	cout << "Boucle : " << dialog ? "Normale" : "Dialog" << endl;
	cout << "Tick: " << GET_TICKS << "ms" << endl;
	cout << "PlayerPosition: " << Model::Data::player.getPosition().getPosition().x << " - " << Model::Data::player.getPosition().getPosition().y << endl;
	cout << "PlayerPositionPx: " << character.getPosition().x << " - " << character.getPosition().y << endl;
	cout << "Moving: " << Model::Data::player.getPosition().isMoving() ? "true" : "false" << endl;
	cout << "Anim: " << Model::Data::player.getPosition().isAnim() ? "true" : "false" << endl;
	cout << "PlayerDirection: " << (int) ppDir << endl;
    
	debugText.setString("Debug mode");
	debugText.setPosition(Window::frame.mapPixelToCoords(sf::Vector2i(0, 0)));
	debugText.setFont(Main::mainframe.font);
	debugText.setColor(sf::Color(127, 127, 127));
	debugText.setCharacterSize(40);
	fpsPrint.setPosition(Window::frame.mapPixelToCoords(sf::Vector2i(0, 50)));
	fpsPrint.setFont(Main::mainframe.font);
	fpsPrint.setCharacterSize(48);
      }
  
      Window::frame.clear(sf::Color::Black);
      //Drawing the two first layers
      if((debugMode ? printlayer[0] : true)) {
	Window::frame.draw(*layer1);
      }
      if((debugMode ? printlayer[1] : true)) {
	Window::frame.draw(*layer2);
      }
      //Drawing event under the player
      for(Event *event : current->getEvents()) {
	if(event->getPosition().y <= ppPosY) {
	  Window::frame.draw(*event->getSprite());
	}
      }
      //Sets the character's texture.
      if(Model::Data::player.getPosition().isAnim() && !anims) {
	character.setTexture(Model::Data::Ui::walkingPP[(int) Model::Data::player.getPosition().getDir()]);
	animsCounter++;
	anims = animsCounter > 8;

      } else if(Model::Data::player.getPosition().isAnim() && anims) {
	character.setTexture(Model::Data::Ui::walkingPP2[(int) anim]);
	animsCounter++;
	if(animsCounter > 16) {
	  anims = false;
	  animsCounter = 0;
	}
      } else if(Model::Data::player.getPosition().isAnim()) {
	character.setTexture(Model::Data::Ui::texturePP[(int) ppDir]);
      }
      //Drawing character
      Window::frame.draw(character);
      //Drawing the events above the player
      for(Event *event : current->getEvents()) {
	if(event->getPosition().y > ppPosY) {
	  Window::frame.draw(*event->getSprite());
	}
      }
      //Drawing the third layer
      if((debugMode ? printlayer[2] : true)) {
	Window::frame.draw(*layer3);
      }
      if(scrolling){
	camera.setCenter(character.getPosition().x + 16, character.getPosition().y + 16);
      }
      Window::frame.setView(Window::frame.getDefaultView());
      Window::frame.setView(camera);
      updateElements();
  
      if(dialog){
	this->dialog.updateTextAnimation();
	this->dialog.draw();
      } else if(Model::Data::player.getPosition().isAnim()){
	if(Model::Data::player.getPosition().isMoving()){
	  switch(Model::Data::player.getPosition().getDir()){
	  case Side::TO_UP:
	    character.move(0, -4);
	    break;
	  case Side::TO_DOWN:
	    character.move(0, 4);
	    break;
	  case Side::TO_LEFT:
	    character.move(-4, 0);
	    break;
	  case Side::TO_RIGHT:
	    character.move(4, 0);
	    break;
	  }
	}
	if(frames - startFrames >= 7){
	  Model::Data::player.getPosition().stopMove();
	}
      }

      if(debugMode){
	Window::frame.draw(debugText);
	Window::frame.draws(fpsPrint);
      }

      //Refresh to do in GameLoop

      return endGame ? GameStatus::CONTINUE : GameStatus::STOP;
  
    }

  }

}
