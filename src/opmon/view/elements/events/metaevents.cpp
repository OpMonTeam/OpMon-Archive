#include "metaevents.hpp"
#include "AnimationEvent.hpp"
#include "SoundEvent.hpp"
#include "TPEvent.hpp"
#include <queue>

namespace OpMon::Elements {
	DoorEvent::DoorEvent(OverworldData &data, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, EventTrigger eventTrigger, Side ppDir, int sides, bool passable)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new AnimationEvent(data.getDoorsTexture(doorType), eventTrigger, position, 1, false, passable, sides),
		new SoundEvent(data.getUiDataPtr()->alpha, eventTrigger, position, doorType + " sound", false, false, sides, passable),
		new TPEvent(data.getUiDataPtr()->alpha, eventTrigger, position, tpCoord, map, ppDir, sides, passable),
		nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false}))){
		this->position += sf::Vector2f(0, -6); //TODO : Fix the sprites to get rid of this little fix
		if(doorType == "shop door") {
		   this->position.x -= 4;
		}
	}

	void DoorEvent::action(Player &player, Overworld &overworld){
		player.getPosition().lockMove();
		LinearMetaEvent::action(player, overworld);
	}

	void DoorEvent::update(Player &player, Overworld &overworld){
		LinearMetaEvent::update(player, overworld);
		if(!processing){
			player.getPosition().unlockMove();
		}
	}
}
