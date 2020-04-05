#include "metaevents.hpp"
#include "AnimationEvent.hpp"
#include "SoundEvent.hpp"
#include "TPEvent.hpp"
#include "DialogEvent.hpp"
#include <queue>

namespace OpMon::Elements {
	DoorEvent::DoorEvent(OverworldData &data, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, EventTrigger eventTrigger, Side ppDir, int sides, bool passable)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		new AnimationEvent(data.getDoorsTexture(doorType), eventTrigger, position, 1, false, passable, sides),
				new SoundEvent(data.getDoorsTexture(doorType), eventTrigger, position, doorType + " sound", false, false, sides, passable),
				new TPEvent(data.getDoorsTexture(doorType), eventTrigger, position, tpCoord, map, ppDir, sides, passable),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false, false}))){
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


	TalkingCharaEvent::TalkingCharaEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Utils::OpString const &dialogKey, Side posDir, EventTrigger eventTrigger, MoveStyle moveStyle, std::vector<Side> predefinedPath, bool passable, int side)
	: LinearMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
				new CharacterEvent(textures, position, posDir, moveStyle, eventTrigger, predefinedPath, passable, sides),
				new DialogEvent(textures, position, dialogKey, sides, eventTrigger, passable),
				nullptr})),
			std::queue<bool>(std::deque<bool>({false, true, false}))) {

	}

	void TalkingCharaEvent::action(Player &player, Overworld& overworld){
		mapPos.lockMove();
		LinearMetaEvent::action(player, overworld);
	}

	void TalkingCharaEvent::update(Player &player, Overworld &overworld){
		if(processing && !mapPos.isAnim()){
			switch(player.getPosition().getDir()) { //Put the character's face in front of the player's one
			case Side::TO_DOWN:
				mapPos.setDir(Side::TO_UP);
				break;
			case Side::TO_UP:
				mapPos.setDir(Side::TO_DOWN);
				break;
			case Side::TO_LEFT:
				mapPos.setDir(Side::TO_RIGHT);
				break;
			case Side::TO_RIGHT:
				mapPos.setDir(Side::TO_LEFT);
				break;
			default:
				break;
			}
			//Put the correct texture to the NPC
			currentTexture = otherTextures.begin() + (int)mapPos.getDir();
			updateTexture();
		}
		LinearMetaEvent::update(player, overworld);
		if(processing && !mapPos.isAnim()){
			mapPos.unlockMove();
		}
	}


	TrainerEvent::TrainerEvent(TalkingCharaEvent* prebattlenpc, BattleEvent* battle, TalkingCharaEvent* postbattlenpc)
	: AbstractMetaEvent(std::queue<AbstractEvent*>(std::deque<AbstractEvent*>({
		prebattlenpc, battle, postbattlenpc
	}))) {}

	void TrainerEvent::update(Player &player, Overworld &overworld){
		eventQueue.front()->update(player, overworld);
		if(triggered && !defeated && eventQueue.front()->isOver()){
			eventQueue.pop();
			if(eventQueue.size() == 1){
				eventQueue.front()->action(player, overworld);
				defeated = true;
			}
		}

		AbstractMetaEvent::update(player, overworld);
	}

	void TrainerEvent::action(Player &player, Overworld &overworld){
		eventQueue.front()->action(player, overworld);
		triggered = true;
	}
}
