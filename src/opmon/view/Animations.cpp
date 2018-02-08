#include "Animations.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/time.hpp"
#include "../model/storage/Data.hpp"
#include "../start/Core.hpp"
#include "../view/Window.hpp"

UNS

  namespace OpMon {
	namespace View {

		namespace Animations {

			Animation::Animation(sf::Texture bgTxt)
			  : bgTxt(bgTxt) {}

			WinAnim::WinAnim(sf::Texture bgTxt, bool order)
			  : Animation(bgTxt)
			  , order(order) {
			}

			GameStatus WinAnim::operator()() {
				bgSpr.setTexture(bgTxt);
				anim.setTexture(Model::Data::Animations::fen[(order ? counter : (frames - counter))]);

				frame.draw(bgSpr);
				frame.draw(anim);

				counter++;
				return (counter > frames) ? GameStatus::PREVIOUS : GameStatus::CONTINUE;
			}

		} // namespace Animations
	}   // namespace View
}
