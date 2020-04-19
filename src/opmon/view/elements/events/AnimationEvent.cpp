#include "AnimationEvent.hpp"
#include "src/utils/exceptions.hpp"

namespace OpMon {
	namespace Elements {

		AnimationEvent::AnimationEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, unsigned int framerate, bool loop, bool passable, bool lastTexture, int sides)
		: AbstractEvent(otherTextures, eventTrigger, position, sides, passable)
		, framerate(framerate)
		, loop(loop)
		, lastTexture(lastTexture) {
		}

		AnimationEvent::AnimationEvent(OverworldData &data, nlohmann::json jsonData)
		: AbstractEvent(data, jsonData)
		, framerate(jsonData.value("framerate", 0))
		, loop(jsonData.value("loop", false))
		, lastTexture(jsonData.value("lastTexture", true)){

		}

		void AnimationEvent::action(Player &player, Overworld &overworld){
			playing = !(playing && loop); //Stops playing only if it's a loop. Else, stay playing or start playing.
			resetTexture();
		}

		void AnimationEvent::update(Player &player, Overworld &overworld){
			if(playing && (framecount >= framerate)){
				++currentTexture;
				framecount = 0;
				if(currentTexture == otherTextures.end()){
					currentTexture = otherTextures.begin();
					playing = loop; //If loop, continue playing, else, stop.
					if(!playing && lastTexture) currentTexture = otherTextures.end() - 1;
				}
			}else if(playing && (framecount < framerate)){
				framecount++;
			}
		}


	} /* namespace Elements */
} /* namespace OpMon */
