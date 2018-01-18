#include "Animations.hpp"
#include "../view/Window.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/time.hpp"
#include "../start/Core.hpp"
#include "../model/storage/Data.hpp"

UNS

namespace OpMon{
  namespace View{
    
    namespace Animations {

      
      Animation::Animation(sf::Texture bgTxt)
	: bgTxt(bgTxt) {}

      WinAnim::WinAnim(sf::Texture bgTxt, bool order)
	: Animation(bgTxt), order(order) {}
      
      
      GameStatus WinAnim::operator()() {

	bgSpr.setTexture(bgTxt);
	anim.setTexture(Model::Data::Animations::fen[order ? counter : (frames - counter)]);
	window.clear(sf::Color::Black);
	window.draw(bgSpr);
	window.draw(anim);
	window.display();
	
	counter++;
	return (counter > frames) ? GameStatus::PREVIOUS : GameStatus::CONTINUE;
      }


    }
  }
}
