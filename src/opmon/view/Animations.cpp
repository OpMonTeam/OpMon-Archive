#include "Animations.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/time.hpp"
#include "../start/Core.hpp"
#include "../view/Window.hpp"
#include "../model/storage/ResourceLoader.hpp"

UNS

  namespace OpMon {
    namespace View {

        namespace Animations {

	  bool WinAnim::fenInit = false;
	  sf::Texture WinAnim::fen[6];
	  
            Animation::Animation(sf::Texture bgTxt)
              : bgTxt(bgTxt) {
	      
	    }

            WinAnim::WinAnim(sf::Texture bgTxt, bool order)
              : Animation(bgTxt)
              , order(order) {
	      if(!fenInit){
		fenInit = true;
		Model::ResourceLoader::loadTextureArray(fen, "animations/winChange/animWindowFrame%d.png", 6, 1);
	      }
            }

	  GameStatus WinAnim::operator()(sf::RenderTexture& frame) {
                bgSpr.setTexture(bgTxt);
                anim.setTexture(fen[(order ? counter : (frames - counter))]);

                frame.draw(bgSpr);
                frame.draw(anim);

                counter++;
                return (counter > frames) ? GameStatus::PREVIOUS : GameStatus::CONTINUE;
            }

        } // namespace Animations
    }     // namespace View
}
