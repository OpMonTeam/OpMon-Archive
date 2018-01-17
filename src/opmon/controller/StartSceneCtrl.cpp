
#include <src/opmon/model/storage/Data.hpp>
#include <src/opmon/view/Window.hpp>
#include "StartSceneCtrl.hpp"
#include "./OverworldCtrl.hpp"
#include "AnimationCtrl.hpp"

namespace OpMon{
  namespace Controller{

    StartSceneCtrl::StartSceneCtrl()
    :view(){}

    GameStatus StartSceneCtrl::checkEvent(sf::Event const& event){
      auto &startscene = view;

      switch(event.type){
        case sf::Event::KeyPressed:
          if(event.key.code == sf::Keyboard::Space){
            startscene.getDialog()->pass();
          }
          if(event.key.code == sf::Keyboard::Return && startscene.getPart() == 1){
            sf::String& pName = startscene.getpName();
            if(pName.isEmpty()){
              pName = "Player";
            }
            startscene.delLoop1();
	    _next_gs = new AnimationCtrl(new View::Animations::WinAnim(false));
	    return GameStatus::NEXT;
          }
          break;
        case sf::Event::TextEntered:
          if(startscene.getPart() == 1){
            if(event.text.unicode == 8) { //Backspace
              sf::String& pName = startscene.getpName();
              if(!pName.isEmpty()){
                pName = sf::String::fromUtf32(pName.begin(), pName.end() - 1);
              } else if(event.text.unicode == '\n' || event.text.unicode <= 32) {//Do nothing
              } else {
                if (pName.toUtf32().size() < 14) {//14 = Max name length
                  pName += event.text.unicode;
                }
              }
            }
          }
      }

      if (view.getPart() > 2){
        _next_gs = new OverworldCtrl(Model::Data::player);
        return GameStatus::NEXT;
      }
      return GameStatus::CONTINUE;
    }

    GameStatus StartSceneCtrl::update(){
      GameStatus toReturn = view();
      view.draw(View::frame);

      if(toReturn == GameStatus::NEXT){	
	switch(view.getPart()){
	case 1:
	  _next_gs = new AnimationCtrl(new View::Animations::WinAnim(true));
	  break;
	case 3:
	  _next_gs = new OverworldCtrl(Model::Data::player);
	  break;
	default:
	  handleError("Internal error, unknown part in StartSceneCtrl::update", true);
	  break;
	}
      }

      return toReturn;
    }

  }
}
