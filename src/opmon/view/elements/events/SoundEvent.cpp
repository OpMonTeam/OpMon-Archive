#include "SoundEvent.hpp"
#include "src/opmon/screens/overworld/Overworld.hpp"

namespace OpMon {
	namespace Elements {

		SoundEvent::SoundEvent(sf::Texture &texture, std::vector<sf::IntRect> rectangles, EventTrigger eventTrigger, sf::Vector2f const &position, std::string const& playID, bool music, bool toggle, int sides, bool passable)
				: AbstractEvent(texture, rectangles, eventTrigger, position, sides, passable)
				  , playID(playID)
				  , music(music)
				  , toggle(toggle) {}

		SoundEvent::SoundEvent(OverworldData &data, nlohmann::json jsonData)
		: AbstractEvent(data, jsonData)
		, playID(jsonData.at("playID"))
		, music(jsonData.value("music", false))
		, toggle(jsonData.value("toggle", false)){
			this->rectangles = std::vector<sf::IntRect>{sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y)};
			this->currentFrame = rectangles.begin();
		}

		void SoundEvent::action(Overworld& overworld){
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
