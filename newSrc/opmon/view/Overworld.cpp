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

void Overworld::initVars() {
  
}

void Overworld::tp(std::string toTp, sf::Vector2i pos){
  Model::Data::player.getPosition().tp(toTp, pos);
  actual = &Model::Data::World::maps.at(Model::Data::player.getPosition().getMapId());
  character.setPosition(8 CASES + pos.x CASES - 16, 8 CASES + pos.y CASES);
  if(music != actual->getBg()) {
    music->stop();
    music = actual->getBg();
    music->play();
  }

  delete(layer1);
  delete(layer2);
  delete(layer3);
  
  layer1 = new MapLayer(actual->getLayer1());
  layer2 = new MapLayer(actual->getLayer2());
  layer3 = new MapLayer(actual->getLayer3());
  tpCount = 0;
}



GameStatus Overworld::overworld() {
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
    
  music->play();
  Window::frame.setView(camera);
  GameStatus returned = boucle();
  music->stop();
  delete(layer1);
  delete(layer2);
  delete(layer3);
  return returned;
}

GameStatus Overworld::operator()(bool dialog, int frame, std::vector<sf::String> dialogs = std::vector<OpString>()){
  if(dialog){
    // `&dialogs[0]` converts the std::vector into a regular array.
    dialog = new Dialog(&dialogs[0], dialogs.size());
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

  if(!dialog){
    if(moving == Side::NO_MOVE) {
      std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i(ppPosX CASES, ppPosY CASES));
      if(nextEvents.size() > 0) {
	for(Event *nextEvent : nextEvents) {
	  if(nextEvent->getEventTrigger() == Events::EventTrigger::BE_IN) {
	    bool go = false;
	    if(((nextEvent->getSide() & SIDE_UP) == SIDE_UP) && (ppDir == Side::TO_UP)) {
	      go = true;
	    } else if(((nextEvent->getSide() & SIDE_DOWN) == SIDE_DOWN) && (ppDir == Side::TO_DOWN)) {
	      go = true;
	    } else if(((nextEvent->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && (ppDir == Side::TO_RIGHT)) {
	      go = true;
	    } else if(((nextEvent->getSide() & SIDE_LEFT) == SIDE_LEFT) && (ppDir == Side::TO_LEFT)) {
	      go = true;
	    }
	    if(go) {
	      nextEvent->action(Main::player);
	    }
	  }
	}
      }
    }
  }
  
  Window::frame.clear(sf::Color::Black);
  //Drawing the two first layers
  if((debugMode ? printlayer[0] : true)) {
    Window::frame.draw(*layer1);
  }
  if((debugMode ? printlayer[1] : true)) {
    Window::frame.draw(*layer2);
  }
  //Updaing events
  if(!dialog){
    actual->updateEvents(Main::player);
  }
  //Drawing event under the player
  for(Event *event : actual->getEvents()) {
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
  for(Event *event : actual->getEvents()) {
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
    dialog.updateTextAnimation();
    dialog.draw();
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

//This passage must be moved in OverworldCtrl

/*Main::mainframe.window.pollEvent(Main::mainframe.events);

switch(Main::mainframe.events.type) {
  RETURN_ON_CLOSE_EVENT

 case sf::Event::KeyPressed:
  if(Main::mainframe.events.key.code == sf::Keyboard::Equal) {
    debugMode = !debugMode;
  }
  if(debugMode) {
    if(Main::mainframe.events.key.code == sf::Keyboard::F10) {
      printlayer[0] = !printlayer[0];
    }
    if(Main::mainframe.events.key.code == sf::Keyboard::F11) {
      printlayer[1] = !printlayer[1];
    }
    if(Main::mainframe.events.key.code == sf::Keyboard::F12) {
      printlayer[2] = !printlayer[2];
    }

    if(Main::mainframe.events.key.code == sf::Keyboard::F5) {
      tp("Mom's room", sf::Vector2i(0, 1), true);
    } else if(Main::mainframe.events.key.code == sf::Keyboard::F6) {
      tp("Player's room", sf::Vector2i(0, 0), true);
    } else if(Main::mainframe.events.key.code == sf::Keyboard::F1) {
      tp("Fauxbourg Euvi", sf::Vector2i(25, 28), true);
    } else if(Main::mainframe.events.key.code == sf::Keyboard::F2) {
      tp("Player's home", sf::Vector2i(8, 14), true);
    } else if(Main::mainframe.events.key.code == sf::Keyboard::F3) {
      tp("Laboratory", sf::Vector2i(15, 14), true);
    } else if(Main::mainframe.events.key.code == sf::Keyboard::F4) {
      tp("Rival's house", sf::Vector2i(8, 14), true);
    } else if(Main::mainframe.events.key.code == sf::Keyboard::F7){
      tp("Route 14", sf::Vector2i(0, 31), true);
    } else if(Main::mainframe.events.key.code == sf::Keyboard::F8){
      tp("MysteriouCity", sf::Vector2i(12, 0), true);
    }
  }
 default:
   break;
 }
RETURN_ON_ECHAP_EVENT
if(Main::player.gameIsOver) {
  return -1;
 }
if(!justTp) {
  if(isKeyPressed(sf::Keyboard::Up)) {
    up();
  } else if(isKeyPressed(sf::Keyboard::Down)) {
    down();
  } else if(isKeyPressed(sf::Keyboard::Left)) {
    left();
  } else if(isKeyPressed(sf::Keyboard::Right)) {
    right();
  }
 }
	  
if(debugMode) {
  if(isKeyPressed(sf::Keyboard::Numpad2)) {
    camera.move(0, 4);
  }
  if(isKeyPressed(sf::Keyboard::Numpad4)) {
    camera.move(-4, 0);
  }
  if(isKeyPressed(sf::Keyboard::Numpad8)) {
    camera.move(0, -4);
  }
  if(isKeyPressed(sf::Keyboard::Numpad6)) {
    camera.move(4, 0);
  }
 }

		
  ________________________________________________________


  if(anim == Side::NO_MOVE) {
    if(isKeyPressed(sf::Keyboard::Return)) {
      int lx = ppPosX;
      int ly = ppPosY;
      switch(ppDir) {
      case Side::TO_UP:
	ly--;
	break;
      case Side::TO_DOWN:
	ly++;
	break;
      case Side::TO_LEFT:
	lx--;
	break;
      case Side::TO_RIGHT:
	lx++;
	break;
      default:
	break;
      }
      vector<Event *> events = actual->getEvent(sf::Vector2i(lx CASES, ly CASES));
                    
      if(events.size() > 0) {
	for(unsigned int i = 0; i < events.size(); i++) {
	  if(events[i]->getEventTrigger() == Events::EventTrigger::PRESS) {
	    bool go = false;
	    if(((events[i]->getSide() & SIDE_UP) == SIDE_UP) && ppDir == Side::TO_UP) {
	      go = true;
	    } else if(((events[i]->getSide() & SIDE_DOWN) == SIDE_DOWN) && ppDir == Side::TO_DOWN) {
	      go = true;
	    } else if(((events[i]->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && ppDir == Side::TO_RIGHT) {
	      go = true;
	    } else if(((events[i]->getSide() & SIDE_LEFT) == SIDE_LEFT) && ppDir == Side::TO_LEFT) {
	      go = true;
	    }
	    if(go) {
	      events[i]->action(Main::player);
	    }
	  }
	}
      }
    }
  }*/
           
	    
//int Overworld::boucleDialog(vector<sf::String> const& dialogs)
 


/*
  while(!dialog.isDialogOver()) {*/
//Don't forget this part
  
//To do in the controller
/*
  switch(Main::mainframe.events.type) {
  RETURN_ON_CLOSE_EVENT

  case sf::Event::KeyPressed:
  if(Main::mainframe.events.key.code == sf::Keyboard::Space) {
  dialog.pass();
  }
  break;
  default:
  break;
  }
  if(isKeyPressed(sf::Keyboard::Escape)) {
  Main::player.gameIsOver = true;
  return -1;
  }
*/
           

