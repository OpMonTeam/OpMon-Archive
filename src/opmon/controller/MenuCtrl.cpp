#include "MenuCtrl.hpp"

namespace OpMon{
  namespace Controller{
    namespace MenuCtrl{
      GameStatus checkEvents(sf::Events& event, View::MainMenu& menu){
	switch(event) {
	  
	case sf::Event::KeyPressed:
	  if(event.key.code == sf::Keyboard::Return) {
	    switch(curPosI) {
	    case 0:
	      bgMusTitle.stop();
	      return (View::Interface*) new View::StartScene();
	    case 3:
	      bgMusTitle.stop();
	      return nullptr;
	    case 2:
	      return (View::Interface*) new View::OptionsMenu();
	      break;
	    case 1:
	      Model::Data::Sounds::nope.play();
	      return &menu;
	    }
	  }else if(event.key.code == sf::Keyboard::Up){
	    menu.moveArrow(true);
	  }else if(event.key.code == sf::Keyboard::Down){
	    menu.moveArrow(false);
	  }
	  break;
	default:
	  break;

	}
      }

      GameStatus Options::checkEvents(sf::Event& event, View::OptionsMenu& menu){
	switch(event.type){
	case sf::Event::KeyPressed:
	  if(event.key.code == sf::Keyboard::Return){
	    if(menu.getCurrentOption() == View::OptionType::ALL){
	      switch(menu.cursorPosition()){
	      case 0:
		return GameStatus::PREVIOUS;
	      case 1:
		if(Model::OptionsSave::getParam("fullscreen").getValue() == "true") {
		  Model::OptionsSave::addOrModifParam("fullscreen", "false");
		} else {
		  Model::OptionsSave::addOrModifParam("fullscreen", "true");
		}
		break;
	      case 2:
		menu.setCurrentOption(View::OptionType::LANG);
		return GameStatus::CONTINUE;
		break;
	      case 3:
		Model::Data::Sounds::nope.play();
		break;
	      case 4:
		menu.setCurrentOption(View::OptionType::CREDITS);
		return GameStatus::CONTINUE;
		break;
	      }
	    }else if(menu.getCurrentOption() == View::OptionType::LANG){
	      bool changedLang = false;
	      switch(menu.cursorPosition()){
	      case 0:
		menu.setCurrentOption(View::OptionType::ALL);
		return GameStatus::CONTINUE;
	      case 1:
		Model::OptionsSave::modifyParam("lang", "eng");
		Utils::StringKeys::initialize(getPath(RESSOURCES_PATH + "keys/english.rkeys"));
		changedLang = true;
		break;
	      case 2:
		Model::OptionsSave::modifyParam("lang", "esp");
		Utils::Stringkeys::initialize(getPath(RESSOURCES_PATH + "keys/espanol.rkeys"));
		changedLang = true;
		break;
	      case 3:
		Model::OptionsSave::modifyParam("lang", "fr");
		Utils::StringKeys::initialize(getPath(RESSOURCES_PATH + "keys/francais.rkeys"));
		changedLang = true;
		break;
	      }
	      if(changedLang){
		Initializer::initStrings();
	      }
	    }else{
	      return GameStatus::CONTINUE;
	    }
	  }
	  if(event.key.code == sf::Keyboard::Up){
	    menu.moveArrow(true);
	  }else if(event.key.code == sf::Keyboard::Down){
	    menu.moveArrow(false);
	  }else if(event.key.code == sf::Keyboard::BackSpace){
	    if(menu.getCurrentOption() == View::OptionsType::ALL){
	      return GameStatus::PREVIOUS;
	    }else{
	      menu.setCurrentOption(View::OptionType::ALL);
	      return GameStatus::CONTINUE;
	    }
	  }
	  
	}
	return GameStatus::CONTINUE;
      }
    }
  }
}
