#include "SoundEvent.hpp"
#include "Overworld.hpp"

namespace OpMon {
	namespace Elements {

		SoundEvent::SoundEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, std::string const& playID, bool music, bool toggle, int sides, bool passable)
				: AbstractEvent(otherTextures, eventTrigger, position, sides, passable)
				  , playID(playID)
				  , music(music)
				  , toggle(toggle) {}

		SoundEvent::SoundEvent(OverworldData &data, nlohmann::json jsonData)
		: AbstractEvent(data, jsonData)
		, playID(jsonData.at("playID"))
		, music(jsonData.value("music", false))
		, toggle(jsonData.value("toggle", false)){

		}

		void SoundEvent::action(Player& player, Overworld& overworld){
			Ui::Jukebox &jukebox = overworld.getData().getGameDataPtr()->getJukebox();
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
