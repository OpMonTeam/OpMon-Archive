#include "SoundEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"

namespace OpMon {
	namespace Elements {

		SoundEvent::SoundEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, std::string const& playID, bool music, bool toggle, int sides, bool passable)
				: AbstractEvent(otherTextures, eventTrigger, position, sides, passable)
				  , playID(playID)
				  , music(music)
				  , toggle(toggle) {}

		void SoundEvent::action(Player& player, Overworld& overworld){
			Ui::Jukebox &jukebox = overworld.getData().getUiDataPtr()->getJukebox();
			if(toggle && playing && music){
				jukebox.stop();
				playing = false;
			}else if(music){
				jukebox.play(playID);
				playing = true;
			} else {
				jukebox.playSound(playID);
			}
		}

	} /* namespace Elements */
} /* namespace OpMon */
