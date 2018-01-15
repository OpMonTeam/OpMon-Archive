#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../model/objects/Enums.hpp"

#define FPS_TICKS 33
#include <cmath>
//#define ppPosY ((character.getPosition().y / CASE_SIZE) - 8)
//#define ppPosX (((character.getPosition().x - 16) / CASE_SIZE) - 8)
#include "../model/sysObjects/Events.hpp"
#include "Dialog.hpp"
#include "../../utils/log.hpp"
#include "../../utils/time.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/Data.hpp"
#include "Window.hpp"


#ifndef _WIN32

//#define DEBUG_REPORT

#endif

UNS
using OpMon::Model::Side;

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
      current = Model::Data::World::maps.at(Model::Data::player.getMapId());
      character.setPosition(8 SQUARES + pos.x SQUARES - 16, 8 SQUARES + pos.y SQUARES);
      if(musicPath != current->getBg()) {
	setMusic(current->getBg());
	music->play();
      }
      
      delete(layer1);
      delete(layer2);
      delete(layer3);
  
      layer1 = new MapLayer(current->getDimensions(), current->getLayer1());
      layer2 = new MapLayer(current->getDimensions(), current->getLayer2());
      layer3 = new MapLayer(current->getDimensions(), current->getLayer3());
      tpCount = 0;
      
      for(auto itor = current->getEvents().begin(); itor != current->getEvents().end(); ++itor){
	eventsSprites.try_emplace(itor, new sf::Sprite());
	eventsSprites[itor].setPosition();
	eventsSprites[itor].setTexture(itor->getTexture());
      }
    }

    void Overworld::pause(){
      if (music)
        music->pause();
    }

    void Overworld::play(){
      if (music)
        music->play();
    }

    Overworld::Overworld(){
      character.setTexture(Model::Data::Ui::texturePP[(int) Side::TO_DOWN]);
      character.setPosition(8 SQUARES + 2 SQUARES - 16, 8 SQUARES + 2 SQUARES);
      camera.setCenter(this->getCharacter().getPosition());
      camera.setSize(sf::Vector2f(16 SQUARES, 16 SQUARES));
      
      setMusic(current->getBg());
      layer1 = new MapLayer(current->getDimensions(), current->getLayer1());
      layer2 = new MapLayer(current->getDimensions(), current->getLayer2());
      layer3 = new MapLayer(current->getDimensions(), current->getLayer3());
      character.setScale(2, 2);
      character.setOrigin(16, 16);
      for(auto map = Model::Data::World::maps.cbegin(); map != Model::Data::World::maps.cend(); ++map) {

    //This should be done in event constructor
	for(Model::Event *event : map->second->getEvents()) {
	  Model::Events::TalkingEvent *te = dynamic_cast<Model::Events::TalkingEvent *>(event);
	  if(te != nullptr) {
	    te->onLangChanged();
	  }
	}
      }
      posArrow = View::frame.mapPixelToCoords(sf::Vector2i(512-75, 512-30));
      Dialog::arrDial.setPosition(posArrow);

      if(music != nullptr){
	music->play();
      }else{
	setMusic(current->getBg());
	music->play();
      }

    View::frame.setView(camera);
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

      fpsCounter++;
      if(Utils::Time::getElapsedMilliseconds() - oldTicksFps >= 1000) {
        fps = "";
        fps << fpsCounter;
        fpsPrint.setString(fps);
        fpsCounter = 0;
        oldTicksFps = Utils::Time::getElapsedMilliseconds();
      }
      sf::Text debugText;
      /*
	In the bloc, every commented line must be moved in GameLoop
      */
      if(debugMode){
	//cout << "[FRAME Nｰ" << frames << "]" << endl;
	cout << "Boucle : " << (is_in_dialog ? "Normale" : "Dialog") << endl;
	cout << "Tick: " << Utils::Time::getElapsedMilliseconds() << "ms" << endl;
	cout << "PlayerPosition: " << Model::Data::player.getPosition().getPosition().x << " - " << Model::Data::player.getPosition().getPosition().y << endl;
	cout << "PlayerPositionPx: " << character.getPosition().x << " - " << character.getPosition().y << endl;
	cout << "Moving: " << (Model::Data::player.getPosition().isMoving() ? "true" : "false") << endl;
	cout << "Anim: " << (Model::Data::player.getPosition().isAnim() ? "true" : "false") << endl;
	cout << "PlayerDirection: " << (int) Model::Data::player.getPosition().getDir() << endl;
    
	debugText.setString("Debug mode");
	debugText.setPosition(View::frame.mapPixelToCoords(sf::Vector2i(0, 0)));
	debugText.setFont(Model::Data::Ui::font);
	debugText.setColor(sf::Color(127, 127, 127));
	debugText.setCharacterSize(40);
	fpsPrint.setPosition(View::frame.mapPixelToCoords(sf::Vector2i(0, 50)));
	fpsPrint.setFont(Model::Data::Ui::font);
	fpsPrint.setCharacterSize(48);
      }

      View::frame.clear(sf::Color::Black);
      //Drawing the two first layers
      if((debugMode ? printlayer[0] : true)) {
        View::frame.draw(*layer1);
      }
      if((debugMode ? printlayer[1] : true)) {
        View::frame.draw(*layer2);
      }
      //Drawing events under the player
      for(auto itor = eventsSprites.begin(); itor != eventsSprites.end(); ++itor) {
	if(itor->first->getPosition().y <= ppPosY) {
	  itor->second.setTexture(*itor->first->getTexture());
    View::frame.draw(itor->second);
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
      View::frame.draw(character);
      //Drawing the events above the player
      for(auto itor = eventsSprites.begin(); itor != eventsSprites.end(); ++itor) {
	if(itor->first->getPosition().y > ppPosY) {
	  itor->second.setTexture(*itor->first->getTexture());
    View::frame.draw(itor->second);
	}
      }
      //Drawing the third layer
      if((debugMode ? printlayer[2] : true)) {
        View::frame.draw(*layer3);
      }
      if(scrolling){
	camera.setCenter(character.getPosition().x + 16, character.getPosition().y + 16);
      }
      View::frame.setView(View::frame.getDefaultView());
      View::frame.setView(camera);
      printElements(View::frame);
  
      if(is_in_dialog){
        this->dialog->updateTextAnimation();
        this->dialog->draw(View::frame);
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
        View::frame.draw(debugText);
        View::frame.draw(fpsPrint);
      }

      //Refresh to do in GameLoop

      //return endGame ? GameStatus::CONTINUE : GameStatus::STOP;
      return GameStatus::CONTINUE;
    }

    /**
     * Events can call this method to start a new dialog with the player.
     */
    void Overworld::startDialog(std::vector<sf::String> const& dialogs) {
      if (this->dialog){
        if (!this->dialog->isDialogOver()){
          Utils::Log::oplog("WARNING: We create a new dialog ... but the last one isn't finished yet!", true);
        }
        delete(this->dialog);
      }

      // `&dialogs[0]` converts the std::vector into a regular array.
      this->dialog = new Dialog(&dialogs[0], dialogs.size());
    }
  }

}
