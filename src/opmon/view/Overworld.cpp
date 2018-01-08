#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define FPS_TICKS 33
#include <cmath>
//#define ppPosY ((character.getPosition().y / CASE_SIZE) - 8)
//#define ppPosX (((character.getPosition().x - 16) / CASE_SIZE) - 8)
#include "Events.hpp"
#include "Dialog.hpp"
#include "../../utils/log.hpp"
#include "../../utils/time.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/Data.hpp"


#ifndef _WIN32

//#define DEBUG_REPORT

#endif

UNS

namespace OpMon{
  namespace View{

    void Overworld::setMusic(std::string const& path){
      if(path != musicPath){
	
      
	musicPath = path;
	if(music != nullptr){
	  music->stop();
	  delete(music);
	}
	music = new sf::Music();
	music->openFromFile(path);
	music->setLoop(true);
      }
    }
						      
    
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

    void Overworld::printElements(sf::RenderTexture& frame){
      for(std::string const& i : current->getAnimatedElements()) {
	Model::Data::Elements::elementsCount[i]++;
        if(Model::Data::Elements::elementsCount[i] >= (int) Model::Data::Elements::animatedElements[i].size()) {
	  Model::Data::Elements::elementsCount[i] = 0;
        }
        Model::Data::Elements::elementsSprites[i].setTexture(animatedElements[i][elementsCount[i]]);
        frame.draw(Model::Data::Elements::elementsSprites[i]);
      }
    }
    
    void Overworld::tp(std::string toTp, sf::Vector2i pos){
      Model::Data::player.tp(toTp, pos);
      current = &Model::Data::World::maps.at(Model::Data::player.getMapId());
      character.setPosition(8 CASES + pos.x CASES - 16, 8 CASES + pos.y CASES);
      if(musicPath != current->getBg()) {
	setMusic(current->getBg());
	music->play();
      }
      
      delete(layer1);
      delete(layer2);
      delete(layer3);
  
      layer1 = new MapLayer(current->getDimentions(), current->getLayer1());
      layer2 = new MapLayer(current->getDimentions(), current->getLayer2());
      layer3 = new MapLayer(current->getDimentions(), current->getLayer3());
      tpCount = 0;
      
      for(auto itor = current->getEvents().begin(); itor != current->getEvents().end(); ++itor){
	eventsSprites.try_emplace(itor, new sf::Sprite());
	eventsSprites[itor].setPosition();
	eventsSprites[itor].setTexture(itor->getTexture());
      }
    }

    void pause(){
      music.pause();
    }

    void play(){
      music.play();
    }

    Overworld(){
      init();
      
    }
    
    void init(){
      character.setTexture(Initializer::texturePP[(int) Side::TO_DOWN]);
      character.setPosition(8 * CASES + 2 * CASES - 16, 8 * CASES + 2 * CASES);
      camera.setCenter(this->getCharacter().getPosition());
      camera.setSize(sf::Vector2f(16 *CASES, 16 * CASES));
      
      setMusic(actual->getBg());
      setLayer1(MapLayer(actual->getLayer1(), Model::Data::World::tileset));
      setLayer2(MapLayer(actual->getLayer2(), Model::Data::World::tileset));
      setLayer2(MapLayer(actual->getLayer3(), Model::Data::World::tileset));
      character.setScale(2, 2);
      character.setOrigin(16, 16);
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
	setMusic(current->getBg());
	music->play();
      }

    Window::frame.setView(camera);
    launched = true;
  }

    Overworld::~Overworld(){
    music->stop();
    delete(music);
    delete(layer1);
    delete(layer2);
    delete(layer3);
  }

    GameStatus Overworld::operator()(int frames){
      bool is_in_dialog = this->dialog && !this->dialog->isDialogOver();

      if(!launched){
	    init();
      }
      fpsCounter++;
      if(Utils::getElapsedMilliseconds() - oldTicksFps >= 1000) {
        fps = "";
        fps << fpsCounter;
        fpsPrint.setString(fps);
        fpsCounter = 0;
        oldTicksFps = Utils::getElapsedMilliseconds();
      }
      sf::Text debugText;
      /*
	In the bloc, every commented line must be moved in GameLoop
      */
      if(debugMode){
	//cout << "[FRAME Nｰ" << frames << "]" << endl;
	cout << "Boucle : " << is_in_dialog ? "Normale" : "Dialog" << endl;
	cout << "Tick: " << Utils::getElapsedMilliseconds() << "ms" << endl;
	cout << "PlayerPosition: " << Model::Data::player.getPosition().getPosition().x << " - " << Model::Data::player.getPosition().getPosition().y << endl;
	cout << "PlayerPositionPx: " << character.getPosition().x << " - " << character.getPosition().y << endl;
	cout << "Moving: " << Model::Data::player.getPosition().isMoving() ? "true" : "false" << endl;
	cout << "Anim: " << Model::Data::player.getPosition().isAnim() ? "true" : "false" << endl;
	cout << "PlayerDirection: " << (int) ppDir << endl;
    
	debugText.setString("Debug mode");
	debugText.setPosition(Window::frame.mapPixelToCoords(sf::Vector2i(0, 0)));
	debugText.setFont(Model::Data::Ui::font);
	debugText.setColor(sf::Color(127, 127, 127));
	debugText.setCharacterSize(40);
	fpsPrint.setPosition(Window::frame.mapPixelToCoords(sf::Vector2i(0, 50)));
	fpsPrint.setFont(Model::Data::Ui::font);
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
      //Drawing events under the player
      for(auto itor = eventsSprites.begin(); itor != eventsSprites.end(); ++itor) {
	if(itor->first->getPosition().y <= ppPosY) {
	  itor->second.setTexture(itor->first->getTexture());
	  Window::frame.draw(itor->second);
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
      for(auto itor = eventsSprites.begin(); itor != eventsSprites.end(); ++itor) {
	if(itor->first->getPosition().y > ppPosY) {
	  itor->second.setTexture(itor->first->getTexture());
	  Window::frame.draw(itor->second);
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
      printElements();
  
      if(is_in_dialog){
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

    /**
     * Events can call this method to start a new dialog with the player.
     */
    void Overworld::startDialog(std::vector<sf::String> const& dialogs) {
      if (this->dialog){
        if (!this->dialog.isDialogOver()){
          oplog("WARNING: We create a new dialog ... but the last one isn't finished yet!", true);
        }
        delete(this->dialog);
      }

      // `&dialogs[0]` converts the std::vector into a regular array.
      this->dialog = new Dialog(&dialogs[0], dialogs.size());
    }
  }

}
